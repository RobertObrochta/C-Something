#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>
#include <string.h>

#define PLAYER '*'
#define EMPTY ' '
#define LOG '='
#define QUIT "Quitting..."
#define WINDOW_COLOR 4


// TO COMPILE
// gcc -o learning learning.c -lncurses




int main(void){
	WINDOW * win;
	win = initscr();
	box(win, 0, 0);
	start_color();
	init_pair(1, COLOR_WHITE, COLOR_BLUE);
	wbkgd(win, COLOR_PAIR(1));
	cbreak();
	int ch;
	int y = 1;
	int x = 1;
	int ymax, xmax;
	getmaxyx(stdscr, ymax, xmax);
	keypad(stdscr, true);
	int i = 1;

	while (i == 1){
		int random = rand() % 4;
		mvaddch(y, x, PLAYER);
		refresh();
		ch = getch();
		switch (ch){
			case KEY_UP:
				if (y > 1){
					mvaddch(y, x, EMPTY);
					--y;
				}
				break;
			case KEY_DOWN:
				if (y < ymax - 2){
					mvaddch(y, x, EMPTY);
					++y;
				}
				break;
			case KEY_LEFT:
				if(x > 1){
					mvaddch(y, x, EMPTY);
					--x;
				}
				break;
			case KEY_RIGHT:
				if (x < xmax - 2){
					mvaddch(y, x, EMPTY);
					++x;	
				}
				break;
			case ' ':
				if (y > 3){
					mvaddch(y, x, EMPTY);
					y -= 3;
				}
				break;
			case 27:
				mvaddstr(y, x, QUIT);
				refresh();
				sleep(1.4);
				i++;
				break;
			default:
				break;
		}
	}
	refresh();
	endwin();
	return 0;
}
