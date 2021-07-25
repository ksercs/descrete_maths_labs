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

#define IN_NAME "isomorphism.in"
#define OUT_NAME "isomorphism.out"

using namespace std;

const int MAXN = (int)1e5 + 5, GR_CNT = 2, ALPHA_SZ = 26;
const string ANS[] = {"NO\n", "YES\n"};

int ans = 1;
int gr[MAXN][ALPHA_SZ][GR_CNT];
bool isTerm[MAXN][GR_CNT], u[MAXN][GR_CNT];

void in()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ifstream cin(IN_NAME);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < k; ++i) {
        int a;
        cin >> a;
        isTerm[a][0] = 1;
    }
    for (int i = 0; i < m; ++i) {
        int a, b;
        char c;
        cin >> a >> b >> c;
        gr[a][(int)(c-'a')][0] = b;
    }
    cin >> n >> m >> k;
    for (int i = 0; i < k; ++i) {
        int a;
        cin >> a;
        isTerm[a][1] = 1;
    }
    for (int i = 0; i < m; ++i) {
        int a, b;
        char c;
        cin >> a >> b >> c;
        gr[a][(int)(c-'a')][1] = b;
    }
}

void solution()
{
    queue <PII> q;
    q.push(MP(1, 1));
    while (!q.empty()) {
        int f = q.front().FF,
            s = q.front().SS;
		if (isTerm[f][0] != isTerm[s][1]) {
			ans = 0;
			return;
		}
		u[f][0] = 1,
		u[s][1] = 1;
		for (int c = 0; c < 26; ++c) {
			if ( !u[gr[f][c][0]][0] || !u[gr[s][c][1]][1] ) {
				q.push( MP(gr[f][c][0], gr[s][c][1]) );
			}
		}
		q.pop();
    }
}

void out()
{
    cout.tie(0);
    ofstream cout(OUT_NAME);
    cout << ANS[ans];
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
