#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;

    sort(times.begin(), times.end());

    long long left = 1;
    long long right = (long long)times[times.size() - 1] * n;

    while (left <= right) {
        long long mid = (left + right) / 2;
        long long people = 0;

        for (int t = 0; t < times.size(); t++) {
            people += mid / times[t];

            if (people >= n) {
                break;
            }
        }

        if (people >= n) {
            answer = mid;
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }

    return answer;
}