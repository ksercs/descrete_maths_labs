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

const int MAXN = 2*20 + 5;

string sq;
LL ans, len;

LL dp[MAXN][MAXN];

void make_DP()
{
    dp[0][0] = 1;
    for (int i = 1; i <= len; ++i)
        for (int j = 0; j <= len; ++j)
            dp[i][j] = dp[i-1][j-1] + dp[i-1][j+1];
}

void in()
{
    ifstream cin("brackets2num.in");
    cin >> sq;
}

void solution()
{
    len = (LL)sq.SZ;
    make_DP();
    int bal = 0;
    for (int i = 0; i < len; ++i) {
      if (sq[i] == '(')
        ++bal;
      else {
        ans += dp[len-i-1][bal+1];
        --bal;
      }
    }
}

void out()
{
    ofstream cout("brackets2num.out");
    cout << ans << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
