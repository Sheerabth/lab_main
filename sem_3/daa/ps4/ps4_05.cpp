#include <iostream>
#include <cmath>
#include <limits.h>

using namespace std;

void merge(int arr[], int start, int mid, int end)
{
    int start2 = mid + 1;

    if (arr[mid] <= arr[start2])
        return;

    while (start <= mid && start2 <= end)
    {

        if (arr[start] <= arr[start2])
            start++;
        else
        {
            int value = arr[start2];
            int index = start2;

            while (index != start)
            {
                arr[index] = arr[index - 1];
                index--;
            }
            arr[start] = value;

            start++;
            mid++;
            start2++;
        }
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

int main()
{
    int test_cases;
    cin >> test_cases;
    while (test_cases--)
    {
        int cost, n, index = 0;
        cin >> n;
        cin >> cost;
        int *arr = new int[n];
        while (index < n)
        {
            int val = 0;
            cin >> val;
            arr[index] = val;
            index++;
        }
        mergeSort(arr, 0, n-1);

        double sum = 0.0;
        sum = (arr[n - 1] - arr[1] + arr[n - 2] - arr[0]) * 2.0;
        sum += (arr[n - 1] - arr[n - 2] + arr[1] - arr[0]) * sqrt(2.0);
        
        long long rounded = ceil(sum);
        cout << rounded * cost << endl;
    }
}