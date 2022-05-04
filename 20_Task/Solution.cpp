#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;

vector<int> adj[200001];

vector<bool> visited(200001, false);

int bfs(int start)
{
    int sum = 0;
    queue<int> q;
    q.push(start);

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        for (auto i = adj[curr].begin(); i != adj[curr].end(); i++)
        {
            q.push(*i);
            visited[*i] = true;
            sum = sum + *i;
        }
    }
    return sum;
}

int main()
{
    int edges, queues;
    cin >> edges >> queues;
    int t1, t2;
    for (int i = 0; i < edges; i++)
    {
        cin >> t1 >> t2;
        adj[t1].push_back(t2);
    }

    int t;
    vector<int> ans;

    for (int i = 0; i < queues; i++)
    {
        cin >> t;
        ans.push_back(bfs(t));
    }

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }

    return 0;
}
