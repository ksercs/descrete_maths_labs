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
#define PII pair <LL, LL>
#define LL long long

using namespace std;

int n;
LL ans;
VEC <PII> ev;

bool comp(const PII & a, const PII & b) {
    if (a.SS == b.SS) {
        return a.FF < b.FF;
    }
    return a.SS > b.SS;
}

void in()
{
    ifstream cin("schedule.in");
    cin >> n;
    ev.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> ev[i].FF >> ev[i].SS;
    }
}

void solution()
{
    set<int> t;
    for (int i = 1; i <= n; ++i) {
        t.insert(i);
    }

    sort(ev.begin(), ev.end(), comp);

    for (int i = 0; i < n; ++i) {
        auto it = t.upper_bound(ev[i].FF);
        if (it == t.begin()) {
            ans += ev[i].SS;
            continue;
        }
        t.erase(--it);
    }
}

void out()
{
    ofstream cout("schedule.out");
    cout << ans << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}

