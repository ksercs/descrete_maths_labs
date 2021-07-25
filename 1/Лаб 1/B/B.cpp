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

const int MAXN = 100 + 5;

int n, k, ans;
int con[MAXN][MAXN], con_save[MAXN][MAXN];
int con_size[MAXN], x[MAXN];

int single_count(){
	int sum = 0;
	for(int i = 0; i < k; i++){
		if(con_size[i] == 1){
			sum++;
			for(int j = 0; j < n; j++)
				if( con[i][j] != -1 )
					x[j] = (con[i][j] == 1);
		}
	}
	return sum;
}

void in()
{
    ifstream cin("B.in");
    cin >> n >> k;
    for (int i = 0; i < k; ++i)
        for (int j = 0; j < n; ++j){
            cin >> con[i][j];
        }
}

void solution(){
	for(int i = 0; i < k; i++)
		for(int j = 0; j < n; j++){
			con_size[i] += ( con[i][j] != -1 );
			con_save[i][j] = con[i][j];
		}
	for(int i = 0; i < n; i++)
		x[i] = -1;
	while( single_count() )
		for(int i = 0; i < k; i++)
			for(int j = 0; j < n; j++)
				if( (con[i][j] != -1) && (x[j] != -1) )
					if( con_size[i] > 0 ){
						int res = (con[i][j] == 1)? x[j]:(!x[j]);
						if(res){
							con_size[i] = 0;
							break;
						}
						else{
							con[i][j] = -1;
							con_size[i]--;
						}
					}

	for(int i = 0; i < n; i++){
		cout << x[i] << ' ';
	}
	cout << "\n";

	int answer = 1;
	for(int i = 0; i < k; i++){
		int res = 0;
		for(int j = 0; j < n;  j++){
			if(con_save[i][j] !=-1){
				x[j] = (x[j] == -1)? 0:x[j];
				res = (res | ( (con_save[i][j] == 1)? x[j]:(!x[j]) ) );
			}
		}
		answer = ( answer & res );
	}
	answer = !answer;
	ans = answer;
}

void out()
{
    ofstream cout("B.out");
    ans ? cout << "YES\n" : cout << "NO\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
