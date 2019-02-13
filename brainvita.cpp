#include<iostream>
#include<stdlib.h>
#define clrscr system("cls");

using namespace std;
int main()
{
	//initialisation of the matrix
	int a[8][8];
	int i,j,ch=1;
	for(j=0;j<8;j++)
	{
		a[0][j]=j;
	}
	for(i=0;i<8;i++)
	{
		a[i][0]=i;
	}
	
	//Rules
	printf("\n\n\t\t\t\t\t\tBrainvita\n\n");
	cout << "---------->About\n\n";
	cout << " ->Brainvita, also called Peg Solitaire, is a single person board game.\n";
	cout << "\n ->It involves moving marbles from one position to another position on the board according to rules.\n";
	cout << "\n ->The objective is to have as few marbles as possible at the end of the game.\n";
	cout << "\n -----------> Rules:\n";
	cout << "\n ->The presence of marbles is marked as '1' and the absence is '0'.\n";
	cout << "\n ->Movements are defined for four directions, UP DOWN LEFT RIGHT.\n";
	cout << "\n ->A valid move is defined by:\n";
	cout << "\n				1.A marble present source cell,\n";
	cout << "\n 				2.A marble absent destination cell alternate in any valid direction to the first cell.\n";
	cout << "\n 				3.The adjacent cellbetween the source and the destination must have the marble.\n";
	cout << "\n ----------->Steps:\n";
	cout << "\n 			!! Make sure that all the inputs are integers, any other character would lead to crash of the game.";
	cout << "\n				1.Enter the row of first cell:\n";
	cout << "\n				2.Enter the column of first cell:\n";
	cout << "\n				3.Enter the row of second cell(alternate to the first cell):\n";
	cout << "\n 				4.Enter the column of second cell:\n";
	cout << "\n ->For example;\n";
	for(j=0;j<8;j++)
	{
		a[0][j]=j;
	}
	for(i=0;i<8;i++)
	{
		a[i][0]=i;
	}
	for(i=1;i<=7;i++)
	{
		for(j=1;j<=7;j++)
		{	
			if((i<3 && j<3) || (i<3 && j>5) || (i>5 && j<3) || (i>5 && j>5))
			{
				a[i][j]=7;
			}
			else
				a[i][j]=0;
		}		
	}
	a[4][4]=0;
	a[4][3]=1;
	a[4][2]=1;
	for(i=0;i<=7;i++)
	{
		for(j=0;j<=7;j++)
		{	
				if((i==1 || i==2 || i==6 || i==7) && (j==1 || j==2 || j==6 || j==7))
				{
					printf("     ");
				}
				else
					printf("  %d  ",a[i][j]);
		}
		printf("\n\n\n");
	}
	cout << "\n	1.Enter the row of first cell:4\n";
	cout << "\n	2.Enter the column of first cell:2\n";
	cout << "\n	3.Enter the row of second cell(alternate to the first cell):4\n";
	cout << "\n 	4.Enter the column of second cell:4\n";
	a[4][4]=1;
	a[4][3]=0;
	a[4][2]=0;
	for(i=0;i<=7;i++)
	{
		for(j=0;j<=7;j++)
		{	
				if((i==1 || i==2 || i==6 || i==7) && (j==1 || j==2 || j==6 || j==7))
				{
					printf("     ");
				}
				else
					printf("  %d  ",a[i][j]);
		}
		printf("\n\n\n");
	}
	cout << "\n ->So, apparently, the marble from source cell(4,2) is transferred to the destination cell(4,4) removing the marble of the adjacent cell(4,3).\n";
	cout << "\n ->Similarly, you have to remove as many marbles as possible\n";
	cout << "\n ->I hope You have undersood the game logic, lets start.\n";
	cout << "\n ->To start the game, press 1, else press 0.";
	cin >> ch;
	if(ch==1)
		goto Play;
	else {
		
		cout << "\n -> Thankyou.";
		return 0;
	}
	Play:;		
	for(i=1;i<=7;i++)
	{
		for(j=1;j<=7;j++)
		{	
			if((i<3 && j<3) || (i<3 && j>5) || (i>5 && j<3) || (i>5 && j>5))
			{
				a[i][j]=7;
			}
			else
				a[i][j]=1;
		}		
	}
	a[4][4]=0;
	int count=0,flag=0;
	//-------------------------------------------------------------------------
	//printing the matrix and processing the game
	while(count<=30 && flag==0 )
	{
		clrscr;
		cout << endl << endl <<endl;
		for(i=0;i<=7;i++)
		{
			for(j=0;j<=7;j++)
			{	
				if((i==1 || i==2 || i==6 || i==7) && (j==1 || j==2 || j==6 || j==7))
				{
					printf("     ");
				}
				else
					printf("  %d  ",a[i][j]);
			}
			printf("\n\n\n");
		}
		//next step
		int r1,r2,c1,c2;
		cout << "Enter the start index row and column:";
		cin >> r1 >> c1;
		cout << "Enter the end index row and column:";
		cin >> r2 >> c2;
		flag=0;
		if((((r1==1 || r1==2 || r1==6 || r1==7) && (c1>2 || c1<6)) || (r1>2 && r1<6 && c1>0 && c1<8)) && (((r2==1 || r2==2 || r2==6 || r2==7) && (c2>2 || c2<6)) || (r2>2 && r2<6 && c2>0 && c2<8))){
		 
		
		 //|Checking the area of brainvita board
			
			if(a[r2][c2]==0)//checking if the end index elementis zero or not
			{
				if(r1==r2 && c2==c1-2){a[r2][c2]=1;a[r1][c1]=0;a[r1][c1-1]=0;++count;}//move left
				else if(r1==r2 && c2==c1+2){a[r2][c2]=1;a[r1][c1]=0;a[r1][c1+1]=0;++count;}//move right
				else if(c1==c2 && r2==r1-2){a[r2][c2]=1;a[r1][c1]=0;a[r1-1][c1]=0;++count;}//move up
				else if(c1==c2 && r2==r1+2){a[r2][c2]=1;a[r1][c1]=0;a[r1+1][c1]=0;++count;}//move down
				else{cout << "Invalid move\n";goto label;}
			}
			else{cout << "Destination not empty\n";goto label;}
		}
		else{printf("Invalid indices\n");goto label;}
		clrscr;
		cout << endl << endl <<endl;
		for(i=0;i<=7;i++)
		{
			for(j=0;j<=7;j++)
			{	
				if((i==1 || i==2 || i==6 || i==7) && (j==1 || j==2 || j==6 || j==7))
				{
					printf("     ");
				}
				else
					printf("  %d  ",a[i][j]);
			}
			printf("\n\n\n");
		}
		
		//checking of the end game
		//corners
		//-----------------------------------------------------------
		if(a[1][3]==1)
		{
			if(a[1][4]==0 && a[2][3]==0){flag=1;cout << "1" << " " << "3" << " " << flag <<endl;}
			else{flag=0;cout << "1" << " " << "3" << " " << flag <<endl;goto label;}
		}
		if(a[1][5]==1)
		{
			if(a[1][4]==0 && a[2][5]==0){flag=1;cout << "1" << " " << "5" << " " << flag <<endl;}
			else{flag=0;cout << "1" << " " << "5" << " " << flag <<endl;goto label;}
		}
		if(a[3][1]==1)
		{
			if(a[4][1]==0 && a[3][2]==0){flag=1;cout << "3" << " " << "1" << " " << flag <<endl;}
			else{flag=0;cout << "3" << " " << "1" << " " << flag <<endl;goto label;}
		}
		if(a[5][1]==1)
		{
			if(a[4][1]==0 && a[5][2]==0){flag=1;cout << flag <<endl;}
			else{flag=0;cout << "5" << " " << "1" << " " << flag <<endl;goto label;}
		}
		if(a[3][7]==1)
		{
			if(a[3][6]==0 && a[4][7]==0){flag=1;cout << flag <<endl;}
			else{flag=0;cout << "3" << " " << "7" << " " << flag <<endl;goto label;}
		}
		if(a[5][7]==1)
		{
			if(a[5][6]==0 && a[4][7]==0){flag=1;cout << flag <<endl;}
			else{flag=0;cout << "5" << " " << "7" << " " << flag <<endl;goto label;}
		}
		if(a[7][3]==1)
		{
			if(a[7][4]==0 && a[6][3]==0){flag=1;cout << flag <<endl;}
			else{flag=0;cout << "7" << " " << "3" << " " << flag <<endl;goto label;}
		}
		if(a[7][5]==1)
		{
			if(a[6][5]==0 && a[7][4]==0){flag=1;cout << "7" << " " << "5" << " " << flag <<endl;}
			else{flag=0;cout << "7" << " " << "5" << " " << flag <<endl;goto label;}
		}
		//--------------------------------------------------------------
		//second corners
		//--------------------------------------------------------------
		if(a[2][3]==1)
		{
			if(a[2][4]==0 && a[3][3]==0 && a[1][3]==0){flag=1;cout << "2" << " " << "3" << " " << flag <<endl;}
			else{flag=0;cout << "2" << " " << "3" << " " << flag <<endl;goto label;}
		}
		if(a[2][5]==1)
		{
			if(a[2][4]==0 && a[3][5]==0 && a[1][5]==0){flag=1;cout << flag <<endl;}
			else{flag=0;cout << flag <<endl;goto label;}
		}
		if(a[3][2]==1)
		{
			if(a[4][2]==0 && a[3][3]==0 && a[3][1]==0){flag=1;cout << flag <<endl;}
			else{flag=0;cout << flag <<endl;goto label;}
		}
		if(a[5][2]==1)
		{
			if(a[4][2]==0 && a[5][3]==0 && a[5][1]==0){flag=1;cout << "5" << " " << "2" << " " << flag <<endl;}
			else{flag=0;cout << "5" << " " << "2" << " " << flag <<endl;goto label;}
		}
		if(a[3][6]==1)
		{
			if(a[3][5]==0 && a[4][6]==0 && a[3][7]==0){flag=1;cout << flag <<endl;}
			else{flag=0;cout << flag <<endl;goto label;}
		}
		if(a[5][6]==1)
		{
			if(a[5][5]==0 && a[4][6]==0 && a[5][7]==0){flag=1;cout << flag <<endl;}
			else{flag=0;cout << flag <<endl;goto label;}
		}
		if(a[6][3]==1)
		{
			if(a[5][3]==0 && a[6][4]==0 && a[7][3]==0){flag=1;cout << flag <<endl;}
			else{flag=0;cout << flag <<endl;goto label;}
		}
		if(a[6][5]==1)
		{
			if(a[5][5]==0 && a[6][4]==0 && a[7][5]==0){flag=1;cout << "6" << " " << "5" << " " << flag <<endl;}
			else{flag=0;cout << "6" << " " << "5" << " " << flag <<endl;goto label;}
		}
		//-------------------------------------------------------------
		//corner edge centers
		//-------------------------------------------------------------
		if(a[1][4]==1)
		{
			if(a[1][3]==0 && a[2][4]==0 && a[1][5]==0 ){flag=1;cout << "1" << " " << "4" << " " << flag <<endl;}
			else{flag=0;cout << "1" << " " << "4" << " " << flag <<endl;goto label;}
		}
		if(a[4][1]==1)
		{
			if(a[3][1]==0 && a[4][2]==0 && a[5][1]==0 ){flag=1;cout << flag <<endl;}
			else{flag=0;cout << flag <<endl;goto label;}
		}
		if(a[7][4]==1)
		{
			if(a[7][3]==0 && a[7][5]==0 && a[6][4]==0 ){flag=1;cout << flag <<endl;}
			else{flag=0;cout << flag <<endl;goto label;}
		}
		if(a[4][7]==1)
		{
			if(a[3][7]==0 && a[5][7]==0 && a[4][6]==0 ){flag=1;cout << "4" << " " << "7" << " " << flag <<endl;}
			else{flag=0;cout << "4" << " " << "7" << " " << flag <<endl;goto label;}
		}
		//-------------------------------------------------------------
		//second corner edge centrs
		//-------------------------------------------------------------
		if(a[2][4]==1)
		{
			if(a[2][3]==0 && a[2][5]==0 && a[1][4]==0 && a[3][4]==0){flag=1;cout << "2" << " " << "4" << " " << flag <<endl;}
			else{flag=0;cout << flag <<endl;goto label;}
		}
		if(a[4][2]==1)
		{
			if(a[3][2]==0 && a[5][2]==0 && a[4][1]==0 && a[3][4]==0){flag=1;cout << flag <<endl;}
			else{flag=0;cout << flag <<endl;goto label;}
		}
		if(a[6][4]==1)
		{
			if(a[6][3]==0 && a[6][5]==0 && a[5][4]==0 && a[7][4]==0){flag=1;cout << flag <<endl;}
			else{flag=0;cout << flag <<endl;goto label;}
		}
		if(a[4][6]==1)
		{
			if(a[3][6]==0 && a[5][6]==0 && a[4][5]==0 && a[4][7]==0){flag=1;cout << "4" << " " << "6" << " " << flag <<endl;}
			else{flag=0;cout << "4" << " " << "6" << " " << flag <<endl;goto label;}
		}
		//-------------------------------------------------------------
		//center corners
		//-------------------------------------------------------------
		if(a[3][3]==1)
		{
			if(a[3][2]==0 && a[3][4]==0 && a[2][3]==0 && a[4][3]==0){flag=1;cout << "3" << " " << "3" << " " << flag <<endl;}
			else{flag=0;cout << "3" << " " << "3" << " " << flag <<endl;goto label;}
		}
		if(a[3][5]==1)
		{
			if(a[3][4]==0 && a[3][6]==0 && a[2][5]==0 && a[4][5]==0){flag=1;cout << flag <<endl;}
			else{flag=0;cout << flag <<endl;goto label;}
		}
		if(a[5][3]==1)
		{
			if(a[5][2]==0 && a[5][4]==0 && a[4][3]==0 && a[6][3]==0){flag=1;cout << flag <<endl;}
			else{flag=0;cout << flag <<endl;goto label;}
		}
		if(a[5][5]==1)
		{
			if(a[5][4]==0 && a[5][6]==0 && a[4][5]==0 && a[6][5]==0){flag=1;cout << "5" << " " << "5" << " " << flag <<endl;}
			else{flag=0;cout << "5" << " " << "5" << " " << flag <<endl;goto label;}
		}
		//---------------------------------------------------------------------
		//edge centers
		//------------------------------------------------------------------
		if(a[3][4]==1)
		{
			if(a[3][3]==0 && a[3][5]==0 && a[2][4]==0 && a[4][4]==0){flag=1;cout << "3" << " " << "4" << " " << flag <<endl;}
			else{flag=0;cout << "3" << " " << "4" << " " << flag <<endl;goto label;}
		}
		if(a[4][3]==1)
		{
			if(a[4][2]==0 && a[4][4]==0 && a[3][3]==0 && a[5][3]==0){flag=1;cout << "4" << " " << "3" << " " << flag <<endl;}
			else{flag=0;cout << "4" << " " << "3" << " " << flag <<endl;goto label;}
		}
		if(a[4][5]==1)
		{
			if(a[4][4]==0 && a[4][6]==0 && a[3][5]==0 && a[5][5]==0){flag=1;cout << "4" << " " << "5" << " " << flag <<endl;}
			else{flag=0;cout << "4" << " " << "5" << " " << flag <<endl;goto label;}
		}
		if(a[5][4]==1)
		{
			if(a[4][4]==0 && a[6][4]==0 && a[5][3]==0 && a[5][5]==0){flag=1;cout << "5" << " " << "4" << " " << flag <<endl;}
			else{flag=0;cout << "5" << " " << "4" << " " << flag <<endl;goto label;}
		}
		//-----------------------------------------------------------------
		label:;
		//cout << "After everything flag= " << flag <<endl;
		
		//cout<< "Wanna print again, press 1, else 0\n";
		//cin >> ch;
		
	}

	
	//count=0;
	clrscr;
	for(i=0;i<=7;i++)
	{
		for(j=0;j<=7;j++)
		{	
			if((i==1 || i==2 || i==6 || i==7) && (j==1 || j==2 || j==6 || j==7))
			{
				printf("     ");
			}
			else{
				printf("  %d  ",a[i][j]);
				//if(a[i][j]==1){++count;}
				
				
			}
		}
		printf("\n\n\n");
	}
	
	cout << "The numbers of Marbles remaining is " << 32-count;
	cout << "\n Game Over" << endl;
	
}

