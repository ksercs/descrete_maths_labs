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

const int MAXN = 2000 + 15;

int n;
VEC <string> x;
VEC <int> last;
int dp[MAXN][MAXN];

void in()
{
    //ifstream cin("F.in");
    cin >> n;
    x.resize(1<<n);
    for (int i = 0; i < (1<<n); ++i){
        cin >> x[i];
        cin >> dp[1][i];
    }
}

void solution()
{
    int L = 0, R = (1<<n);
    int ind = 2;
    last.PB(dp[1][0]);
    while (R != L){
        int i;
        for (i = 0; i < R-1; ++i){
            dp[ind][i] = (dp[ind-1][i]^(dp[ind-1][i+1]));
        }
        last.PB(dp[ind][0]);
        --R;
        ++ind;
    }
    --ind;
}

void out()
{
    //ofstream cout("F.out");
    for (int i = 0; i < (1<<n); ++i){
        cout << x[i] << " " << last[i] << "\n";
    }
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
