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
#define PLL pair <LL,LL>

using namespace std;

int n, m;
LL ans;
VEC <PLL> weight;
VEC <int> sets;

void in()
{
    ifstream cin("cycles.in");
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        LL w;
        cin >> w;
        weight.PB({w, i});
    }
    for (int i = 0; i < m; ++i) {
        int sz;
        cin >> sz;
        int mask = 0;
        for (int j = 0; j < sz; ++j) {
            int cur;
            cin >> cur;
            mask |= (1 << cur);
        }
        sets.PB(mask);
    }
}

void solution()
{
    sort(weight.begin(), weight.end());

    int cur = 0;
    for (int i = n - 1; i >= 0; --i) {
        int ind = weight[i].SS;
        int bit = (1 << ind);
        int fl = 1;
//        cout << (cur | bit) << "\n";
        int next = (cur | bit);
        for (int j = 0; j < m; ++j) {
            if ((next & sets[j]) == sets[j]) {
                fl = 0;
                break;
            }
        }
        if (fl) {
            cur = next;
            ans += weight[i].FF;
        }
    }
}

void out()
{
    ofstream cout("cycles.out");
    cout << ans << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
