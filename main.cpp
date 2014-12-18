#include <iostream>
#include <cstdlib>
#include <cstdio>
#include "Tictactoe.h"

#define O 1
#define X -1

using namespace std;


int main()
{
    Tictactoe tic;
    int opt=0;
    do
    {
        tic.clearScreen();
        fflush(stdin);

        cout<<"\t\t      .......:WElcome to Tictactoe:......"<<endl;
        cout<<"\t\t\t\tBeta Realease 1.0"<<endl<<endl<<endl;
        cout<<"1. Player versus Player"<<endl;
        cout<<"2. Player versus AI"<<endl;
        cout<<"3. Player versus Player LAN"<<endl;
        cout<<"5. EXIT"<<endl;
        cout<<"Choose Gamemode: ";
        cin>>opt;
        switch(opt)
        {
        case 1://pvp
            tic.clearScreen();
            tic.pvpMenu();
            break;
        case 2://PvAI
            tic.clearScreen();
            tic.pvaiMenu();
            break;
        case 5:
            break;
        default:
            cout<< endl<< "not valid!"<<endl;
        }
    }while(opt not_eq 5);

    //simbolo[0] = 'O', simbolo [1]='X';
}
