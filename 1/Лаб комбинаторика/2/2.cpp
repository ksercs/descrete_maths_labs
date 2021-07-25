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

int n;
VEC <string> gr;

void make_GR(int n)
{
    VEC <string> v = gr;
    reverse(v.begin(), v.end());
    for (int i = 0; i < gr.SZ; ++i)
        gr[i] = '0'+gr[i];
    for (int i = 0; i < v.SZ; ++i)
        gr.PB('1'+v[i]);
}

void in()
{
    ifstream cin("gray.in");
    cin >> n;
}

void solution()
{
    string s = "0";
    gr.PB(s);
    s = "1";
    gr.PB(s);
    if (n == 1)
        return;
    for (int i = 2; i <= n; ++i)
        make_GR(i);
}

void out()
{
    ofstream cout("gray.out");
    for (int i = 0; i < gr.SZ; ++i)
        cout << gr[i] << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
