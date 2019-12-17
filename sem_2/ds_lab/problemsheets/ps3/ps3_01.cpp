#include<iostream>
using namespace std;


int main()
{
    short int score[50],tempScore,i;
    cout<<"Enter the scores of 500 students:"<<endl;
    for(i=0;i<10;i++)
    {
input:  cin>>temp_Score;
        if(temp_Score<0||temp_Score>100)
        {
            cout<<"Enter valid score:\n";
            goto input;
        }
        else if(temp_Score>50)
            score[temp_Score-50]++;
    }
    cout<<"The result is:\n";
    for(i=0;i<50;i++)
        cout<<"The frequency of the score "<<i+1<<" is "<<score[i]<<endl;
}
