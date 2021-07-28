#include <iostream>
#include <vector>

using namespace std;

int BinarySearch(vector<int>& v, int value, int beg, int end) {
    if (beg <= end) {
        int mid = beg + (end - beg) / 2;
        if (value == v[mid])
            return mid;
        else if (value <= v[mid])
            return BinarySearch(v, value, beg, mid - 1);
        else
            return BinarySearch(v, value, mid + 1, end);
    }
    return -1;
}

int main() {
    vector<int> v = {1, 3, 4, 9, 12, 19};
    cout << BinarySearch(v, 5, 0, v.size() - 1) << endl;
}