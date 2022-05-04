#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

vector<int> v[1000001];
int used[1000001];

void DFS(int curr, int to)
{
    used[curr] = to;

    for (int x : v[curr])
    {
        if (!used[x])
        {
            DFS(x, to);
        }
    }
}

int main() {
    int vertices, edges;
    cin >> vertices >> edges;

    int tempVertix, tempEdge;
    for(int i = 0; i < edges; i++)
    {
        cin >> tempVertix >> tempEdge;
        v[tempVertix].push_back(tempEdge);
        v[tempEdge].push_back(tempVertix);
    }
    int help = 1;
    for(int i = 1; i <= vertices; i++)
    {
        if(used[i] == 0)
        {
            DFS(i,help);
            help++;
        }
    }
    int k;
    cin >> k;
    vector<int> answer;
    int searching1, searching2;
    for(int i = 0; i < k; i++)
    {
        cin >> searching1 >> searching2;
        if(used[searching1] == used[searching2])
        {
            answer.push_back(1);
        }
        else answer.push_back(0);
    }
    
    for(int i = 0; i < (int)answer.size(); i++)
    {
        cout << answer[i] << " ";
    }
    return 0;
}