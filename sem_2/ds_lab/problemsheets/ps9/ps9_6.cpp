#include<iostream>
#include"SinglyLinked.hpp"
using namespace std;

void Adjacency(int **mat, int num)
{
	SinglyLinked *Adj = new SinglyLinked[num];
	for(int i = 0; i < num; i++)
	{
		for(int j = 0; j < num; j++)
		{
			if(mat[i][j])
			{
				Adj[i].insEnd(j);
			}
		}
	}
	for(int i = 0; i < num; i++)
	{
		cout << "List in index " << i << endl;
		Adj[i].display();
	}
}

int main()
{
	int num;
	cout << "Enter the number: ";
	cin >> num;
	int **mat = new int*[num];
	cout << "Enter the Adjacency matrix elements:\n";
	for(int i = 0; i < num; i++)
	{
		mat[i] = new int[num];
	}
	for(int i = 0; i < num; i++)
	{
		for(int j = 0; j <  num; j++)
		{
			cin >> mat[i][j];
		}
	}
	Adjacency(mat,num);
	return 0;
}
