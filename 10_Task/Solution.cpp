#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

string decimalToBinary(int number)
{
    string str;
    do
    {
        str = str + to_string(number % 2);
        number /= 2;
    } while (number > 0);

    reverse(str.begin(), str.end());

    auto new_str = std::string(21 - min(21, (int)str.length()), '0') + str;

    return new_str;
}

int main()
{
    int n;
    cin >> n;
    vector<int> elements;
    int temp;
    for (size_t i = 0; i < n; i++)
    {
        cin >> temp;
        elements.push_back(temp);
    }

    set<int> zero;
    int first, second;
    bool help = true;
    for (int i = 0; i < elements.size(); i++)
    {
        first = elements[i];
        for (int j = elements[i]; j >= 0; j--)
        {
            second = j;
            if (first == (first | second))
            {
                zero.insert(j);
            }
        }
    }
    cout << zero.size() << endl;
    return 0;
}