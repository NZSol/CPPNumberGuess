#include <iostream>
#include <ctime>




void PrintIntro(int level)
{
    //Comments pasted to the console
    std::cout << "\n\nHave some maths to figure out\nGet it right to continue onwards.\nYour current stage is: " << level << "\n\n";
}



bool PlayGame(int difficulty)
{



    PrintIntro(difficulty);



    //creation and initialization of ints a, b and c
    const int CodeA = (rand() % (difficulty + difficulty)) + 1, CodeB = (rand() % (difficulty + difficulty)) + 1, CodeC = (rand() % (difficulty + difficulty)) + 1;
    std::cout << CodeA << " " << CodeB << " " << CodeC << std::endl;



    //creation of ints sum and multiple
    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeMult = CodeA * CodeB * CodeC;



    //Send to console telling us the total CodeSum and CodeMultiple, and saying what each is
    std::cout << "There are 3 numbers in the code\n";
    std::cout << "\nThe codes add to: " << CodeSum;
    std::cout << "\nThe codes multiply to: " << CodeMult << std::endl;



    //Store Player Guesses
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;



    //Store sum and mult of player guesses
    int GuessSum = GuessA + GuessB + GuessC;
    int GuessMult = GuessA * GuessB * GuessC;



    //Check players guess = correct
    if (difficulty < 10)
    {
        if (GuessSum == CodeSum && GuessMult == CodeMult)
        {
            std::cout << "\nYou Win";
            return true;
        }
        else
        {
            std::cout << "\nNot quite, you'll have to try again";
            return false;
        }
    }
}




int main()
{
    srand(time(NULL));



    int levelDifficulty = 1;
    const int maxDifficulty = 10;



    while (levelDifficulty <= maxDifficulty)
    {
        bool bLevelComplete = PlayGame(levelDifficulty);
        std::cin.clear();
        std::cin.ignore();



        if (bLevelComplete)
        {
            ++levelDifficulty;
        }
    }
    std::cout << "\nCongrats on getting through the questions!\n";
    return 0;
}