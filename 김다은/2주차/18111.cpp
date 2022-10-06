#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

const int digTime = 2; // 땅 1칸 파는 시간
const int placeTime = 1; // 땅 1칸 채우는 시간 


static int N; // 세로(집터)
static int M; // 가로(집터)
static int B; // 주어진 인벤 블록갯수

static int minHeight; //기존 땅 최소 높이
static int maxHeight; //기존 땅 최대 높이

static int minRange; //가능한 최소 높이
static int maxRange; //가능한 최대 높이

static int mapSize; // 집터 크기 (= 세로 * 가로)

static vector<int> map(mapSize); // 땅의 높이 저장

/// Q 왜 1차 배열로 저장?
/// [1,2,2], [2,1,2], [1][2][2] 모두 같은 output을 가짐
/// 따라서 땅의 좌표는 신경 안써도 되므로 1차 배열로 저장
/// 

static int minTaskTime; // 최소 시간
static int minTaskHeight; // 최소 시간에서의 높이


static int sum = 0; // 높이 합

void getInput() {
	cin >> N >> M >> B; // 가로, 세로, 인벤블록 받기
	
	mapSize = N * M; // 가로 세로로 맵 사이즈 얻기
	map.resize(mapSize, 0); // 맵 세팅

	int tmp = 0;

	for (int row = 0; row < N; row++) {
		for (int col = 0; col < M; col++) {
			cin >> map[tmp]; // 높이 저장
			sum += map[tmp]; // 높이 합 구하기

			//기존 땅 최대 최소 높이 구하기
			if (tmp == 0) {
				minHeight = map[tmp];
				maxHeight = map[tmp];
			}
			if (minHeight > map[tmp]) { minHeight = map[tmp]; }
			if (maxHeight < map[tmp]) { maxHeight = map[tmp]; }

			tmp++;
		}
	}

}

void setRange() { // 가능한 높이 범위 구하기
	// 우선 가능한 높이 범위 기존 땅 최대 최소 높이로 세팅
	minRange = minHeight;
	maxRange = maxHeight;

	// 기존 땅 최대 최소 높이 중 가능한 범위만 세팅
	if (maxRange > (sum + B) / (N * M)) { maxRange = (sum + B) / (N * M); }


	/// 수식 해석
	///
	/// 땅 파서 블록 얻으면 +1, 땅 채워서 블록 쓰면 -1
	/// 땅 정보 배열 : [a1, a2, ..., a_n]
	///	
	/// 높이 k로 맞춘다고 했을때 쓰이는 블록 수 A는
	///	
	/// A = (a1 - k) + (a1 - k) + ... + (a_n - k)
	///   = (a1 + a2 + ... + a_n) - n * k
	///
	///  목표 작업이 가능하려면
	///  A + (인벤에 주어진 블록 ) >= 0
	/// 
	/// 이를 k로 정리하면
	///  k =< ( (a1 + a2 + ... + a_n) +  (인벤에 주어진 블록) ) / n
	/// 
	/// 최대 가능 높이는 ( (a1 + a2 + ... + a_n) +  (인벤에 주어진 블록) ) / n

}

int calcTime(int baseHeight) {// 시간 구하기
	int resultTime = 0;
	int mop;
	for (int i = 0; i < mapSize; i++) {
		mop = map[i];
		if (mop >= baseHeight) { resultTime += (mop - baseHeight) * digTime; } 
		else { resultTime += (baseHeight - mop) * placeTime; }

	}

	return resultTime;
}

void findMinTask() { // 최소 시간 구하기

	int tmpTime;

	for (int height = minRange; height <= maxRange; height++) {
		tmpTime = calcTime(height);
		if (height == minRange) { minTaskTime = tmpTime; minTaskHeight = height; }
		if (tmpTime <= minTaskTime ) { minTaskTime = tmpTime; minTaskHeight = height; }
	}
}

int main(){

	getInput(); // 입력 가져오기
	setRange(); // 가능한 높이범위 구하기

	findMinTask(); // 가능한 높이 범위 안에서 최소 시간 구하기

	cout << minTaskTime <<" "<<minTaskHeight; // 출력

	return 0;
}