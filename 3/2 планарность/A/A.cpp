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
#define PII pair <int, int>
#define PDD pair <double, double>
#define LL long long

using namespace std;

const int MAX_M = (int)1e4 + 15, MAX_N = 100 + 15;

int n, m, min_edge, backup;
bool isAns = 1;
bool isAdded[MAX_M];
int var_cnt[MAX_M], up_border[MAX_M], down_border[MAX_M];
int x[MAX_N];
VEC <PII> gr;
VEC <VEC <int> > borders;
VEC <PDD> edge_mid;

void in()
{
    ifstream cin("A.in");
    cin >> n >> m;
    borders.resize(2);
    gr.resize(m);
    edge_mid.resize(m);
    for (int i = 0; i < m; ++i) {
        cin >> gr[i].FF >> gr[i].SS;
    }
    for (int i = 0; i < n; ++i) {
        borders[0].PB(i + 1);
        borders[1].PB(i + 1);
        int a;
        cin >> a;
        x[a] = i;
    }
}

void iniz() {
    fill(var_cnt, var_cnt + m + 2, 2);
    fill(down_border, down_border + m + 2, 1);
}

void get_edges_for_gam() {
    int fl = 0;
    for (int i = 0; i < m; ++i) {
        int a = gr[i].FF,
            b = gr[i].SS;
        int dx = abs(x[a] - x[b]);
        if (dx == 1 || dx == n - 1) {
            isAdded[i] = 1;
            var_cnt[i] = 3;
            edge_mid[i] = {(x[a] + x[b]) / 2.0, 0};
            if (dx == n - 1) {
                edge_mid[i].SS = edge_mid[i].FF;
            }
        } else if (!fl) {
            fl = 1;
            min_edge = i;
        }
    }
}

void try_add_edge(int a, int b) {
    int ind = (up_border[min_edge] == -1) ? down_border[min_edge] : up_border[min_edge];
    if (x[a] > x[b]) {
        swap(a, b);
    }

    edge_mid[min_edge].FF = (x[a] + x[b]) / 2.0;
    edge_mid[min_edge].SS = ((x[b] - x[a]) / 2.0) * ((up_border[min_edge] == -1) ? -1 : 1);
//      cout << min_edge << " : " << edge_mid[min_edge].FF << " " << edge_mid[min_edge].SS << "\n";
    isAdded[min_edge] = 1;
    var_cnt[min_edge] = 3;

    borders.resize(borders.SZ + 1);
//      cout << a << " " << b << "\n";
    for (int i = 0; i < borders[ind].SZ; ++i) {
        if (x[a] <= x[borders[ind][i]] && x[borders[ind][i]] <= x[b]) {
            borders.back().PB(borders[ind][i]);
            if (x[borders[ind][i]] != x[a] && x[borders[ind][i]] != x[b]) {
//                  cout << "---> " << x[borders[ind][i]] << "\n";
                borders[ind].erase(borders[ind].begin() + i);
                --i;
            }
        }
    }
//      for (auto it : borders.back()) {
//            cout << it << " ";
//      }
//      cout << "\n";
//    cout << ((var_cnt[min_edge] == 1) ? "DOWN\n" : "UP\n");
    int * border_ind = (up_border[min_edge] == -1) ? down_border : up_border;
    for (int i = 0; i < m; ++i) {
        int v = gr[i].FF,
            u = gr[i].SS;
//        cout << "ADD : " << i << " : " << isAdded[i] << "\n";
        if (isAdded[i]) {
            continue;
        }
//        cout << "--> " << i << "\n";
        if ( *(border_ind + i) == ind) {
            int cur = (find(borders.back().begin(), borders.back().end(), v) != borders.back().end()) + (find(borders.back().begin(), borders.back().end(), u) != borders.back().end());
            int last = (find(borders[ind].begin(), borders[ind].end(), v) != borders[ind].end()) + (find(borders[ind].begin(), borders[ind].end(), u) != borders[ind].end());
            if (cur == 2) {
                *(border_ind + i) = borders.SZ - 1;
//                cout << "first\n";
//                cout << down_border[i] << "\n";
            }
            else if (last != 2) {
                *(border_ind + i) = -1;
//                cout << "HERE " << backup << " : " << i << "\n";
                --var_cnt[i];
            }
        }
        if (var_cnt[min_edge] > var_cnt[i]) {
            min_edge = i;
        }
    }
}

void solution()
{
    iniz();
    get_edges_for_gam();

    for (int t = n; t < m; ++t) {
        backup = min_edge;
        try_add_edge(gr[min_edge].FF, gr[min_edge].SS);
//        cout << t << " : " << backup << " | " << edge_mid[backup].FF << " " << edge_mid[backup].SS << "\n";
//        cout << "CHECK "  << min_edge << " : " << var_cnt[min_edge] << "\n";
        if (!var_cnt[min_edge]) {
//            cout << t << " : " << min_edge << " BAD END !\n\n";
            isAns = 0;
            break;
        }
    }
}

void out()
{
    ofstream cout("A.out");
    if (!isAns) {
        cout << "NO\n";
        return;
    }
    cout << "YES" << "\n";
    cout.precision(20);
    cout << fixed;
    for (int i = 1; i <= n; ++i) {
        cout << x[i] << " 0 ";
    }
    cout << "\n";
    for (int i = 0; i < m; ++i) {
        cout << edge_mid[i].FF << " " << edge_mid[i].SS << "\n";
    }
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
