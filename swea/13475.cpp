#include <string.h>
#include <stdio.h>
#include <vector>

#define MAX 10000

using namespace std;

typedef struct _Place {
	int pID;
	int _r, _c;
	bool infected;
	bool valid;
	_Place* near[8];
} Place;

Place* place[50001];
Place placePool[50000]; int pCount;
vector<int> Row[MAX], Col[MAX], Dia[2][MAX*2];
vector<int> Route[1000];

void print() {
	for (int i = 1; i <= pCount; i++) {
		if (!place[i]->valid) continue;
		printf("#%3d (%3d,%3d) :", i, place[i]->_r, place[i]->_c);
		if (place[i]->infected) printf("infect!! ");
		for (int j = 0; j < 8; j++) {
			if (place[i]->near[j] != NULL)
				printf("%3d ", place[i]->near[j]->pID);
			else printf("  x ");
		}
		printf("\n");
	}
	printf("-----------------------------------------\n");
}

void deleteArr(vector<int> arr, int target) {
	int len = arr.size();
	
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] == target) {
			arr.erase(arr.begin() + i);
			break;
		}
	}
	return;
}

void updateInfo(int pID, int r, int c, int x) {
	//추가
	if (x == 1) {
		Row[r].push_back(pID);
		Col[c].push_back(pID);
		Dia[0][r + c].push_back(pID);
		Dia[1][r - c + 10000].push_back(pID);
	}
	//삭제
	else {
		deleteArr(Row[r], pID);
		deleteArr(Col[c], pID);
		deleteArr(Dia[0][r + c], pID);
		deleteArr(Dia[1][r - c + 10000], pID);
	}

	return;
}

Place* allocPlace(int pID, int r, int c) {
	Place* newPlace = &placePool[pCount++];

	newPlace->pID = pID;
	newPlace->_r = r; newPlace->_c = c;
	newPlace->infected = false; newPlace->valid = true;
	for (int dir = 0; dir < 8; dir++)
		newPlace->near[dir] = NULL;

	return newPlace;
}

void init()
{
	pCount = 0;

	for (int i = 0; i < 1000; i++) {
		Route[i].clear();
	}

	for (int i = 0; i < MAX; i++) {
		Row[i].clear();
		Col[i].clear();
	}
	for (int i = MAX; i < 2 * MAX; i++) {
		Dia[0][i].clear();
		Dia[1][i].clear();
	}
}

void addPlace(int pID, int r, int c)
{
	place[pID] = allocPlace(pID, r, c);

	//near 갱신
	for (int dir = 0; dir < 4; dir++) {
		int up = 0, up_dist = MAX*2;
		int down = 0, down_dist = MAX*2;
		
		switch (dir) {
		//0, 4 -> 열 방향
		case 0 :
			for (int i = 0; i < Col[c].size(); i++) {
				int temp = Col[c][i]; int pRow = place[temp]->_r;
				//위
				if (pRow < r && r - pRow < up_dist) {
					up = temp; up_dist = r - pRow;
				}
				//아래
				else if(pRow > r && pRow - r < down_dist) {
					down = temp; down_dist = pRow - r;
				}
			}
			break;

		//1, 5 -> 0번 대각 방향
		case 1:
			for (int i = 0; i < Dia[0][r + c].size(); i++) {
				int temp = Dia[0][r + c][i]; int pRow = place[temp]->_r;
				//위
				if (pRow < r && r - pRow < up_dist) {
					up = temp; up_dist = r - pRow;
				}
				//아래
				else if (pRow > r && pRow - r < down_dist) {
					down = temp; down_dist = pRow - r;
				}
			}
			break;
		//2, 6 -> 행방향
		case 2:
			for (int i = 0; i < Row[r].size(); i++) {
				int temp = Row[r][i]; int pCol = place[temp]->_c;
				//오른쪽
				if (pCol > c && pCol - c < up_dist) {
					up = temp; up_dist = pCol - c;
				}
				//왼쪽
				else if (pCol < c && c - pCol < down_dist) {
					down = temp; down_dist = c - pCol;
				}
			}
			break;
		//3, 7 -> 1번 대각 방향
		case 3:
			for (int i = 0; i < Dia[1][r - c + 10000].size(); i++) {
				int temp = Dia[1][r - c + 10000][i]; int pRow = place[temp]->_r;
				//위
				if (pRow < r && r - pRow < down_dist) {
					down = temp; down_dist = r - pRow;
				}
				//아래
				else if (pRow > r && pRow - r < up_dist) {
					up = temp; up_dist = pRow - r;
				}
			}
			
			break;
		}

		if (up != 0) {
			place[pID]->near[dir] = place[up];
			place[up]->near[dir + 4] = place[pID];
		}
		if (down != 0) {
			place[pID]->near[dir + 4] = place[down];
			place[down]->near[dir] = place[pID];
		}
	}

	updateInfo(pID, r, c, 1);

}

