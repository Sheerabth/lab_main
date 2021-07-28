#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int Partition(vector<int>& v, int begin, int end) {
    int& pivot = v[begin];  
    int i = begin;
    int j = end;
    while (i < j && i <=end && j >=begin) {
        while (v[i] <= pivot && i <end) 
            i++;
        while (v[j] > pivot && j >begin)
            j--;
        if (i < j) {
            int temp = v[i];
            v[i] = v[j];
            v[j] = temp;
        }
    }
    int temp = pivot;
    pivot = v[j];
    v[j] = temp;
    return j;
}

void QuickSort(vector<int> &v, int l, int r ) {
    if (l < r) {
        int s = Partition(v, l, r);
        QuickSort(v, l, s-1);
        QuickSort(v, s+1, r);
    }
}

int main() {
    vector<int> v = {1, 2, 2, 4, 5, 5};
    QuickSort(v, 0, v.size() - 1);
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
}