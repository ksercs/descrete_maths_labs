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
    VEC <string> v1 = gr;
    reverse(v.begin(), v.end());
    for (int i = 0; i < gr.SZ; ++i)
        gr[i] = '0'+gr[i];
    for (int i = 0; i < v1.SZ; ++i)
        gr.PB('1'+v1[i]);
    for (int i = 0; i < v1.SZ; ++i)
        gr.PB('2'+v1[i]);
}

void in()
{
    ifstream cin("antigray.in");
    cin >> n;
}

void solution()
{
    string s = "0";
    gr.PB(s);
    s = "1";
    gr.PB(s);
    s = "2";
    gr.PB(s);
    for (int i = 2; i <= n; ++i)
        make_GR(i);
}

void out()
{
    ofstream cout("antigray.out");
    for (int i = 0; i < (int)gr.SZ/3; ++i){
        cout << gr[i] << "\n";
        for (int j = 0; j < gr[i].SZ; ++j)
            cout << ((gr[i][j]-'0')+1)%3;
        cout << "\n";
        for (int j = 0; j < gr[i].SZ; ++j)
            cout << ((gr[i][j]-'0')+2)%3;
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
