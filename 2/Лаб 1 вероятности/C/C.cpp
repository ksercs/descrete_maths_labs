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

int n, m;
double ans;
VEC <int> a, b;

void in()
{
    ifstream cin("lottery.in");
    cin >> n >> m;
    a.resize(m);
    b.resize(m);
    for (int i = 0; i < m; ++i)
        cin >> a[i] >> b[i];
}

void solution()
{
    ans = n;
    double koef = 1.0 / a[0];
    for (int i = 1; i < m; ++i) {
        ans -= koef / a[i] * (a[i] - 1) * b[i-1];
        koef *= 1.0 / a[i];
    }
    ans -= koef * b[m-1];
}

void out()
{
    ofstream cout("lottery.out");
    cout.precision(7);
    cout << ans << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
