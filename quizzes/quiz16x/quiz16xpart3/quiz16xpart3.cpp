/*
> Step #1

Goals:

We’ll start by defining our list of words and writing a random word picker.
Tasks:

First define a namespace named WordList. The starter list of words is: “mystery”, “broccoli” , “account”, “almost”, “spaghetti”, “opinion”, “beautiful”, “distance”, “luggage”. You can add others if you like.
Write a function to pick a random word and display the word picked. Run the program several times to make sure the word is randomized.
Here is a sample output from this step:

Welcome to C++man (a variant of Hangman)
To win: guess the word.  To lose: run out of pluses.

The word is: broccoli
*/


/*
> Step #2

As we develop complex programs, we want to work incrementally, adding one or two things at a time and then making sure they work. What makes sense to add next?

Goals:

Be able to draw the basic state of the game, showing the word as underscores.
Accept a letter of input from the user, with basic error validation.
In this step, we will not yet keep track of which letters the user has entered.

Create a class named Session that will be used to store all of the data the game needs to manage in a game session. For now, we just need to know what the random word is.
Create a function to display the basic state of the game, where the word is displayed as underscores.
Create a function to accept a letter of input from the user. Do basic input validation to filter out non-letters or extraneous input.

Step #3

Now that we can display some game state and get input from the user, let’s integrate that user input into the game.

Goals:

Keep track of which letters the user has guessed.
Display correctly guessed letters.
Implement a basic game loop.
Tasks:

Update the Session class to track which letters have been guessed so far.
Modify the game state function to display both underscores and correctly guessed letters.
Update the input routine to reject letters that have already been guessed.
Write a loop that executes 6 times before quitting (so we can test the above).
In this step, we will not tell the user whether the letter they guessed is in the word (but we will show it as part of the game state display).

The tricky part of this step is deciding how to store information on which letters the user has guessed. 
There are several different viable ways to do this. A hint: there are a fixed number of letters, and you’re going to be doing this a lot.

> Step #4

Goal: Finish the game.

Tasks:

Add in display of total wrong guesses left
Add in display of incorrect letters guessed
Add in win/loss condition and win/loss text.
*/


#include <iostream>
#include <vector>
#include <string>
#include <string_view>
#include <ranges>
#include <algorithm>

#include "Random.h"


namespace Wordlist {
    std::vector<std::string_view> words{ "mystery", "broccoli", "account", "almost", "spaghetti", "opinion", "beautiful", "distance", "luggage" };
    
    std::string_view getRandomWord() {
        return words.at(Random::get(0, std::size(words) - 1));
    }

}

template <typename T>
const bool contains(std::vector<T>& Vec, const T& Element)
{
    if (std::find(Vec.begin(), Vec.end(), Element) != Vec.end())
        return true;

    return false;
}

class Session {
private: 
    std::string_view m_word{};
    std::vector<char> m_lettersGuessed{};
    int m_guesses{};

public:

    char getInput() {
        
        char letter{};

        do {
            std::cout << std::endl;
            std::cout << "Enter your next letter: ";
            std::cin >> letter;
            

            if (letter < 'a' || letter > 'z') {
                std::cout << "Invalid input." << std::endl;
            }
            //user has already used this letter
            else if (contains(m_lettersGuessed, letter)) {
                std::cout << "Already used that letter." << std::endl;
            }
            else {
                std::cout << "You entered: " << letter << std::endl;
            }
        } while ((letter < 'a' || letter > 'z') || contains(m_lettersGuessed, letter));

        return letter;
    }

    void gameState() {
        bool isFinished{ false };
        bool isFound{ false };
        int guessesLeft{ m_guesses };
        std::vector<char> wrongGuesses{};
        std::vector<char> correctGuesses{};

        do {

            char guess{ getInput() };
            isFound = false;

            m_lettersGuessed.push_back(guess);

            std::cout << "The word: ";

            for (char letter : m_word) {
                if (guess == letter) {
                    std::cout << letter;
                    isFound = true;
                }
                else if (contains(correctGuesses, letter)) {
                    std::cout << letter;
                }
                else {
                    std::cout << '_';
                }
            }

            if (!isFound) {
                guessesLeft--;
                wrongGuesses.push_back(guess);
            }
            else {
                correctGuesses.push_back(guess);
            }


            std::cout << " Wrong guesses: ";
            for (int i{ 0 }; i < guessesLeft; i++) {
                std::cout << "+";
            }
            for (char x : wrongGuesses) {
                std::cout << x;
            }


            std::cout << std::endl;

            if (guessesLeft == 0) {
                std::cout << "You lost. The word was: " << m_word << std::endl;
                isFinished = true;
            }
            if (std::size(correctGuesses) == m_guesses) {
                std::cout << "You won!" << std::endl;
                isFinished = true;
            }

        } while (!isFinished);
    }

    std::string_view getWord() const { return m_word; }

    Session() {
        m_word = Wordlist::getRandomWord();
        m_guesses = static_cast<int>(std::size(m_word));
    }

};
int main()
{
    Session s{  };

    std::cout << "Welcome to c++man (a variant of Hangman)\nTo win: guess the word. To lose: run out of pluses.\nThe word is: " << s.getWord() << std::endl;

    s.gameState();

    
}
