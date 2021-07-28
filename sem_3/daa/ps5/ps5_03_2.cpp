#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    string pattern, input;

    cout << "Enter the pattern: ";
    cin >> pattern;
    cout << "Enter the input: ";
    cin >> input;

    sort(input.begin(), input.end(), [pattern](char a, char b) {
        return pattern.find(a) < pattern.find(b);
    });

    cout << "Sorted String : " << input << endl;
    return 0;
}