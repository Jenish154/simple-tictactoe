#include <iostream>
using namespace std;

void breakline(){
	for(int i=0 ; i<7 ; i++){
		cout<<" - ";
	}
	cout<<endl;
}

void showboard(string board[3][3],int length){
	for(int i=0 ; i<3 ; i++){
		breakline();
		cout<<" | ";
		for(int j=0 ; j<3 ; j++){
			cout<<board[i][j];
			cout<<" | ";
		}
		cout<<endl;
	}
	breakline();
}

void game(string board[3][3],int length){
	bool run=true;
	int i=1,a,b,c=0;
	while(run){
		showboard(board,length);
		cout<<"Player "<<i<<" :";
		cin>>a>>b;
		if (a==10){
			run=false;
			break;
		}
		while(board[a][b]!="   "){
			cout<<"Invalid position. Enter again:";
			cin>>a>>b;
		}
		c++;
		if(i==1){
			board[a][b]=" X ";
		}
		else{
			board[a][b]=" O ";
		}
		if(board[a][0]==board[a][1] && board[a][0]==board[a][2]){
			showboard(board,length);
			cout<<"Player "<<i<<" wins";
			run=false;
			break;
		}
		if(board[0][b]==board[1][b] && board[0][b]==board[2][b]){
			showboard(board,length);
			cout<<"Player "<<i<<" wins";
			run=false;
			break;
		}
		if (!((a==1 && b!=1) || (b==1 && a!=1))){
			if(board[0][0]==board[1][1] && board[0][0]==board[2][2] && board[1][1]!="   "){
				showboard(board,length);
				cout<<"Player "<<i<<" wins";
				run=false;
				break;
			}
			if(board[0][2]==board[1][1] && board[0][2]==board[2][0] && board[1][1]!="   "){
				showboard(board,length);
				cout<<"Player "<<i<<" wins";
				run=false;
				break;
			}
		}
		if(c==length*length){
			showboard(board,length);
			cout<<"It's a tie.";
			run=false;
			break;
		}
		if(i==1){
			i=2;
		}
		else{
			i=1;
		}
	}
}

int main(int argc,char* argv[]){
	string board[3][3];
	int length=sizeof(board)/sizeof(board[0]);
	for(int i=0;i<length;i++){
		for(int j=0;j<length;j++){
			board[i][j]="   ";
		}
	}
	game(board,length);
}