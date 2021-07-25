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

const int MAXN = 1000 + 15;

int n, ans;
int num[MAXN];
string s[MAXN];

int T0(int ind){
	return s[ind][0] == '0';
}

int T1(int ind){
	return s[ind][ (1 << num[ind]) - 1] == '1';
}

int ne(int a, int siz){
	int res = 0;
	for(int i = 0; i < siz; i++)
		res += ( a&(1 << i) )? 0:(1 << i);
	return res;
}

int S(int ind){
	for(int i = 0; i < (1 << num[ind]); i++){
		int ri = ne(i, num[ind]);
		if( s[ind][i] == s[ind][ri] )return 0;
	}
	return 1;
}

int M(int ind){
	int res = 1;
	int siz = s[ind].SZ;
	for(int i = 0; i < siz; i++){
		for(int j = 0; j < num[ind]; j++){
			int new_i = (i | (1 << j) );
			res = ( res && (s[ind][i] <= s[ind][new_i]));
		}
	}
	return res;
}

int bit_count(int a){
	int res = 0;
	for(int i = 0; i < 32; i++)
		res += ( ( a&(1 << i) ) > 0 );
	return res;
}

int L(int ind){
	int siz = (1 << num[ind]);
	int dp[(1 << 12)];
	for(int i = 0; i < siz; i++)
		dp[i] = (s[ind][i] == '1');
	for(int i = 1; i < siz; i++){
		for(int j = 0; j < siz - i; j++)
			dp[j] = (dp[j] ^ dp[j + 1]);
		if( (bit_count(i)>1) && dp[0] )return 0;
	}
	return 1;
}

void in()
{
    //ifstream cin("C.in");
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> num[i] >> s[i];
}

void solution()
{
	int res_T0 = 1, res_T1 = 1, res_S = 1, res_M = 1, res_L = 1;
	for(int i = 0; i < n; i++){
		res_T0 = (res_T0 && T0(i));
		res_T1 = (res_T1 && T1(i));
		res_S = (res_S && S(i));
		res_M = (res_M && M(i));
		res_L = (res_L && L(i));
	}
	ans = !(res_T0 || res_T1 || res_S || res_M || res_L);
}

void out()
{
   // ofstream cout("C.out");
    ans ? cout << "YES\n" : cout << "NO\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
