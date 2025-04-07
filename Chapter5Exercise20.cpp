/*File Name:Chapter5Exercise20.cpp
Programmer Name:Charles Sherwood
Date:4/2025
Requirements:This program should generate a random 
number and have the user guess it correctly and save
the results of the guess
*/
#include <ctime>
#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

// Prototypes
int Random();
void Welcome();
void SaveScore(const string& name, int tries);
void ReadScores();
void Menu();
void DeleteScores();
void PlayGame();



int main()
{
    srand(time(0));
    Welcome();
    Menu();
    return 0;
}




// Show welcome message
void Welcome()
{
    cout << "-----------------------------------------\n";
    cout << "!!!Welcome To The Number Guessing Game!!!\n";
    cout << "-----------------------------------------\n";
    cout << "This Program Will Generate A Random Number From 1-100 For You To Guess\n";
}



// Menu system with switch statements
void Menu()
{
    int Choice;
    do
    {
        cout << "\n=========== MENU ===========\n";
        cout << "1 - Display Scores\n";
        cout << "2 - Play A Session\n";
        cout << "3 - Delete Old Sessions\n";
        cout << "4 - Exit The Program\n";
        cout << "Enter your choice: ";
        cin >> Choice;

        switch (Choice)
        {
        case 1:
            ReadScores();
            break;

        case 2:
            PlayGame();
            break;

        case 3:
            DeleteScores();
            break;

        case 4:
            cout << "Exiting program. Goodbye!\n";
            break;

        default:
            cout << "Invalid option. Please try again.\n";
        }

    } while (Choice != 4);
}



// Has The Guessing Game inside
void PlayGame()
{
    string Name;
    int Guess;
    int tries = 0;
    int Rand = Random();

    cout << "\nPlease Enter Your Name: ";
    cin.ignore(); // clear leftover newline
    getline(cin, Name);

    do
    {
        cout << "Please Enter Your Guess: ";
        cin >> Guess;
        tries++;

        if (Guess > Rand)
            cout << "**Guess Too High**\n";
        else if (Guess < Rand)
            cout << "**Guess Too Low**\n";
        else
            cout << "!!Correct!!\n";

    } while (Guess != Rand);

    SaveScore(Name, tries);
}




// Generate random number
int Random()
{
    return (rand() % 100 + 1);
}



// Save name and tries to file
void SaveScore(const string& name, int tries)
{
    ofstream file("scores.txt", ios::app);
    if (file.is_open())
    {
        file << name << " - " << tries << " tries\n";
        file.close();
        cout << "**Score saved to scores.txt!**\n";
    }
    else
    {
        cerr << "\nError: Unable to open scores.txt for writing.\n";
    }
}




// Read and print all saved scores
void ReadScores()
{
    ifstream file("scores.txt");

    if (!file.is_open())
    {
        cerr << "\nError: Unable to open scores.txt for reading.\n";
        return;
    }

    cout << "\n===== All Saved Scores =====\n";
    string line;
    while (getline(file, line))
    {
        cout << line << "\n";
    }
    cout << "============================\n";

    file.close();
}



// Delete the scores file
void DeleteScores()
{
    if (remove("scores.txt") == 0)
    {
        cout << "\n**All scores have been deleted!**\n";
    }
    else
    {
        cerr << "Error: Could not delete scores.txt or file does not exist.\n";
    }
}
