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
#define PIC pair<int,char>
#define PCC pair<char,char>

#define IN_NAME "minimization.in"
#define OUT_NAME "minimization.out"

using namespace std;

const int MAXN = 1000 + 15;
const char S_ALPHA = 'a', F_ALPHA = 'z';

int n, m, k;
int ansN, ansK;
VEC <int> ansTerm, term;
bool isTerm[MAXN], u[MAXN][MAXN], isAttainable[MAXN], ok[MAXN];
map <PIC, VEC<int> > gr, reverseGr;
map <PII, VEC<char> > edges;
//int dx[] = {1, 0, -1, 0},
//    dy[] = {0, 1, 0, -1};

void in()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ifstream cin(IN_NAME);
    cin >> n >> m >> k;
    for (int i = 0; i < k; ++i) {
        int a;
        cin >> a;
        isTerm[a] = 1;
        term.PB(a);
    }
    for (int i = 0; i < m; ++i) {
        int a, b;
        char c;
        cin >> a >> b >> c;
        gr[MP(a, c)].PB(b);
        reverseGr[MP(b, c)].PB(a);
        edges[MP(a, b)].PB(c);
    }
}

void DFS2 (int v) {
    ok[v] = 1;
    for (char c = S_ALPHA; c <= F_ALPHA; ++c) {
        for (int i = 0; i < reverseGr[MP(v, c)].SZ; ++i) {
            int to = reverseGr[MP(v, c)][i];
            if (!ok[to]) {
                DFS2(to);
            }
        }
    }
}

/*void DFS (int i, int j, string &s) {
    u[i][j] = 1;
    s[i] = '1';
    s[j] = '1';
    for (int g = 0; g < 4; ++g) {
        int x = i + dx[g],
            y = j + dy[g];
        if (x && y && x <= n && y <= n && !u[x][y]) {
            DFS(x, y, s);
        }
    }
}*/

void DFS (int v) {
    //cout << "DFS : " << v << "\n";
    isAttainable[v] = 1;
    for (char c = S_ALPHA; c <= F_ALPHA; ++c) {
        for (int i = 0; i < gr[MP(v, c)].SZ; ++i) {
            int to = gr[MP(v, c)][i];
            //cout << "->> " << to << "\n";
            if (!isAttainable[to]) {
                DFS(to);
            }
        }
    }
}

struct triple {
    int a;
    int b;
    char c;

    triple (int a_, int b_, char c_) {
        a = a_;
        b = b_;
        c = c_;
    }
};

VEC <triple> aut;

void solution()
{
    for (int i = 0; i < term.SZ; ++i) {
        if (!ok[term[i]]) {
            DFS2(term[i]);
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (char c = S_ALPHA; c <= F_ALPHA; ++c) {
            gr[MP(i, c)].PB(0);
            //gr[MP(0, c)].PB(i);
            //reverseGr[MP(0, c)].PB(i);
            //reverseGr[MP(i, c)].PB(0);
        }
    }
    queue <PII> q;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (!u[i][j] && isTerm[i] != isTerm[j]) {
                //cout << "NEW : " << i << " " << j << "\n";
                u[i][j] = 1;
                u[j][i] = 1;
                q.push(MP(i, j));
            }
        }
    }

    while (!q.empty()) {
        int x = q.front().FF,
            y = q.front().SS;
        //cout << "X Y : " << x << " " << y << "\n";
        q.pop();
        for (char c = S_ALPHA; c <= F_ALPHA; ++c) {
            for (int i = 0; i < reverseGr[MP(x, c)].SZ; ++i) {
                for (int j = 0; j < reverseGr[MP(y, c)].SZ; ++j) {
                    int newX = reverseGr[MP(x, c)][i],
                        newY = reverseGr[MP(y, c)][j];
                    if (!u[newX][newY]) {
                        //cout << "TO : " << x << " " << y << " -> " << newX << " " << newY << "\n";
                        u[newX][newY] = 1;
                        u[newY][newX] = 1;
                        q.push(MP(newX, newY));
                    }
                }
            }
        }
    }
    /*for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (!u[i][j])
                cout << i << " " << j << "\n";
        }
    }*/


    DFS(1);
    VEC <string> comp;
    /*for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (!u[i][j]) {
                string s(n + 1, '0');
                DFS(i, j, s);
                comp.PB(s);
                //cout << s << "\n";
            }
        }
    }*/
    VEC <int> component(n+1, -1);
    /*for (int i = 1; i <= n; ++i) {
        if (!u[0][i] ){//&& isAttainable[i]) {
            component[i] = 0;
        }
    }*/
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        if (!isAttainable[i] || !ok[i])
            continue;
        //cout << "I : " << i << "\n";
        if (component[i] == -1) {
            cnt++;
            component[i] = cnt;
            for (int j = i + 1; j <= n; ++j) {
                if (!u[i][j] && isAttainable[j] && ok[j]) {
                    component[j] = cnt;
                }
            }
        }
    }
    /*for (int i = 1; i <= n; ++i) {
        cout << component[i] << " ";
    }*/
    for (int color = 1; color <= cnt; ++color) {
        string s(n + 1, '0');
        for (int j = 1; j <= n; ++j) {
            if (component[j] == color) {
                s[j] = '1';
            }
        }
        comp.PB(s);
    }
    ansN = comp.SZ;

    bool isAnsTerm[MAXN];
    for (int i = 0; i < comp.SZ; ++i) {
        string s = comp[i];
        set <char> st;
        for (int c = 1; c < s.SZ; ++c) {
            if (s[c] == '1') {
                if (isTerm[c] && !isAnsTerm[i + 1]) {
                    ansTerm.PB(i + 1);
                    isAnsTerm[i + 1] = 1;
                }
                for (int j = 0; j < comp.SZ; ++j) {
                    string s2 = comp[j];
                    for (int c2 = 1; c2 < s2.SZ; ++c2) {
                        if (s2[c2] == '1') {
                            while (edges[MP(c, c2)].SZ) {
                                //cout << "CHECK : " << i + 1 << " " << j + 1 << " " << edges[MP(c, c2)][0] << " (" <<edges[MP(c, c2)].SZ << ")\n";
                                if (!st.count(edges[MP(c, c2)][0])) {
                                    aut.PB(triple(i + 1, j + 1, edges[MP(c, c2)][0]));
                                    //cout << i + 1 << " " << j + 1 << " " << edges[MP(c, c2)][0] << "\n";
                                    st.insert(edges[MP(c, c2)][0]);
                                    //cout << "INSERT : " << st.SZ << "\n";
                                }
                                edges[MP(c, c2)].erase(edges[MP(c, c2)].begin());
                            }
                        }
                    }
                }
            }
        }
    }
    ansK = ansTerm.SZ;
}

void out()
{
    cout.tie(0);
    ofstream cout(OUT_NAME);
    cout << ansN << " " << aut.SZ << " " << ansK << "\n";
    for (int i = 0; i < ansK; ++i) {
        cout << ansTerm[i] << " ";
    }
    cout << "\n";
    for (int i = 0; i < aut.SZ; ++i) {
        cout << aut[i].a << " " << aut[i].b << " " << aut[i].c << "\n";
    }
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
