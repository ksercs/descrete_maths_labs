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

const int MAXN = 100 + 15;

LL n, k;
VEC <int> ans;
LL dp[MAXN][MAXN];

void make_DP()
{
    for (int i = 0; i <= n; ++i)
        dp[i][i] = 1;
    for (int i = 0; i <= n; ++i)
        for (int j = 1; j < i; ++j){
            for (int k = j; k <= n; ++k)
                dp[i][j] += dp[i-j][k];
        }
    /*for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j)
            cout << dp[i][j] << " ";
        cout << "\n";
    }*/
}

void in()
{
    ifstream cin("num2part.in");
    cin >> n >> k;
}

void solution()
{
    int num = n,
        ind = 0;
    make_DP();
    while (num > 0){
        LL tmp = 0;
        while (ind <= n && tmp + dp[num][ind] <= k){
            tmp += dp[num][ind];
            ++ind;
        }
        ans.PB(ind);
        num -= ind;
        k -= tmp;
    }
}

void out()
{
    ofstream cout("num2part.out");
    cout << ans[0];
    for (int i = 1; i < ans.SZ; ++i)
        cout << "+" << ans[i];
    cout << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
