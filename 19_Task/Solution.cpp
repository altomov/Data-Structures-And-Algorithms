#include <iostream>
#include <vector>
#include <string>

using namespace std;

int n, m, f;

vector<string> ans;
bool used[100000];

void DFS(int &curr, vector<int> v[100000])
{
  used[curr] = true;

  for (int x : v[curr])
  {
    if (!used[x])
    {
      DFS(x, v);
    }
  }
}

void read(vector<int> v[100000])
{
    cin >> n >> m;
    int a, b;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        if(i == 0)
        {
            f = a;
        }
        v[a].push_back(b);
        v[b].push_back(a);
    }
}

void euler(vector<int> v[100000])
{
    int odd = 0;
    int lastOdd = 0;

    for (int i = 0; i < n; i++)
    {
        if (v[i].size() % 2 == 1)
        {
            odd++;
            lastOdd = i;
        }
    }
    DFS(f, v);
    int br = 0;
    for(int i = 0; i < 100000; i++)
    {
        if(used[i] == true)
        {
            br++;
        }
    }
    if(br == n)
    {
        if (odd == 0)
        {
            ans.push_back("ecycle");
        }
        else if (odd == 2)
        {
            ans.push_back("epath");
        }
        else
        {
            ans.push_back("none");
        }
    }
    else ans.push_back("none");
}

void make0()
{
    for(int i = 0; i < 100000; i++)
    {
        used[i] = 0;
    }
}

int main()
{
    int queries = 0;
    cin >> queries;
    for (int i = 0; i < queries; i++)
    {
        vector<int> v[100000];
        read(v);
        euler(v);
        make0();
    }
    for (int i = 0; i < (int)ans.size(); i++)
    {
        cout << ans[i] << endl;
    }
    return 0;
}