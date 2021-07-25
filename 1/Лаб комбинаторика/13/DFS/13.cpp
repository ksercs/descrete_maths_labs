#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <set>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

vector < char > vec;
vector < string > ans;

string str, answer;
int n, k, vecsize, ch;

void out()
{
     //ofstream cout ("a.out");
     for (int i = 0; i < answer.size()-1; i++)
     {
         cout << answer[i] << " ";
     }
     cout << answer[answer.size()-1] << "\n";
}

void dfs()
{
  int vsize = vec.size();
  if (str.size() == vecsize) {
                             ans.push_back(str);
                             cout << str << "\n";
                             ch++;
                           }
  else
  {
    for (int g = 0; g < vsize; g++)
    {
        char temp = vec[g];
        str += temp;
        vec.erase(vec.begin() + g);
        dfs();
        vec.push_back(temp);
        sort(vec.begin(), vec.end());
        str.erase(str.size()-1, str.size());
    }
  }
  if (ch == k) {answer = str; out(); exit(0);}
}

void in()
{
    //ifstream cin ("a.in");
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        vec.push_back(i + '0');
    }
    vecsize = vec.size();
}

void solution()
{
    for (int i = 0; i < vecsize; i++)
    {
     char help = vec[i];
     str += help;
     vec.erase(vec.begin() + i);
     dfs();
     vec.push_back(help);
     sort(vec.begin(), vec.end());
     str.clear();
    }
}

int main()
{
    in();
    solution();
return 0;
}
