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

long long n, k;

long long fac[] = {0, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800, 39916800, 479001600, 6227020800, 87178291200, 1307674368000, 20922789888000, 355687428096000, 6402373705728000, 121645100408832000};

vector <int> el;
VEC <int> ans;

void ekv_R(LL m, LL r)
{
    if (!m)
        return;
    //cout << m << " " << r << "\n";
    LL pr, ost;
    pr = r / fac[m];
    ost = r % fac[m];
    if (!ost)
    {
        ans.PB(el[pr-1]);
        el.erase(el.begin()+pr-1);
        for (int i = el.SZ-1; i >= 0; i--)
            ans.PB(el[i]);
    }
    else
    {
        ans.PB(el[pr]);
        el.erase(el.begin()+pr);
        ekv_R(m-1, ost);
    }
}

void in()
{
    ifstream cin ("num2perm.in");
    cin >> n >> k;
}

void solution()
{
    ++k;
  for (int i = 1; i <= n; i++)
  {
      el.push_back(i);
  }
  ekv_R(n-1, k);
}

void out()
{
     ofstream cout ("num2perm.out");
     if (ans.empty()){
        cout << 1 << "\n";
        return;
     }
     for (int i = 0; i < ans.size()-1; ++i)
        cout << ans[i] << " ";
     cout <<ans.back() << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
