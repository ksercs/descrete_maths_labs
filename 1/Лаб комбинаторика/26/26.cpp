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
#include <cctype>

#define SZ size()
#define VEC vector
#define PB push_back
#define MP make_pair
#define SS second
#define FF first
#define PII pair <int,int>
#define LL long long

using namespace std;

const int MAXN = 200 + 15;

LL n = -1, k = -1, fl;
VEC < VEC <int> > st, lastSt, ans;

void genLast (int sz)
{
    if (sz%2){
        lastSt.resize(sz/2+sz%2);
        int num = 1;
        for (int i = 0; i < sz/2+(sz%2); ++i)
            lastSt[i].PB(num++);
        if (sz/2-1+!(sz%2) < 0)
            return;
        for (int i = sz/2-1+!(sz%2); i >= 0; --i)
            lastSt[i].PB(num++);
    }
    else{
        lastSt.resize(sz/2);
        int num = 1;
        for (int i = 0; i < sz/2; ++i)
            lastSt[i].PB(num++);
        if (sz/2-1 < 0)
            return;
        for (int i = sz/2-1; i >= 0; --i)
            lastSt[i].PB(num++);
    }
    /*for (int i = 0; i < lastSt.SZ; ++i){
        for (int j = 0; j < lastSt[i].SZ; ++j)
            cout << lastSt[i][j] << " ";
        cout << "\n";
    }*/
}

void parseInt(string s)
{
    int ind = s.SZ-1;
    VEC <int> v;
    while (ind >= 0){
        int dop = 1,
            num = 0;
        while (ind >= 0 && s[ind] != ' '){
            num += (s[ind]-'0')*dop;
            dop *= 10;
            --ind;
        }
        v.PB(num);
        //cout << num << " ";
        --ind;
    }
    reverse(v.begin(), v.end());
    st.PB(v);
    /*cout << "\n";
    for (int i = 0; i < st.back().SZ; ++i)
        cout << st.back()[i] << " ";
    cout << "\n";*/
}

void out()
{
    if (fl)
        cout << "\n";
    cout << n << " " << ans.SZ << "\n";
    for (int i = 0; i < ans.SZ; ++i){
        for (int j = 0; j < ans[i].SZ; ++j)
            cout << ans[i][j] << " ";
        cout << "\n";
    }
}

void solution()
{
    //cout << "VVOD : " << n << " " << k << "\n";
    genLast(n);
    if (st == lastSt){
        if (fl)
            cout << "\n";
        cout << n << " " << n << "\n";
        for (int i = 1; i <= n; ++i)
            cout << i << "\n";
        return;
    }
    int tmp = 0;
    VEC <int> u;
    for (int i = st.SZ-1; i >= 0; --i){
        //if (u.SZ) cout << u.back() << "\n";
        if (u.SZ && u.back() > st[i].back()){
            for (int k = 0; k < u.SZ; ++k){
                if (st[i].back() < u[k]){
                    st[i].PB(u[k]);
                    u.erase(u.begin()+k);
                    tmp = 1;
                    break;
                }
            }
            break;
        }
        int j = st[i].SZ-1;
        for (; j >= 0; --j){
            if (u.SZ && st[i][j] < u.back() && j){
                for (int k = 0; k < u.SZ; ++k){
                    if (st[i][j] < u[k]){
                        u.PB(st[i][j]);
                        st[i][j] = u[k];
                        u.erase(u.begin()+k);
                        tmp = 1;
                        break;
                    }
                }
                if (tmp)
                    break;
            }
            else{
                u.PB(st[i][j]);
                st[i].resize(st[i].SZ-1);
            }
        }
        if (tmp)
            break;
        if (u.SZ)
            sort(u.begin(), u.end());
    }
    if (u.SZ)
        sort(u.begin(), u.end());
    for (int i = 0; i < u.SZ; ++i){
        VEC <int> v;
        v.PB(u[i]);
        //cout << "DOP = " << u[i] << "\n";
        st.PB(v);
    }
    ans = st;

    for (int i = 0; i < ans.SZ; ++i)
        if (ans[i].SZ == 0){
            ans.erase(ans.begin()+i);
            --i;
        }
    out();
}

void in ()
{
    while (1) {
        cin >> n >> k;
        if (!n && !k)
            break;
        string s;
        getline(cin, s);
        for (int i = 0; i < k; ++i){
            getline(cin, s);
            //cout << s << "\n";
            parseInt(s);
        }
        solution();
        ++fl;
        st.clear();
        lastSt.clear();
        ans.clear();
        //cout << "\n";
    }
}

int main()
{
    freopen("nextsetpartition.in", "r", stdin);
    freopen("nextsetpartition.out", "w", stdout);
    in();
    return 0;
}
