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
#define PIC pair <int,char>
#define LL long long

#define IN_NAME "problem1.in"
#define OUT_NAME "problem1.out"

using namespace std;

const int MAXN = (int)1e6 + 15;
const string ANS[] = {"Rejects\n", "Accepts\n"};

string s;
int n, m, k, ans;
bool isTerm[MAXN];
map <PIC, int> gr;

void in()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(0);
    ifstream cin(IN_NAME);
    cin >> s;
    //cout << s << "\n";
    cin >> n >> m >> k;
    for (int i = 0; i < k; ++i) {
        int a;
        cin >> a;
        isTerm[a] = 1;
    }
    for (int i = 0; i < m; ++i) {
        int a, b;
        char c;
        cin >> a >> b >> c;
        //st.insert(MP(b, c));
        gr[MP(a, c)] = b;
        //gr[MP(b, c)] = a;
    }
}

void solution()
{
    int cur = 1;
    for (int i = 0; i < s.SZ; ++i) {
        cur = gr[MP(cur, s[i])];
    }
    if (isTerm[cur])
        ans = 1;
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
