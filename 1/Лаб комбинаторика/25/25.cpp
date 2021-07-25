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

int n, k, ind = -1;
VEC <int> el, ans;

void in()
{
    ifstream cin("nextchoose.in");
    cin >> n >> k;
    el.resize(k);
    for (int i = 0; i < k; ++i)
        cin >> el[i];
}

void solution()
{
    ans = el;
    ans.PB(n+1);
    for (int i = k-1; i >= 0; --i){
        if (ans[i]+2 <= ans[i+1]){
            ind = i;
            break;
        }
    }
    if (ind == -1){
        return;
    }
    set <int> st;
    for (int i = 0; i < ans.SZ; ++i)
        st.insert(ans[i]);
    int fl = 0;
    for (int i = n; i >= n-k; --i)
        if (!st.empty() && !st.count(i))
            fl = 1;
    if (!fl){
        ind = -1;
        return;
    }
    st.clear();
    ans[ind]++;
    for (int i = ind+1; i < k; ++i){
        ans[i] = ans[i-1]+1;
    }
}

void out()
{
    ofstream cout("nextchoose.out");
    if (ind == -1){
        cout << ind << "\n";
        return;
    }
    for (int i = 0; i < k; ++i)
        cout << ans[i] << " ";
    cout << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
