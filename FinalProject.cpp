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
// This will find the state you want and add it to another array then remove it from the electoral array
// current issues are states with spaces so New York
void total(int e[], string s[],int u[], int& total)
{
    string choice;
    int count = 0;
    cin >> choice;
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

    total += e[count];
    u[count] += e[count];
    e[count] = 0;

}

int main(int argc, char* argv[])
{
    int Total = 0;
    string choice;
    string Ttotal = "T";
    const string QUIT = "Q";
    string StateList[STATES] = {};
    int Electoral[STATES] = {};
    int UserTotal[STATES] = {};
    Introduction('*', "Welcome to the 2024 Presidential Election");
    readFile("ListofStates.txt", "electoral.txt", Electoral, StateList);
    //This will let you choose the operation
    while (choice != QUIT)
    {
        cout << "Please make a selection uppercase only ", cin >> choice;
      
        if (choice == Ttotal)
        {
            total(Electoral, StateList,UserTotal, Total);
        }
    }
}

