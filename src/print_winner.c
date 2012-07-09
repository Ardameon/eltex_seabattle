#include "UI.h"
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void drawScreen(char *field, int row, int col, char *name);
void updateFlakes(char **fieldIn, int *rowIn, int *colIn);

int print_winner(struct Player *winner)
{
        char *field =NULL;
	int row = 0;
	int col = 0;
	int i;
        for(i = 0; i < 30; i++){
                updateFlakes(&field, &row, &col);
                if(field==NULL){
                        break;
                }
		
                drawScreen(field, row, col, winner->name);
                sleep(1);
        }
	free(field);
}
void updateFlakes(char **fieldIn, int *rowIn, int *colIn)
 {
         int numnew = 0; int row = 0; int col = 0; int i = 0;
         char *field =*fieldIn;
         getmaxyx(stdscr, row, col);
 
         if (field == NULL || *rowIn!=row || *colIn!=col){
		 free(field);
                 *fieldIn = calloc(row*col, sizeof(char));
                 field=*fieldIn;
                 *rowIn = row;
                 *colIn = col;
         }
         memmove(&field[col], &field[0], (row-1)*col);
         memset(field, 0, col);
         numnew = random()%(col/2);
         for(i=0; i < numnew; i++){
                 field[random()%col]=1;
         }
 }
void drawScreen(char *field, int row, int col, char *name)
{
         int x = 0;
         int y = 0;
         clear();
         for(y = 0; y < row; y++){
                 for(x = 0; x < col; x++){
                           if(field[y*col+x]==1){
                                 mvaddch(y, x, '*');
                           }
                 }
         }
         move(15,50);
         printw("!!! %s ARE WIN !!!", name);
         refresh();
 }
