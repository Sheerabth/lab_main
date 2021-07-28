#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<pair<int, char>> result;
    string pattern, input;
    cout << "Enter the pattern of alphabets: ";
    cin >> pattern;
    cout << "Enter the input string: ";
    cin >> input;
    for (int i = 0; i < input.length(); i++) {
        for (int j = 0; j < 26; j++) {
            if (input[i] == pattern[j]) {
                result.push_back(make_pair(j, input[i]));
            }
        }
    }

    sort(result.begin(), result.end());

    for (int i = 0; i < result.size(); i++)
        cout << result[i].second;
    cout << endl;
}