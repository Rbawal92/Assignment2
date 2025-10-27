/*
Name: Raymond Bawal III
Date: October 24, 2025
Section: ITCS 2530 C++
BasicInputAssignment.cpp

A program that does the following:
1.) Create a friendly introduction banner to welcome the user to your program.
Prompt the user for at least three inputs of mixed types (e.g., string name with spaces, int count, double price/time) related to your assigned hobby or interest (as noted in my reply to your Week 00: Student Introduction).
Your code should handle invalid input (refer to the concepts in chapter 3). Note: You can use selection statements for this.
Compute at least one derived value tied to the hobby (e.g., average lap time, total cost, win/loss ratio).

2.) Formatted, readable output:
Present a pretty summary table using setw and alignment. For any floating-point result, use a sensible precision.
Save the pretty formatted report to a file named report.txt.

3.) No Functions, Loops, or Conditionals (except where noted):
Do not use for, while, or any custom functions (if can be used for input validation). Using code that we have not covered in class will result in a significant reduction of your score.
Focus on using only concepts covered in the first 3 chapters of out bookLinks to an external site..
4.)  Use clear and meaningful variable names.
Include comments explaining what your code is doing.
Format your code neatly for readability.
Format your code output neatly as well (including output to the file).
** Copied from assignment instructions above for reference. **

*/

