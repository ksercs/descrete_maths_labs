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
#include <unordered_map>
#include <unordered_set>

#define SZ size()
#define VEC vector
#define PB push_back
#define MP make_pair
#define SS second
#define FF first
#define PII pair <int,int>
#define LL long long
#define PIC pair <char, int>

#define IN_NAME "fastminimization.in"
#define OUT_NAME "fastminimization.out"

using namespace std;

const int MAXN = 50000 + 15;
const char BEGIN_ALPHA = 'a', END_ALPHA = 'z';

int n, m, k, ansN, ansM, ansK;
VEC <VEC <VEC <int>>> reverseGr, RG;
VEC <VEC <int>> gr, ansGr;
VEC <bool> isTerm, isAssumedFromStart, isAssumedFromTerm, isAnsTerm;
set <char> alpha;

void in()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ifstream cin(IN_NAME);
    cin >> n >> m >> k;
    isTerm.resize(n + 5);
    isAssumedFromStart.resize(n + 5);
    isAssumedFromTerm.resize(n + 5);
    gr.assign(n + 5, VEC <int>(26));
    reverseGr.assign(n + 5, VEC <VEC <int>>(26, VEC <int>()));
    RG.assign(n + 5, VEC <VEC <int>>(26, VEC <int>()));
    for (int i = 0; i < k; ++i) {
        int a;
        cin >> a;
        isTerm[a] = 1;
    }
    for (int i = 0; i < m; ++i) {
        int a, b;
        char c;
        cin >> a >> b >> c;
        alpha.insert(c);
        gr[a][c-'a'] = b;
        reverseGr[b][c-'a'].PB(a);
    }
}

void DFS (int v) {
    isAssumedFromStart[v] = 1;
    for (auto c : alpha) {
        int to = gr[v][c-'a'];
        if (to) {
            if (!isAssumedFromStart[to]) {
                DFS(to);
            }
        }
    }
}

void reverseDFS (int v) {
    isAssumedFromTerm[v] = 1;
    for (auto c : alpha) {
        for (int i = 0; i < reverseGr[v][c-'a'].SZ; ++i) {
            int to = reverseGr[v][c-'a'][i];
            if (!isAssumedFromTerm[to]) {
                reverseDFS(to);
            }
        }
    }
}

void printSet (set <int> *st) {
    for (auto it : *st) {
        cout << it << " ";
    }
    cout << "\n";   //
}

void solution()
{
    DFS(1);
    for (int i = 1; i <= n; ++i) {
        if (isTerm[i] && !isAssumedFromTerm[i]) {
            reverseDFS(i);
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (!isAssumedFromTerm[i] || !isAssumedFromStart[i])
            continue;
        for (auto c : alpha) {
            int to = gr[i][c-'a'];
            if (to) {
                RG[to][c-'a'].PB(i);
            }
        }
    }

    queue < pair <set <int>, char> > q;
    VEC <int> Class(n + 5);
    VEC < set <int> > P(1);
    set <int> stTerm,
              stNotTerm;

    for (int i = 1; i <= n; ++i) {
        if (!isAssumedFromStart[i] || !isAssumedFromTerm[i]) {
            continue;
        }
        if (!isTerm[i]) {
            stNotTerm.insert(i);
            Class[i] = 2;
        } else {
            stTerm.insert(i);
            Class[i] = 1;
        }
    }
    if (!stTerm.empty()) {
        P.PB(stTerm);
    }
    if (!stNotTerm.empty()) {
        P.PB(stNotTerm);
    }
    //cout << "TERM : ", printSet(stTerm);
    //cout << "NOT TERM : ", printSet(stNotTerm);

    for (auto c : alpha) {
        if (stTerm.SZ)
            q.push(MP(stTerm, c));
        if (stNotTerm.SZ)
            q.push(MP(stNotTerm, c));
    }

//    for (auto R : P) {
//        cout << "P_BEFORE: ", printSet(&R);
//    }

    map<int, set <int>> involved;
    //cout << q.SZ << "\n";
    while ( !q.empty() ) {
        involved.clear();
        set <int> &st = q.front().FF;
//        printSet(&st);
        char c = q.front().SS;
        //cout << c << "\n";
        //cout << st << " " << c << "\n";

        for (auto v : st) {
          //      cout << v << "\n";
            for (auto to : RG[v][c-'a']) {
                int i = Class[to];
                involved[i].insert(to);
            }
        }

        for (auto &item : involved) {
            int i = item.FF;
            //cout << i << "\n";
            if (item.SS.SZ < P[i].SZ) {
                //cout << "INV\n";
                P.resize(P.SZ + 1);
                int j = P.SZ-1;
                for (int to : item.SS) {
                    P[i].erase(to);
                    P[j].insert(to);
                    Class[to] = j;
                }
                for (char cNext : alpha) {
                    q.push(MP(P[j], cNext));
                }
            }
        }
        q.pop();
    }

//        for (auto R : p) {
//        cout << "P : ", printSet(P[R]);
//      }

    ansN = P.SZ - 1;
    int startCl = Class[1];
    if (startCl) {
        for (int i = 1; i <= n; ++i) {
            if (Class[i] == startCl) {
                Class[i] = 1;
            }
            else if (Class[i] == 1) {
                Class[i] = startCl;
            }
        }
    }
    ansGr.resize(ansN + 5, VEC <int>(26));
    isAnsTerm.resize(ansN + 5);
    VEC<VEC<bool>> ed(ansN + 5,  VEC <bool>(26));
    for (int i = 1; i <= n; ++i) {
        int cl = Class[i];
        if (!cl)
            continue;
        if (isTerm[i] && !isAnsTerm[cl]) {
            isAnsTerm[cl] = 1;
            ++ansK;
        }
        for (auto c : alpha) {
            int to = gr[i][c-'a'];
            if (to) {
                int toCl = Class[to];
                if (toCl && !ed[cl][c-'a']) {
                    ed[cl][c-'a'] = 1;
                    ansGr[cl][c-'a'] = toCl;
                    ++ansM;
                }
            }
        }
    }

//    if (!ansM || !ansK || !ansN) {
//        ansM = ansN = ansK = 0;
//    }
    //sort(ansTerm.begin(), ansTerm.end());
}

void out()
{
    cout.tie(0);
    ofstream cout(OUT_NAME);
    cout << ansN << " " << ansM << " " << ansK << "\n";
    for (int i = 1; i <= ansN; ++i) {
        if (isAnsTerm[i])
            cout << i << " ";
    }
    cout << "\n";
    for (int i = 1; i <= ansN; ++i) {
        for (char c : alpha) {
            int to = ansGr[i][c-'a'];
            if (to) {
                cout << i << " " << to << " " << c << "\n";
            }
        }
    }
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
