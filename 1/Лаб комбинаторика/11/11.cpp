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
VEC <deque <int> >  ans;

void subset (int fl, deque <int>& sel_set, deque <int>& un_set)
{
    if (!sel_set.empty() && fl)
        ans.PB(sel_set);
    if (un_set.empty())
        return;
    int ch = un_set.front();
    sel_set.PB(ch);
    un_set.pop_front();
    subset(1, sel_set, un_set);
    sel_set.pop_back();
    subset(0, sel_set, un_set);
    un_set.push_front(ch);
}

void in()
{
    ifstream cin("subsets.in");
    cin >> n;
}

void solution()
{
    deque <int> sel_set, un_set;
    for (int i = 1; i <= n; ++i)
        un_set.PB(i);
    subset(1, sel_set, un_set);
}

void out()
{
    ofstream cout("subsets.out");
    cout << "\n";
    for (int i = 0; i < ans.SZ; ++i) {
        while (!ans[i].empty()){
            cout << ans[i].front() << " ";
            ans[i].pop_front();
        }
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
