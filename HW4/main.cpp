#include <iostream>
using namespace std;

class TicTacToe{
	char a[9];
	int n;
	int count;
public:
	TicTacToe(){
		cout<<"-- Tic Tac Toe -- CSIE@CGU\n";
		cout<<"Player 1 (X)  -  Player 2 (O)\n";
		for(int i=1;i<=9;i++)
			a[i-1]=i+48;
		count=1;
	}
	void run();
	void printBoard();
	int drawBoard();
	void checkBoard(int&);
	int checkWinner();
};
void TicTacToe::printBoard(){
	int j=0;
	for(int i=0;i<11;i++){
		switch (i%4){
			case 0:
			case 2:
				cout<<"   ■   ■   ";
				break;
			case 1:
				cout<<" "<<a[j];	j++;
				cout<<" ■ "<<a[j];	j++;
				cout<<" ■ "<<a[j];	j++;
				break;
			default:
				cout<<"■■■■■■■■■■■";
		}
		cout<<endl;
	}
}
void TicTacToe::checkBoard(int &n){
	while(a[n-1]!=n+48){
		cout<<"請輸入下一步";
		cin>>n;
	}
}
int TicTacToe::checkWinner(){
	if(a[0]==a[1] && a[1]==a[2]){
		if(a[0]=='O')	return 1;
		else	return 2;
	}
	else if(a[3]==a[4] && a[4]==a[5]){
		if(a[3]=='O')	return 1;
		else	return 2;
	}
	else if(a[6]==a[7] && a[7]==a[8]){
		if(a[6]=='O')	return 1;
		else	return 2;
	}
	else if(a[0]==a[3] && a[3]==a[6]){
		if(a[0]=='O')	return 1;
		else	return 2;
	}
	else if(a[1]==a[4] && a[4]==a[7]){
		if(a[1]=='O')	return 1;
		else	return 2;
	}
	else if(a[2]==a[5] && a[5]==a[8]){
		if(a[2]=='O')	return 1;
		else	return 2;
	}
	else if(a[0]==a[4] && a[4]==a[8]){
		if(a[1]=='O')	return 1;
		else	return 2;
	}	
	else if(a[2]==a[4] && a[4]==a[6]){
		if(a[2]=='O')	return 1;
		else	return 2;
	}
	else if(count==10){
		return 3;
	}
	else{
		return 0;
	}
}
int TicTacToe::drawBoard(){
	int win=0;
	while(win==0){
		if(count%2)	cout<<"Player 1, ";
		else	cout<<"Player 2, ";
		cout<<"請輸入『1-9』的數字：";
		cin>>n;
		checkBoard(n);
		a[n-1] = (count%2) ? 'O' : 'X';
		count++;
		printBoard();
		win=checkWinner();
	}
	return win;
}
void TicTacToe::run(){
	printBoard();
	int winner= drawBoard();
	
	if(winner==1)	cout<<"==>Player 1 win\n";
	else if(winner==2)	cout<<"==>Player 2 win\n";
	else	cout<<"==>Game draw";
}

int main(){
	TicTacToe game;
	game.run();
	return 0;
}
