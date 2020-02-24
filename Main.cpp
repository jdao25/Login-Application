#include <iostream>
#include <chrono>
#include <thread>
#include "Functions.h"
#include "windows.h"
#include "conio.h"

int main()
{
	//Gray out exit button on cmdln to prevent anyone exiting
	HWND hwnd = GetConsoleWindow();
	HMENU hmenu = GetSystemMenu(hwnd, FALSE);
	EnableMenuItem(hmenu, SC_CLOSE, MF_GRAYED);

	std::string id;
	do
	{
		title();
		std::cout << "\nWelcome, please enter your student ID, without the C: ";
		std::cin >> id;
		
		if (id != "something")
		{
			validateID(id);
			std::string user;
			system("CLS");
			signInUser(id);
		}
		//delay 5 seconds then clear the cmdln
		std::this_thread::sleep_until(std::chrono::system_clock::now() + std::chrono::seconds(5));
		system("CLS");
	} while (id != "something");

	return 0;
}