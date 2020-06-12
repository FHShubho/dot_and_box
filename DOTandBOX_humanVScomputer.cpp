#include <iostream>
#include <stdlib.h>
#include <windows.h>

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
    int oriR,oriC,oriN;
    oriR=r;
    oriC=c;
    oriN=r*c;
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

    char p,l,lastBox=' ',lastLine=' ';
    int m,n,y,e=0, lastPlayer = 0;
    y=oriN+65;
    int score1=0,score2=0, player=1, turn, again;

    //playing the game
    while (e < total)
    {
        cout << endl;
        //scorecard
        cout << "Last move: ";
        if(lastPlayer==1)
        {
            cout << "Human - ";
        }
        else if(lastPlayer==2)
        {
            cout << "Computer - ";
        }
        cout << lastBox << " " << lastLine << endl;
        cout << "::::::::Score::::::::" << endl;
        cout << "Human: " << score1 << "    " << "Computer: " << score2 << endl << endl;

        //player move
        if(player==1) //Human Player
        {
            cout << "::::Human move::::";
            cout << endl << "Select box: ";
            cin >> p;
            cout << "Select line: ";
            cin >> l;
        }
        else //AI player
        {
            cout << "::::Computer move::::";
            //////////////////////////////////
            char pos,lin;
            int flag= 0;
            
            // searching for 3 lined box 
            for(i=2; i < r ; i+=4)
            {
                for (j=2; j < c; j+=4)
                {
                    if(board[i-2][j]=='-' && board[i+2][j]=='-' && board[i][j-2]=='|' &&  board[i][j+2]==' ')
                    {
                        pos=board[i][j];
                        lin='R';
                        flag=1;
                        break;
                    }

                    else if(board[i-2][j]=='-' && board[i+2][j]=='-' && board[i][j-2]==' ' &&  board[i][j+2]=='|')
                    {
                        pos=board[i][j];
                        lin='L';
                        flag=1;
                        break;
                    }

                    else if(board[i-2][j]=='-' && board[i+2][j]==' ' && board[i][j-2]=='|' &&  board[i][j+2]=='|')
                    {
                        pos=board[i][j];
                        lin='D';
                        flag=1;
                        break;
                    }

                    else if(board[i-2][j]==' ' && board[i+2][j]=='-' && board[i][j-2]=='|' &&  board[i][j+2]=='|')
                    {
                        pos=board[i][j];
                        lin='U';
                        flag=1;
                        break;
                    }
                }       
            }

            //Searching for no line box
            if(flag != 1)
            {
                for(i=2;i<r;i+=4)
                {
                for ( j = 2; j < c; j+=4)
                {
                    if(board[i-2][j]==' ' && board[i+2][j]==' ' && board[i][j-2]==' ' && board[i][j+2]==' ')
                    {
                        pos=board[i][j];
                        lin='U';
                        flag=1;
                        break;
                    }
                }     
                }
            }

            //searching for one line box
            if(flag !=1)
            {
                for(i=2;i<r;i+=4)
                {
                for(j=2;j<c;j+=4)
                {
                    int check=0;
                    // uper line present
                    if(board[i-2][j]=='-' && board[i+2][j]==' ' && board[i][j-2]==' ' &&  board[i][j+2]==' ')
                    {
                        //check the left box
                        if(j-6 >= 0)
                        {
                            if (board[i-2][j-4]=='-' && board[i+2][j-4]=='-')
                            {
                                check=1;
                            }
                            else if(board[i-2][j-4]=='-' && board[i][j-6]=='|')
                            {
                                check=1;
                            }
                            else if(board[i+2][j-4]=='-' && board[i][j-6]=='|')
                            {
                                check=1;
                            }
                            else
                            {
                                check=0;
                            }
                            if(check==0)
                            {
                                if(board[i][j-2]!='-')
                                {
                                    pos=board[i][j];
                                    lin='L';
                                    flag=1;
                                    break;
                                }
                                // pos=board[i][j];
                                // lin='L';
                                // flag=1;
                                // //check=2;
                                // break;
                            }   
                        }
                        //check right box
                        if(flag != 1)
                        {   if (j+6 <= c)
                            {
                                if (board[i-2][j+4]=='-' && board[i+2][j+4]=='-')
                                {
                                    check=1;
                                }
                                else if(board[i-2][j+4]=='-' && board[i][j+6]=='|')
                                {
                                    check=1;
                                }
                                else if(board[i+2][j+4]=='-' && board[i][j+6]=='|')
                                {
                                    check=1;
                                }
                                else
                                {
                                    check=0;
                                }
                                if(check==0)
                                {
                                    if(board[i][j+2]!='-')
                                    {
                                        pos=board[i][j];
                                        lin='R';
                                        flag=1;
                                        break;
                                    }
                                    // pos=board[i][j];
                                    // lin='R';
                                    // flag=1;
                                    // //check=3;
                                    // break;
                                }
                            }
                        } 

                        //check down box
                        if(flag != 1)
                        {   if (i+6 <= r)
                            {
                                if (board[i+6][j]=='-' && board[i+4][j-2]=='|')
                                {
                                    check=1;
                                }
                                else if(board[i+6][j]=='-' && board[i+4][j+2]=='|')
                                {
                                    check=1;
                                }
                                else if(board[i-4][j+2]=='-' && board[i+4][j-2]=='|')
                                {
                                    check=1;
                                }
                                else
                                {
                                    check=0;
                                }
                                
                                if(check==0)
                                {
                                    if(board[i+2][j]!='-')
                                    {
                                        pos=board[i][j];
                                        lin='D';
                                        flag=1;
                                        break;
                                    }           
                                    // pos=board[i][j];
                                    // lin='D';
                                    // flag=1;
                                    // //check=3;
                                    // break;
                                    
                                }
                            }
                        }

                    }

                    //Down line present
                    else if(board[i+2][j]=='-' && board[i-2][j]==' ' && board[i][j-2]==' ' &&  board[i][j+2]==' ')
                    {
                        //check the left box
                        if(j-6 >= 0)
                        {
                            if (board[i-2][j-4]=='-' && board[i+2][j-4]=='-')
                            {
                                check=1;
                            }
                            else if(board[i-2][j-4]=='-' && board[i][j-6]=='|')
                            {
                                check=1;
                            }
                            else if(board[i+2][j-4]=='-' && board[i][j-6]=='|')
                            {
                                check=1;
                            }
                            else
                            {
                                check=0;
                            }
                            if(check==0)
                            {
                                if(board[i][j-2]!='-')
                                {
                                    pos=board[i][j];
                                    lin='L';
                                    flag=1;
                                    break;
                                }  
                                // pos=board[i][j];
                                // lin='L';
                                // flag=1;
                                // //check=2;
                                // break;
                            }   
                        }
                        //check right box
                        if(flag != 1)
                        {   if (j+6 <= c)
                            {
                                if (board[i-2][j+4]=='-' && board[i+2][j+4]=='-')
                                {
                                    check=1;
                                }
                                else if(board[i-2][j+4]=='-' && board[i][j+6]=='|')
                                {
                                    check=1;
                                }
                                else if(board[i+2][j+4]=='-' && board[i][j+6]=='|')
                                {
                                    check=1;
                                }
                                else
                                {
                                    check=0;
                                }
                                if(check==0)
                                {
                                    if(board[i][j+2]!='-')
                                    {
                                        pos=board[i][j];
                                        lin='R';
                                        flag=1;
                                        break;
                                    }  
                                    // pos=board[i][j];
                                    // lin='R';
                                    // flag=1;
                                    // //check=3;
                                    // break;
                                }
                            }
                        }

                        //check upper box
                        if(flag != 1)
                        {   if (i-6 <= r)
                            {
                                if (board[i-6][j]=='-' && board[i-4][j-2]=='|')
                                {
                                    check=1;
                                }
                                else if(board[i-6][j]=='-' && board[i-4][j+2]=='|')
                                {
                                    check=1;
                                }
                                else if(board[i-4][j+2]=='-' && board[i-4][j-2]=='|')
                                {
                                    check=1;
                                }
                                else
                                {
                                    check=0;
                                }
                                
                                if(check==0)
                                {
                                    if(board[i-2][j]!='-')
                                    {
                                        pos=board[i][j];
                                        lin='U';
                                        flag=1;
                                        break;
                                    }  
                                    // pos=board[i][j];
                                    // lin='U';
                                    // flag=1;
                                    // //check=3;
                                    // break;
                                }
                            }
                        }

                    }

                    //Left line present
                    else if(board[i-2][j]==' ' && board[i+2][j]==' ' && board[i][j-2]=='|' &&  board[i][j+2]==' ')
                    {
                        //check down box
                        if(flag != 1)
                        {   if (i+6 <= r)
                            {
                                if (board[i+6][j]=='-' && board[i+4][j-2]=='|')
                                {
                                    check=1;
                                }
                                else if(board[i+6][j]=='-' && board[i+4][j+2]=='|')
                                {
                                    check=1;
                                }
                                else if(board[i-4][j+2]=='-' && board[i+4][j-2]=='|')
                                {
                                    check=1;
                                }
                                else
                                {
                                    check=0;
                                }
                                
                                if(check==0)
                                {
                                    if(board[i+2][j]!='-')
                                    {
                                        pos=board[i][j];
                                        lin='D';
                                        flag=1;
                                        break;
                                    }  
                                    // pos=board[i][j];
                                    // lin='D';
                                    // flag=1;
                                    // //check=3;
                                    // break;
                                }
                            }
                        }
                        //check right box
                        if(flag != 1)
                        {   if (j+6 <= c)
                            {
                                if (board[i-2][j+4]=='-' && board[i+2][j+4]=='-')
                                {
                                    check=1;
                                }
                                else if(board[i-2][j+4]=='-' && board[i][j+6]=='|')
                                {
                                    check=1;
                                }
                                else if(board[i+2][j+4]=='-' && board[i][j+6]=='|')
                                {
                                    check=1;
                                }
                                else
                                {
                                    check=0;
                                }
                                if(check==0)
                                {
                                    if(board[i][j+2]!='-')
                                    {
                                        pos=board[i][j];
                                        lin='R';
                                        flag=1;
                                        break;
                                    }  
                                    // pos=board[i][j];
                                    // lin='R';
                                    // flag=1;
                                    // //check=3;
                                    // break;
                                }
                            }
                        } 

                        //check upper box
                        if(flag != 1)
                        {   if (i-6 <= r)
                            {
                                if (board[i-6][j]=='-' && board[i-4][j-2]=='|')
                                {
                                    check=1;
                                }
                                else if(board[i-6][j]=='-' && board[i-4][j+2]=='|')
                                {
                                    check=1;
                                }
                                else if(board[i-4][j+2]=='-' && board[i-4][j-2]=='|')
                                {
                                    check=1;
                                }
                                else
                                {
                                    check=0;
                                }
                                
                                if(check==0)
                                {
                                    if(board[i-2][j]!='-')
                                    {
                                        pos=board[i][j];
                                        lin='U';
                                        flag=1;
                                        break;
                                    }  
                                    // pos=board[i][j];
                                    // lin='U';
                                    // flag=1;
                                    // //check=3;
                                    // break;
                                }
                            }
                        }

                    }

                    //Right line present
                    else if(board[i-2][j]=='-' && board[i+2][j]==' ' && board[i][j-2]==' ' &&  board[i][j+2]=='|')
                    {
                        //check down box
                        if(flag != 1)
                        {   if (i+6 <= r)
                            {
                                if (board[i+6][j]=='-' && board[i+4][j-2]=='|')
                                {
                                    check=1;
                                }
                                else if(board[i+6][j]=='-' && board[i+4][j+2]=='|')
                                {
                                    check=1;
                                }
                                else if(board[i-4][j+2]=='-' && board[i+4][j-2]=='|')
                                {
                                    check=1;
                                }
                                else
                                {
                                    check=0;
                                }
                                
                                if(check==0)
                                {
                                    if(board[i+2][j]!='-')
                                    {
                                        pos=board[i][j];
                                        lin='D';
                                        flag=1;
                                        break;
                                    }  
                                    // pos=board[i][j];
                                    // lin='D';
                                    // flag=1;
                                    // //check=3;
                                    // break;
                                }
                            }
                        }
                        //check the left box
                        if(j-6 >= 0)
                        {
                            if (board[i-2][j-4]=='-' && board[i+2][j-4]=='-')
                            {
                                check=1;
                            }
                            else if(board[i-2][j-4]=='-' && board[i][j-6]=='|')
                            {
                                check=1;
                            }
                            else if(board[i+2][j-4]=='-' && board[i][j-6]=='|')
                            {
                                check=1;
                            }
                            else
                            {
                                check=0;
                            }
                            if(check==0)
                            {
                                if(board[i][j-2]!='-')
                                    {
                                        pos=board[i][j];
                                        lin='L';
                                        flag=1;
                                        break;
                                    }  
                                // pos=board[i][j];
                                // lin='L';
                                // flag=1;
                                // //check=2;
                                // break;
                            }   
                        }

                        //check upper box
                        if(flag != 1)
                        {   if (i-6 <= r)
                            {
                                if (board[i-6][j]=='-' && board[i-4][j-2]=='|')
                                {
                                    check=1;
                                }
                                else if(board[i-6][j]=='-' && board[i-4][j+2]=='|')
                                {
                                    check=1;
                                }
                                else if(board[i-4][j+2]=='-' && board[i-4][j-2]=='|')
                                {
                                    check=1;
                                }
                                else
                                {
                                    check=0;
                                }
                                
                                if(check==0)
                                {
                                    if(board[i-2][j]!='-')
                                    {
                                        pos=board[i][j];
                                        lin='U';
                                        flag=1;
                                        break;
                                    }  
                                    // pos=board[i][j];
                                    // lin='U';
                                    // flag=1;
                                    // //check=3;
                                    // break;
                                }
                            }
                        }

                    }
                }
                }
            }

            //giving score to opponent
            if(flag != 1)
            {
                for(i=2;i<r;i+=4)
                {
                for ( j = 2; j < c; j+=4 )
                {
                    if(board[i-2][j]==' ' || board[i+2][j]==' ' || board[i][j-2]==' ' || board[i][j+2]==' ')
                    {
                        if(board[i-2][j]==' ')
                        {
                            pos=board[i][j];
                            lin='U';
                            flag=1;
                            break;
                        }
                        else if(board[i+2][j]==' ')
                        {
                            pos=board[i][j];
                            lin='D';
                            flag=1;
                            break;
                        }
                        else if(board[i][j-2]==' ')
                        {
                            pos=board[i][j];
                            lin='L';
                            flag=1;
                            break;
                        }
                        else if(board[i][j+2]==' ')
                        {
                            pos=board[i][j];
                            lin='R';
                            flag=1;
                            break;
                        }                                              
                    }
                }     
                }
            }

            p=pos;
            l=lin;
            //////////////////////////////////
            Sleep(1000);
        }
        
        lastBox=p;
        lastLine=l;
    
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
                            lastPlayer=1;
                        }
                        else
                        {
                            player=1;
                            lastPlayer=2;
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
    }

    cout << endl << "Human " << score1 << "    " << "Computer: " << score2 <<endl;
    if (score1>score2)
    {
        cout << "Human Won" << endl;
    }

    else if(score2 > score1)
    {
        cout << "Computer Won" << endl;
    }
    
    else
    {
        cout << "Match Draw" << endl;
    }

    return 0;
}
