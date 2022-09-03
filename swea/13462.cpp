#include <set>
#include <vector>
#include <list>

using namespace std;

typedef struct _Particle {
	bool valid;
	int Px, Py, Pz;
	int Vx, Vy, Vz;
	int Sx, Sy, Sz;
} Particle;

int L, LL, LLLL, l, R;
long long RR;
Particle p[50001];
int pCount;
//set<int> Section[10][10][10];
list<int> Section[10][10][10];

bool checkSectionBound(int x, int y, int z) {
	return x >= 0 && x < 10 && y >= 0 && y < 10 && z >= 0 && z < 10;
}

bool roughCheck(int mID, int dx, int dy, int dz, int nSx, int nSy, int nSz) {
	int Sx = (p[mID].Px + dx * R) / l;
	int Sy = (p[mID].Py + dy * R) / l;
	int Sz = (p[mID].Pz + dz * R) / l;

	return (Sx == nSx) || (Sy == nSy) || (Sz == nSz);
}

void updateLocation(int* next, int* v, int mTick) {
	//Px + Vx >= 2L
	*next += *v * mTick;
	while (*next > LL || *next < 0) {
		if (*next > LL) *next = LLLL - *next;
		else *next = -(*next);
		*v = -(*v);
	}
}

long long calcDistance(int mID1, int mID2) {
	long long sum = 0;

	sum += (p[mID1].Px - p[mID2].Px) * (p[mID1].Px - p[mID2].Px);
	sum += (p[mID1].Py - p[mID2].Py) * (p[mID1].Py - p[mID2].Py);
	sum += (p[mID1].Pz - p[mID2].Pz) * (p[mID1].Pz - p[mID2].Pz);

	return sum;
}

void init(int _L, int _R)
{
	L = _L; R = _R;
	RR = (long long)_R * _R;
	l = L / 5; // L은 5의 배수이기 때문에 l은 정수
	LL = L << 1; LLLL = L << 2;
	
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			for (int k = 0; k < 10; k++)
				Section[i][j][k].clear();
	pCount = 0;
}

void insertParticle(int mID, int mPx, int mPy, int mPz, int mVx, int mVy, int mVz)
{
	p[mID].valid = true;

	//좌표를 모두 양수로 만들어줌
	mPx += L; mPy += L; mPz += L;

	//구조체 변수 저장
	p[mID].Px = mPx; p[mID].Py = mPy; p[mID].Pz = mPz;
	p[mID].Vx = mVx; p[mID].Vy = mVy; p[mID].Vz = mVz;

	//여기선 모서리 입력이 안 들어와서 2L인 경우에 예외처리 필요없음
	p[mID].Sx = mPx / l; p[mID].Sy = mPy / l; p[mID].Sz = mPz / l;
	if (p[mID].Sx >= 10) p[mID].Sx = 9;
	if (p[mID].Sy >= 10) p[mID].Sy = 9;
	if (p[mID].Sz >= 10) p[mID].Sz = 9;

	//해당 구역에 저장
	//Section[p[mID].Sx][p[mID].Sy][p[mID].Sz].insert(mID);
	Section[p[mID].Sx][p[mID].Sy][p[mID].Sz].push_front(mID);

	pCount++;
}

void removeParticle(int mID)
{
	p[mID].valid = false;

	//해당 구역에서 삭제
	//Section[p[mID].Sx][p[mID].Sy][p[mID].Sz].remove(mID);
}

int findNearParticle(int mID)
{
	int ret = 0;
	int Sx = p[mID].Sx, Sy = p[mID].Sy, Sz = p[mID].Sz;

	//총 27개 구역 검사
	for (int dx = -1; dx < 2; dx++) {
		for (int dy = -1; dy < 2; dy++) {
			for (int dz = -1; dz < 2; dz++) {
				int nSx = Sx + dx, nSy = Sy + dy, nSz = Sz + dz;

				if (!checkSectionBound(nSx, nSy, nSz)) continue;
				if (!roughCheck(mID, dx, dy, dz, nSx, nSy, nSz)) continue;

				//구역에 들어있는 입자들이 조건을 만족하는지 체크
				list<int>::iterator iter = Section[nSx][nSy][nSz].begin();
				list<int>::iterator end = Section[nSx][nSy][nSz].end();

				for (; iter != end; iter++) {
					if (!p[*iter].valid) continue;
					//제곱근은 계산에서 제외
					if (calcDistance(mID, *iter) <= RR) {
						ret += *iter;
					}
				}
			}
		}
	}

	return ret - mID;
}

void go(int mTick)
{
	//현재 박스 초기화
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			for (int k = 0; k < 10; k++)
				Section[i][j][k].clear();

	for (int i = 1; i <= pCount; i++) {
		if (p[i].valid == false) continue;
		int mID = i;
		Particle cur = p[mID];

		//주어진 시간만큼 이동
		updateLocation(&cur.Px, &cur.Vx, mTick);
		updateLocation(&cur.Py, &cur.Vy, mTick);
		updateLocation(&cur.Pz, &cur.Vz, mTick);

		//이동이 끝난 이후의 구역
		cur.Sx = cur.Px / l; cur.Sy = cur.Py / l; cur.Sz = cur.Pz / l;

		//끝에 걸치는 경우에 구간 인덱스를 벗어날 수 있음
		if (cur.Sx >= 10) cur.Sx = 9;
		if (cur.Sy >= 10) cur.Sy = 9;
		if (cur.Sz >= 10) cur.Sz = 9;

		Section[cur.Sx][cur.Sy][cur.Sz].push_front(mID);
	
		//바뀐 정보 저장
		p[mID] = cur;
	}
}
