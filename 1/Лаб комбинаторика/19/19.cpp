#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <iomanip>
#include <stack>
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

LL n, k, len, cl, op;
LL dp[MAXN][MAXN];
string ans;
stack <char> last;

int tryOpen_1(int i)
{
    LL num = 0;
    if (op-cl < n)
        num = dp[i][op-cl+1]*(1<<((i-op+cl-1)/2));
    if (num < k){
        k -= num;
        return 0;
    }
    ans += '(';
    last.push('(');
    ++op;
    return 1;
}

int tryClose_1 (int i)
{
    LL num = 0;
    if (last.empty() || last.top() != '(')
            ;
    else
        num = dp[i][op-cl-1]*(1<<((i-op+cl+1)/2));
    if (num < k){
        k -= num;
        return 0;
    }
    ans += ')';
    ++cl;
    last.pop();
    return 1;
}

int tryOpen_2(int i)
{
    LL num = 0;
    if (op-cl < n)
        num = dp[i][op-cl+1]*(1<<((i-op+cl-1)/2));
    if (num < k){
        k -= num;
        return 0;
    }
    ans += '[';
    last.push('[');
    ++op;
    return 1;
}


void make_DP()
{
    dp[0][0] = 1;
    for (int i = 0; i < len; ++i)
        for (int j = 0; j <= n; ++j){
            if (!i && !j)
                continue;
            if (j)
                dp[i][j] = dp[i-1][j-1];
            dp[i][j] += dp[i-1][j+1];
        }
    /*for (int i = 0; i < len; ++i){
        for (int j = 0; j <= n; ++j){
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }*/
}


void in()
{
    ifstream cin("num2brackets2.in");
    cin >> n >> k;
}

void solution()
{
    ++k;
    len = 2*n;
    make_DP();
    for (int i = len-1; i >= 0; --i) {
        //cout << ans << "\n";
        if (tryOpen_1(i))
            continue;
        if (tryClose_1(i))
            continue;
        if (tryOpen_2(i))
            continue;
        ans += ']';
        ++cl;
        last.pop();
    }
}

void out()
{
    ofstream cout("num2brackets2.out");
    cout << ans << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
