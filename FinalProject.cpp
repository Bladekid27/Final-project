// Final Project
// Ethan Brown & Armoni Myles

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

void Introduction(char c, string message)
{
    cout << setfill(c) << setw(50) << ' ' << endl;
    cout << setw(45) << message << setw(5) << ' ' << endl;
    cout << setfill(c) << setw(50) << ' ' << endl;
    
}

//Loading the array with state names from a file
bool readFile(string fileName, string states[])
{
    ifstream statesData(fileName);

    if (!statesData)
        return false;

    for (int i = 0; i < 50; i++)
    {
        getline(statesData, states[i]);
        
        // Test to see if the data was loaded correctly. 
        //cout << states[i] << endl;
    }
    return true;
}


int main(int argc, char* argv[])
{
    string stateList[50];

    Introduction('*', "Welcome to the 2024 Presidential Election");
    
    readFile("ListofStates.txt", stateList);

}


