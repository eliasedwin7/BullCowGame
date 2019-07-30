#include "FBullCowGame.h"

FBullCowGame::FBullCowGame()
{
	Reset();
}

void FBullCowGame::Reset()
{
	constexpr int Max_Try= 5;
	MyCurrentTry = 1;
	MyMaxTries = Max_Try;
	const FString HIDDEN_WORD = "hay";

	MyHiddenWord = HIDDEN_WORD;
	return;
}

int FBullCowGame::GetMaxTries() const
{

	return MyMaxTries;
}
int FBullCowGame::GetCurrentTry() const
{
	return MyCurrentTry;
}
bool FBullCowGame::IsGameWon() const
{
	return false;
}

bool FBullCowGame::CheckGuessValidity(FString)
{
	return false;
}

FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
	MyCurrentTry++;
	FBullCowCount BCcount;
	

	int  WordLength = MyHiddenWord.length();


	for (int32 i = 0; i < WordLength; i++) //i=myhiddenword
	{
		for (int32 j = 0; j < WordLength; j++)//j=guesschar
		{
			if (Guess[j]==MyHiddenWord[i])//if characters are equal
			{
				if (i == j)// if there are in same place
					BCcount.Bulls++;
				else
					BCcount.Cows++;
			}

		}
	}
	return BCcount;
}
