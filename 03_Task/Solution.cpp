#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool groz(pair<pair<double,double>, int> a, pair<pair<double, double>, int> b)
{
    double q = (a.first.first * a.first.first) / a.first.second;
    double p = (b.first.first * b.first.first) / b.first.second;
    if (q > p)return true;
    else if (q == p && a.first.first > b.first.first)return true;
    else return false;
}

int main()
{
    int n;
    cin >> n;
    vector<pair< pair <double, double>, int>> team;

    double comp1, comp2;
    for (int i = 0; i < n; i++)
    {
        cin >> comp1 >> comp2;
        team.push_back(make_pair(make_pair(comp1, comp2), i + 1));
    }

    sort(team.begin(), team.end(), groz);
    

    for (int i = 0; i < (int)team.size(); i++)
    {
        cout << team[i].second << " ";
    }
    return 0;
}