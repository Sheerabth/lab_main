// Sheerabth O.S. (19pw33)
// Sem 3 Design and Analysis of Algorithms Final Lab Exam

// Program to find the number of lucky elements

#include <iostream>

using namespace std;

bool checkLucky(int num1, int num2) // Function to check if a pair of elements are lucky
{
    if ((num1 > num2) && ((num1 % num2) == 0 || (num2 % num1) == 0))
        return true;
    else return false;
}

int Lucky(int v[], int size) // Returns number of lucky numbers
{
    int count = 0;
    int mid = size / 2;
    for (int i = 0, j = mid; i < mid, j < size; i++, j++) 
    {
        if (checkLucky(v[i], v[j]))
            count++; 
    }
    return count;
}

int main() // Driver code
{
    int size;
    cout << "Enter the size of the array (it should be even): ";
    cin >> size;
    int A[size];
    cout << "Enter the elements of the array\n";
    for (int i = 0; i < size; i++)
        cin >> A[i]; 
    cout << "The number lucky elements are " << Lucky(A, size) << endl;
}