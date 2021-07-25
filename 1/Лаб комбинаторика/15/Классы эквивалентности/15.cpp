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

const int MAXN = 30+5;

LL n, k, m;
VEC <LL> ans;

long long fac[] = {0, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800, 39916800, 479001600, 6227020800, 87178291200, 1307674368000, 20922789888000, 355687428096000, 6402373705728000};
LL dp[MAXN][MAXN];

LL get_C(LL n, LL k)
{
    if (dp[n][k])
        return dp[n][k];
    if (!k || k == n)
        return dp[n][k] = 1;
    else
        return dp[n][k] = get_C(n-1,k-1)+get_C(n-1,k);
}

void in()
{
    ifstream cin("num2choose.in");
    cin >> n >> k >> m;
}

void solution()
{
    ++m;
    long long st = 1;
    for (int i = 1; i <= k; ++i)
        for (int j = st; j <= n; j++) {
            LL c = get_C(n - j, k - i);
            if (m <= c){
                ans.PB(j);
                st = j+1;
                break;
            }
            else
                m -= c;
        }
}

void out()
{
    ofstream cout("num2choose.out");
    for (int i = 0; i < ans.SZ-1; ++i)
        cout << ans[i] << " ";
    cout << ans.back() << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
