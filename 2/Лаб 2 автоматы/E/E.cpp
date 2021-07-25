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

#define IN_NAME "problem5.in"
#define OUT_NAME "problem5.out"

using namespace std;

const int MAXN = 100 + 15, MOD = (int)1e9 + 7;

int n, m, k, L, ans;
map <PIC, VEC <int>> gr;
VEC <LL> dp;
VEC <int> totalTerm;
VEC <VEC <int>> totalGr;
map <string, bool> u;
bool isTerm[MAXN];
map <string, int> num;

void in()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ifstream cin(IN_NAME);
    cin >> n >> m >> k >> L;
    for (int i = 0; i < k; ++i) {
        int a;
        cin >> a;
        isTerm[a] = 1;
    }
    for (int i = 0; i < m; ++i) {
        int a, b;
        char c;
        cin >> a >> b >> c;
        gr[MP(a, c)].PB(b);
    }
}

void solution()
{
    queue <pair<string, int>> q;
    string s = "1";
    totalGr.resize(MAXN + 15);
    for (int i = 2; i <= n; ++i)
        s += '0';
    q.push(MP(s,1));
    //u[s] = 1;
    num[s] = 1;
    int maxi = 1;
    while (!q.empty()) {
        int pos = q.front().SS;
        int toPos = maxi+1;
        s = q.front().FF;
        //cout << "ST : " << s << " " << pos << "\n";
        q.pop();
        for (char c = 'a'; c <= 'z'; ++c) {
            string to(n, '0');
            int fl = 0, term = 0;
            for (int i = 0; i < n; ++i) {
                if (s[i] == '1') {
                    for (int j = 0; j < gr[MP(i+1, c)].SZ; ++j) {
                        //cout << "(" << gr[MP(i+1, c)][j] << ")\n";
                        to[gr[MP(i+1, c)][j] - 1] = '1';
                        if (isTerm[gr[MP(i+1, c)][j]])
                            term = 1;
                        fl = 1;
                    }
                }
            }
            if (!fl)
                continue;
            if (!u[to]) {
                maxi = max(maxi, toPos);
                if (term)
                    totalTerm.PB(toPos);
                totalGr[pos].PB(toPos);
                q.push(MP(to, toPos));
                u[to] = 1;
                num[to] = toPos;
                //cout << c << " " << to << " " << num[to] << "\n";
                ++toPos;
                //cout << "NUM : " << to << " " << num[to] << "\n";
            } else {
                totalGr[pos].PB(num[to]);
            }
        }
    }
    dp.resize(maxi + 5);
    for (int i = 0; i < totalTerm.SZ; ++i) {
        dp[totalTerm[i]] = 1;
        //cout << "TERM : " << totalTerm[i] << "\n";
    }
    for (int len = 0; len < L; ++len) {
        VEC <LL> tmpDp(maxi + 5);
        for (int i = 1; i <= maxi; ++i) {
            for (int j = 0; j < totalGr[i].SZ; ++j) {
                int to = totalGr[i][j];
                //cout << i << " -> " << to << "\n";
                tmpDp[i] = (tmpDp[i] + dp[to]) % MOD;
            }
        }
       // cout << "\n\n";
        dp = tmpDp;
    }
    ans = dp[1];
}

void out()
{
    cout.tie(0);
    ofstream cout(OUT_NAME);
    //cout << ans << "\n";
    for (int i = 1; i <= n; ++i) {
        cout << "--- " << i << " :\n";
        for (char c = 'a'; c <= 'e'; ++c) {
            cout << c << " : ";
            for (int j = 0; j < gr[MP(i, c)].SZ; ++j) {
                cout << gr[MP(i,c)][j] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
