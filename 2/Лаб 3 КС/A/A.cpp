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

#define IN_NAME "automaton.in"
#define OUT_NAME "automaton.out"

using namespace std;

const string ANS[] = {"no\n", "yes\n"};

int n, start, m;
VEC<string> gr[256 + 5], q;
VEC<bool> ans;

bool dfs(int i, int num, string& s) {
    //cout << s[i] << " " << char(num+'A') << " " << s << "\n";
    char curC = s[i];
    for (int j = 0; j < gr[num].SZ; ++j) {
        string to = gr[num][j];
        if (to[0] == curC) {
            if (s.SZ - 1 == i && to.SZ == 1) {
                return 1;
            } else if (to.SZ == 2 && s.SZ - 1 != i) {
                //cout << to[1] << "\n";
                bool res = dfs(i + 1, to[1] - 'A', s);
                if (res)
                    return 1;
            }
        }
    }
    return 0;
}

void in()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ifstream cin(IN_NAME);
    char c;
    cin >> n >> c;
    start = int(c - 'A');
    for (int i = 0; i < n; ++i) {
        string s, to;
        cin >> c >> s >> to;
        //cout << c << " -> " << to << "\n";
        //cout << int(c-'A') << "\n";
        gr[int(c-'A')].PB(to);
    }
    cin >> m;
    //cout << m << "\n";/*
    ans.resize(m + 5);
    q.resize(m + 5);
    for (int i = 0; i < m; ++i) {
        cin >> q[i];
    }
}

void solution()
{
    for (int i = 0; i < m; ++i) {
        ans[i] = dfs(0, start, q[i]);
    }
}

void out()
{
    cout.tie(0);
    ofstream cout(OUT_NAME);
    for (int i = 0; i < m; ++i) {
        cout << ANS[ans[i]];
    }
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
