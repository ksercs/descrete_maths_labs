#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <iomanip>
#include <set>
#include <map>
#include <climits>
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
VEC <int> el, nextPerm;

void getNext()
{
    int nextInd = -1;
    for (int i = n-2; i >= 0; --i)
        if (el[i] < el[i+1]){
            nextInd = i;
            break;
        }
    if (nextInd == -1)
        for (int i = 0; i < n; ++i)
            nextPerm[i] = 0;
    else{
        int mini = INT_MAX, cur = el[nextInd];
        int ind;
        for (ind = nextInd+1; ind < n-1; ++ind)
            if (el[ind + 1] <= el[nextInd])
                break;
        swap(nextPerm[ind], nextPerm[nextInd]);
        reverse(nextPerm.begin() + nextInd + 1,nextPerm.end());
    }
}

void in()
{
    ifstream cin("nextmultiperm.in");
    cin >> n;
    el.resize(n);
    nextPerm.resize(n);
    for (int i = 0; i < n; ++i){
        cin >> el[i];
        nextPerm[i] = el[i];
    }
}

void solution()
{
    getNext();
}

void out()
{
    ofstream cout("nextmultiperm.out");
    for (int i = 0; i < n; ++i)
        cout << nextPerm[i] << " ";
    cout << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
