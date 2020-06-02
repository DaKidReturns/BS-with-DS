#include<iostream>
#include<cstdlib>
#include<vector>

/************ Create Board ***********/
class TicTacToeBoard{
	private:
		int rows;
		int columns;
		const int X =1;
		const int O = -1;
		const int EMPTY = 0;
		
	public:
		TicTacToeBoard(int m,int n):row(m),columns(n){clearBoard();} //Constructor
		void clearBoard();
	
};
int board[3][3];
int i,j;


void clearBoard(int board[3][3]){
	for(i = 0;i<3;++i)
		for(j = 0;j<3;++j)
			board[i][j] = EMPTY;
}

void printBoard(int A[3][3]){
	for(int i=0;i<3;++i)
		for(int j=0;j<3;++j){
			switch(A[i][j]){
				case 1:cout<<'X';break;
				case -1:cout<<'O';break;
				case 0:cout<<' ';break;

			}
			if(j<2)cout<<"|";
		}
	if(i<2) cout<<"\n--+--+--\n";
}

void putMark(int mark,int x,int y,int board[3][3]){
	}
