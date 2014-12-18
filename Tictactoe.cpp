#include "Tictactoe.h"
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>

#define O 1
#define X -1

#define VBAR char (186)
#define HBAR char (205)
#define CBAR char (206)
using namespace std;
Tictactoe::Tictactoe()
{

    srand((unsigned)time(NULL));
    turn=rand()%2;
    if(turn==0)
    {
        turn=X;
    }
    else
    {
        turn=O;
    }

    p1wins=p2wins=0;

    for(int i=0; i<3; i++)//Inicializamos la matriz en 0's
    {
        for(int j=0; j<3; j++)
        {
            matrix[i][j]=0;
        }
    }

}

Tictactoe::~Tictactoe()
{
    //dtor
}

void Tictactoe::pvaiMenu()
{
    fflush(stdin);
    Tictactoe tic;
    int cont=0, playing, winner=0;
    char resp;
    int flg=0;
    string p1,p2;

    cout<<"Set player 1 name's: ";
    getline(cin, p1);
    setPlayer1(p1);
    fflush(stdin);
    setPlayer2("AI");
    cout<<endl<<endl;
    //system("pause");

    do
    {
        playing=getTurn();
        clearScreen();
        //cout<<endl<<"playin: "<<playing<<" cont: "<<cont<<endl;
        //system("pause");
        if(playing == O)//if player 1
        {

            if (cont>=5)//if prolly winner will compare
            {
                winner=compare();//we compare stuff if winner
                if(winner==1)
                {
                    flg=1;//flag to know when user win this shit..
                    cout<<endl;
                    cout<<"\tThe Score is"<<endl<<endl;
                    cout<<getPlayer1()<<" "<<getP1wins()<<" wins!"<<endl;
                    cout<<getPlayer2()<<" "<<getP2wins()<<" wins!"<<endl;
                    cout<<"Try again? [S/N] "<<endl;
                    cin>>resp;
                    if(resp=='S' or resp=='s')
                    {
                        winner=0;
                        TryAgain();
                        cont=0;
                    }
                    else
                    {
                        TryAgain();
                        winner=1, cont=8;
                    }
                }
                else
                {
                    flg=0;
                }
            }
            if(flg==0)///if no winner, still validate da stuff and keep playin'
            {
                if(validate(playing)==1)//if position is correct//there you insert da stuff
                {
                    /////////CAMBIO DE TURNO///////////
                    if(getTurn()==O)//change to player X
                    {
                        setTurn(X);
                    }
                    else//change to player O
                    {
                        setTurn(O);
                    }
                }
            }
        }
        else//if AI's turn
        {
            if (cont>=5)//if prolly winner will compare
            {
                winner=compare();//we compare stuff if winner
                if(winner==1)
                {
                    flg=1;//flag to know when user win this shit..
                    cout<<endl;
                    cout<<"\tThe Score is"<<endl<<endl;
                    cout<<getPlayer1()<<" "<<getP1wins()<<" wins!"<<endl;
                    cout<<getPlayer2()<<" "<<getP2wins()<<" wins!"<<endl;
                    cout<<"Try again? [S/N] "<<endl;
                    cin>>resp;
                    if(resp=='S' or resp=='s')
                    {
                        winner=0;
                        TryAgain();
                        cont=0;
                    }
                    else
                    {
                        TryAgain();
                        winner=1, cont=8;
                    }
                }
                else
                {
                    flg=0;
                }
            }
            if(flg==0)///if no winner, still validate da stuff and keep playin'
            {
                if(aiValidate(playing)==1)//if position is correct//there you insert da stuff
                {
                    /////////CAMBIO DE TURNO///////////
                    if(getTurn()==O)//change to player X
                    {
                        setTurn(X);
                    }
                    else//change to player O
                    {
                        setTurn(O);
                    }
                }
            }
        }
        if(cont==8)
        {
            clearScreen();
            printMatrix();
            cout<<endl<<"DRAW!!!!"<<endl<<endl;
            cout<<"Try again? [Y/N] "<<endl;
            cin>>resp;
            if(resp=='Y' or resp=='y')
            {
                winner=0;
                TryAgain();
                cont=0;
            }
            else
            {
                TryAgain();
                winner=1, cont=8;//flag to exit this stuff
            }
        }
        else
        {
            cont++;
        }
    }while(cont not_eq 8 or winner not_eq 1);

    clearScreen();
}

