#include "Functions.h"
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <sstream>


void signInUser(std::string& id)
{
	title();
	std::string user;
	if (!checkForUser(id, user))
	{
		bool idFound = false;
		std::string response;
		do
		{
			system("CLS");
			title();
			std::cout << id << " not found. Are you sure you entered it correctly? ";
			getline(std::cin, response);
			//std::cin.ignore(10000, '\n');
			std::cin.clear();
			if (response[0] == 'n')
			{
				std::cout << "Please enter your student ID, without the C: ";
				std::cin >> id;
				std::cin.ignore(10000, '\n');
				std::cin.clear();
				idFound = checkForUser(id, user);
			}
		} while (response[0] != 'y' && !idFound);
		if (!idFound)
		{
			system("CLS");
			registerNewUser(id, user);
		}
	}
	std::string first, last;
	std::stringstream ss(user);
	ss >> first >> last;
	std::cout << "Welcome " << first << " " << last << "!\n";
	timeStamp(user);
}

bool checkForUser(std::string& id, std::string& user)
{
	bool found = false;
	std::ifstream in;
	
	in.open("Registry.txt");
	while (!found && getline(in, user))
	{
		if(user != "")
			found = user.substr(user.size() - 8, 8) == id;
	}
	return found;
	
}

//Get data from user and store to write to Registry.txt
void registerNewUser(std::string& id, std::string& user)
{
	title();
	std::cout << "Please enter your first name, laste name, and branch: ";
	std::string first, last, branch;
	std::cin >> first >> last >> branch;
	std::cin.ignore(10000, '\n');
	std::cin.clear();
	user = first + " " + last + " " + branch + " " + id;
	addUserToRegistry(user);
}

//Writes out user name, branch, and ID to Registry.xt
void addUserToRegistry(const std::string& user)
{
	std::ofstream inFile;
	inFile.open("Registry.txt", std::fstream::app);

	inFile << user << std::endl;
}

//Writes out a time stamp and user name, id, and branch to SignInSheet.txt
void timeStamp(std::string& user)
{
	std::time_t now = std::time(0);
	char realNow[50];
	ctime_s(realNow, 50, &now);

	std::ofstream outFile;
	outFile.open("SignInSheet.txt", std::fstream::app);
	outFile << std::endl << realNow << user << "\n------------------------------------------";
	outFile.close();
}

void validateID(std::string& id)
{
	bool valid = false;
	while (!valid)
	{
		size_t i = 0;
		size_t size = id.length();
		bool digit = true;
		if (size < 8 || size > 8)
			digit = false;
		while (digit && i < size)
		{
			if (id[i] > 57 || id[i] < 48)
				digit = false;
			i++;
		}
		valid = digit;
		if (!valid)
		{
			std::cout << "Invalid ID entry, pleace try again: ";
			std::cin >> id;
			std::cin.ignore(10000, '\n');
			std::cin.clear();
			valid = (id == "something");
		}
	}
}

void title()
{
	std::cout << "\t----------------------------------------------------------------"
		"\n \t\t\tOCC Veteran's Club lounge login"
		"\n\t----------------------------------------------------------------\n";
}