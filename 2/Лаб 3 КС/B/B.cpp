#include <iostream>
#include <fstream>
#include <sstream>
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

#define IN_NAME "epsilon.in"
#define OUT_NAME "epsilon.out"

using namespace std;

const string ANS[] = {"no\n", "yes\n"};

int n, start;
VEC<string> gr[1000000];
set <char> ans;

set <char>* dfs(int num) {
    //cout << s[i] << " " << char(num+'A') << " " << s << "\n";
    set <char>* st = new set <char>;
    for (int j = 0; j < gr[num].SZ; ++j) {
        string to = gr[num][j];
        if (to.SZ == 0) {
            st->insert(char(num + 'A'));
        }
        for (int k = 0; k < to.SZ; ++k) {
            set<char>* tmp = dfs(to[k] - 'A');

        }
    }
}

void in()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ifstream cin(IN_NAME);
    char c;
    cin >> n >> c;
    start = int(c - 'A');
    string s, emp = "";
    getline(cin, s);
    for (int i = 0; i < n; ++i) {
        string str;
        getline(cin, s);
        stringstream ss(s);
        VEC<string> v;
        while (!ss.eof()) {
            ss >> str;
            v.PB(str);
            //cout << str << " ; ";
        }
        if (v.SZ == 3) {
                //cout << v[0] << " " << v[2] << "\n";
            bool fl = 1;
            for (int j = 0; j < v[2].SZ; ++j) {
                if (v[2][j] >= 'a' && v[2][j] <= 'z') {
                    fl = 0;
                }
            }
            if (fl)
                gr[v[0][0] - 'A'].PB(v[2]);
        } else {
            ans.insert(v[0][0]);
        }
    }
}

void solution()
{
    int tmp = 1;
    set <pair <char, string>> u;
    while (tmp) {
        tmp = 0;
        for (char c = 'A'; c <= 'Z'; ++c) {
            for (int i = 0; i < gr[c-'A'].SZ; ++i) {
                string to = gr[c-'A'][i];
                if (!u.empty() && u.count({c, to}))
                    continue;
                bool fl = 1;
                for (int j = 0; j < to.SZ; ++j) {
                    if (!ans.empty() && !ans.count(to[j])) {
                        fl = 0;
                        break;
                    }
                }
                if (fl) {
                    ans.insert(c);
                    u.insert(MP(c, to));
                    tmp = 1;
                }
            }
        }
    }
}

void out()
{
    cout.tie(0);
    ofstream cout(OUT_NAME);
    char last = *ans.rbegin();
    ans.erase(last);
    for (auto it : ans) {
        cout << it << " ";
    }
    cout << last << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
