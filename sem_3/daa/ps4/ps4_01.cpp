#include <iostream>
#include <vector>
using namespace std;

int MergeSort(vector<int>&);
int Merge(vector<int>&, vector<int>&, vector<int>&);

int MergeSort (vector<int>& A) {
    int count = 0;
    int n = A.size();
    if (n > 1) {
        vector<int> :: iterator first = A.begin(); 
        vector<int> :: iterator mid = A.begin() + n/2;
        vector<int> :: iterator end = A.end(); 
        vector<int> B(first, mid);
        vector<int> C(mid, end);
        count += MergeSort(B);
        count += MergeSort(C);
        count += Merge(B, C, A);
    }
    return count;
}

int Merge (vector<int>& B, vector<int>& C, vector<int>& A) {
    int i = 0, j = 0, k = 0;
    int count = 0;
    while (i < B.size() && j < C.size()) {
        if (B[i] <= C[j]) {
            A[k++] = B[i++];
        }
        else {
            A[k++] = C[j++];
            count += B.size() - i; 
        }
    }
    while (i < B.size()) {
        A[k++] = B[i++];
    }
    while (j < C.size()) {
        A[k++] = C[j++];
    }
    return count;
}

int main() {
    int length, number;
    vector<int> vec;
    cout << "Enter the number of elements: ";
    cin >> length;
    cout << "Enter the elements\n";
    for (int i = 0; i < length; i++) {
        cin >> number;
        vec.push_back(number);
    }
    cout << "The number of inversions are " << MergeSort(vec) << endl;
}