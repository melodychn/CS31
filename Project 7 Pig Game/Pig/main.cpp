//
//  main.cpp
//  Bunco
//
//  Created by Howard Stahl on 1/27/17.
//  Copyright © 2017 Howard Stahl. All rights reserved.
//

#include <iostream>
#include <cassert>
#include "Die.h"
#include "Player.h"
#include "Pig.h"


void clearScreen( );
bool handleComputerPlay( cs31::Pig & game );
void display( cs31::Pig & game, std::string message="", bool checkForGameOver=false );


int main()
{
    using namespace cs31;
    using namespace std;
    
    
    clearScreen();
    
    Pig game;
    int human;
    std::string action, message = "(r)oll (e)ndturn (q)uit: ";
    display( game, message, false );

    
    do
    {
        getline( cin, action );
        while (action.size() == 0)
        {
            getline( cin, action );  // no blank entries allowed....
        }
        switch (action[0])
        {
            default:   // if bad move, nobody moves
                cout << '\a' << endl;  // beep
                continue;
            case 'Q':
            case 'q':
                return 0;
            case 'r':
            case 'R':
                human = game.humanPlay();
                cout << "human rolled:" << human << endl;
                if (human == 1)
                {
                    game.humanEndTurn();
                    display( game );
                    do
                    {
                        if (handleComputerPlay( game ))
                            break;
                    } while (game.computerKeepRolling());
                    game.computerEndTurn();
                    display( game, message, true );
                }
                break;
            case 'e':
            case 'E':
                game.humanEndTurn();
                cout << game.display(  ) << endl;
                do
                {
                    if (handleComputerPlay( game ))
                        break;
                }
                while( game.computerKeepRolling());
                game.computerEndTurn();
                display( game, message, true );
                break;
        }
        
    } while( !game.isGameOver() );
    
    return( 0 );
     
}

