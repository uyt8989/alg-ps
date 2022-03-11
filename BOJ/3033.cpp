#include <iostream>
#include <vector>

using namespace std;

#define MOD 100003

int L;
char s[200005];

int mod(long long n) {
    if (n >= 0) return n % MOD;
    else return ((-n / MOD + 1) * MOD + n) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> L;
    cin >> s;

    int l = 0, r = L;
    while (l + 1 < r) {
        int mid = (l + r) / 2;
        long long pow = 1;
        int hash = 0;
        vector<int> pos[MOD];
        bool found = false;

        for (int i = 0; i + mid < L; i++) {
            if (i == 0) {
                for (int j = 0; j < mid; j++) {
                    hash = mod(hash + s[mid - 1 - j] * pow);
                    if (j + 1 < mid) pow = mod(pow << 1);
                }
            }
            else hash = mod(2 * (hash - s[i - 1] * pow) + s[i + mid - 1]);
            
            if (!pos[hash].empty()) {
                for (int p : pos[hash]) {
                    bool flag = true;
                    
                    for (int j = 0; j < mid; j++) {
                        if (s[i + j] != s[p + j]) {
                            flag = false;
                            break;
                        }
                    }
                    if (flag) {
                        found = true;
                        break;
                    }
                }
            }
            if (found) break;
            else pos[hash].push_back(i);
        }
        if (found) l = mid;
        else r = mid;
    }
    cout << l << '\n';
}
