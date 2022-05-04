#include <iostream>
#include <vector>
#include <algorithm>   
using namespace std;

int count(int* elements, int elementCount, int* Si, int* Pi, int currentRequest)
{
    int c = 0, j = 0;
    auto bound = upper_bound(elements, elements + elementCount, Pi[currentRequest]);
    for (j = 0; j < bound - elements; j++)
    {
        if (Si[currentRequest] - elements[bound - elements - c - 1] >= 0)
        {
            Si[currentRequest] = Si[currentRequest] - elements[bound - elements - c - 1];
            c++;
        }
        else break;
    }
    return c;
}

void input(int* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
}

void input2(int* arr, int size, int* arr2)
{
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i] >> arr2[i];
    }
}

void output(int* elements, int elementCount, int* Si, int* Pi, int requestCount)
{
    for (int j = 0; j < requestCount; j++)
    {
        printf("%i\n", count(elements, elementCount, Si, Pi, j));
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int elementCount, requestCount;
    cin >> elementCount >> requestCount;

    int* elements = new int[elementCount];
    input(elements, elementCount);

    int* Si = new int[requestCount];
    int* Pi = new int[requestCount];

    input2(Si, requestCount, Pi);

    sort(elements, elements + elementCount);

    output(elements, elementCount, Si, Pi, requestCount);

    return 0;
}