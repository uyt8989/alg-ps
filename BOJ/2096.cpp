#include <iostream>
#include <utility>
#include <algorithm>

#define PREV 0
#define CUR 1

std::pair<int, int> score[2][3];
int data[3];
int N;

int main() {
	std::cin >> N;

	std::cin >> data[0] >> data[1] >> data[2];
	for (int i = 0; i < 3; i++)
		score[0][i].first = score[0][i].second = data[i];

	for (int i = 1; i < N; i++) {
		std::cin >> data[0] >> data[1] >> data[2];

		score[CUR][0].first = std::max(score[PREV][0].first, score[PREV][1].first) + data[0];
		score[CUR][0].second = std::min(score[PREV][0].second, score[PREV][1].second) + data[0];

		score[CUR][2].first = std::max(score[PREV][1].first, score[PREV][2].first) + data[2];
		score[CUR][2].second = std::min(score[PREV][1].second, score[PREV][2].second) + data[2];

		score[CUR][1].first = std::max(score[CUR][0].first - data[0], score[CUR][2].first - data[2]) + data[1];
		score[CUR][1].second = std::min(score[CUR][0].second - data[0], score[CUR][2].second - data[2]) + data[1];
		
		for (int i = 0; i < 3; i++) {
			score[PREV][i].first = score[CUR][i].first;
			score[PREV][i].second = score[CUR][i].second;
		}
	}

	int Max = score[PREV][0].first;
	int Min = score[PREV][0].second;
	
	for (int i = 1; i < 3; i++) {
		Max = std::max(Max, score[PREV][i].first);
		Min = std::min(Min, score[PREV][i].second);
	}

	std::cout << Max << " " << Min;

	return 0;
}
