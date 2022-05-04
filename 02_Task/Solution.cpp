#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool criteria(pair<pair<double, double>, int> a, pair<pair<double, double>, int> b)
{
    double effa = (a.first.first * a.first.first) / a.first.second;
    double effb = (b.first.first * b.first.first) / b.first.second;
    if (effa > effb)
    {
        return true;
    }
    else if (effa == effb && a.first.first > b.first.first)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int n;
    cin >> n;
    vector<pair< pair <double, double>, int>> weight;

    double di, time;
    for (int i = 0; i < n; i++)
    {
        cin >> di >> time;
        weight.push_back(make_pair(make_pair(di, time), i + 1));
    }

    sort(weight.begin(), weight.end(), criteria);

    for (int i = 0; i < weight.size(); i++)
    {
        cout << weight[i].second << " ";
    }
    return 0;
}