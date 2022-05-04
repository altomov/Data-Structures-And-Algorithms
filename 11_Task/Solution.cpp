#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <climits>

using namespace std;

int main()
{
    int queriesCount;
    cin >> queriesCount;
    set<int> s;
    int num, maxi = INT_MAX;
    s.insert(0);
    vector<int> store;
    for (size_t i = 0; i < queriesCount; i++)
    {
        cin >> num;
        s.insert(num);
        auto low = --s.lower_bound(num);
        auto up = s.upper_bound(num);

        if (num == *(--s.end()))
        {
            int z = (*low) ^ (num);

            store.push_back(min(z, maxi));
            maxi = min(z, maxi);
        }
        else
        {
            int p = (*low) ^ (num);
            int q = (*up) ^ (num);

            if (p > q && q < maxi)
            {
                store.push_back(q);
                maxi = q;
            }
            else if (p < q && p < maxi)
            {
                store.push_back(p);
                maxi = p;
            }
            else
            {
                store.push_back(maxi);
            }
        }
    }

    for (size_t i = 0; i < store.size(); i++)
    {
        cout << store[i] << endl;
    }
    return 0;
}