/*
int main()
{
    using namespace std;
    using namespace cs31;
    
    Die d;
    Player p;
    Board board, b1;
    Pig game;
    // test code for Die
    for (int i = 1; i <= 100; i++ )
    {
        d.roll();
        int value = d.getValue();
        assert( value >=1 && value <= 6 );
    }
    // test code for Player
    
    assert(p.getScore( ) == 0 ); //test if initial cond is 0
    assert(p.getTotal( ) == 0 ); //test if initial cond is 0
    assert( p.roll( 6 ) == 6 ); //test is roll is correct
    assert( p.roll( 7 ) == 7 ); //test is roll is correct
    assert( p.getScore() == 13 ); //test is getscore is correct
    assert( p.roll( 5 )  == 5 ); //test is roll is correct
    assert( p.getScore() == 18 ); //test is getscore is correct
    assert( p.getTotal() == 0 ); //total should only be updated after endTurn
    p.endTurn();
    assert( p.getScore() == 0 ); //score should be reset after endturn
    assert( p.roll( 4 ) == 4 );//test is roll is correct
    assert( p.getScore() == 4 );//test is getscore is correct
    assert( p.roll( 5 ) == 5 );//test is roll is correct
    assert( p.getScore() == 9 );//test is getscore is correct
    assert( p.roll( 1 ) == 1 );//test is roll is correct
    assert( p.getScore() == 0 ); //test if score gets reset
    assert( p.getTotal() == 18 ); //total should not be updated
    
    // test code for Board
    assert( board.getComputerTotal() == 0 ); //total should be zero at start
    assert( board.getHumanTotal() == 0);//total should be zero at start
    assert( board.getRolledValue() == 0);//rolledvalue should be zero at start
    assert( board.getComputerScore() == 0 ); //computer score should be zero at start
    assert( board.getHumanScore() == 0); //human score should be zero at start
    assert( board.isHumanWinner() == false ); //human has not won yet
    assert( board.isHumanTurn() == true ); //default human's turn
    assert( board.isGameOver() == false ); //game is not over
    board.setComputerTurn();
    board.setComputerTotal(1); //see if total changes
    board.setComputerScore(2); //see if score changes
    board.setHumanScore(30); //should not do anything
    assert(board.getHumanScore()==0); //human score should still be zero
    board.setHumanTurn();
    board.setHumanScore(3);
    board.setHumanTotal(4);
    board.setRolledValue(7);
    board.setComputerScore(20); //should not do anything
    assert( board.getComputerTotal() == 1 ); //see if total is changed
    assert( board.getHumanTotal() == 4); //see if total is changed
    assert( board.getRolledValue() == 7); //see if rolled value is 7
    assert( board.getComputerScore() == 2 ); //see if computer score is updated
    assert( board.getHumanScore() == 3); //see if human score is correct
    assert( board.isHumanWinner() == false ); //no one has won yet
    assert( board.isHumanTurn() == true ); //still human's turn
    assert( board.isGameOver() == false ); //no one's score is above 30

    
    b1.setComputerTurn();
    b1.setComputerTotal(21);
    b1.setComputerScore(24);
    b1.setComputerScore(22);
    b1.setHumanTurn();
    assert( b1.getComputerTotal() == 21 ); //see if total updates correctly
    assert( b1.getComputerScore() == 22 ); //see if score updates correctly
    b1.setHumanScore(23);
    b1.setHumanScore(1);
    b1.setHumanTotal(24);
    b1.setRolledValue(27);
    b1.setRolledValue(250);
    b1.setGameOver(true);
    b1.markComputerAsWinner();
    assert( b1.getComputerTotal() == 21 ); //see if total is correct
    assert( b1.getHumanTotal() == 24); //see if total is correct
    assert( b1.getRolledValue() == 250); //see if rolled value is correct
    assert( b1.getComputerScore() == 22 ); //see if socre is correct
    assert( b1.getHumanScore() == 1); //see is human socre is correct
    assert( b1.isHumanWinner() == false ); //human should not be winner
    assert( b1.isHumanTurn() == true ); //still human's turn
    assert( b1.isGameOver() == true ); //game is over
    
    b1.setComputerTurn();
    b1.setComputerTotal( 60 );
    b1.setComputerScore( 50 );
    b1.setComputerScore(60);
    b1.setRolledValue( 2 );
    assert( b1.getComputerTotal( ) == 21 ); //no change made
    assert( b1.getComputerScore( ) == 22 ); //no change made
    assert( b1.getRolledValue( ) == 250 ); //no change made
    
    
    // test code for Game
    assert( game.isGameOver() == false );//game should not be over when it started
    assert( game.determineGameOutcome() == Pig::GAMEOUTCOME::GAMENOTOVER ); //game should not be over
    game.humanPlay( 5 );
    game.humanEndTurn( );
    game.computerPlay( 5 );
    game.computerEndTurn( );
    assert( game.isGameOver() == false ); //game should not be over
    assert( game.determineGameOutcome() == Pig::GAMEOUTCOME::GAMENOTOVER ); //game should not be over
    game.humanPlay( 5 );
    game.humanPlay( 5 );
    game.humanPlay( 5 );
    game.humanEndTurn( );
    assert( game.isGameOver() == false ); //game should still not be over
    assert( game.determineGameOutcome() == Pig::GAMEOUTCOME::GAMENOTOVER ); //game should not be over
    game.computerPlay( 5 );
    game.computerPlay( 5 );
    game.computerPlay( 5 );
    
    game.computerEndTurn( );
    
    assert( game.isGameOver() == false ); //game is not over yet
    assert( game.determineGameOutcome() == Pig::GAMEOUTCOME::GAMENOTOVER ); //game not over
    game.humanPlay( 5 );
    game.humanPlay( 6 );
    assert( game.determineGameOutcome() == Pig::GAMEOUTCOME::GAMENOTOVER ); //game not over becuase human has to end turn
    game.humanEndTurn( );
    assert( game.isGameOver() == true ); //game is over
    assert( game.determineGameOutcome() == Pig::GAMEOUTCOME::HUMANWONGAME ); //human won game
    
    // once the game is over, scores can't be changed
    game.computerPlay( 6 );
    game.computerPlay( 6 );
    game.computerPlay( 6 );
    game.computerEndTurn( );
    game.humanPlay(10);
    assert( game.isGameOver() == true );
    assert( game.determineGameOutcome() == Pig::GAMEOUTCOME::HUMANWONGAME );
    
    Pig game2;
    game2.humanPlay(30);
    game2.humanEndTurn();
    game2.computerPlay(50);
    game2.computerEndTurn();
    assert(game2.isGameOver()==true); //game should be over
    game2.computerPlay(50);
    assert( game2.determineGameOutcome() == Pig::GAMEOUTCOME::HUMANWONGAME ); //human should win because computer did not end turn
    cout << "all tests passed!" << endl;
    return 0;
    
}
*/
/*
int main(){
    using namespace cs31;
    using namespace std;
    clearScreen();
    
    Die d;
    Player p;
    Board b;
    Pig game;
    
    //test code for die
    for (int i = 0; i < 50; i++) {
        d.roll();
        int a = d.getValue();
        assert(a <= 6 && a >= 1);
    }
    
    //test code for plyaer
    assert(p.getScore() == 0); //starting score is 0
    assert(p.getTotal() == 0); //starting total is 0
    assert(p.roll(2) == 2); //should return 2
    assert(p.getScore() == 2); //current score should be 2
    assert(p.getTotal() == 0); //current total should be 0 because turn not ended
    assert(p.roll(4) == 4); //rolling a 4 should return a 4
    assert(p.getScore() == 6); //total score should be a 6
    assert(p.getTotal() == 0); //total score should still be 0
    p.endTurn();
    assert(p.getTotal() == 6); //total score should be 6 now
    assert(p.getScore() == 0); //score should be 0 (should have been moved to total)
    assert(p.roll(3) == 3); //rolling a 3 should return a 3
    assert(p.getTotal() == 6); //total should be unchanged
    p.endTurn();
    assert(p.getTotal() == 9); //6+3=9
    assert(p.getScore() == 0); //score should be reset
    assert(p.roll(3) == 3);
    assert(p.roll(1) == 1); //should return 1 for rolling a 1
    assert(p.getScore() == 0); //if rolled a 1, score should be set to 0
    p.endTurn();
    assert(p.getTotal() == 9); //score should be unchanged because 1 was rolled
    
    //test code for board
    assert(b.getComputerScore() == 0); //starting value should be 0
    assert(b.getComputerTotal() == 0); //starting value should be 0
    assert(b.getHumanScore() == 0); //starting value should be 0
    assert(b.getHumanTotal() == 0); //starting value should be 0
    assert(b.getRolledValue() == 0); //starting value should be 0
    assert(b.isGameOver() == false); //game should not be over at first
    assert(b.isHumanTurn() == true); //should start out with human's turn
    assert(b.isHumanWinner() == false); //human should not be winner at first
    b.setRolledValue(4); //set rolled value to 4
    assert(b.getRolledValue() == 4); //rolled value should be 4
    b.setHumanScore(10);
    assert(b.getHumanScore() == 10); //human score should be set to 10
    b.setHumanScore(15);
    cout<<b.getHumanScore()<<endl;
    assert(b.getHumanScore() == 25); //check if human score is updated
    b.setHumanTotal(12);
    assert(b.getHumanTotal() == 12); //check if human total is updated
    b.setComputerScore(5);
    assert(b.getComputerScore() == 0); //computer score should still be 0 because currently not the computer's turn
    b.setComputerTotal(13);
    assert(b.getComputerTotal() == 0); //computer total should still be 0 because currently not the computer's turn
    b.setComputerTurn(); //make it the computer's turn
    b.setComputerScore(6);
    assert(b.getComputerScore() == 6); //computer score should be set to 5
    b.setComputerScore(10);
    assert(b.getComputerScore() == 16); //check if computer score is updated
    b.setComputerTotal(14);
    assert(b.getComputerTotal() == 14); //check if computer total is updated
    b.setHumanScore(16);
    assert(b.getHumanScore() == 25); //human score should stay the same because not the human's turn
    b.setHumanTotal(13);
    assert(b.getHumanTotal() == 12); //human total should stay the same because not the human's turn
    b.setGameOver(true);
    b.setComputerScore(4);
    assert(b.getComputerScore() == 16); //computer score should not be updated because game is over
    b.setComputerTotal(4);
    assert(b.getComputerTotal() == 14); //computer total should not be updated because game is over
    b.setHumanScore(3);
    assert(b.getHumanScore() == 25); //human score should stay the same because game is over
    b.setHumanTotal(3);
    assert(b.getHumanTotal() == 12); //human score should stay the same because game is over
    

    //test the computer winning the game
    Pig game1;
    game1.humanPlay(6);
    game1.humanEndTurn();
    game1.computerPlay(6);
    game1.computerPlay(6);
    game1.computerPlay(6);
    game1.computerPlay(6);
    game1.computerPlay(6);
    game1.computerPlay(6);
    assert(game1.isGameOver() == false); //game should not be over yet
    assert(game1.determineGameOutcome() == Pig::GAMEOUTCOME::GAMENOTOVER); //game should not be over yet
    game1.computerEndTurn();
    assert(game1.determineGameOutcome() == Pig::GAMEOUTCOME::COMPUTERWONGAME); //computer should win game
    
    Pig game2; //now test both computer and player have scores of >=30 - human should win
    game2.humanPlay(6);
    game2.humanPlay(6);
    game2.humanPlay(6);
    game2.humanPlay(6);
    game2.humanPlay(6);
    game2.humanPlay(6);
    assert(game2.isGameOver() == false); //game should not be over yet
    assert(game2.determineGameOutcome() == Pig::GAMEOUTCOME::GAMENOTOVER); //game should not be over yet
    game2.humanEndTurn();
    game2.computerPlay(6);
    game2.computerPlay(6);
    game2.computerPlay(6);
    game2.computerPlay(6);
    game2.computerPlay(6);
    game2.computerPlay(6);
    game2.computerEndTurn();
    assert(game2.isGameOver() == true); //game should not be over now
    assert(game2.determineGameOutcome() == Pig::GAMEOUTCOME::HUMANWONGAME); //human should win game
    
    cerr << "All test passed!" << endl;
    return 0;
}
 */
