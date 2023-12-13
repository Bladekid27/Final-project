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


int main(int argc, char* argv[])
{

    string stateList[STATES] = {};
    int Electoral[STATES] = {};
    Introduction('*', "Welcome to the 2024 Presidential Election");

    readFile("ListofStates.txt","electoral.txt",Electoral, stateList);

}




