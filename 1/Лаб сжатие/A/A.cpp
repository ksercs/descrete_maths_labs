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
#define PII pair <LL, LL>
#define LL long long

using namespace std;

const int MAXN = (int)1e6;

int n, ind;
LL ans;
set <PII> st;
VEC <LL> v;
int p[MAXN];

void in()
{
    ifstream cin("huffman.in");
    cin >> n;
    v.resize(n+1);
    for (int i = 1; i <= n; ++i){
        int a;
        cin >> a;
        v[i] = a;
        st.insert(MP(a,i));
    }
}

int getAns (int i)
{
    if (!p[i])
        return 0;
    else
        return getAns(p[i])+1;
}

void solution()
{
    ind = n+1;
    while (st.SZ != 1){
        PII p1, p2;
        p1 = (*st.begin());
        st.erase(st.begin());
        p2 = (*st.begin());
        st.erase(st.begin());
        LL sum = p1.FF+p2.FF;
        p[p1.SS] = ind;
        p[p2.SS] = ind;
        st.insert(MP(sum, ind++));
    }
    for (int i = 1; i <= n; ++i){
        ans += getAns(i)*v[i];
    }
}

void out()
{
    ofstream cout("huffman.out");
    cout << ans << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
