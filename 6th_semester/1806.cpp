#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int INF = 987654321;
int N, S;
int low = 0, high = 0;
int sum = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    cin >> N >> S;

    vector<int> arr(N);

    for (int i = 0; i < N; i++)
        cin >> arr[i];

    int result = INF;
    sum += arr[0];

    while (low <= high && high < N) {
        if (sum < S)
            sum += arr[++high];
        else if (sum == S) {
            result = min(result, (high - low + 1));
            sum += arr[++high];
        }
        else if (sum > S) {
            result = min(result, (high - low + 1));
            sum -= arr[low++];
        }
    }

    if (result == INF)
        cout << 0 << "\n";
    else
        cout << result << "\n";

    return 0;
}
