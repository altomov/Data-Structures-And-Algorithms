#include <iostream>
#include <vector>
using namespace std;

void merge(long arr[], int p, int q, int r) 
{

    int n1 = q - p + 1;
    int n2 = r - q;

    vector<int> L;
    L.resize(n1);

    vector<int> M;
    M.resize(n2);

    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[p + i];
    }
    for (int j = 0; j < n2; j++)
    {
        M[j] = arr[q + 1 + j];
    }

    int i, j, k;
    i = 0;
    j = 0;
    k = p;

    while (i < n1 && j < n2)
    {
        if (L[i] <= M[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = M[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = M[j];
        j++;
        k++;
    }
}

void mergeSort(long arr[], int l, int r)
{
    if (l < r) {

        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

int main() {
    long n;
    cin >> n;
    long* arr = new long[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    mergeSort(arr, 0, n - 1);

    long k;
    cin >> k;

    long sum = 0;
    for (long i = 0; i < k; i++)
    {
        sum += arr[i];
    }
    std::cout << sum << std::endl;
    return 0;
}