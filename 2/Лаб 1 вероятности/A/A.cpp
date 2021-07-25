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

int n, k;
double ans;

void in()
{
    ifstream cin("exam.in");
    cin >> k >> n;
    for (int i = 0; i < k; ++i) {
        int x, p;
        cin >> x >> p;
        ans += 0.01*x/n*p;
    }
}

void solution()
{
}

void out()
{
    ofstream cout("exam.out");
    cout.precision(7);
    cout << fixed << ans << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
