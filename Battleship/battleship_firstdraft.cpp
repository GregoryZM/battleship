#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/*
    Project: Battleship

    Goal: Allow two players to take turns choosing spaces on each others boards
    and seeing if there is a ship in that spot or not. Play the game until one
    person has had all their ships sunk.

    Input (Keyboard) : Ship locations, guesses on the board
    Output (Display) : A board marked with hits, misses, or unknown spots to
    to choose from.
        -Introduction to user
        -Board to user #1 to choose locations of ships
        -Board to user #2 to choose locations of ships
        -Board of user #2 to user #1 to choose shot location
        -Board of user #1 to user #2 to choose shot location
        -Congratulatory message for win
        -Ask for replay

    Constants: PLAYER_COUNT

    Variables: char ship_boards[2][20][10],
                    display_boards [2][20][10],
               int player1_ship1[4],
                   player1_ship2[4],
                   player2_ship1[4],
                   player2_ship2[4],
                   player1_choice[2],
                   player2_choice[2]
               string player1_name,
                      player2_name


    Output:

    Hello! Welcome to Battleship! If you would ever like to quit the game
    please press 'Q'.

    Please choose a name for player one:
    Please choose a name for player two:

    "Player one" please choose where you would like to place your first and
    second submarine (length of two units).by entering the first and last
    position of each ship.

    i.e. Ship 1     Ship 2
         X1: 2      X1: 18
         Y1: 1      Y1: 2
         X2: 3      X2: 18
         Y2: 1      Y2: 3

      X 1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20
    Y
    1   #  O  O  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #
    2   #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  O  #  #
    3   #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  O  #  #
    4   #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #
    5   #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #
    6   #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #
    7   #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #
    8   #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #
    9   #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #
    10  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #

    "Player one" please choose where you would like to place your first and
    second cruiser ships (length of three units) by entering the first and last
    position of each ship.

    i.e. Ship 1     Ship 2
         X1: 3      X1: 15
         Y1: 7      Y1: 10
         X2: 3      X2: 17
         Y2: 9      Y2: 10


      X 1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20
    Y
    1   #  O  O  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #
    2   #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  O  #  #
    3   #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  O  #  #
    4   #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #
    5   #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #
    6   #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #
    7   #  #  O  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #
    8   #  #  O  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #
    9   #  #  O  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #
    10  #  #  #  #  #  #  #  #  #  #  #  #  #  #  O  O  O  #  #  #

    "Player one" please choose where you would like to place your battleship
    (length of five units) by entering the first and last position of the ship.

    i.e. X1: 9
         Y1: 5
         X2: 13
         Y2: 5


      X 1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20
    Y
    1   #  O  O  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #
    2   #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  O  #  #
    3   #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  O  #  #
    4   #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #
    5   #  #  #  #  #  #  #  #  O  O  O  O  O  #  #  #  #  #  #  #
    6   #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #
    7   #  #  O  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #
    8   #  #  O  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #
    9   #  #  O  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #
    10  #  #  #  #  #  #  #  #  #  #  #  #  #  #  O  O  O  #  #  #


    Repeat process for player two...

    "Player one" please choose where you would like to attack.

      X 1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20
    Y
    1   #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #
    2   #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #
    3   #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #
    4   #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #
    5   #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #
    6   #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #
    7   #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #
    8   #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #
    9   #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #
    10  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #

    X: ~5~
    Y: ~3~


      X 1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20
    Y
    1   #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #
    2   #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #
    3   #  #  #  #  X  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #
    4   #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #
    5   #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #
    6   #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #
    7   #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #
    8   #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #
    9   #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #
    10  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #

    You missed!

    Repeat for player two's turn.

*/





int main ( )
{
    const int PLAYER_COUNT = 2;
    
    const char x_grid[] = "  X 1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20";
    
    string player1_name = "",
           player2_name;

    char ship_boards[2][20][10],
         display_boards [2][20][10];

    int  player1_ships[2][4],
         player2_ships[2][4],
         player1_choice[2],
         player2_choice[2];

    cout << "Hello! Welcome to Battleship! If you would ever like to quit the"
         << "game please enter a capital 'Q'." << endl;

    while (player1_name != "Q")
    {
        cout << "Please choose a name for player one (besides Q): ";
        cin >> player1_name;

        cout << endl
             << "Please choose a name for player two (besides Q): ";
        cin >> player2_name;

        cout << player1_name << " please choose where you would like to place"
             << "your first and second submarine (length of two units) by"
             << endl
             << "entering the first and last position of each ship." << endl;

        cout << "i.e. Ship 1     Ship 2" << endl
             << "     X1: 2      X1: 18" << endl
             << "     Y1: 1      Y1: 2" << endl
             << "     X2: 3      X2: 18" << endl
             << "     Y2: 1      Y2: 3" << endl;


    }
    
    cout << x_grid;

           /*
           && player2_name != 'Q' && player1_ships != 'Q'
           && player2_ships != 'Q' && player1_choice != 'Q' &&
           player2_choice != 'Q');
            */









}
