#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <cstdlib>
#include <iostream>

using namespace std;

class Tictactoe
{
private:
    string player1,player2,winner;
    int turn, p1wins, p2wins;
public:
    int matrix[3][3];

    Tictactoe();//ctor
    virtual ~Tictactoe();

    void clearScreen();
    void pvpMenu();
    void pvaiMenu();
    void setPlayer1( string p ) { player1 = p; }
    void setPlayer2( string p ) { player2 = p; }
    void setWinner( string w ) { winner = w; }
    void setTurn( int t ) { turn = t; }
    void setP1wins( int w ) { p1wins += w; }
    void setP2wins( int w ) { p2wins += w; }
    void TryAgain();
    int getP1wins() { return p1wins; }
    int getP2wins() { return p2wins; }
    string getPlayer1(){return player1;}
    string getPlayer2(){return player2;}
    string getWinner(){return winner;}
    int getTurn(){return turn;}

    int compare();
    int aiValidate(int);
    int validate(int);
    void printMatrix();
};


#endif // TICTACTOE_H
