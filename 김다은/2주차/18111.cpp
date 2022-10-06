#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

const int digTime = 2;
const int placeTime = 1;


static int N;
static int M;
static int B;

static int minHeight;
static int maxHeight;

static int minRange;
static int maxRange;

static int mapSize;

static vector<int> map(mapSize);

static int minTaskTime;
static int minTaskHeight;


static int sum = 0;

void getInput() {
	cin >> N >> M >> B;

	mapSize = N * M;
	map.resize(mapSize, 0);

	int tmp = 0;

	for (int row = 0; row < N; row++) {
		for (int col = 0; col < M; col++) {
			cin >> map[tmp];
			sum += map[tmp];

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

void setRange() {
	minRange = minHeight;
	maxRange = maxHeight;

	if (maxRange > (sum + B) / (N * M)) { maxRange = (sum + B) / (N * M); }
}

int calcTime(int baseHeight) {
	int resultTime = 0;
	int mop;
	for (int i = 0; i < mapSize; i++) {
		mop = map[i];
		if (mop >= baseHeight) { resultTime += (mop - baseHeight) * digTime; }
		else { resultTime += (baseHeight - mop) * placeTime; }

	}

	return resultTime;
}

void findMinTask() {

	int tmpTime;

	for (int height = minRange; height <= maxRange; height++) {
		tmpTime = calcTime(height);
		if (height == minRange) { minTaskTime = tmpTime; minTaskHeight = height; }
		if (tmpTime <= minTaskTime ) { minTaskTime = tmpTime; minTaskHeight = height; }
	}
}

int main(){

	getInput();
	setRange();

	findMinTask();

	cout << minTaskTime <<" "<<minTaskHeight;

	return 0;
}