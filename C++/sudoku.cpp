#include<iostream>
using namespace std;
bool check_this_box(int y,int x,int k);
bool check_next_box(int y,int x);
void show_board();
int find_next_box(int x,int y);
//int non_touch[25][2]={{0,0},{7,0},{2,1},{5,1},{8,1},{0,2},{1,2},{2,2},{8,2},{1,3},{4,3},
//						{8,3},{4,4},{0,5},{4,5},{7,5},{0,6},{6,6},{7,6},{8,6},{0,7},{3,7},{6,7},{1,8},{8,8}};
int sudoku[9][9]={{6,0,0,0,0,0,0,4,0},
				  {0,0,5,0,0,2,0,0,7},
				  {7,2,9,0,0,0,0,0,3},
				  {0,9,0,0,4,0,0,0,1},
				  {0,0,0,0,6,0,0,0,0},
				  {4,0,0,0,8,0,0,7,0},
				  {3,0,0,0,0,0,1,6,5},
				  {2,0,0,4,0,0,8,0,0},
				  {0,5,0,0,0,0,0,0,4}};
int main()
{
	int k=0;
	bool ret=0, rec=0;
	for(k=1;k!=10;k++){
		rec=check_this_box(0,1,k);
		if(rec==1){
			sudoku[0][1]=k;
			ret=check_next_box(0,2);
			if(ret==1){
				show_board();
				break;
			}
		}
	}
	if(ret==0)
	cout<<"NOT POSSIBLE TO SOLVE!!";
}
bool check_this_box(int y,int x,int k)
{
	int i,j,f=0;
	for(j=0;j!=9;j++){
		for(i=0;i!=9;i++){
			if(((j==y)&&(i!=x)&&(sudoku[j][i]==k))||((i==x)&&(j!=y)&&(sudoku[j][i]==k))||((i/3==x/3)&&(j/3==y/3)&&(sudoku[j][i]==k))){
				f=1;
				return 0;
			}
		}
	}
	if(f==0)
	return 1;
}
int find_next_box(int y, int x)
{

	int i, j;
	if(x==8)
		i=0,j=y+1;
	else
		i=x+1,j=y;
	while(j!=9){
		while(i!=9){
			if(sudoku[j][i]==0){
				return j*10+i;
			}
			i++;
		}
		i=0,j++;
	}
	return 90;
}
bool check_next_box(int y, int x)
{
	int k,l,m;
	bool rec=0,ret=0;
	if(y==9)
		return 1;
	else
	{
		for(k=1;k!=10;k++){
			rec=check_this_box(y,x,k);
			if(rec){
				sudoku[y][x]=k;
				l=find_next_box(y,x);
				m=l%10;
				l/=10;
				ret=check_next_box(l,m);
				if(ret)
					return 1;
			}
		}
		sudoku[y][x]=0;
		return 0;
	}
}
void show_board()
{
	int i,j;
	for(j=0;j!=9;j++){
		for(i=0;i!=9;i++){
			cout<<sudoku[j][i]<<"  ";
		}
		cout<<"\n";
	}
}