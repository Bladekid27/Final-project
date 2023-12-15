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
    cout << "To input a state, enter '\S\'" << endl;
    cout << "To check your total, enter '\T\'" << endl;
    cout << "To check your opponents' total, enter '\O\'" << endl;
    cout << "To end the race, enter '\Q\'" << endl;
    cout << setw(50) << ' ' << endl;
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
void SelectState(int e[], string s[], int u[])
{
    string choices;
    int count = 0;
    cout << "Please select a state: ", cin >> choices;
    //getline(cin, choices);
    for (int line = 0; line < STATES; line++)
    {
        if (s[line] == choices)
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
    int Opponents_Points = {};
    int Total = {};
    for (int row = 0; row < STATES; row++)
    {
        Points_User += u[row];
        Opponents_Points += e[row];
    }

    if (Points_User > Opponents_Points)
    {
        Total += Points_User - Opponents_Points;
        cout << "You've won with a total of " << Points_User << ". You're in the lead by " << Total << " and your opponent has " << Opponents_Points << "votes." << endl;
    }
    else if (Points_User < Opponents_Points)
    {
        Total += Opponents_Points - Points_User;
        cout << "You lost with a total of " << Points_User << " votes. You've lost by " << Total << " and your opponent has " << Opponents_Points << " votes." << endl;
    }
    else
    {
        cout << "You are currently tied. You have " << Points_User << " and your opponent has " << Opponents_Points << " votes." << endl;
    }
}
void User_Total(int u[])
{
    int Total = {};
    for (int row = 0; row < STATES; row++)
    {
        Total += u[row];
    }
    cout << "You currently have a total of: " << Total << " votes." << endl;
}

void OTotal(int e[])
{
    int Total = {};
    for (int row = 0; row < STATES; row++)
    {
        Total += e[row];
    }
    cout << "Your opponent currently has a total of: " << Total << " votes." << endl;
}
int main(int argc, char* argv[])
{
    string choice;
    string T_total = "T";
    string lower_Ttotal = "t";
    string StateChoice = "S";
    string lower_StateChoice = "s";
    string Opponent = "O";
    string lower_Opponent = "o";
    const string QUIT = "Q";
    const string lower_QUIT = "q";
    string StateList[STATES] = {};
    int Electoral[STATES] = {};
    int UserTotal[STATES] = {};

    Introduction('*', "Welcome to the 2024 Presidential Election");
    readFile("ListofStates.txt", "electoral.txt", Electoral, StateList);
    while (choice != QUIT && choice != lower_QUIT)
    {
        cout << "Please make a selection: ", cin >> choice;

        if (choice == StateChoice || choice == lower_StateChoice)
        {
            SelectState(Electoral, StateList, UserTotal);
        }
        else if (choice == QUIT || choice == lower_QUIT)
        {
            Total_Electoral(Electoral, StateList, UserTotal);
        }
        else if (choice == T_total || choice == lower_Ttotal)
        {
            User_Total(UserTotal);
        }
        else if (choice == Opponent || choice == lower_Opponent)
        {
            OTotal(Electoral);
        }
    }
}
