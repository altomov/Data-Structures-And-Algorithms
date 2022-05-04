#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main()
{
    int n, k, temp;
    cin >> n >> k;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        arr.push_back(temp);
    }

    deque<int> window(k);

    long long int sum = 0;

    for (int i = 0; i < k; i++)
    {
        while (!window.empty() && arr[i] <= arr[window.back()])
        {
            window.pop_back();
        }
        window.push_back(i);
    }

    sum = sum + arr[window.front()];

    for (int i = k; i < n; i++)
    {
        if (!window.empty() && window.front() == i - k)
        {
            window.pop_front();
        }
        while (!window.empty() && arr[i] <= arr[window.back()])
        {
            window.pop_back();
        }
        window.push_back(i);
        sum = sum + arr[window.front()];
    }
    cout << sum << endl;
    return 0;
}