void Tictactoe::pvpMenu()
{
    fflush(stdin);
    Tictactoe tic;
    int cont=0, playing, winner=0;
    char resp;
    int flg=0;
    //char simbolo[2];
    string p1,p2;

    cout<<"Set player 1 name's: ";
    getline(cin, p1);
     setPlayer1(p1);
    cout<<"Now set Player 2 name's: ";
    getline(cin, p2);
    setPlayer2(p2);
    cout<<endl<<endl;
    system("pause");

    do
    {
        playing=getTurn();
         clearScreen();

        if (cont>=5)
        {
            winner=compare();//we compare stuff if winner
            if(winner==1)
            {
                flg=1;//flag to know when user win this shit..
                cout<<endl;
                cout<<"\tThe Score is"<<endl<<endl;
                cout<<getPlayer1()<<" "<<getP1wins()<<" wins!"<<endl;
                cout<<getPlayer2()<<" "<<getP2wins()<<" wins!"<<endl;
                cout<<"Try again? [S/N] "<<endl;
                cin>>resp;
                if(resp=='S' or resp=='s')
                {
                    winner=0;
                    TryAgain();
                    cont=0;
                }
                else
                {
                    winner=1, cont=8;
                }
            }
            else
            {
                flg=0;
            }
        }
        if(flg==0)///if no winner, still validate da stuff and keep playin'
        {
            if(validate(playing)==1)//there puts actual player if correct position returns 1 and change turn
            {
                /////////CAMBIO DE TURNO///////////
                if(getTurn()==O)//change to player X
                {
                    setTurn(X);
                }
                else//change to player O
                {
                    setTurn(O);
                }
            }

        }
        if(cont==8)
        {
            clearScreen();
            printMatrix();
            cout<<endl<<"DRAW!!!!"<<endl<<endl;
            cout<<"Try again? [Y/N] "<<endl;
            cin>>resp;
            if(resp=='Y' or resp=='y')
            {
                winner=0;
                TryAgain();
                cont=0;
            }
            else
            {
                winner=1, cont=8;//flag to exit this stuff
            }
        }
        else
        {
            cont++;
        }
    }while(cont not_eq 8 or winner not_eq 1);

    clearScreen();

}

void Tictactoe::clearScreen()
{
    #ifdef WIN32
    system("cls");
    #endif
    #ifdef LINUX
    system ("clear");
    #endif
}


void Tictactoe::TryAgain()//restore to empty
{
    srand((unsigned)time(NULL));
    turn=rand()%2;
    if(turn==0)
    {
        turn=X;
    }
    else
    {
        turn=O;
    }

    for(int i=0; i<3; i++)//Inicializamos la matriz en 0's
    {
        for(int j=0; j<3; j++)
        {
            matrix[i][j]=0;
        }
    }
}

void Tictactoe::printMatrix()
{
    char space[3][3];
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            if(matrix[i][j]==O)
            {
                space[i][j]='O';
            }
            else if(matrix[i][j]==X)
            {
                space[i][j]='X';
            }
            else
            {
                space[i][j]=' ';
            }
        }
    }
    cout<<endl<<endl;
    cout<<"\t\t       1   2   3"<<endl<<endl;
    //cout<<"\t\t\t "<<HBAR<<"   "<<HBAR<<endl;
    cout<<"\t\t   1   "<<space[0][0]<<" "<<VBAR<<" "<<space[0][1]<<" "<<VBAR<<" "<<space[0][2]<<endl;
    cout<<"\t\t      "<<HBAR<<HBAR<<HBAR<<CBAR<<HBAR<<HBAR<<HBAR<<CBAR<<HBAR<<HBAR<<HBAR<<endl;
    cout<<"\t\t   2   "<<space[1][0]<<" "<<VBAR<<" "<<space[1][1]<<" "<<VBAR<<" "<<space[1][2]<<endl;
    cout<<"\t\t      "<<HBAR<<HBAR<<HBAR<<CBAR<<HBAR<<HBAR<<HBAR<<CBAR<<HBAR<<HBAR<<HBAR<<endl;
    cout<<"\t\t   3   "<<space[2][0]<<" "<<VBAR<<" "<<space[2][1]<<" "<<VBAR<<" "<<space[2][2]<<endl;
    //cout<<"\t\t\t "<<HBAR<<"   "<<HBAR<<endl;
}

