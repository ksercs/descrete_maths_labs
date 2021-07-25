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

const int MAX_N = 50000 + 15, MAX_M = 100000 + 15;

struct Edge {
    int id;
    int v;
    int u;
    LL w;

    Edge() {}
    Edge(int _id, int _v, int _u, LL _w) : id(_id), v(_v), u(_u), w(_w) {}
};

int n, m;
LL maxW;
VEC <Edge> edges;
int dsu[MAX_N], isInTree[MAX_M];
VEC <int> ans;

bool comp(Edge const & a, Edge const & b) {
    return a.w < b.w;
}

int getDsu(int a) {
    if (dsu[a] == a) {
        return a;
    }
    return dsu[a] = getDsu(dsu[a]);
}

void unionDsu(int a, int b) {
    int A = getDsu(a);
    int B = getDsu(b);
    if (A == B) {
        return;
    }

    dsu[A] = dsu[B];
}

void in()
{
    ifstream cin("destroy.in");
    cin >> n >> m >> maxW;
    edges.resize(m);
    for (int i = 0; i < m; ++i) {
        cin >> edges[i].v >> edges[i].u >> edges[i].w;
        edges[i].id = i;
    }
}

void solution()
{
    sort(edges.begin(), edges.end(), comp);

    for (int i = 1; i <= n; ++i) {
        dsu[i] = i;
    }

    for (int i = m - 1; i >= 0; --i) {
        if (getDsu(edges[i].v) != getDsu(edges[i].u)) {
            unionDsu(edges[i].v, edges[i].u);
            isInTree[i] = 1;
        }
    }

    for (int i = 0; i < m; ++i) {
        if (!isInTree[i] && maxW >= edges[i].w) {
            ans.PB(edges[i].id);
            maxW -= edges[i].w;
        }
    }
}

void out()
{
    ofstream cout("destroy.out");
    cout << ans.SZ << "\n";
    for (auto it : ans) {
        cout << it + 1 << " ";
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
