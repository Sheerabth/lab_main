#include<iostream>
using namespace std;

class SoccerPlayer
{
    int jersyNo, noOfGoals, noOfAssists;
    public:
        bool operator > (SoccerPlayer&);
        SoccerPlayer& operator = (const SoccerPlayer&);
        friend istream& operator >> (istream&, SoccerPlayer&);
        friend ostream& operator << (ostream&, const SoccerPlayer&);
};

bool SoccerPlayer::operator > (SoccerPlayer &S)
{
    if(noOfGoals + noOfAssists > S.noOfGoals + S.noOfAssists)
        return true;
    else
        return false;
}

SoccerPlayer& SoccerPlayer::operator = (const SoccerPlayer &S)
{
    jersyNo = S.jersyNo;
    noOfGoals = S.noOfGoals;
    noOfAssists = S.noOfAssists;
    return *this;
}

istream& operator >> (istream &in, SoccerPlayer &S)
{
    in.sync();
    cout << "Enter the Jersy Number: ";
    in >> S.jersyNo;
    cout << "Enter the number of goals: ";
    in >> S.noOfGoals;
    cout << "Enter the number of assists: ";
    in >> S.noOfAssists;
    return in;
}

ostream& operator << (ostream &out, const SoccerPlayer  &S)
{
    out << "Jersy Number: " << S.jersyNo << endl;
    out << "Number of goals: " << S.noOfGoals << endl;
    out << "Number of assistes: " << S.noOfAssists << endl;
    return out;
};

int main()
{
    SoccerPlayer S[11];
    cout << "Enter the detais of SoccerPlayers: \n";
    for(int i = 0; i < 11; i++)
    {
        cout << "Enter the details of player "<< i+1 <<endl;
        cin >> S[i];
    }
    SoccerPlayer large = S[0];
    for(int i = 1; i<11 ; i++)
    {
        if(S[i] > large)
            S[i] = large;
    }
    cout << large;
}























