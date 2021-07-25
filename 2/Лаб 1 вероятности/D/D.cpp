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
#include <ctime>

#define SZ size()
#define VEC vector
#define PB push_back
#define MP make_pair
#define SS second
#define FF first
#define PII pair <int,int>
#define LL long long

using namespace std;

const int MAXN = 100 + 15;
const double EPS = 1e-4;

int  n;
time_t start;
VEC <VEC <double> > gr, ans;

void getAns (int cnt)
{
    while (cnt--) {
        VEC <VEC <double> > tmp(n+1, VEC<double>(n+1, 0.0));
        int fl = 0;
        for(int i = 1; i <= n; i++) {
            //cout << "TMP : \n";
            for(int j = 1; j <= n; j++) {
                for(int k = 1; k <= n; k++) {
                    tmp[i][j] += 1.0 * ans[i][k] * ans[k][j];
                    //cout << ans[i][k] << " " << gr[k][j] << " " << tmp[i][j] << "\n";
                }
                //cout << "\n";
                if (abs(tmp[i][j] - ans[i][j]) > EPS) {
                    fl = 1;
                }
            }
        }
        ans = tmp;
        if (!fl )//|| (double)(clock()-start)/CLOCKS_PER_SEC > 1.99)
            return;
        //cout << "\nANS : \n";
        /*for (int d = 1; d <= n; ++d) {
            for (int g = 1; g <= n; ++g) {
                //cout << ans[d][g] << " " ;
            }
            //cout << "\n";
        }*/
    }
    //cout << "\n";
}

int main()
{
    start = clock();
    ios_base:: sync_with_stdio(false);
    cin.tie();
    ifstream cin("markchain.in");
    cin >> n;
    gr.resize(n+1);
    ans.resize(n+1);
    for (int i = 1; i <= n; ++i) {
        gr[i].resize(n+1);
        ans[i].resize(n+1, 0.0);
        for (int j = 1; j <= n; ++j) {
            cin >> ans[i][j];
        }
        //ans[i][i] = 1.0;
    }
    getAns(100000);
    cout.tie();
    ofstream cout("markchain.out");
    cout.precision(15);
    for (int i = 1; i <= n; ++i) {
        cout << fixed << ans[1][i] << "\n";
    }
    return 0;
}
