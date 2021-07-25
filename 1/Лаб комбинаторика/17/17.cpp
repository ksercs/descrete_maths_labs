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

const int MAXN = 40 + 5;

LL n, k, len;

string ans;
LL dp[MAXN][MAXN];

void make_DP()
{
    dp[0][0] = 1;
    for (int i = 1; i <= len; ++i)
        for (int j = 0; j <= 2*n; ++j)
            dp[i][j] = dp[i-1][j-1] + dp[i-1][j+1];
}

void in()
{
    ifstream cin("num2brackets.in");
    cin >> n >> k;
}

void solution()
{
    ++k;
    len = 2*n;
    make_DP();
    int bal = 0;
    for (int i = 0; i < len; ++i){
        LL val = dp[len-i-1][bal+1];
        if (dp[len-i-1][bal+1] >= k){
            ans += '(';
            ++bal;
        }
        else {
            k -= val;
            ans += ')';
            --bal;
        }
    }
}

void out()
{
    ofstream cout("num2brackets.out");
    cout << ans << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
