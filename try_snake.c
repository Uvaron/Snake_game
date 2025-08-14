#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void frame(char *board){
	printf("----------------------\n");
	for(int i1 = 0; i1 < 200; i1++){
    	if(i1%20 == 0){
    		printf("|%c", board[i1]);
    	}
    	else if((i+1)%20 == 0){
    		printf("%c|\n", board[i1]);
    	}
    	else{
    		printf("%c", board[i1]);
    	}
    }
    printf("----------------------\n");*/
    }

int init_vert(int *snake, char *board){
	for(int i1 = 0; i1 < 5; i1++){
		snake[i1] = 25 + 20*i1;
	}
	for(int i2 = 0; i2 < 200; i2++){
		if(snake[i1] == i2){
			board[i2] = '*';
		}
		else{
			board[i2] = ' ';
		}
	}
	
}

int init_horiz(int *snake, int *board){
	for(int i1 = 0; i1 < 5; i1++){
		snake[i1] = 45 + i1;
	}
	for(int i2 = 0; i2 < 200; i2++){
		if(snake[i1] == i2){
			board[i2] = '*';
		}
		else{
			board[i2] = ' ';
		}
	}
}

int main(){
	char *board = (char*)malloc(200*sizeof(char));
	int *snake = (int*)malloc(5*sizeof(int));
	
	init_horiz(snake, board);
	frame(board);
	

	
	
	
    
    

	
	
	
	
	return 0;
}
