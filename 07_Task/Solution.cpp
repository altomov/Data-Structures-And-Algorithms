#include <iostream>
#include <vector>
#include <stack>
#include <deque>
#include <queue>

using namespace std;

int main()
{
    int n, temp;
    cin >> n;
    stack<long long int> voini;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        voini.push(temp);
    }
    deque<int> deq;

    stack<int> positive;
    stack<int> negative;


    while (voini.top() > 0)
    {
        deq.push_front(voini.top());
        voini.pop();
    }

    int top;
    while (!voini.empty())
    {
        while (!voini.empty() && voini.top() < 0)
        {
            negative.push(voini.top());
            voini.pop();
        }

        while (!voini.empty() && voini.top() > 0)
        {
            if (!negative.empty())
            {
                top = abs(negative.top());
                if (voini.top() == top)
                {
                    negative.pop();
                    voini.pop();
                    break;
                }
                if (voini.top() < top)
                {
                    voini.pop();
                    break;
                }
                if (voini.top() > top)
                {
                    negative.pop();
                }
            }
            else
            {
                deq.push_front(voini.top());
                voini.pop();
            }
        }
    }


    queue<int>st2;
    while (!negative.empty())
    {
        st2.push(negative.top());
        negative.pop();
    }
    while (!st2.empty())
    {
        cout << st2.front() << " ";
        st2.pop();
    }

    while (!deq.empty())
    {
        cout << deq.front() << " ";
        deq.pop_front();
    }
    return 0;
}