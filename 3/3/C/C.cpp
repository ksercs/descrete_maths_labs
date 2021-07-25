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
#define PLL pair <LL,LL>

using namespace std;

const int MAX_N = 1000 + 15;

int n;
int u[MAX_N], isInPair[MAX_N];
VEC <PII> weight;
VEC <VEC <int>> gr;
VEC <int> ans;

bool tryKuhn(int v) {
    if (u[v]) {
        return 0;
    }
    u[v] = 1;

    for (auto to : gr[v]) {
        if (!isInPair[to] || tryKuhn(isInPair[to])) {
            isInPair[to] = v;
            return 1;
        }
    }

    return 0;
}

void in()
{
    ifstream cin("matching.in");
    cin >> n;
    gr.resize(n + 5);
    for (int i = 1; i <= n; ++i) {
        LL w;
        cin >> w;
        weight.PB({w, i});
    }
    for (int i = 1; i <= n; ++i) {
        int m;
        cin >> m;
        gr[i].resize(m);
        for (int j = 0; j < m; ++j) {
            cin >> gr[i][j];
        }
    }
}

void solution()
{
    sort(weight.begin(), weight.end());

    for (int i = n - 1; i >= 0; --i) {
        int vertex = weight[i].SS;
//        cout << vertex << "\n";
        int w = weight[i].FF;
        tryKuhn(vertex);
        for (int j = 1; j <= n; ++j) {
            u[j] = 0;
        }
    }

    ans.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
//        cout << isInPair[i] << " ";
        if (isInPair[i]) {
            ans[isInPair[i]] = i;
        }
    }
}

void out()
{
    ofstream cout("matching.out");
    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << " ";
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
