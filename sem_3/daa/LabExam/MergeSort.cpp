#include <iostream>
#include <vector>
using namespace std;

void Merge (vector<int>& B, vector<int>& C, vector<int>& A) {
    int i = 0, j = 0, k = 0;
    while (i < B.size() && j < C.size()) {
        if (B[i] <= C[j]) {
            A[k++] = B[i++];
        }
        else {
            A[k++] = C[j++];
        }
    }
    while (i < B.size()) {
        A[k++] = B[i++];
    }
    while (j < C.size()) {
        A[k++] = C[j++];
    }
}


void MergeSort (vector<int>& A) {
    int n = A.size();
    if (n > 1) {
        vector<int> :: iterator first = A.begin(); 
        vector<int> :: iterator mid = A.begin() + n/2;
        vector<int> :: iterator end = A.end(); 
        vector<int> B(first, mid);
        vector<int> C(mid, end);
        MergeSort(B);
        MergeSort(C);
        Merge(B, C, A);
    }
}

int main() {
    vector<int> v = {10, 12, 7, 8, 9, 15, 16, 17, 36, 38, 41, 44};
    MergeSort(v);
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
}