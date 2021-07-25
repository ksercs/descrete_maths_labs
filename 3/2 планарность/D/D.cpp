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

const string ANS[] = {"NO\n", "YES\n"};
const int MAX_M = 30, MAX_N = 9;

int t;
VEC <int> ans;
map <int, int> n_map;

int n, m, min_edge;
bool isAdded[MAX_M];
int var_cnt[MAX_M], up_border[MAX_M], down_border[MAX_M];
int x[MAX_N];
VEC <PII> gr;
VEC <VEC <int> > borders;

void inizA(VEC <int> & gam) {
    min_edge = 0;
    fill(var_cnt, var_cnt + m + 2, 2);
    fill(down_border, down_border + m + 2, 1);
    fill(up_border, up_border + m + 2, 0);
    fill(isAdded, isAdded + m + 2, 0);
    borders.clear();
    borders.resize(2);
    for (int i = 0; i < n; ++i) {
		borders[0].PB(i + 1);
		borders[1].PB(i + 1);
        x[gam[i]] = i;
	}
}


void try_add_edge(int a, int b) {
    int ind = (up_border[min_edge] == -1) ? down_border[min_edge] : up_border[min_edge];
    if (x[a] > x[b]) {
        swap(a, b);
    }

//		cout << min_edge << " : " << edge_mid[min_edge].FF << " " << edge_mid[min_edge].SS << "\n";
    isAdded[min_edge] = 1;
    var_cnt[min_edge] = 3;

    borders.resize(borders.SZ + 1);
//		cout << a << " " << b << "\n";
    for (int i = 0; i < borders[ind].SZ; ++i) {
        if (x[a] <= x[borders[ind][i]] && x[borders[ind][i]] <= x[b]) {
            borders.back().PB(borders[ind][i]);
            if (x[borders[ind][i]] != x[a] && x[borders[ind][i]] != x[b]) {
//					cout << "---> " << x[borders[ind][i]] << "\n";
                borders[ind].erase(borders[ind].begin() + i);
                --i;
            }
        }
    }
//		for (auto it : borders.back()) {
//            cout << it << " ";
//		}
//		cout << "\n";
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

bool sol(VEC <int> & vec)
{
    inizA(vec);

    int cnt = 0;
    int fl = 0;
	for (int i = 0; i < m; ++i) {
		int a = gr[i].FF,
            b = gr[i].SS;
		int dx = abs(x[a] - x[b]);
		if (dx == 1 || dx == n - 1) {
//			cout <<  "! " << a << " " << b << "\n";
			isAdded[i] = 1;
			++cnt;
			var_cnt[i] = 3;
			//if (dx == n - 1) {
             //   edge_mid[i].SS = edge_mid[i].FF;
			//}
		} else if (!fl) {
            fl = 1;
            min_edge = i;
		}
	}
//	cout << "cnt : " << cnt << "\n";
//    if (cnt != n) {
//        return 0;
//    }

	for (int h = cnt; h < m; ++h) {
//        cout << h << " : " << min_edge << "\n";
        try_add_edge(gr[min_edge].FF, gr[min_edge].SS);
//        cout << "CHECK "  << min_edge << " : " << var_cnt[min_edge] << "\n";
        if (!var_cnt[min_edge]) {
//            cout << t << " : " << min_edge << " BAD END !\n\n";
            return 0;
        }
	}
//	cout << "\n";
	return 1;
}

int solution(string & s) {
//    cout << s << "\n";
    n = n_map[s.SZ];
//    cout << "n = " << n << "\n";
    if (n <= 4) {
        return 1;
    }

    int pos = 0;
    gr.clear();
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j < i; ++j) {
            if (s[pos++] == '1') {
//                cout << i << " " << j << "\n";
                gr.PB({i, j});
            }
        }
    }
    m = gr.SZ;

    if (n == 5) {
        bool fl = 0;
        for (int i = 0; i < s.SZ; ++i) {
            if (s[i] == '0') {
                fl = 1;
                break;
            }
        }
        return fl;
    }

    if (m < (n / 2) * (n / 2) ) {
        return 1;
    }
    VEC<int> gam;
    for (int i = 1; i <= 6; ++i) {
        gam.PB(i);
    }

    bool res = 0;
    for (int i = 0; i < 720; ++i) {
        res = (res || sol(gam));
        if (res) {
//            for (auto it : gam) {
//                cout << it << " ";
//            }
//            cout << "\n";
            break;
        }
        next_permutation(gam.begin(), gam.end());
//        cout << "\n";
    }
    return res;
}

void iniz() {
    n_map[0] = 0;
    n_map[1] = 2;
    n_map[3] = 3;
    n_map[6] = 4;
    n_map[10] = 5;
    n_map[15] = 6;
}

void in()
{
    ifstream cin("planaritycheck.in");
    cin >> t;
    ans.resize(t);
    iniz();
    string s;
    getline(cin, s);
    for (int i = 0; i < t; ++i) {
        getline(cin, s);
        ans[i] = solution(s);
    }
}

void out()
{
    ofstream cout("planaritycheck.out");
    for (auto it : ans) {
        cout << ANS[it];
    }
}

int main()
{
    in();
    out();
    return 0;
}
