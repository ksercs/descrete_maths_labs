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

const int MAXN = 4000 + 15;

int n;
int gr[MAXN][MAXN];
deque <int> q;

void in()
{
    ifstream cin("fullham.in");
    cin >> n;
    for (size_t i = 1; i <= n; ++i) {
        for (size_t j = 1; j < i; ++j) {
            char c;
            cin >> c;
            if (c == '1') {
                gr[i][j] = gr[j][i] = 1;
            }
        }
    }
}

void q_reverse(VEC <int> & v) {
    for (auto it : v) {
        q.push_front(it);
    }
}

void solution()
{
    for (int i = 1; i <= n; ++i) {
        q.push_back(i);
    }

    for (int k = 0; k < n * (n - 1); ++k) {
        int v = q[0],
            first = q[1];
        if (!gr[v][first]) {
            int ind = 2;
            while (!gr[v][q[ind]] || !gr[first][q[ind + 1]]) {
                ++ind;
            }
            reverse(q.begin() + 1, q.begin() + ind + 1);
        }
        q.push_back(q.front());
        q.pop_front();
    }
}

void out()
{
    ofstream cout("fullham.out");
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop_front();
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
