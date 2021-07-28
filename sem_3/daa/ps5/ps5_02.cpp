#include <iostream>
#include <list>
using namespace std;

list<bool> getMaxOfTwo(list<bool> bin1, list<bool> bin2) {
    list<bool> :: iterator it1 = bin1.begin();
    list<bool> :: iterator it2 = bin2.begin();
    while (it1 != bin1.end() || it2 != bin2.end()) {
        if (*it1 ^ *it2) {
            it1++;
            it2++;
        }
        else
            return *it1 ? bin1: bin2;
    }
    return bin1;
}

list<bool> getMax(list<list<bool>> matrix) {
    list<bool> max = matrix.front();
    for (auto list : matrix) {
        max = getMaxOfTwo(max, list);
    }
    return max;
}

int main() {
    int entries, size;
    cout << "Enter the bit size of the binary numbers: ";
    cin >> size;
    cout << "Enter the number of entries: ";
    cin >> entries;
    list<list<bool>> matrix;
    cout << "Enter the binary numbers:\n";
    for (int i = 0; i < entries; i++) {
        list<bool> temp;
        bool ex;
        for (int j = 0; j < size; j++) {
            cin >> ex;
            temp.push_back(ex);
        }
        matrix.push_back(temp);
    }
    list<bool> max = getMax(matrix);
    cout << "The maximim binary number is: ";
    for (auto val : max)
        cout << val << " ";
    cout << endl;
}