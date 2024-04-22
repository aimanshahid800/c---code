/******************************************S
                 FUN GAME.
 ********************************************/
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

// Function for the number guessing game
void numberGuessingGame()
{
    srand(time(0));
    int number = rand() % 100;
    int guess, hint;
    int chances = 3;
    cout << "\n\n\t\t\t\t    $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;
    cout << "\t\t\t\t    # ************* NUMBER GUSSING GAME *************# \t\t\t" << endl;
    cout << "\t\t\t\t    $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n\n\n"
         << endl;
    cout << "\t\t\t\tGuess the number between 1 and 100.\n";
    cout << "\t\t\t\t\t You have 3 chances: ";
    while (chances > 0)
    {
        cin >> guess;
        if (guess == number)
        {
            cout << "Congratulations! You guessed the number.\n";
            break;
        }
        else
        {
            chances--;
            if (chances == 0)
            {
                cout << "\t\t\tSorry, you've run out of chances. Better luck next time!\n";
                int playAgain;
                cout << "\t\t\t\tDo you want to play again?.\n\n\t\t\t\t Press 1 for yes and 0 for no: ";
                cin >> playAgain;
                if (playAgain == 1)
                {
                    numberGuessingGame();
                }
                break;
            }
            cout << "\t\t\t\t\t    Incorrect guess.\n";
            cout << "\t\t\t\t\t You have " << chances << " chances left.\n";
            cout << "\t\t\t\t\t    Do you want a hint?\n";
            cout << "\t\t\t\tPress : 1 for yes and 0 for no: ";
            cin >> hint;
            if (hint == 1)
            {
                if (guess < number)
                {
                    cout << "\n\t\t\t\tThe number is between " << guess << " and " << guess + 3 << ": ";
                }
                else
                {
                    cout << "\n\t\t\t\tThe number is between " << guess - 3 << " and " << guess << ": ";
                }
            }
        }
    }
}

