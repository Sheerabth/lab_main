#include <iostream>
#include <algorithm>
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


int MergeSort (vector<int>& A) {
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

bool getIndex(vector<int> v, int K) 
{ 
    vector<int> :: iterator it = find(v.begin(), v.end(), K); 
  
    if (it != v.end()) 
        return true;
 
    else
        return false;
} 

int filter (vector<int>& vec, int x){
    MergeSort(vec);
    if (x > vec.back())
        return x + 1;
    x = x + 1;
    for (int available = 0; available = getIndex(vec, x); x++);

    return x;
}

int main() {
    int length, number, x;
    vector<int> vec;
    cout << "Enter the number of elements: ";
    cin >> length;
    cout << "Enter the elements\n";
    for (int i = 0; i < length; i++) {
        cin >> number;
        vec.push_back(number);
    }
    cout << "Enter the number: ";
    cin >> x;
    int result = filter(vec, x);
    cout << result << " is the result\n";
}