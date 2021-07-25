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
#include <stack>

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

LL n, k, len, ans, bal1, bal2;
string s;
LL dp[MAXN][MAXN];
stack <char> last;

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
}

void in()
{
    ifstream cin("brackets2num2.in");
    cin >> s;
}

void solution()
{
    len = (LL)s.SZ;
    n = len/2;
    make_DP();
    char arr[] = {'(', ')', '[', ']'};
    for (int i = 0; i < len; ++i){
        for (int j = 0; j < 3; ++j){
            if (arr[j] == s[i])
                break;
            if (arr[j] == '('){
                if (bal1+bal2+i+1 < len)
                    ans += dp[len-i-1][bal1+bal2+1]*(1<<((len-i-1-bal1-bal2-1)/2));
            }
            else if (arr[j] == ')'){
                if (!last.empty() && last.top() == '(' && bal1)
                        ans += dp[len-i-1][bal1+bal2-1]*(1<<((len-i-1-bal1-bal2+1)/2));
            }
            else if (bal1+bal2+1+i < len)
                ans += dp[len-i-1][bal1+bal2+1]*(1<<((len-i-1-bal1-bal2-1)/2));
        }
        if (s[i] == '('){
            ++bal1;
            last.push(s[i]);
        }
        else if (s[i] == ')'){
            --bal1;
            last.pop();
        }
        else if (s[i] == '['){
            ++bal2;
            last.push(s[i]);
        }
        else {
            --bal2;
            last.pop();
        }
        //ans += dp[len-i-1][op-cl]*(1<<((len-i-1-op+cl)/2));
    }
}

void out()
{
    ofstream cout("brackets2num2.out");
    cout << ans << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
