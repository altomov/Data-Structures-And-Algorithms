#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int closestElement(int first, int x, int second)
{
    if (x - first > second - x)
    {
        return second;
    }
    else return first;
}

int binarySearch(int* arr, int x, int l, int r)
{
    int size = r;
    if (x >= arr[size - 1])
    {
        return arr[size - 1];
    }

    int mid;
    while (l < r)
    {
        mid = (l + r) / 2;

        if (arr[mid] == x)
        {
            return arr[mid];
        }

        if (mid < size - 1 && x > arr[mid])
        {
            if (x < arr[mid + 1])
            {
                return closestElement(arr[mid], x, arr[mid + 1]);
            }

            l = mid + 1;
        }
        else
        {
            if (mid > 0 && x > arr[mid - 1])
            {
                return closestElement(arr[mid - 1], x, arr[mid]);
            }
            r = mid;
        }
    }
    return arr[mid];
}

void input(int* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
}

int main()
{
    int topics, teams;

    cin >> topics >> teams;

    int* topicComplexity = new int[topics];
    int* teamKnowledge = new int[teams];

    input(topicComplexity, topics);
    input(teamKnowledge, teams);

    for (int i = 0; i < teams; i++)
    {
        cout << binarySearch(topicComplexity, teamKnowledge[i], 0, topics) << endl;
    }
    return 0;
}