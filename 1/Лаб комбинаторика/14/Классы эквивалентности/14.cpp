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

int n;
LL ans;
VEC <int> el;

long long fac[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800, 39916800, 479001600, 6227020800, 87178291200, 1307674368000, 20922789888000, 355687428096000, 6402373705728000};

void ekv(int k, int ind)
{
    LL s = el[ind];
    ans += 1LL*((s-1)*fac[k-1]);
    k--;
    for (int i = ind+1; i < n; i++)
    {
        if (el[i] > s)
            --el[i];
    }
    if (k > 0)
        ekv(k, ind+1);
}

void in()
{
    ifstream cin ("perm2num.in");
    cin >> n;
    el.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> el[i];
}

void solution()
{
    ekv(n, 0);
}

void out()
{
     ofstream cout ("perm2num.out");
     cout << ans << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
