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

const int MAXN = 100;

int n;
VEC <string> ans;
VEC <int> v;

string makeS (int a)
{
    string s = "";
    if (a > 9) {
        s += char(a/10+'0');
        s += char(a%10+'0');
    }
    else
        s += (a%10+'0');
    return s;
}

void getAns(int cur)
{
    if(!cur){
        string s = "";
        s += makeS(v[0]);
        for (int i = 1; i < v.SZ; ++i)
            s += '+' + makeS(v[i]);
        ans.PB(s);
    }
    int i;
    if (v.size() == 0)
        i = 1;
    else
        i = v.back();
    for(; i <= cur; ++i)
    {
        v.PB(i);
        getAns(cur - i);
        v.pop_back();
    }
}

void in()
{
    ifstream cin("partition.in");
    cin >> n;
}

void solution()
{
    getAns(n);
}

void out()
{
    ofstream cout("partition.out");
    for (int i = 0; i < ans.SZ; ++i)
        cout << ans[i] << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
