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

const int MAXN = 40 + 5;

LL n, k, len, ans;

string sq, nextS;

void in()
{
    ifstream cin("nextbrackets.in");
    cin >> sq;
}

void solution()
{
    len = (LL)sq.SZ;
    int op = 0, cl = 0;
    for (int i = len-1; i >= 0; --i) {
       if (sq[i] == ')'){
            ++cl;
       }
       else{
            ++op;
            if (cl > op)
                break;
       }
    }
    sq.erase(len-op-cl);
    if (sq.SZ == 0){
        ans = 1;
        return;
    }
    nextS = sq;
    nextS += ')';
    for (int i = 0; i < op; ++i)
      nextS += '(';
    for (int j = 0; j < cl-1; ++j)
      nextS += ')';
}

void out()
{
    ofstream cout("nextbrackets.out");
    if (ans)
        cout << "-\n";
    else
        cout << nextS << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
