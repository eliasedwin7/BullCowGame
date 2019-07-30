// BullCowGAme.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*
This is the console executable ,that make use of FBullCow cla

*/

#include <iostream>
#include<string>
#include"FBullCowGame.h"

using FText =std::string;


FBullCowGame BCGame;


bool AskToPlayAgain()
{
	std::cout << "Do want to play again ? \n";
	FText Response = "";
	std::getline(std::cin, Response);
	return ((Response[0] == 'Y') || (Response[0] == 'y'));
}

void PrintIntro()
{
	//Introduce the games
	constexpr int32 WORD_LENGTH = 6;
	std::cout << "\t\tWelcome to Bulls and Cows!\n";
	std::cout << std::endl;
	std::cout << "Can you think of the " << WORD_LENGTH << " letter isogram I'm thinking of?\n";
	return;

}
FText GetGuess()
{
	int32 CurrentTry = BCGame.GetCurrentTry();
	//Get the guess from user
	std::cout<<"Try "<<CurrentTry << ".\tEnter Your Guess : "; 
	FText Guess = "";
	getline(std::cin, Guess);
	return Guess;

}


void PlayGame()
{
		
	int32 limit=BCGame.GetMaxTries();
	//Start the game in loop
	for (int32 count = 1; count <= limit; count++) //TODO Get valid guess
	{
		FText Guess = GetGuess();



		//submit valid guess to game

		FBullCowCount BC_count = BCGame.SubmitGuess(Guess);
		// print bulls and cows
		std::cout << "Bulls = " << BC_count.Bulls;
		std::cout << "\t cows = " << BC_count.Cows << "\n\n";
	}
}


int main()
{
	bool bPlayAgain;
	do
	{
		PrintIntro();
		PlayGame();
		bPlayAgain = AskToPlayAgain();
	} while ((bPlayAgain == 1));
	
	
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
