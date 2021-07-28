#include <iostream>

using namespace std;

int DivBy5(int n) {
    return (n % 5 == 0) ? 1 + DivBy5(n / 5) : 0; 
}

int minNumber(int current, int sum, int value)
{
    if(sum >= value)
        return current - 1;
    else {
        sum += DivBy5(current);
        return minNumber(current + 1, sum, value);
    }
}

int main()
{
    int val;
    cout << "Please enter the value: ";
    cin >> val;
    int result = minNumber(1, 0, val);
    cout << "The result is " << result << endl;
}