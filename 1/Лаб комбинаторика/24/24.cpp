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
VEC <int> el, prevPerm, nextPerm;

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
        int ind = 0;
        for (int i =  nextInd+1; i < n; ++i)
            if (el[i] < mini && el[i] > cur){
                mini = el[i];
                ind = i;
            }
        swap(nextPerm[ind], nextPerm[nextInd]);
        reverse(nextPerm.begin() + nextInd + 1,nextPerm.end());
    }
}

void getPrev()
{
    int prevInd = -1;
    for (int i = n-2; i >= 0; --i)
        if (el[i] > el[i+1]){
            prevInd = i;
            break;
        }
    if (prevInd == -1)
        for (int i = 0; i < n; ++i)
            prevPerm[i] = 0;
    else{
        int maxi = 0, cur = el[prevInd];
        int ind = 0;
        for (int i = prevInd+1; i < n; ++i)
            if (el[i] > maxi && el[i] < cur){
                maxi = el[i];
                ind = i;
            }
        swap(prevPerm[ind], prevPerm[prevInd]);
        reverse(prevPerm.begin() + prevInd + 1, prevPerm.end());
    }
}

void in()
{
    ifstream cin("nextperm.in");
    cin >> n;
    el.resize(n);
    prevPerm.resize(n);
    nextPerm.resize(n);
    for (int i = 0; i < n; ++i){
        cin >> el[i];
        prevPerm[i] = el[i];
        nextPerm[i] = el[i];
    }
}

void solution()
{
    getPrev();
    getNext();
}

void out()
{
    ofstream cout("nextperm.out");
    for (int i = 0; i < n; ++i)
        cout << prevPerm[i] << " ";
    cout << "\n";
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
