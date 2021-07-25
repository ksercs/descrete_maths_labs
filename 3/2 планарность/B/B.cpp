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

struct Point {
    double x = 0;
    double y = 0;

    point() {}
    point(double _x, double _y) : x(_x), y(_x) {}
};

struct Line {
    Point a;
    Point b;

    Line() {}
    Line(Point _a, Point _b) : a(_a), b(_b) {}
};

int n;
VEC <Line> lines;
VEC <double> ans;

void in()
{
    ifstream cin("B.in");
    cin >> n;
    lines.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> lines[i].a.x >> lines[i].a.y >> lines[i].b.x >> lines[i].b.y;
    }
}

void solution()
{

}

void out()
{
    ofstream cout("B.out");
    cout << ans.SZ << "\n";
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
