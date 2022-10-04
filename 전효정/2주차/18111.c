#include <stdio.h>
#include <stdlib.h>

int main()
{
	int N, M, B;
	scanf("%d %d %d", &N, &M, &B);
	int *heightsInArea = (int *)malloc(sizeof(int) * (N*M));
	int num;

	for (int i = 0; i < N*M; i++) {
		scanf("%d", &num); 
		heightsInArea[i] = num;
	}

	int minTime = M * N *  512 + 1;
	int inventory, time, resultOfHeight;


	for (int height = 0; height <= 256; height++) {
		inventory = B;
		time = 0;
		for (int i = 0; i < N*M; i++) {
			if (heightsInArea[i] > height) {
				inventory += heightsInArea[i] - height;
				time += (heightsInArea[i] - height) * 2;
			} else if (heightsInArea[i] < height) {
				inventory -= height - heightsInArea[i];
				time += height - heightsInArea[i];
			}
		}

		if (inventory < 0) continue; 

		if (time == 0) minTime = 0; 
		if (time <= minTime) { 
			minTime = time;
			resultOfHeight = height;
		}
	}

	printf("%d %d", minTime, resultOfHeight);
	free(heightsInArea);
}