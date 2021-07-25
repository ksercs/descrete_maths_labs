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

string s;
int n, sum, fl;
VEC <int> v;

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

void NextPart()
{
    int sz = (int)v.SZ;
    ++v[sz-2];
    --v[sz-1];
    if (v[sz-2] > v[sz-1]) {
        v[sz-2] += v[sz-1];
        v.erase(--v.end());
    }
    else {
        while (v[sz-2]*2 <= v[sz-1]){
            v.PB(v[sz-1]-v[sz-2]);
            ++sz;
            v[sz-2] = v[sz-3];
        }
    }
}

void in()
{
    ifstream cin("nextpartition.in");
    cin >> s;
}

void solution()
{
    n = (int)s.SZ;
    int ind = 0, p = 0;
    while (ind < n){
        while (ind < n && s[ind] != '+' && s[ind] != '=')
            ++ind;
        v.PB(StrToInt(s.substr(p, ind-p)));
        ++ind;
        p = ind;
    }
    sum = v[0];
    v.erase(v.begin());
    /*for (int i = 0; i < v.SZ; ++i)
        cout << v[i] << " " ;*/
    if (v.SZ > 1) NextPart();
    else fl = 1;
}

void out()
{
    ofstream cout("nextpartition.out");
    if (fl){
        cout << "No solution\n";
        return;
    }
    cout << sum << "=" << v[0];
    for (int i = 1; i < v.SZ; ++i)
        cout << "+" <<v[i];
    cout << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
