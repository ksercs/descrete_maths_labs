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
#include <iterator>

#define SZ size()
#define VEC vector
#define PB push_back
#define MP make_pair
#define SS second
#define FF first
#define PII pair <LL, LL>
#define LL long long

using namespace std;

VEC <int> compressed;

void compress(string uncompressed)
{
    int dictSize = 26;
    map<string,int> dictionary;
    int cnt = 0;
    for (char c = 'a'; c <= 'z'; ++c){
        string s = "";
        s =+ c;
        dictionary[s] = cnt;
        ++cnt;
    }
    string w;
    for (int i = 0; i < uncompressed.SZ; ++i) {
        char c = uncompressed[i];
        string wc = w + c;
        if (dictionary.count(wc))
            w = wc;
        else {
            compressed.PB(dictionary[w]);
            dictionary[wc] = dictSize++;
            w = string(1, c);
        }
    }

    if (!w.empty())
        compressed.PB(dictionary[w]);
}

int main() {
    ifstream cin("lzw.in");
    ofstream cout("lzw.out");
    string s;
    cin >> s;
    compress(s);
    int sz = compressed.SZ;
    for (int i = 0; i < sz-1; ++i)
        cout << compressed[i] << " ";
    cout << compressed[sz-1] << "\n";
    return 0;
}
