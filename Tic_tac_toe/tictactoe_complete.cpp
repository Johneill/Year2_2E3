// lab.cpp : Defines the entry point for the console application.
//

#include <stdafx.h>
#include <iostream>
#include <cmath>


using namespace std;

int player;
bool gameover = false;
const int player1 = 1;
const int player2 = 2;
const char a = '-';
const char x = 'X';
const char o = 'O';
void printBoard(char **b, int r, int c);
void printBoard2(char**b, int r, int c);
void winner(char **b, int r);



int main() {

	int c;
	int r;
	int sequence = 1;
	int d, e;
	cout << "how many columns and rows do you want" << endl;
	cin >> c;
	cout << endl;
	r = c;



	char**board; // repeat this to delete other way
	board = new char*[r];
	for (int i = 0;i<r;i++)
		board[i] = new char[c];

	//cout << c;


	for (int y = 0; y < c; y++) {
		for (int x = 0; x < r; x++) {
			board[x][y] = a;
			//cout << board[x][y];
		}
	}
	printBoard(board, r, c);

	while (!gameover) {

		player = player1;
		if (sequence % 2 == 0) {
			player = player2;
		}
		else player = player1;

		cout << "player " << player << " to go, please enter co-ordinates of" << endl;

		cin >> e >> d;

		if (board[e][d] == o || board[e][d] == x) {
			cout << "This place is taken pick another square" << endl;
		}
		else {


			if (board[e][d] == '-' && player == player1) {
				board[e][d] = x;

			}
			//else cout << "This place is full pick another place";

			if (board[e][d] == '-' && player == player2) {
				board[e][d] = o;

			}
			sequence++;
		}
		//else cout << "This place is full pick another place";


		printBoard2(board, r, c);


		if (sequence-1 == c*c) {
			cout << " Game is a draw" << endl;
			gameover = true;

		}
		
		winner(board, r);
	}

	cin.get();
	cin.get();

	return 0;
}

void printBoard(char**b, int r, int c) {

	for (int i = 0; i < 1; i++) {
		cout << "  " << i;
	}

	for (int i = 1; i < r; i++) {
		cout << " " << i;
	}
	cout << endl;

	for (int y = 0; y < r; y++) {
		cout << y << " ";
		for (int x = 0; x < c; x++) {
			b[x][y] = a;
			cout << b[x][y] << " ";
		}
		cout << endl;
	}


}

void printBoard2(char**b, int r, int c) {

	for (int i = 0; i < 1; i++) {
		cout << "  " << i;
	}

	for (int i = 1; i < r; i++) {
		cout << "  " << i;
	}
	cout << endl;

	for (int y = 0; y < r; y++) {
		cout << y << " ";
		for (int x = 0; x < c; x++) {
			cout << b[x][y] << "  ";
		}
		cout << endl;
	}


}

void winner(char **b, int r) {
	int a, c, d;
	int z = 0;
    int n0 = 0;
	int n1 = 0;
	int n2 = 0;
	int n3 = 0;
	int n4 = 0;
	int n5 = 0;
	int n6 = 0;
    int n7 = 0;
	int q = 0;
	int w = r-1;
	int e = r-1;


    
    if (player == player1) {
        for (a = 0; a < r; a++) {
            for (int d = 0; d < r; d++) {
                if (b[a][d] == x) {
                    n1++;
                    if (n1 == r) {
                        gameover = true;
                        cout << "player 1 wins";
                    }
                }
                
            }
            n1 = 0;
        }
    }
    
    if (player == player2) {
        for (a = 0; a < r; a++) {
            for (d = 0; d < r; d++) {
                if (b[a][d] == o) {
                    n2++;
                    if (n2 == r) {
                        gameover = true;
                        cout << "player 2 wins";
                    }
                }
                
            }
            n2 = 0;
        }
    }

    if (player == player1) {
        for (a = 0; a < r; a++) {
            for (int d = 0; d < r; d++) {
                if (b[d][a] == x) {
                    n0++;
                    if (n0 == r) {
                        gameover = true;
                        cout << "player 1 wins";
                    }
                }
                
            }
            n0 = 0;
        }
    }
    
    if (player == player2) {
        for (a = 0; a < r; a++) {
            for (d = 0; d < r; d++) {
                if (b[d][a] == o) {
                    n7++;
                    if (n7 == r) {
                        gameover = true;
                        cout << "player 2 wins";
                    }
                }
                
            }
            n7 = 0;
        }
    }
    
    if (player == player1) {
		for (a = 0; a < r; a++) {
			if (b[a][z] == x) {
				n3++;
				z++;
				if (n3 == r) {
					gameover = true;
					cout << "player 1 wins";
				}
			}
		}

	}

	if (player == player2) {
		for (a = 0; a < r; a++) {
			if (b[a][q] == 0) {
				n4++;
				q++;
				if (n4 == r){
					gameover = true;
					cout << "player 2 wins";
				}
			}
		}

	}
	

	if (player == player1) {
		for (a = 0; a < r; a++) {
			if (b[a][w] == x) {
				n5++;
				w--;
				if (n5 == r) {
					gameover = true;
					cout << "player 1 wins";
				}
			}
		}
		n5 = 0;
	}

	if (player == player2) {
		for (a = 0; a < r; a++) {
			if (b[a][e] == o) {
				n6++;
				e--;
				if (n6 == r) {
					gameover = true;
					cout << "player 2 wins";
				}
			}
		}

	}




}
