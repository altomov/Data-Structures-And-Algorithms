#include <bits/stdc++.h>
using namespace std;

priority_queue<int> maxHeap;
priority_queue<int, vector<int>, greater<int>> minHeap;

void addNum(int num)
{
    maxHeap.push(num);
    minHeap.push(maxHeap.top());

    maxHeap.pop();

    if (minHeap.size() > maxHeap.size())
    {
        maxHeap.push(minHeap.top());
        minHeap.pop();
    }
}
double mediana()
{
    if (maxHeap.size() > minHeap.size())
    {
        return maxHeap.top();
    }
    return ((maxHeap.top() + minHeap.top()) / 2.0);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
  	cout << fixed << setprecision(1);
  	
    long long int n;
    cin >> n;
    
    long long int temp = 0;
    vector<double> ans;
    for (long long int i = 0; i < n; i++)
    {
        cin >> temp;
        addNum(temp);
        ans.push_back(mediana());
    }
    for (long long int i = 0; i < (int)ans.size(); i++)
    {
        printf("%0.1f\n", ans[i]);
    }

    return 0;
    return 0;
}