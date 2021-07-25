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

string s;
int n;
LL ans;
VEC <int> v;
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
    }
    cout << "\n";*/
}

int StrToInt(string s)
{
    int res = 0;
    int st = 1;
    for (int i = s.SZ-1; i >= 0; --i){
        res += int(s[i]-'0')*st;
        st *= 10;
    }
    return res;
}

void in()
{
    ifstream cin("part2num.in");
    cin >> s;
}

void solution()
{
    int ind = 0, p = 0;
    while (ind < s.SZ){
        while (ind < s.SZ && s[ind] != '+')
            ++ind;
        v.PB(StrToInt(s.substr(p, ind-p)));
        n += v.back();
        ++ind;
        p = ind;
    }
    make_DP();
    int num = n,
        last = 0;
    for (int t = 0; t < v.SZ; ++t){
        if (num <= 0)
            return;
        for (int i = last; i < v[t]; ++i){
            //cout << num << " " << i << " : " << dp[num][i] << "\n";
            cout << num << " " << i << " " << dp[num][i] << "\n";
            ans += dp[num][i];
        }
        num -= v[t];
        last = v[t];
    }
}

void out()
{
    ofstream cout("part2num.out");
    cout << ans << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
