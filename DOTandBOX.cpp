//Fahimul Hoque Shubho
#include <iostream>
#include <stdlib.h>

using namespace std;

int main() {

    int c,r,count=65,total;

    cout << "Enter number of rows: ";
    cin >> r;
    //cout << r;
    //system("cls");
    cout << "Enter number of Colums: ";
    cin >> c;
    cout << endl;
    //cout << c;
    total= (r*c)*2+r+c;
    r=r*4+1;
    c=c*4+1;
    int temp1,temp2, temp3, tCount=0;

    char board[r][c];

    int i,j;

    for(i=0;i<r;i++)
    {
        for (j = 0; j < c; j++)
        {
            board[i][j]='s';
        }
        //cout << endl;
    }

    // intitalizing the board
    for(i=0;i<r;i++)
    {
        temp1=i%4;
        temp3=i%2;
        if(temp1==0)
        {
            for (j= 0; j < c; j++)
            {
                temp2=j%4;
                if(temp2==0)
                {
                board[i][j]='O';
                }
                else
                {
                board[i][j]=' ';
                }
            }
        }

        else
        {
            for (j = 0; j < c; j++)
            {
                if(temp3 == 0)
                {
                    if(j==2)
                    {
                        board[i][j]=count;
                        count++;
                        tCount=0;
                    }
                    else if (tCount==3)
                    {
                        board[i][j]=count;
                        tCount=0;
                        count++;
                    }
                    else
                    {
                        board[i][j]=' ';
                        tCount++;
                    }

                }
                else
                {
                    board[i][j]=' ';
                }

            }
        }
        //cout << endl;
        tCount=0;
    }

    system("cls");


    //printing the board for first time
    for(i=0;i<r;i++)
    {
        for (j = 0; j < c; j++)
        {
            cout << board[i][j];
        }
        cout << endl;
    }

    char p,l;
    int m,n,y,e=0;
    int score1=0,score2=0, player=1, turn, again;

    //playing the game
    while (e < total)
    {
        cout << endl;
        //scorecard
        cout << "::::::::Score::::::::" << endl;
        cout << "Player 1: " << score1 << "    " << "Player 2: " << score2 << endl << endl;

        //player move
        if(player==1)
        {
            cout << "::::Player 1 move::::";
        }
        else
        {
            cout << "::::Player 2 move::::";
        }
        

        cout << endl << "Select box: "; //select the box with corresponding alphabets eg,- A/B/C/D
        cin >> p;
        //cout << p <<endl;
        cout << "Select Side(L/R/U/D): "; // sides are as L= left, R= Right, U= Up, D= Down 
        cin >> l;
        //cout << l << endl;
        system("cls");
        again=0;
        turn=0;

        for(i=0;i<r; i++)
        {
        for(j=0;j<c;j++)
        {
            if (board[i][j]==p)
            {
                m=i;
                n=j;

                if(l=='U')
                {
                    m=m-2;
                    //checking if the line is already drawn
                    if(board[m][n]=='-')
                    {
                        cout << "Line already drawn, Choose another" << endl;
                    }
                    else
                    {
                        board[m][n-1]='-';
                        board[m][n]='-';
                        board[m][n+1]='-';
                        //cout << board[m][x];
                        turn=1;
                    }
                }
                else if(l=='D')
                {
                    m=m+2;
                    //checking if the line is already drawn
                    if(board[m][n]=='-')
                    {
                        cout << "Line already drawn, Choose another" << endl;
                    }
                    else
                    {
                        board[m][n-1]='-';
                        board[m][n]='-';
                        board[m][n+1]='-';
                    
                        turn=1;                    
                    }
                }

                else if(l=='L')
                {
                    n=n-2;
                    //checking if the line is already drawn
                    if(board[m][n]=='|')
                    {
                        cout << "Line already drawn, Choose another" << endl;
                    }
                    else
                    {
                        board[m-1][n]='|';
                        board[m][n]='|';
                        board[m+2][n]='|';

                        turn=1;
                    }                  
                }

                else if(l=='R')
                {
                    n=n+2;
                    //checking if the line is already drawn
                    if(board[m][n]=='|')
                    {
                        cout << "Line already drawn, Choose another" << endl;
                    }
                    else
                    {
                        board[m-1][n]='|';
                        board[m][n]='|';
                        board[m+2][n]='|';

                        turn=1;
                    }
                }

                
                

                //update
                if(turn == 1)
                {
                    //to update score
                    if( board[i-2][j]=='-')
                    {
                        if(board[i+2][j]=='-')
                        {
                            if (board[i][j-2]=='|')
                            {
                                if (board[i][j+2]=='|')
                                {
                                    if (player==1){
                                       score1++;
                                    }
                                    else{
                                        score2++;
                                    }
                                    again=1;   
                                }  
                            }   
                        }
                    }

                    if (again==1)
                    {
                       //Do nothing. Repeat player 
                    }
                    else //next turn other player
                    {
                        if(player==1)
                        {
                            player=2;
                        }
                        else
                        {
                            player=1;
                        }
                    }
                    e++;
                } 

                break;
            }
            
        }
        }

        //print the updated board
        for(i=0;i<r;i++)
        {
            for (j = 0; j < c; j++)
            {
                cout << board[i][j];
            }
            cout << endl;
        }
        //cout << endl << "Exit game? (y/n): ";
        //cin >> e;
        //cout << endl;
        //system("cls");
    }


    cout << "Player1: " << score1 << "    " << "Player2: " << score2 <<endl;
    if (score1>score2)
    {
        cout << "Player 1 Won" << endl;
    }

    else if(score2 > score1)
    {
        cout << "Player 2 Won" << endl;
    }
    
    else
    {
        cout << "Match Draw" << endl;
    }
    
    

    return 0;
}