bool handleComputerPlay( cs31::Pig & game )
{
    using namespace std;
    bool result( false );
    if (!game.isGameOver())
    {
        int computer = game.computerPlay();
        cout << "computer rolled:" << computer << endl;
        if (computer == 1)
        {
            result = true;
        }
    }
    return( result );}


void display( cs31::Pig & game, std::string message, bool checkForGameOver )
{
    using namespace std;
    // add this if statement...
    if (!game.isGameOver() || game.determineGameOutcome()== cs31::Pig::COMPUTERWONGAME)
    {
        cout << game.display( message ) << endl;
    }
    
    if (checkForGameOver)
    {
        game.isGameOver();
    }
}



///////////////////////////////////////////////////////////////////////////
//  clearScreen implementations
///////////////////////////////////////////////////////////////////////////

// DO NOT MODIFY OR REMOVE ANY CODE BETWEEN HERE AND THE END OF THE FILE!!!
// THE CODE IS SUITABLE FOR VISUAL C++, XCODE, AND g++ UNDER LINUX.

// Note to Xcode users:  clearScreen() will just write a newline instead
// of clearing the window if you launch your program from within Xcode.
// That's acceptable.

#ifdef _MSC_VER  //  Microsoft Visual C++

#include <windows.h>

void clearScreen()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    DWORD dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
    COORD upperLeft = { 0, 0 };
    DWORD dwCharsWritten;
    FillConsoleOutputCharacter(hConsole, TCHAR(' '), dwConSize, upperLeft,
                               &dwCharsWritten);
    SetConsoleCursorPosition(hConsole, upperLeft);
}

#else  // not Microsoft Visual C++, so assume UNIX interface

#include <cstring>

void clearScreen()  // will just write a newline in an Xcode output window
{
    using namespace std;
    static const char* term = getenv("TERM");
    if (term == nullptr  ||  strcmp(term, "dumb") == 0)
    {
        cout << endl << endl << endl << endl << endl << endl << endl << endl;;
    }
    else
    {
        static const char* ESC_SEQ = "\x1B[";  // ANSI Terminal esc seq:  ESC [
        cout << ESC_SEQ << "2J" << ESC_SEQ << "H" << flush;
    }
}

#endif

