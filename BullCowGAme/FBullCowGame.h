#pragma once
#include<string>

using FString =std::string;
using int32=int;

struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;

};

class FBullCowGame
{
public:
	FBullCowGame();
	void Reset();//
	int GetMaxTries() const;
	int GetCurrentTry() const;
	bool IsGameWon() const;
	bool CheckGuessValidity(FString);
	FBullCowCount SubmitGuess(FString);


private:
	//Look Constructor
	int MyCurrentTry;
	int MyMaxTries;
	FString MyHiddenWord;


};