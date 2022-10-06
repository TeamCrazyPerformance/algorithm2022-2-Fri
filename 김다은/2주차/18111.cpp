#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

const int digTime = 2; // �� 1ĭ �Ĵ� �ð�
const int placeTime = 1; // �� 1ĭ ä��� �ð� 


static int N; // ����(����)
static int M; // ����(����)
static int B; // �־��� �κ� ��ϰ���

static int minHeight; //���� �� �ּ� ����
static int maxHeight; //���� �� �ִ� ����

static int minRange; //������ �ּ� ����
static int maxRange; //������ �ִ� ����

static int mapSize; // ���� ũ�� (= ���� * ����)

static vector<int> map(mapSize); // ���� ���� ����

/// Q �� 1�� �迭�� ����?
/// [1,2,2], [2,1,2], [1][2][2] ��� ���� output�� ����
/// ���� ���� ��ǥ�� �Ű� �Ƚᵵ �ǹǷ� 1�� �迭�� ����
/// 

static int minTaskTime; // �ּ� �ð�
static int minTaskHeight; // �ּ� �ð������� ����


static int sum = 0; // ���� ��

void getInput() {
	cin >> N >> M >> B; // ����, ����, �κ���� �ޱ�
	
	mapSize = N * M; // ���� ���η� �� ������ ���
	map.resize(mapSize, 0); // �� ����

	int tmp = 0;

	for (int row = 0; row < N; row++) {
		for (int col = 0; col < M; col++) {
			cin >> map[tmp]; // ���� ����
			sum += map[tmp]; // ���� �� ���ϱ�

			//���� �� �ִ� �ּ� ���� ���ϱ�
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

void setRange() { // ������ ���� ���� ���ϱ�
	// �켱 ������ ���� ���� ���� �� �ִ� �ּ� ���̷� ����
	minRange = minHeight;
	maxRange = maxHeight;

	// ���� �� �ִ� �ּ� ���� �� ������ ������ ����
	if (maxRange > (sum + B) / (N * M)) { maxRange = (sum + B) / (N * M); }


	/// ���� �ؼ�
	///
	/// �� �ļ� ��� ������ +1, �� ä���� ��� ���� -1
	/// �� ���� �迭 : [a1, a2, ..., a_n]
	///	
	/// ���� k�� ����ٰ� ������ ���̴� ��� �� A��
	///	
	/// A = (a1 - k) + (a1 - k) + ... + (a_n - k)
	///   = (a1 + a2 + ... + a_n) - n * k
	///
	///  ��ǥ �۾��� �����Ϸ���
	///  A + (�κ��� �־��� ��� ) >= 0
	/// 
	/// �̸� k�� �����ϸ�
	///  k =< ( (a1 + a2 + ... + a_n) +  (�κ��� �־��� ���) ) / n
	/// 
	/// �ִ� ���� ���̴� ( (a1 + a2 + ... + a_n) +  (�κ��� �־��� ���) ) / n

}

int calcTime(int baseHeight) {// �ð� ���ϱ�
	int resultTime = 0;
	int mop;
	for (int i = 0; i < mapSize; i++) {
		mop = map[i];
		if (mop >= baseHeight) { resultTime += (mop - baseHeight) * digTime; } 
		else { resultTime += (baseHeight - mop) * placeTime; }

	}

	return resultTime;
}

void findMinTask() { // �ּ� �ð� ���ϱ�

	int tmpTime;

	for (int height = minRange; height <= maxRange; height++) {
		tmpTime = calcTime(height);
		if (height == minRange) { minTaskTime = tmpTime; minTaskHeight = height; }
		if (tmpTime <= minTaskTime ) { minTaskTime = tmpTime; minTaskHeight = height; }
	}
}

int main(){

	getInput(); // �Է� ��������
	setRange(); // ������ ���̹��� ���ϱ�

	findMinTask(); // ������ ���� ���� �ȿ��� �ּ� �ð� ���ϱ�

	cout << minTaskTime <<" "<<minTaskHeight; // ���

	return 0;
}