#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int Q = 10000000;
vector<int> children[Q];

void countingbfs(int root)
{
    queue<int> q;
    int gifts = 0;

    q.push(root);

    while (!q.empty())
    {
        int temp_node = q.front();
        q.pop();
        for (int i = 0; i < children[temp_node].size(); i++)
        {
            gifts++;
            q.push(children[temp_node][i]);
        }
    }
    cout << gifts << " ";
}

void bfs(int root)
{
    queue<int> q;

    q.push(root);

    while (!q.empty())
    {
        int temp_node = q.front();
        q.pop();
        countingbfs(temp_node);
        for (int i = 0; i < children[temp_node].size(); i++)
        {
            q.push(children[temp_node][i]);
        }
    }
}

int main()
{
    int n;
    cin >> n;
    int input1, input2;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> input1 >> input2;
        children[input1].push_back(input2);
    }
    bfs(0);
    return 0;
}