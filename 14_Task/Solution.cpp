#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;


int main() {
    int n;
    cin >> n;
    unordered_map<int, int> map;
    vector<int> v;
    int str, sum = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> str;
        v.push_back(str);
        map.insert(make_pair(str, 0));
    }
       
    for(int i = 0; i < n; i++)
    {
        auto found = map.find(v[i]);
        if(found != map.end())
        {
            map[v[i]]++;
        }
    }
    for(int i = 0; i < n; i++)
    {
        if(map[v[i]] %2 == 1)
        {
            sum = sum + v[i];
        }

    }
    cout << sum << endl;
}
