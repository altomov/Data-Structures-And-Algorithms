#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool sortbysec(const pair<int, int>& a,
    const pair<int, int>& b)
{
    return (a.second < b.second);
}

int main()
{
    string lectures;
    cin >> lectures;

    vector<pair<int, int>> store;

    for (int i = 0; i < 62; i++)
    {
        store.push_back(make_pair(0, -1));
    }

    for (int i = 0; i < (int)lectures.length(); i++)
    {
        if ((int)lectures[i] >= '0' && (int)lectures[i] <= '9')
        {
            store[lectures[i] - 48].first++;
            store[lectures[i] - 48].second = i;
        }
        else if ((int)lectures[i] >= 'A' && (int)lectures[i] <= 'Z')
        {
            store[(int)lectures[i] - 55].first++;
            store[(int)lectures[i] - 55].second = i;
        }
        else if ((int)lectures[i] >= 'a' && (int)lectures[i] <= 'z')
        {
            store[(int)lectures[i] - 61].first++;
            store[(int)lectures[i] - 61].second = i;
        }
    }

    sort(store.begin(), store.end(), sortbysec);

    for (int i = 0; i < 62; i++)
    {
        if (store[i].second != -1)
        {
            if (store[i].first == 1)
            {
                cout << store[i].second << " ";
            }
        }
    }
    return 0;
}
