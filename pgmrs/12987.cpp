#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(int a, int b) {
    return a < b;
}

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    int a = 0;
    
    sort(A.begin(), A.end(), comp);
    sort(B.begin(), B.end(), comp);
    
    for (int b = 0; b < B.size(); b++) {
        if (A[a] < B[b]) {
            answer++;
            a++;
        }
    }
    
    return answer;
}