#include <iostream>
#include <string>
#include <iomanip> //Needed for setw manipulator.
#include <fstream>// for report.txt
#include "windows.h" //Needed for system("pause") on Windows OS
using namespace std;
int main()
{
	HANDLE headerColor = GetStdHandle(STD_OUTPUT_HANDLE);
	// handle for console text color changes.
	//Constructors for the input variables.
	//https://www.benryves.com/tutorials/winconsole to help with console text color change and UX design element.
	string videoGame;
	string gamingPlatform;
	string favoriteCharacter;
	int age;
	string programName = "Fun with Video Games and the First Steps of My Journey in UX Design";
	const int childAge = 7; //Constant variable for age calculation my age when I started playing pokemon.
	int ageDifference; //Variable to hold the difference in age between user and me.
	// double values as required for the assignment.
	double gamePrice;
	int hoursPlayed;
	double gameValue; //Variable to hold the value of the game per hour played.


	//Title box for the program.
	SetConsoleTextAttribute(headerColor, 11); //Sets the console text color to light cyan for the title box. A little UX design fun!
	cout << string(90, '*') << endl;
	cout << "*" << setw(89) << "*" << endl; //Title box design.
	cout << "*" << setw(89) << "*" << endl; //Title box design
	cout << "*" << setw(89) << "*" << endl; //Title box design
	//cout << "*" << string(9, ' ') << setw(10) << programName << setw(89) << "*" << endl// Struggled here because the * was ending up on the next line. Due to length of programName.
	cout << "*" << string(9, ' ') << setw(10) << programName << setw(13) << "*" << endl; //Title box design.
	cout << "*" << setw(89) << "*" << endl; //Title box design
	cout << "*" << setw(89) << "*" << endl; //Title box design
	cout << "*" << setw(89) << "*" << endl; //Title box design
	cout << string(90, '*') << endl;


	//
	// \n used to space the input prompts for better readability.
	cout << "\nEnter the name of your favorite video game.\n";
	getline(cin, videoGame);
	cout << "\nEnter the name of your favorite character.\n";
	getline(cin, favoriteCharacter); //Collects the name of the favorite character

	cout << "\nEnter the gaming platform you used to play your favorite game on.\n";
	getline(cin, gamingPlatform);
	cout << "\nEnter your age in years in an integer.\n";
	// validity check for age input.
	if (!(cin >> age)) {
		cout << "\nInvalid input for age. Please restart and enter a whole number (e.g., 33).\n";
		return 0; // stops the program if user typed letters or bad input
	}

	if (age <= 0 || age >= 110) {
		cout << "\nAge must be between 1 and 109. Please restart and try again.\n";
		return 0; // stops the program if age is unrealistic
	}

	cout << "\nThank you for providing your age as " << age << " years old.\n" << endl;
	cout << "\nYou were " << age << " Years old and loved to play the game " << videoGame
		<< " on the game system. " << gamingPlatform << endl;

	ageDifference = age - childAge; //Calculates the difference in age between user and me when I started playing pokemon.
	cout << "\nYour favorite character from that game is " << favoriteCharacter << endl;
	// Conditional to ensure that the age difference is not negative before displaying the result.
	if (ageDifference >= 0) //Ensures that the age difference is not negative.
	{
		cout << "You are " << ageDifference << " years older than I was when I started playing my favorite game! \n" << endl;
	}
	else
	{
		cout << "\nYou were  younger than I was when I started playing my favorite game! \n" << endl;
	}
		

	// Displays my favorite game of all time with a calculation of my age when I started playing the game and the paragraph required.
	cout << "My name is Raymond and my favorite game of all time is Pokemon Red, more for the nostalgia factor.\n"
		<< "My favorite character was Charizard, but I loved Gyarados as well.\n"
		<< "I used to play it on my Gameboy Color when I was the age of " << childAge << " years old!\n"
		<< "I remember one of the first times using dial-up internet to find this cheat!\n"
		<< "There was the rare candy cheat where you could level up your Pokemon instantly!\n"
		<< "To get the rare candies you would have to encounter the glitch Pokemon Missingno.\n"
		<< "Which would appear on the right side of the screen when you surfed along the shore of Cinnabar Island.\n"
		<< "It would duplicate the item in the 6th slot of your inventory!\n"
		<< "What fun times it was!\n" << endl;
	cout << "Thank you for sharing your favorite game " << videoGame << " and character " << favoriteCharacter << " with me!\n" << endl;
	
	cout << "Now lets see if that game was worth buying!\n" << endl;
	cout << "Enter the price you paid for the game in dollars and cents (example 59.99).\n";
	// validity check for game price input.
	if (!(cin >> gamePrice)) {
		cout << "Invalid input for price. Please restart and enter a dollar amount ex 59.99 or 20.00.";
		return 0;
	}
	if (gamePrice < 0.0) {
		cout << " Unless you stole the game price must be a positive dollar amount please try again.";
		return 0;
	}
	cout << "Enter the number of hours you think you played the game in a whole integer.\n";
	// validity check for hours played input.
	if (!(cin >> hoursPlayed)) {
		cout << " Invalid input for hours. Please restart and enter a whole number ex 20 or 15.";
		return 0;
	}
	if (hoursPlayed <= 0) {
		cout << " Hours played must be a positive whole number not a negative please try again.";
		return 0;
	}
	// Sets decimal precision for dollar amounts.
	cout << fixed << setprecision(2); //Sets decimal precision for dollar amounts set precision for safer math.
	cout << "\nYou paid $" << gamePrice << " for " << videoGame << " and have played it for " << hoursPlayed << " hours.\n";
	gameValue = gamePrice / hoursPlayed; //Calculates the value of the game per hour played.
	cout << "\nThat means you have paid $" << gameValue << " per hour of gameplay!\n"
		<< "\nWhen you think about it that is not a bad value for a game!\n" << endl;
	cout << "\nI sure think that Pokemon Red was worth every penny and hour I put into it back in the day!\n" << endl;
	cout <<"UX design is all about user experience and making things enjoyable and fun for the user!\n"
		<< "Just like how video games are designed to be fun and engaging for the player!\n"
		<< "I would consdier the title box of this progam to be a miniscule example of UX design!\n"
		<< "Lets go deeper in to UX design and data to see a summary of some of the cool stuff we learned about eachothers gaming preferneces!\n" << endl;
	system("pause"); // added this so user can read the previous output before clearing the console.
	system("cls"); //Clears the console for better readability of the summary box.I would also consider this a small UX design choice.
	//https://www.geeksforgeeks.org/cpp/how-to-clear-console-in-cpp/ for reference on system("cls") command.

	//Summary box for the program.
	SetConsoleTextAttribute(headerColor, 11); //Same as title box light cyan color for summary box. More fun with UX design!
	cout << string(90, '*') << endl;
	cout << "*" << setw(50) << "Summary of Your Gaming Preferences" << setw(39) << "*" << endl; //Summary box design.
	cout << string(90, '*') << endl;
	// sub columns summary information.
	cout << left << setw(30) << "Data Collected " << setw(40) << "Your Input" << endl;
	cout << string(90, '-') << endl;

	// Data rows for the summary box.
	cout << left << setw(30) << "Favorite Game: " << setw(40) << videoGame << endl;
	cout << left << setw(30) << "Favorite Character: " << setw(40) << favoriteCharacter << endl;
	cout << left << setw(30) << "Gaming Platform: " << setw(40) << gamingPlatform << endl;
	cout << left << setw(30) << "Your Age: " << setw(40) << age << endl;
	cout << left << setw(30) << "Game Price : " << "$" << setw(39) << gamePrice << endl;
	cout << left << setw(30) << "Hours Played: " << setw(40) << hoursPlayed << endl;
	cout << left << setw(30) << "Value per Hour Played: " << "$" << setw(39) << gameValue << endl;
	cout << string(90, '-') << endl;


	// save to report.txt file
	ofstream report("report.txt");
		report << left << setw(30) << "Favorite Game: " << setw(40) << videoGame << endl;
		report << left << setw(30) << "Favorite Character: " << setw(40) << favoriteCharacter << endl;
		report << left << setw(30) << "Gaming Platform: " << setw(40) << gamingPlatform << endl;
		report << left << setw(30) << "Your Age: " << setw(40) << age << endl;
		report << left << setw(30) << "Game Price: " << "$" << setw(39) << gamePrice << endl;
		report << left << setw(30) << "Hours Played: " << setw(40) << hoursPlayed << endl;
		report << left << setw(30) << "Value per Hour Played: " << "$" << setw(39) << gameValue << endl;
		report << string(90, '-') << endl;
		report.close();
		cout << "A summary report has been saved to report.txt\n" << endl;
		// On w3 schools it says best practice to use if and else to check if file opened correctly but, for this assignment I will keep it simple.

	system("pause");

	return 0;


}
	/* Code Below is all the code I deleted and reasoning why. */
	// Line below no longer needed after getline implementation.
		//<< "Example : Super_Mario or Super-Mario.\n" << endl;// Needed because of multiple word games wont show without getLine not until page 156
		
	//Old code needed getline for multiple word inputs.
	//cin >> videoGame >> favoriteCharacter; //Collects the name of the video game and favorite character.
	
	

	
	

	//Old code needed getline for multiple word inputs.
	//cin >> gamingPlatform >> age; //Collects the gaming platform and age of user.
	//Displays a summary of the information collected.



	//getline(cin, gamingPlatform); //Needed to clear the input buffer before getline.
	//cin >> age; //Collects the gaming platform and age of user.


	
//ai copilot was uses mostly for syntax and code structure suggestions and comments which were incredibly helpful.
