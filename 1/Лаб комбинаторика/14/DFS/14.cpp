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

string str, s1;
int vecsize, answer, ch;

void out()
{
     ofstream cout ("a.out");
     cout << answer << "\n";
}

void dfs()
{
  int vsize = vec.size();
  if (str.size() == vecsize) {
    ans.push_back(str);
    cout << str << "\n";
    ch++;
    if (str == s1) {answer = ch; out(); exit(0);}
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
}

void in()
{
    ifstream cin ("a.in");
    char s;
    while (cin >> s)
    {
        vec.push_back(s);;
        s1 += s;
    }
    vecsize = vec.size();
    sort(vec.begin(), vec.end());
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