char square[10] = {'o', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

int checkwin();
void board();

// Function for the Tic Tac Toe game
void ticTacToeGame()
{
    int player = 1, i, choice;
    char mark;
    do
    {
        board();
        player = (player % 2) ? 1 : 2;

        cout << "Player " << player << ", enter a number:  ";
        cin >> choice;

        mark = (player == 1) ? 'X' : 'O';

        if (choice == 1 && square[1] == '1')
            square[1] = mark;
        else if (choice == 2 && square[2] == '2')
            square[2] = mark;
        else if (choice == 3 && square[3] == '3')
            square[3] = mark;
        else if (choice == 4 && square[4] == '4')
            square[4] = mark;
        else if (choice == 5 && square[5] == '5')
            square[5] = mark;
        else if (choice == 6 && square[6] == '6')
            square[6] = mark;
        else if (choice == 7 && square[7] == '7')
            square[7] = mark;
        else if (choice == 8 && square[8] == '8')
            square[8] = mark;
        else if (choice == 9 && square[9] == '9')
            square[9] = mark;
        else
        {
            cout << "Invalid move ";
            player--;
            cin.ignore();
            cin.get();
        }
        i = checkwin();
        player++;
    } while (i == -1);
    board();
    if (i == 1)
        cout << "\t\t\t\t\t\t ==>\aPlayer " << --player << " win ";
    else
        cout << "\t\t\t\t\t\t ==>\aGame draw";
}

/*********************************************
    FUNCTION TO RETURN GAME STATUS
    1 FOR GAME IS OVER WITH RESULT
    -1 FOR GAME IS IN PROGRESS
    O GAME IS OVER AND NO RESULT
**********************************************/

int checkwin()
{
    if (square[1] == square[2] && square[2] == square[3])
        return 1;
    else if (square[4] == square[5] && square[5] == square[6])
        return 1;
    else if (square[7] == square[8] && square[8] == square[9])
        return 1;
    else if (square[1] == square[4] && square[4] == square[7])
        return 1;
    else if (square[2] == square[5] && square[5] == square[8])
        return 1;
    else if (square[3] == square[6] && square[6] == square[9])
        return 1;
    else if (square[1] == square[5] && square[5] == square[9])
        return 1;
    else if (square[3] == square[5] && square[5] == square[7])
        return 1;
    else if (square[1] != '1' && square[2] != '2' && square[3] != '3' && square[4] != '4' && square[5] != '5' && square[6] != '6' && square[7] != '7' && square[8] != '8' && square[9] != '9')
        return 0;
    else
        return -1;
}

/*******************************************************************
     FUNCTION TO DRAW BOARD OF TIC TAC TOE WITH PLAYERS MARK
********************************************************************/

void board()
{
    system("cls");
    cout << "\n\n\t\t\t\t    $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;
    cout << "\t\t\t\t    # ************* TIC TAC TOE GAME *************# \t\t\t" << endl;
    cout << "\t\t\t\t    $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n\n\n"
         << endl;
    cout << "\t\t\t\t\t   Player 1 (X)  -  Player 2 (O)" << endl
         << endl;
    cout << endl;
    cout << "\t\t\t\t\t\t     |     |     " << endl;
    cout << "\t\t\t\t\t\t  " << square[1] << "  |  " << square[2] << "  |  " << square[3] << endl;
    cout << "\t\t\t\t\t\t_____|_____|_____" << endl;
    cout << "\t\t\t\t\t\t     |     |     " << endl;
    cout << "\t\t\t\t\t\t  " << square[4] << "  |  " << square[5] << "  |  " << square[6] << endl;
    cout << "\t\t\t\t\t\t_____|_____|_____" << endl;
    cout << "\t\t\t\t\t\t     |     |     " << endl;
    cout << "\t\t\t\t\t\t  " << square[7] << "  |  " << square[8] << "  |  " << square[9] << endl;
    cout << "\t\t\t\t\t\t     |     |     " << endl
         << endl;
}

// Function for the palindrome checker game
void palindromeCheckerGame()
{
    string str;
    cout << "\n\n\t\t\t\t  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
    cout << "\t\t\t\t  $************* PALINDROME CHEAKER GAME *************$ \t\t\t" << endl;
    cout << "\t\t\t\t  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n\n"
         << endl;
    cout << "\t\t\t\t\t\t    Enter a string: ";
    cin >> str;
    string rev_str = str;
    reverse(rev_str.begin(), rev_str.end());
    if (str == rev_str)
    {
        cout << "\t\t\t\t\t\tThe string is a palindrome.\n";
    }
    else
    {
        cout << "\t\t\t\t\t\tThe string is not a palindrome.\n";
    }
}

int main()
{
    int choice;
    bool playAgain = true;
    while (playAgain)
    {
        cout << "\t\t\t\t\t########################################" << endl;
        cout << "\t\t\t\t\t# ************* FUN GAMES *************# \t\t\t" << endl;
        cout << "\t\t\t\t\t########################################\n\n\n"
             << endl;
        cout << "\t\t\t\t\t    Which game do you want to play?\n\n";
        cout << "\t\t\t\t1. Number Guessing Game\n";
        cout << "\t\t\t\t2. Tic Tac Toe Game\n";
        cout << "\t\t\t\t3. Palindrome Checker Game\n\n";
        cout << "\t\t\t\t\t\t:If you want to play:\n";
        cout << "\n\n\t\t\t\tNumber Gussing Game Enter: 1\n";
        cout << "\t\t\t\tTic Tac Toe Game Enter: 2\n";
        cout << "\t\t\t\tPalindrome Cheaker Game Enter: 3\n";
        cout << "\n\n\t\t\t\t\t\t  Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            numberGuessingGame();
            break;
        case 2:
            ticTacToeGame();
            break;
        case 3:
            palindromeCheckerGame();
            break;
        default:
            cout << "Invalid choice.\n";
        }
        cout << "\n\n\t\t\t\t  Do you want to play again this game or any other game?";
        cout << "\n\n\t If you want Press (1 for Yes, 0 for No): ";
        cin >> playAgain;
    }

    return 0;
}