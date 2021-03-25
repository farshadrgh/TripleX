#include <iostream>
#include <ctime>

void Player (int Difficulty)
{
    //Print welcome massages from the terminal
    std::cout << "Hello, You are a secret agent breaking into a level " << Difficulty;
    std::cout << " secure sever room...\nEnter the correct code to continue...\n\n";
}

bool PlayGame(int Difficulty)
{
    Player (Difficulty);

    //Declare 3 number code
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    //Print sum and product to the terminal
    std::cout << "+ The are 3 numbers in the code...\n";
    std::cout << "+ The codes add-up to: " << CodeSum << "\n";
    std::cout << "+ The codes multiply to give: " << CodeProduct << "\n\n";

    //Enter player's guesses
    int GuessA, GuessB, GuessC;
    std::cout << "Please enter your first number...\n";
    std::cin >> GuessA;
    std::cout << "Please enter your second number...\n";
    std::cin >> GuessB;
    std::cout << "Please enter your third number...\n";
    std::cin >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    //check the player's guess
    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "\n*** You entered the right numbers! Well done agent! ***\n\n";
        return true;
    }
    else
    {
        std::cout << "\n*** You entered the wrong numbers! Try again! ***\n\n";
        return false;
    }
}

int main()
{
    srand(time(NULL)); //Create new random sequence based on time of day

    int LevelDifficulty = 1;
    int const MaxDifficulty = 5 ;

    while (LevelDifficulty <= MaxDifficulty) //Loop game until all levels completed
    {
        bool BlevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear(); //Clears any errors
        std::cin.ignore(); //Discards the buffer

        if (BlevelComplete)
        {
            ++LevelDifficulty;
        }
    }
    
    std::cout << "**********************************************************************\n";
    std::cout << "**********************************************************************\n";
    std::cout << "**********************************************************************\n";
    std::cout << "*** Great work agent! You got all the files! Now get out of there! ***\n";
    std::cout << "**********************************************************************\n";
    std::cout << "**********************************************************************\n";
    std::cout << "**********************************************************************\n\n";
    return 0;
}
