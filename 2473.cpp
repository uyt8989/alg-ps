#include <iostream>
#include <limits.h>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int N;
vector<long long> liquid;
long long sum = LLONG_MAX;
int idx[3];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    int temp;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        liquid.push_back(temp);
    }

    sort(liquid.begin(), liquid.end());

    for (int i = 0; i < N - 2; i++) {
        int left = i + 1;
        int right = N - 1;
        while (left < right) {
            long long temp = liquid[i] + liquid[left] + liquid[right];
            if (sum > abs(temp)) {
                idx[0] = i;
                idx[1] = left;
                idx[2] = right;
                sum = abs(temp);
            }
            
            if (temp < 0) {
                left++;
            }
            else {
                right--;
            }
        }
    }

    cout << liquid[idx[0]] << ' ' << liquid[idx[1]] << ' ' << liquid[idx[2]];

    return 0;
}
