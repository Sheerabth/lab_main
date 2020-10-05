#include <bits/stdc++.h>
using namespace std;

int noOfSwaps(int arr[], int n) {
    pair<int, int> pairArr[n];
    for (int i = 0; i < n; i++) {
        pairArr[i].first = arr[i];
        pairArr[i].second = i;
    }

    sort(pairArr, pairArr + n);
    
    vector<bool> checked(n, false);
    int swapCount = 0;

    for (int i = 0; i < n; i++) {
        if(checked[i] || i == pairArr[i].second)
            continue;

        int noOfCycles = 0;
        int j = i;
        while (!checked[j]) {
            checked[j] = 1;
            j = pairArr[j].second;
            noOfCycles++;
        }

        if (noOfCycles > 0)
            swapCount += (noOfCycles - 1); 
    }
    return swapCount;
}

int main() {
    int n;
    cout << "Enter the no of nodes: ";
    cin >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << noOfSwaps(arr, n);
}