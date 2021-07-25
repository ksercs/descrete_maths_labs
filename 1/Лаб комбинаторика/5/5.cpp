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

int n, k;
VEC <string> gr;

void make_GR(int n)
{
    VEC <string> v = gr;
    for (int i = 0; i < gr.SZ; ++i)
        gr[i] = gr[i]+'0';
    for (int i = 1; i < k; ++i){
            VEC <string> v1 = v;
            if (i%2) reverse(v1.begin(), v1.end());
            for (int j = 0; j < v1.SZ; ++j)
                gr.PB(v1[j]+char(i+'0'));
    }
}

void in()
{
    ifstream cin("telemetry.in");
    cin >> n >>k;
}

void solution()
{
    string s;
    for (int i = 0; i < k; ++i){
        s = "";
        s += char(i+'0');
        gr.PB(s);
    }
    for (int i = 2; i <= n; ++i)
        make_GR(i);
}

void out()
{
    ofstream cout("telemetry.out");
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