int Tictactoe::validate(int playing)
{
    int valid=0;
    int line,column;
    string pName;
    char space;
    column=line=0;

    printMatrix();
    if(getTurn()==X)//
    {
        pName=getPlayer2();
        space='X';
    }
    else
    {
        pName=getPlayer1();
        space='O';
    }
    cout<<endl;
    cout<<"Playing "<<pName<<" with "<<space<<endl;

    do
    {
        cout<<"Insert Line: ";
        cin>>line;
        cout<<"Insert Column: ";
        cin>>column;
        if(line>0  and line<4)//Que no este ocupada la casilla
        {
            if( column>0 and column<4)
            {
                line--,column--;
                if(matrix[line][column]!=0)
                {
                    cout<<"This space is already occupied, try again."<<endl;
                }
                else
                {
                    matrix[line][column]=playing;
                    valid=1;
                }
            }
            else
            {
                cout<<"Those coord doesn't exist, try again."<<endl;
            }
        }
        else
        {
            cout<<"Those coord doesn't exist, try again."<<endl;
        }

    }while(valid not_eq 1);//Para que no lo ingrese en una casilla equivocada

    return valid;
}

int Tictactoe::aiValidate(int playing)
{
    int add=0, flag=0;

    /// ///////VALIDATION//////////////////
    for(int i=0; i<3; i++)//Comprueba en Horizontal
    {
        for(int j=0; j<3; j++)
        {

            add+=matrix[i][j];
            if(add==-2)
            {
                for( int k=0 ; k<3 ; k++ )
                {
                    if(matrix[i][k]==0)
                    {
                        matrix[i][k]=playing;
                        if(add==2)
                        {
                            flag=O;
                        }
                        else
                        {
                            flag=X;
                        }
                        flag=1;
                        break;
                    }
                }
            }
            if(add==2)
            {
                for( int k=0 ; k<3 ; k++ )
                {
                    if(matrix[i][k]==0)
                    {
                        matrix[i][k]=playing;
                        if(add==2)
                        {
                            flag=O;
                        }
                        else
                        {
                            flag=X;
                        }
                        flag=1;
                        break;
                    }
                }
                break;
            }
        }
        if(flag==1)
        {
            break;
        }
        add=0;
    }
    add=0;

    if(flag not_eq 1)
    {
        for(int i=0; i<3; i++)//Comprueba en vertical
        {
            for(int j=0; j<3; j++)
            {
                add+=matrix[j][i];
                if(add==-2)
                {
                    for( int k=0 ; k<3 ; k++ )
                    {
                        if(matrix[k][i]==0)
                        {
                            matrix[k][i]=playing;
                            flag=1;
                            break;
                        }
                    }
                    break;
                }
                if(add==2)
                {
                    for( int k=0 ; k<3 ; k++ )
                    {
                        if(matrix[k][i]==0)
                        {
                            matrix[k][i]=playing;
                            flag=1;
                            break;
                        }
                    }
                }

            }
            if(flag==1)
            {
                break;
            }
            add=0;
        }
    }
    /// ///////VALIDATION//////////////////
    add=0;
    if(flag not_eq 1)
    {
        add+=matrix[0][0] + matrix[1][1] + matrix[2][2];//Comprueba diagonal superior izquierda a inferior derecha
        if(add==-2)
        {
            if(matrix[0][0]==0)
            {
                matrix[0][0]=playing;
            }
            else if(matrix[1][1]==0)
            {
                matrix[1][1]=playing;
            }
            else if(matrix[2][2]==0)
            {
                matrix[2][2]=playing;
            }
            flag=1;
        }
        if(add==2)
        {
            if(matrix[0][0]==0)
            {
                matrix[0][0]=playing;
            }
            else if(matrix[1][1]==0)
            {
                matrix[1][1]=playing;
            }
            else if(matrix[2][2]==0)
            {
                matrix[2][2]=playing;
            }
            flag=1;
        }
    }
    add=0;
    if(flag not_eq 1)
    {
        add+=add+=matrix[2][0] + matrix[1][1] + matrix[0][2];//Comprueba diagonal inferior izquierda a superior derecha
        if(add==-2)
        {
            if(matrix[2][0]==0)
            {
                matrix[2][0]=playing;
            }
            else if(matrix[1][1]==0)
            {
                matrix[1][1]=playing;
            }
            else if(matrix[0][2]==0)
            {
                matrix[0][2]=playing;
            }
            flag=1;
        }
        if(add==2)
        {
            if(matrix[2][0]==0)
            {
                matrix[2][0]=playing;
            }
            else if(matrix[1][1]==0)
            {
                matrix[1][1]=playing;
            }
            else if(matrix[0][2]==0)
            {
                matrix[0][2]=playing;
            }
            flag=1;
        }
    }
    if(flag not_eq 1)
    {
        int fl=0;
        int f=0;
        int c=0;
        do
        {
            c=0;
            f=0;
            //cout<<f<<"ASDSADADASDSDASDASDD"<<c<<endl;
            //system("pause");
            srand((unsigned)time(NULL));
            f=rand()%3;
            srand((unsigned)time(NULL));
            c=rand()%3;
            if(matrix[f][c]==0)
            {
                matrix[f][c]=playing;
                fl=1;
                break;
            }
        }while(fl not_eq 1);
    }
    add=0;
    //printMatrix();
    //cout<<endl;
    //system("pause");
    return 1;///&&&&&
    clearScreen();
}

