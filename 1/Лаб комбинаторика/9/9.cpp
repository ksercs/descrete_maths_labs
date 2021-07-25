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

void subset(int bal, int cnt, VEC <char> &ans)
{
    if (ans.SZ == 2 * cnt) {
        for (int i = 0; i < 2 * cnt; ++i) {
            cout << ans[i];
        }
        cout << "\n";
        return;
    }
    if (2 * cnt - ans.SZ >= bal + 1) {
        ans.PB('(');
        subset(bal + 1, cnt, ans);
        ans.pop_back();
    }
    if (bal > 0) {
        ans.PB(')');
        subset(bal - 1, cnt, ans);
        ans.pop_back();
    }
}

int main()
{
    freopen("brackets.in", "r", stdin);
    freopen("brackets.out", "w", stdout);
    int n;
    cin >> n;
    VEC <char> answer;
    subset(0, n, answer);
    return 0;
}
