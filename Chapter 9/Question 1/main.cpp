#include "random.cpp"
#include <iostream>
#include <limits>

void guess();
bool playAgain();
void ignoreLine();

int main() {
    std::cout << "Let's play a game. I'm thinking of a number between 1 and 100. You have 7 tries to guess what it is.\n";
    guess();
    while(playAgain()){
        guess();
    }
    return 0;
}

void ignoreLine(){

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void guess() {
    const int random{Random::get(1,100)};
    int x;
    for(int i = 1; i <= 7; ++i) {
        std::cout << "Guess #" << i << ": ";
        std::cin >> x;
        ignoreLine();

        // If there is extraneous input
if (!std::cin) // has a previous extraction failed or overflowed?
{
    if (std::cin.eof()) // if the stream was closed
    {
        exit(0); // shut down the program now
    }

    // yep, so let's handle the failure
    std::cin.clear(); // put us back in 'normal' operation mode
    ignoreLine(); // and remove the bad input
}

        else if(x == random) {
            std::cout << "Congratulations!! YOU WON.\n";
            return;
        } else if(x > random) {
            std::cout << "Your guess is too high.\n";
        } else{
            std::cout << "Your guess is too low.\n";
        }
    }
    std::cout << "I'm sorry, you lost. The number was " << random << ".\n";
}

bool playAgain() {
    char c;
    while(true) {
        std::cout << "Would you like to play again (y/n)? ";
        std::cin >> c;
        ignoreLine();

        if(c == 'n') {
            return false;
        } else if(c == 'y') {
            return true;
        } else {
            std::cout << "Please enter 'y' or 'n': ";
        }
    }
}
