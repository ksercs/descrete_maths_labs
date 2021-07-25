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

int n, prevInd = -1, nextInd = -1;
string s, prevS, nextS;

void getPrev()
{
    prevS = s;
    for (int i = n-1; i >= 0; --i){
        if (prevS[i] == '1'){
            prevInd = i;
            break;
        }
    }
    if (prevInd == -1)
        return;
    prevS[prevInd] = '0';
    for (int i = prevInd+1; i < n; ++i)
        prevS[i] = '1';
}

void getNext()
{
    nextS = s;
    for (int i = n-1; i >= 0; --i){
        if (nextS[i] == '0'){
            nextInd = i;
            break;
        }
    }
    if (nextInd == -1)
        return;
    nextS[nextInd] = '1';
    for (int i = nextInd+1; i < n; ++i)
        nextS[i] = '0';
}

void in()
{
    ifstream cin("nextvector.in");
    cin >> s;
}

void solution()
{
    n = s.SZ;
    getPrev();
    getNext();
}

void out()
{
    ofstream cout("nextvector.out");
    if (prevInd == -1)
        cout << "-\n";
    else
        cout << prevS << "\n";
    if (nextInd == -1)
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
