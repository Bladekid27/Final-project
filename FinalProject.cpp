// Final Project
// Ethan Brown & Armoni Myles

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;
const int STATES = 50;
void Introduction(char c, string message)
{
    cout << setfill(c) << setw(50) << ' ' << endl;
    cout << setw(45) << message << setw(5) << ' ' << endl;
    cout << setfill(c) << setw(50) << ' ' << endl;
    // The options in the while list need to be added
}

//Loading the array with state names from a file
bool readFile(string fileName, string Electoral, int e[], string states[])
{
    ifstream statesData(fileName);
    ifstream electoral(Electoral);
    if (!statesData && electoral)
    {
        return false;
    }
    for (int i = 0; i < 50; i++)
    {
        getline(statesData, states[i]);
        electoral >> e[i];
        // Test to see if the data was loaded correctly. 
        //cout << states[i] << endl;
    }
    return true;
}
void SelectState(int e[], string s[],int u[])
{
    string choice;
    int count = 0;
    cout << "Please select a state every state starts with a capital letter ", cin >> choice;
    for (int line = 0; line < STATES; line++)
    {
        if (s[line] == choice)
        {
            line += STATES;
        }
        else
        {
            count++;
        }
    }

    u[count] += e[count];
    e[count] = 0;

}
void Total_Electoral(int e[], string s[], int u[])
{
    int Points_User = {};
    int Oponnents_Points = {};
    int Total = {};
    for (int row = 0; row < STATES; row++)
    {
        Points_User += u[row];
        Oponnents_Points += e[row];
    }

    if (Points_User > Oponnents_Points)
    {
        Total += Points_User - Oponnents_Points;
        cout << "You've won with a total of " << Points_User << " Your in the lead by " << Total << " Your opponent is at " << Oponnents_Points << endl;
    }
    else if (Points_User < Oponnents_Points)
    {
        Total += Oponnents_Points - Points_User;
        cout << "You lossed with a total of " << Points_User << " You've lost by " << Total << " Your opponent is at " << Oponnents_Points << endl;
    }
    else
    {
        cout << "You are currently tied you have " << Points_User <<" Your opponent has " << Oponnents_Points << endl;
    }
}
void User_Total(int u[])
{
    int Total = {};
    for (int row = 0; row < STATES; row++)
    {
        Total += u[row];
    }
    cout << "You currently have a total of " << Total << endl;
}

void OTotal(int e[])
{
    int Total = {};
    for (int row = 0; row < STATES; row++)
    {
        Total += e[row];
    }
    cout << "Your opponent currently has a total of " << Total << endl;
}
int main(int argc, char* argv[])
{
    string choice;
    string Ttotal = "T";
    string StateChoice = "S";
    string Opponent = "O";
    const string QUIT = "Q";
    string StateList[STATES] = {};
    int Electoral[STATES] = {};
    int UserTotal[STATES] = {};
    Introduction('*', "Welcome to the 2024 Presidential Election");
    readFile("ListofStates.txt", "electoral.txt", Electoral, StateList);
    while (choice != QUIT)
    {
        cout << "Please make a selection uppercase only ", cin >> choice;
      
        if (choice == StateChoice)
        {
            SelectState(Electoral, StateList,UserTotal);
        }
        else if (choice == QUIT)
        {
            Total_Electoral(Electoral, StateList, UserTotal);
        }
        else if (choice == Ttotal)
        {
            User_Total(UserTotal);
        }
        else if (choice == Opponent)
        {
            OTotal(Electoral);
        }
    }
}


