/*
    In N-queen-problem , we have to check whether it is possible to place n-queens on 2-d chess board of order n*n (i am assuming maximum size to be 10*10) .
	I am placing the queens row by row. 
*/

#include <bits/stdc++.h> 
using namespace std;

void printBoard(int board[][10],int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<board[i][j]<<" ";
		}
		cout<<"\n";
	}
}

bool isSafe(int board[][10],int i,int j,int n){
	int row,col;
	for(row=0;row<i;row++){
		if(board[row][j]==1){
			return false;
		}
	}
	for(row=i,col=j;row>=0&&col>=0;row--,col--){
		if(board[row][col]==1){
			return false;
		}
	}
	for(row=i,col=j;row>=0&&col<n;row--,col++){
		if(board[row][col]==1){
			return false;
		}
	}
	
	return true;
}

bool solveNQueen(int board[][10],int i,int n){
	if(i==n){
		return true;
	}else{
		for(int j=0;j<n;j++){
			if(isSafe(board,i,j,n)){
				board[i][j]=1;
				
				bool nextQueen = solveNQueen(board,i+1,n);
				
				if(nextQueen){
					return true;
				}
				
				board[i][j]=0;
			}
		}
		return false;
	}
}

int main(){
	int n;
	bool a;
	cin>>n;
	int board[10][10] = {0};
    a=solveNQueen(board,0,n);
    if(a){
    	printBoard(board,n);
	}else{
		cout<<"Not possible";
	}
	return 0;
}
