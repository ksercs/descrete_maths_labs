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
int u[10];

string str;

VEC <int> el;
VEC <string> ans;

void dfs_R(int ind)
{
    if (ind == n){
        ans.PB(str);
        return;
    }
    for (int i = 1; i <= n; ++i) {
        if (!u[i]) {
            u[i] = 1;
            str[ind] = i+'0';
            dfs_R(ind+1);
            u[i] = 0;
        }
    }
}

void in()
{
    ifstream cin ("permutations.in");
    cin >> n;
}

void solution()
{
    for (int i = 1; i <= n; i++) {
        el.PB(i);
        str+= ' ';
    }
    dfs_R(0);
}

void out()
{
     ofstream cout ("permutations.out");
     for (int i = 0; i < ans.SZ; ++i) {
         for (int j = 0; j < ans[i].SZ; ++j)
            cout << ans[i][j] << " ";
         cout << "\n";
     }
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