int Tictactoe::compare()
{
    int add=0, flag=0, win=0;
    /// ///////VALIDATION//////////////////
    for(int i=0; i<3; i++)//Comprueba en Horizontal
    {
        for(int j=0; j<3; j++)
        {
            add+=matrix[i][j];
        }
        if(add==3 or add==-3)
        {
            if(add==3)
            {
                flag=O;
            }
            else
            {
                flag=X;
            }
            break;
        }
        add=0;
    }

    for(int i=0; i<3; i++)//Comrueba en Vertical
    {
        for(int j=0; j<3; j++)
        {
            add+=matrix[j][i];
        }
        if(add==3 or add==-3)
        {
            if(add==3)
            {
                flag=O;
            }
            else
            {
                flag=X;
            }
            break;
        }
        add=0;
    }

    add+=matrix[0][0] + matrix[1][1] + matrix[2][2];//Comprueba diagonal superior izquierda a inferior derecha
    if(add==3 or add==-3)
    {
        if(add==3)
        {
            flag=O;
        }
        else
        {
            flag=X;
        }
    }
    add=0;
    add+=add+=matrix[2][0] + matrix[1][1] + matrix[0][2];//Comprueba diagonal inferior izquierda a superior derecha
    if(add==3 or add==-3)
    {
        if(add==3)
        {
            flag=O;
        }
        else
        {
            flag=X;
        }
    }

    clearScreen();

    if(flag==O)
    {
        printMatrix();
        cout<<endl<<endl;
        cout<<"The winner is: "<<getPlayer1()<<endl;
        cout<<endl<<"CONGRATULATIONS!"<<endl;
        setP1wins(1);
        win=1;
    }
    else if(flag==X)
    {
        printMatrix();
        cout<<endl<<endl;
        cout<<"The winner is: "<<getPlayer2()<<endl;
        cout<<endl<<"CONGRATULATIONS!"<<endl;
        setP2wins(1);
        win=1;
    }
    return win;
}


