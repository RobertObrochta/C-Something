#include <stdio.h>
#include <ncurses.h>

int main(void)
{
	initscr();			/* Start curses mode */
	int ch;
	printw("Tap any key!\n");
	keypad(stdscr, true);
	int i = 1;

	while (i == 1){
		ch = getch();
		switch (ch){
			case KEY_UP:
				printw("Move up!\n");
				break;
			case KEY_DOWN:
				printw("Down Arrow!\n");
				break;
			case KEY_LEFT:
				printw("Going backwards, eh?\n");
				break;
			case KEY_RIGHT:
				printw("Time to progress...\n");
				break;
			case 27:
				break;
			default:
				printw("Hit something else!\n");
				break;
		}
		
		if (ch == 27){
			printw("Quitting...\n");
			++i; // breaks out of the while loop, closes the program
		}
	}
	refresh();
	endwin();
	return 0;
}