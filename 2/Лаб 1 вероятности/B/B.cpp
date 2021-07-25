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

int n, m, k;
double ans, sum;

void in()
{
    ifstream cin("shooter.in");
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) {
        double a;
        cin >> a;
        a = pow(1-a, m);
        sum += a;
        if (i == k - 1) {
            ans = a;
        }
    }
}

void solution()
{
    ans /= sum;
}

void out()
{
    ofstream cout("shooter.out");
    cout.precision(15);
    cout << fixed << ans << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
