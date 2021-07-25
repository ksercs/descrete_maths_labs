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
#define EDGE pair<int, pair <int, int>>

using namespace std;

const int COL_CNT = 100 + 15, MAX_N = 100 + 15, MAX_M = 5000 + 15;

int n, m;
EDGE ed[MAX_M];
int p[MAX_N], rang[MAX_N];
bool u_col[COL_CNT], isOk[MAX_M];
VEC <VEC <int>> gr;
set <int> ans;
VEC <int> one, two;

int findDsu(int v) {
    if (v == p[v]) {
        return v;
    }

    return p[v] = findDsu(p[v]);
}

void unionDsu(int v1, int v2) {
    v1 = findDsu(v1);
    v2 = findDsu(v2);
    if (v1 == v2) {
        return;
    }
    if (rang[v1] > rang[v2]) {
        swap(v1,v2);
    }
    p[v1] = v2;
    if (rang[v1] == rang[v2]) {
        ++rang[v2];
    }
}

void inizDsu() {
    for (int i = 0; i <= n; ++i) {
        p[i] = i;
    }
}

void inizShares() {
    one.clear();
    two.clear();
    for (int i = 0; i < COL_CNT; ++i) {
        u_col[i] = 0;
    }

    for (int i = 1; i <= m; ++i) {
        if (ans.count(i)) {
            u_col[ed[i].FF] = 1;
            one.PB(i);
        } else {
            two.PB(i);
        }
    }
//    cout << "one : ";
//    for (auto it : one) {
//        cout << it << " ";
//    }
//    cout << "\ntwo : ";
//    for (auto it : two) {
//        cout << it << " ";
//    }
//    cout << "\n : ";
}

void inizGraph() {
    gr.clear();
    gr.resize(m + 1);
    for (int i = 1; i <= m; ++i) {
        isOk[i] = 0;
    }

    for (auto & cur : two) {
        int cur_col = ed[cur].FF;
        int fl = 0;
        if (!u_col[cur_col]) {
            gr[0].PB(cur);
            fl = 1;
        }
        for (auto & cur_2 : one) {
            if (fl || ed[cur_2].FF == cur_col) {
                gr[cur_2].PB(cur);
            }
        }
    }
//    for (int i = 0; i <= m; ++i) {
//        cout << i << " : ";
//        for (auto it : gr[i]) {
//            cout << it << " ";
//        }
//        cout << "\n";
//    }
}

bool BFS() {
    VEC <bool> u(m + 1, 0);
    VEC <int> way(m + 1, 0), path;
    queue <int> q;
    q.push(0);
    u[0] = 1;
    int last = 0;
    bool fl = 0;

    while (!q.empty()) {
        int v = q.front();
//        cout << "st : " << v << "\n";
        for (auto & to : gr[v]) {
            if (!u[to]) {
//                cout << v << " ----> " << to << "\n";
                u[to] = 1;
                q.push(to);
                way[to] = v;
            }
            if (isOk[to]) {
                last = to;
                fl = 1;
                break;
            }
        }
        q.pop();

        if (fl) {
            break;
        }
    }

    bool emp = 1;
    while (last) {
        emp = 0;
        if (!ans.count(last)) {
            ans.insert(last);
        } else {
            ans.erase(last);
        }
        last = way[last];
    }

    return !emp;
 }

void in()
{
    ifstream cin("rainbow.in");
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> ed[i].SS.FF >> ed[i].SS.SS >> ed[i].FF;
    }
//    for (int i = 1; i <= m; ++i) {
//        cout << ed[i].SS.FF << " " << ed[i].SS.SS << " --- " << ed[i].FF << "\n";
//    }
}

void solution()
{
    if (m == 0) {
        return;
    }
    ans.insert(1);
    do {
        inizShares();
        inizGraph();

        for (auto & cur : one) {
            inizDsu();
//            cout "cur : " << cur << "\n";
            for (auto & fir : one) {
                if (fir == cur) {
                    continue;
                }
                unionDsu(ed[fir].SS.FF, ed[fir].SS.SS);
//              cout << "union : " << ed[fir].SS.FF << " " << ed[fir].SS.SS << "\n";
            }
            for (auto & cur_2 : two) {
                if (findDsu(ed[cur_2].SS.FF) == findDsu(ed[cur_2].SS.SS)) {
                    continue;
                }
                gr[cur_2].PB(cur);
//                cout << "CUR_2 : " << cur_2 << "\n";
            }
            unionDsu(ed[cur].SS.FF, ed[cur].SS.SS);
            for (auto & cur_2 : two) {
                if (findDsu(ed[cur_2].SS.FF) == findDsu(ed[cur_2].SS.SS)) {
                    continue;
                }
                isOk[cur_2] = 1;
//                cout << "CUR_2 : " << cur_2 << "\n";
            }
        }
    } while (BFS());
}

void out()
{
    ofstream cout("rainbow.out");
    cout << ans.SZ << "\n";
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
