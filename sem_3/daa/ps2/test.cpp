#include<iostream>
#include<vector>

using namespace std;

vector<int> print(vector<int> &l) {
    l[0] = 0;
    vector<int> k;
    k.push_back(432);
    k.push_back(23);
    k.push_back(54);
    k.push_back(34);
    k.push_back(65);
    return k;
}

int main() {
    vector<int> l;
    l.push_back(432);
    l.push_back(23);
    l.push_back(54);
    l.push_back(34);
    l.push_back(65);
    for (int i = 0; i < l.size(); i++)
        cout << l[i] << " ";
    cout << endl;
    vector<int> k= print(l);
    for (int i = 0; i < k.size(); i++)
        cout << k[i] << " ";
    cout << endl;
}