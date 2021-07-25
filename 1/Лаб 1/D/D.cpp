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

string ans;
LL n, s;
LL a[1000], u[1000];

LL getBit(LL num, int ind){
	return ( num & (1ll << ind) ) > 0;
}

void in()
{
    ifstream cin("D.in");
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    cin >> s;
}

void solution()
{
	if(s == 0){
		ans = "1&~1";
		return;
	}
	for(int i = 0; i < 1000; i++)
		u[i] = -1;
	for(int i = 0; i <= 32; i++){
		int ind = 0;
		cout << ind << " ";
		for(int j = 0; j < n; j++){
			ind = ( (ind << 1) | getBit(a[j], i) );
		}
		cout << ind << "\n";
		int s_bit = getBit(s, i);
		if( (u[ind] == -1) || (u[ind] == s_bit) ){
			u[ind] = s_bit;
			if(s_bit){
				ans += '(';
				for(int j = 0; j < n; j++){
					string ne = getBit(a[j], i)? "":"~";
					ans += ne + (char)(j + '1') + ( (j < n - 1)? "&":"" );
				}
				ans += ')';
				ans += '|';
			}
		}
		else{
			ans.clear();
			return;
		}
	}
	ans.resize(ans.SZ-1);
}

void out()
{
    ofstream cout("D.out");
    if (ans.SZ == 0)
        cout << "Impossible\n";
    else
        cout << ans << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
