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
#include <list>

#define SZ size()
#define VEC vector
#define PB push_back
#define MP make_pair
#define SS second
#define FF first
#define PII pair <int,int>
#define LL long long
#define ST begin()
#define FN end()

using namespace std;

const int MAXN = 1000 + 15;

int n;
int matrix[MAXN][MAXN];
int u[MAXN];
VEC <VEC <int> > gr;
list <int> ans;

int DFS(int v) {
    u[v] = 1;
    for (int i = 0; i < gr[v].SZ; ++i) {
        int to = gr[v][i];
        if (!u[to]) {
            int res = DFS(to);
            if (res) {
                if (ans.front() != res) {
                    ans.push_front(v);
                }
                return res;
            }
        } else if(u[to] == 1) {
            ans.push_front(v);
            return to;
        }
    }
    u[v] = 2;
    return 0;
}

void in()
{
    ifstream cin("guyaury.in");
    cin >> n;
    gr.resize(n + 5);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j < i; ++j) {
            char c;
            cin >> c;
            //cout << i << " " << j << " " << c << "\n";
            if (c == '1') {
                matrix[i][j] = 1;
                gr[i].PB(j);
            } else {
                matrix[j][i] = 1;
                gr[j].PB(i);
            }
        }
    }
}

void solution()
{
    DFS(1);
    for (int i = 1; i <= n; ++i) {
        u[i] = 0;
    }
    for (auto it = ans.ST; it != ans.FN; it++) {
        u[*it] = 1;
    }

    for (int i = 1; i <= n; ++i) {
        if (u[i]) {
            continue;
        }
        auto it = ans.ST;
        while(it != ans.FN &&  matrix[*it][i]) {
            it++;
        }
        ans.insert(it, i);
    }

//    for (auto it : ans) {
//        cout << it << " ";
//    }
//    cout << "\n";

    int k = ans.SZ - 1;
    int first = ans.front();
    for (auto it = ans.rbegin(); it != ans.rend(); it++) {
        if (matrix[*it][first]) {
            break;
        }
        k--;
    }
    if (k == n - 1 || k < 2) {
        return;
    }

    auto ind = ans.ST;
    for (int i = 0; i < k; ++i) {
        ind++;
    }
    list<int> ans_copy(ans.begin(), ind);
    list<int> tmp(ind, ans.FN);

    while (tmp.SZ > 0) {
        auto it_1 = tmp.ST;
        auto it_2 = ans_copy.ST;
        for (; it_1 != tmp.FN; it_1++) {
            for (; it_2 != ans_copy.FN; it_2++) {
                if (matrix[*it_1][*it_2]) {
                    break;
                }
            }
            if (it_2 != ans_copy.FN) {
                break;
            }
        }
        it_1++;
        while (tmp.ST != it_1) {
            ans_copy.insert(it_2, tmp.front());
            tmp.pop_front();
        }
        while (ans_copy.ST != it_2) {
            ans_copy.push_back(ans_copy.front());
            ans_copy.pop_front();
        }
    }
    ans = ans_copy;
}

void out()
{
    ofstream cout("guyaury.out");
    for (auto it : ans) {
        cout << it << " ";
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
