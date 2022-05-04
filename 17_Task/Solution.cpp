#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define type1 1
#define type2 2

vector<int> ans;
vector<int> adj[10000];

void BFS(int town1, int town2)
{
    queue<int> q;
    q.push(town1);
    bool used[10000]{ 0 };

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        if (curr == town2)
        {
            ans.push_back(1);
            return;
        }

        for (int x : adj[curr])
        {
            if (!used[x])
            {
                q.push(x);
                used[x] = true;
            }
        }
    }
    ans.push_back(0);
}

int main()
{
    int vertices, edges;
    cin >> vertices >> edges;

    int h1, h2;
    for (int i = 0; i < edges; i++)
    {
        cin >> h1 >> h2;
        adj[h1].push_back(h2);
        adj[h2].push_back(h1);
    }

    int queues, queueType, town1, town2;
    cin >> queues;
    for (int i = 0; i < queues; i++)
    {
        cin >> queueType >> town1 >> town2;
        if (queueType == type1)
        {
            BFS(town1, town2);
        }
        else if (queueType == type2)
        {
            adj[town1].push_back(town2);
            adj[town2].push_back(town1);
        }
    }

    for (int i = 0; i < (int)ans.size(); i++)
    {
        cout << ans[i];
    }

    return 0;
}
