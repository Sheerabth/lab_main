#include<iostream>
#include<algorithm>

using namespace std;

int Calculate(int n) {
    int i = n-2;

    if (i <= 0) {
        return 0;
    }
    for(; __gcd(n, i) != 1; i--);
    return i;
}

int main() {
    int num;
    cout << "Enter the number to check: ";
    cin >> num;
    int result = Calculate(num);
    if (result)
        cout << result << " is the result\n";
    else
        cout << "A valid result does not exist\n";
}