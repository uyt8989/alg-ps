#include <string.h> // for memset
#include <queue>
#include <algorithm>
#include <vector>
#include <functional>
#include <unordered_map>

#define N 501

using namespace std;

struct Product {
    int pID, lineID, eID, nTime;
};
struct Request {
    int time;
    Product p;
    bool operator<(const Request& y) const {
        return time > y.time;
    }
};

int n, m, timeNow;
bool lineUse[N], eUse[N];
queue<Product> LQ[N];
priority_queue<int, vector<int>, greater<int>> EQ[N];
priority_queue<Request> TQ;
priority_queue<int, vector<int>, greater<int> > Q;

int casheLine[N];
unordered_map<int, int> casheProduct;

void init(int _n, int _m) {
    n = _n; m = _m;
    timeNow = 0;
    memset(lineUse, false, n);
    memset(eUse, false, m);
    for (register int i = 0; i < n; i++) {
        //while (!LQ[i].empty()) LQ[i].pop();
        LQ[i] = queue<Product>();
    }
    for (register int i = 0; i < m; i++) {
        //while (!EQ[i].empty()) EQ[i].pop();
        EQ[i] = priority_queue<int, vector<int>, greater<int>>();
    }
    
    //while (!TQ.empty()) TQ.pop();
    TQ = priority_queue<Request>();
    casheProduct.clear();
}

void timeFlow(int t) {
    while (!TQ.empty() && TQ.top().time <= t) {
        timeNow = TQ.top().time;
        while (TQ.empty() == false && TQ.top().time == timeNow) {
            register Product p = TQ.top().p; TQ.pop();

            if (p.pID < 0) continue;
            lineUse[p.lineID] = false;
            eUse[p.eID] = false;
            casheProduct[p.pID] = 3;

            Q.push(p.lineID);
            if (!EQ[p.eID].empty()) {
                register int line = EQ[p.eID].top();
                Q.push(line);

                while (!EQ[p.eID].empty() && EQ[p.eID].top() == line) EQ[p.eID].pop();
            }
        }

        while (!Q.empty()) {
            register int lineID = Q.top(); Q.pop();
            while (!Q.empty() && Q.top() == lineID) Q.pop();

            if (lineUse[lineID] == false && !LQ[lineID].empty()) {
                register Product p = LQ[lineID].front();

                if (eUse[p.eID] == false) {
                    lineUse[lineID] = true;
                    casheLine[lineID] = p.pID;

                    eUse[p.eID] = true;
                    casheProduct[p.pID] = 2;

                    TQ.push({ timeNow + p.nTime, p });
                    LQ[lineID].pop();
                }
                else EQ[p.eID].push(lineID);
            }
        }
    }
}

int request(int tStamp, int pID, int mLine, int eID, int mTime) {
    timeFlow(tStamp - 1);

    LQ[mLine].push({ pID, mLine, eID, mTime });
    TQ.push({ tStamp, { -1 } });
    Q.push(mLine);
    casheProduct[pID] = 1;

    timeFlow(tStamp);

    return lineUse[mLine] ? casheLine[mLine] : -1;
}

int status(int tStamp, int pID) {
    timeFlow(tStamp);
    return casheProduct[pID];
}