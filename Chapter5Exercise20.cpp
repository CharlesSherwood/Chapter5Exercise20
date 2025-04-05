/*File Name:Chapter5Exercise20.cpp
Programmer Name:Charles Sherwood
Date:4/2025
Requirements:This program should generate a random 
number and have the user guess it correctly and save
the results of the guess
*/
#include <ctime>
#include<cstdlib>
#include<string>
#include <iostream>
#include<fstream>
using namespace std;

int Random();
bool repeat();
void Welcome();
void SaveScore(const string& name, int tries);
void ReadScores();
void Menu();


int main()
{
	srand(time(0));
	int Guess;
	string Name;
	Welcome();
	cout << "Please Enter Your Name: ";
	getline(cin, Name);
		int Rand = Random();
		int tries = 0;
		do
		{
			cout << "Please Enter Your Guess:";
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
		Menu();
}

void Menu()
{
	int Choice;
	do
	{
		cout << "1-Display Scores\n";
		cout << "2-Play A New Session\n";
		cout << "3-Delete Old Sessions\n";
		cout << "4-Exit The Program\n";
		cin >> Choice;
		switch (Choice)
		{
		case 1:
		{
			ReadScores();
		}
		break;
		case 2:
		{
			main();
		}
		break;
		case 3:
		{


		}
		break;
		case 4:
		{


		}
		break;
		}
	} while (Choice != 4);
}


int Random()
{
	return (rand() % 100 + 1);
}



bool repeat()
{
	char repeat;
	cin >> repeat;
	return (repeat == 'Y' || repeat == 'y');
}


void Welcome()
{
	cout << "-----------------------------------------\n";
	cout << "!!!Welcome To The Number Guessing Game!!!\n";
	cout << "-----------------------------------------\n";
	cout << "This Program Will Generate A Random Number From 1-100 For You To Guess\n";
}



void SaveScore(const string& name, int tries)
{
	ofstream file("scores.txt", ios::app); // append mode
	if (file.is_open())
	{
		file << name << " - " << tries << " tries\n";
		file.close();
		cout << "**Score saved to scores.txt!**\n";
	}
	else
	{
		cerr << "Error: Unable to open scores.txt for writing.\n";
	}
}



void ReadScores()
{
	ifstream file("scores.txt");

	if (!file.is_open())
	{
		cerr << "Error: Unable to open scores.txt for reading.\n";
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