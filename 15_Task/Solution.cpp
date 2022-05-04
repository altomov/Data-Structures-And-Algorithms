#include <iostream>
#include <map>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    unordered_multimap<int, int> map;
    int t1, t2, brokenDoors = 0;
    pair<int, int> p;
    vector<int> keys;
    vector<int> doors;
    for (int i = 0; i < n; i++)
    {
        cin >> t1;
        keys.push_back(t1);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> t1;
        doors.push_back(t1);
    }

    for (int i = 0; i < n; i++)
    {
        p.first = keys[i];
        p.second = doors[i];
        map.insert(p);

        auto found = map.find(doors[i]);

        if (found == map.end())
        {
            brokenDoors++;
        }
        else
        {
            map.erase(found);
        }
    }

    cout << brokenDoors << endl;

    return 0;
}