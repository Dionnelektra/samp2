#include "../../sdk/dexsdk.h"
#include "../../sdk/time.h"

void print_board(int **board);
void erase();
void print_inst();
void print_ctl();
void drawBoard(int **board);
void drawBox(int row, int col);

#define RED 4
#define BLUE 1
#define GRAY 56
#define YELLOW 54
#define LARGE_FONT 1
#define SMALL_FONT 0

#define start '1'
#define inst '2'
#define quit '3'
#define yes 'y'
#define no 'n'
#define toMenu 'q'


int main(){

	
	char keypress;
	int i,j;
	int board[4][4];


	set_graphics(VGA_320X200X256);

	do {
		erase(1, 1, 400, 220);
		title(); //prints menu

		keypress = (char)getch();
		erase(1, 1, 400, 220);
		for(i=0; i<4; i++){
			for (j=0;j<4;j++){
				board[i][j] = 0;
			}
		}

		if(keypress==start){
			//print board
			do{

				print_board(&board);
				keypress = (char)getch();
				if(keypress == toMenu){
					erase(60,160,220,40);
				}
			}while(keypress != toMenu);
			

		}
		else if(keypress==inst){
			//print instructions
			do {
				print_inst();

			
				keypress = (char)getch();
				if(keypress == toMenu){
					erase(60,160,220,40);
				}

			}while(keypress != toMenu);
						
			
		}

	}while(keypress != quit);	


	set_graphics(VGA_TEXT80X25X16);
	clrscr();
}



title() {

	write_text("2048",160,50,WHITE,1);

	write_text("1 - Start Game", 40, 120, RED, 0);
	write_text("2 - Instructions", 40, 150, WHITE, 0);
	write_text("3 - Quit", 40, 170, WHITE, 0);


}

void erase(int x, int y, int w, int h){
	int i,j;

	for(i=y;i<=(y+h);i++){
		for(j=x;j<=(x+w);j++){
			write_pixel(j,i,100);
		}
	}
}

void print_inst(){
	write_text("Instructions",130,20,YELLOW,1);

	write_text("Use the keys to move the tiles.",30,60,WHITE,0);
	write_text("When two tiles with the same ",30,80,WHITE,0);
	write_text("number touch,they merge",30,100,WHITE,0);
	write_text("into one!",30,120,WHITE,0);
	write_text("Go and reach 2048!",30,140,WHITE,0);

	write_text(" Q - Back to Menu",5,180,WHITE,0);
}

void print_ctl(){
	write_text("Controls:",5,35,WHITE, 0);
	write_text("Up - W", 5, 45, WHITE, 0);
	write_text("Lf - A", 5, 55, WHITE, 0);
	write_text("Rt - D", 5, 65, WHITE, 0);
	write_text("Dn - S", 5, 75, WHITE, 0);
	write_text("Quit - Q", 5, 125, WHITE, 0);

}
void print_board(int **board){

	print_ctl();
	drawBoard(&board);

}
 
void drawBoard(int **board){

	int a = 130;
	int b = 40;

	for(int i=0; i<100; i+=25){
		for(int j=0; j<100; j+=25){
			drawBox(a+i,b+j);
		}
	}
}

void drawBox(int row, int col){
	for(int i=0; i<20; i++){
		for (int j=0; j<20; j++){
			write_pixel(row+i,col+j,GRAY);
		}
	}
}