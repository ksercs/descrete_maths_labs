#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <iomanip>
#include <set>
#include <map>
#include <utility>
#include <queue>
#include <string.h>

#define SZ size()
#define VEC vector
#define PB push_back
#define MP make_pair
#define SS second
#define FF first
#define PII pair <int,int>
#define LL long long

using namespace std;

const string ANS[] = {"NO\n", "YES\n"};
const int MAX_SET = (int)1e6;

int n, m;
bool isInI[MAX_SET];
int dp[MAX_SET];
bool ax1, ax2, ax3;
VEC <int> sets;
VEC <int> setSize;

bool checkSubsets(int cur) {
//    cout << cur << "\n";
    if (dp[cur] != -1) {
//        cout << "SEFSE\n";
        return dp[cur];
    }

    bool fl = 1;
    for (int i = 1; i <= n; ++i) {
        if ((cur & (1 << i)) > 0) {
            int subset = (cur ^ (1 << i));
//            cout << "--> " << subset << "\n";
            if (!isInI[subset]) {
//                cout << "! " << subset << "\n";
                return dp[cur] = 0;
            }
            fl = fl && checkSubsets(subset);
        }
    }
    return dp[cur] = fl;
}

bool checkXFromDif(int mask1, int mask2) {
    for (int i = 1; i <= n; ++i) {
        int cur = (1 << i);
        if ((mask1 & cur) > 0 && (mask2 & cur) == 0) {
//            cout << (mask2 | cur) << "\n";
            if (isInI[(mask2 | cur)]) {
                return 1;
            }
        }
    }
    return 0;
}

void in()
{
    ifstream cin("check.in");
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int mask = 0;
        int sz = 0, cur = 0;
        cin >> sz;
        for (int j = 0; j < sz; ++j) {
            cin >> cur;
            mask |= (1 << cur);
        }
        if (mask == 0) {
            ax1 = 1;
        }
        setSize.PB(sz);
        sets.PB(mask);
        isInI[mask] = 1;
//        cout << "mask : " << mask << "\n";
    }
}

void solution()
{
    for (int i = 0; i <= MAX_SET; ++i) {
        dp[i] = -1;
    }
    bool fl = 1;
    for (auto it : sets) {
        fl = fl && checkSubsets(it);
    }
    ax2 = fl;

    fl = 1;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            if (setSize[i] > setSize[j]) {
                fl = fl && checkXFromDif(sets[i], sets[j]);
            }
        }
    }
    ax3 = fl;

//    cout << ax1 << " " << ax2 << " " << ax3 << "\n";
}

void out()
{
    ofstream cout("check.out");
    cout << ANS[ax1 && ax2 && ax3];
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
