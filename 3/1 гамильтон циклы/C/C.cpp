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

const int MAXN = 1000 + 15;

int n;
int gr[MAXN][MAXN];
map <PII, bool> mp;

void in()
{
    cin >> n;
}

//struct comp {
    bool comp(const int& a, const int& b) {
        auto it = mp.find({a, b});
        if (it != mp.end()) {
            return mp[{a, b}];
        }
        cout << "1 " << a << " " << b << "\n";
        string res;
        cin >> res;
        bool fl = (res == "YES");
        mp[{a, b}] = fl;
        mp[{b, a}] = !fl;
        return fl;
    }
//};

deque <int> ans;

void solution()
{
    ans.push_back(1);
    for (int i = 2; i <= n; ++i) {
        auto ind = lower_bound(ans.begin(), ans.end(), i, comp);
        ans.insert(ind, i);
        //cout << "INSERTED " << i << "\n";
    }
}

void out()
{
    cout << "0 ";
    for (auto it : ans) {
        cout << it << " ";
    }
    cout << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
