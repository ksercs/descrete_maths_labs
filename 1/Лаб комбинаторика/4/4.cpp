#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <iomanip>
#include <set>
#include <unordered_set>
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
vector <string> ans;
set <string> st;

void in()
{
    ifstream cin("chaincode.in");
    cin >> n;
}

void solution()
{
    string s(n, '0');
    st.insert(s);
    ans.PB(s);
    while (1){
        string pref = s.substr(1);
        if (!st.count(pref+'1'))
            s = pref + '1';
        else if (!st.count(pref+'0'))
            s = pref + '0';
        else
            break;
        st.insert(s);
        ans.PB(s);
    }
}

void out()
{
    ofstream cout("chaincode.out");
    for (auto item : ans)
        cout << item << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