void removePlace(int pID)
{
	place[pID]->valid = false;
	
	//near 갱신
	for (int dir = 0; dir < 8; dir++) {
		int rev = (dir + 4) % 8;
		if (place[pID]->near[dir] != NULL) 
			place[pID]->near[dir]->near[rev] = place[pID]->near[rev];
	}

	//if(place[pID]->infected == false)
	updateInfo(pID, place[pID]->_r, place[pID]->_c, -1);

}

void contactTracing(int uID, int visitNum, int moveInfo[], int visitList[])
{
	memset(visitList, 0, sizeof(visitList));
	
	int now = moveInfo[0];
	visitList[0] = now;
	//Route[uID][0] = now;
	Route[uID].push_back(now);

	for (int i = 1; i < visitNum; i++) {
		if(place[now]->near[moveInfo[i]] != NULL)
			now = place[now]->near[moveInfo[i]]->pID;
		visitList[i] = now;
	}

	bool check[50001];
	memset(check, false, sizeof(check));

	for (int i = 0; i < visitNum; i++) {
		if (!check[visitList[i]]) {
			Route[uID].push_back(visitList[i]);
			check[visitList[i]] = true;
		}
	}

	for (int i = 0; i < Route[uID].size(); i++) {
		int pID = Route[uID][i];
		
		place[pID]->infected = true;
		for (int dir = 0; dir < 8; dir++) {
			int rev = (dir + 4) % 8;
			if (place[pID]->near[dir] != NULL)
				place[pID]->near[dir]->near[rev] = place[pID]->near[rev];
		}

		for (int dir = 0; dir < 8; dir++) {
			place[pID]->near[dir] = NULL;
		}

		updateInfo(pID, place[pID]->_r, place[pID]->_c, -1);
	}
}

void disinfectPlaces(int uID)
{
	for (int i = 0; i < Route[uID].size(); i++) {
		int pID = Route[uID][i];
		int r = place[pID]->_r;
		int c = place[pID]->_c;

		if (place[pID]->valid == false) continue;

		place[pID]->infected = false;
		updateInfo(pID, r, c, 1);

		for (int dir = 0; dir < 4; dir++) {
			int up = 0, up_dist = MAX;
			int down = 0, down_dist = MAX;

			switch (dir) {
				//0, 4 -> 열 방향
			case 0:
				for (int i = 0; i < Col[c].size(); i++) {
					int temp = Col[c][i]; int pRow = place[temp]->_r;
					//위
					if (pRow < r && r - pRow < up_dist) {
						up = temp; up_dist = r - pRow;
					}
					//아래
					else if (pRow > r && pRow - r < down_dist) {
						down = temp; down_dist = pRow - r;
					}
				}
				break;

				//1, 5 -> 0번 대각 방향
			case 1:
				for (int i = 0; i < Dia[0][r + c].size(); i++) {
					int temp = Dia[0][r + c][i]; int pRow = place[temp]->_r;
					//위
					if (pRow < r && r - pRow < up_dist) {
						up = temp; up_dist = r - pRow;
					}
					//아래
					else if (pRow > r && pRow - r < down_dist) {
						down = temp; down_dist = pRow - r;
					}
				}
				break;
				//2, 6 -> 행방향
			case 2:
				for (int i = 0; i < Row[r].size(); i++) {
					int temp = Row[r][i]; int pCol = place[temp]->_c;
					//오른쪽
					if (pCol > c && pCol - c < up_dist) {
						up = temp; up_dist = pCol - c;
					}
					//왼쪽
					else if (pCol < c && c - pCol < down_dist) {
						down = temp; down_dist = c - pCol;
					}
				}
				break;
				//3, 7 -> 1번 대각 방향
			case 3:
				for (int i = 0; i < Dia[1][r - c + 10000].size(); i++) {
					int temp = Dia[1][r - c + 10000][i]; int pRow = place[temp]->_r;
					//위
					if (pRow < r && r - pRow < down_dist) {
						down = temp; down_dist = r - pRow;
					}
					//아래
					else if (pRow > r && pRow - r < up_dist) {
						up = temp; up_dist = pRow - r;
					}
				}

				break;
			}

			if (up != 0) {
				place[pID]->near[dir] = place[up];
				place[up]->near[dir + 4] = place[pID];
			}
			if (down != 0) {
				place[pID]->near[dir + 4] = place[down];
				place[down]->near[dir] = place[pID];
			}
		}
		
	}
}