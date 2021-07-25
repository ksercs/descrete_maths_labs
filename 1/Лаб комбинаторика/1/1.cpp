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

string str;

VEC <string> ans;

void dfs_R(int ind)
{
    if (ind == n){
        ans.PB(str);
        return;
    }
    str[ind] = '0';
    dfs_R(ind+1);
    str[ind] = '1';
    dfs_R(ind+1);
}

void in()
{
    ifstream cin ("allvectors.in");
    cin >> n;
}

void solution()
{
    str.resize(n);
    dfs_R(0);
}

void out()
{
     ofstream cout ("allvectors.out");
     for (int i = 0; i < ans.SZ; ++i) {
         cout << ans[i] << "\n";
     }
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
