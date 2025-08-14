#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

void frame(char *board) {
	printf("----------------------\n");
	for(int i1 = 0; i1 < 200; i1++) {
		if(i1%20 == 0) {
			printf("|%c", board[i1]);
		}
		else if((i1+1)%20 == 0) {
			printf("%c|\n", board[i1]);
		}
		else {
			printf("%c", board[i1]);
		}
	}
	printf("----------------------\n");
	
}

void proceed(char *board, int *arr, int direction){
	int reg = arr[4];
	for(int i1 = 4; i1 >= 1; i1--){
    		arr[i1] = arr[i1-1];
    		//printf("Previous %d, and present %d", arr[i1], arr[i1-1]);
    		board[arr[i1]] = '*';
    	}
	switch(direction){
	case 1:
		if(arr[1]%20 == 0){
			arr[0] += 19;
		}
		else{ 
			arr[0] -= 1;
			}
			break;
    case 2:
    	if((arr[1]+1)%20 == 0){
			arr[0] -= 19;
		}
		else{ 
			arr[0] += 1;
			} 
			break;   
	case 3:
		if(arr[1] < 20){
			arr[0] += 180;
		}
		else{ 
			arr[0] -= 20;
			} 
			break;
    case 4:
    	if(arr[1] >= 180){
			arr[0] -= 180;
		}
		else{ 
			arr[0] += 20;
			} 
			break;
    default:
        if(arr[1]%20 == 0){
			arr[0] += 19;
		}
		else{ 
			arr[0] -= 1;
			}
			break;    
	}
    board[arr[0]] = '*';
    board[reg] = ' ';
    /*for(int i1 = 0; i1< 5; i1++){
    	printf("%d\n", arr[i1]);
    }
    printf("  \n");*/
    
}

void init_vert(int *snake, char *board) {
	for(int i1 = 0; i1 < 5; i1++) {
		snake[i1] = 25 + 20*i1;
	}
	for(int i2 = 0; i2 < 200; i2++) {
	        for(int i1 = 0; i1 < 5; i1++) {
	                if(snake[i1] == i2) {
	                        board[i2] = '*';
	               }
	        }
	        if(board[i2] != '*'){
	                board[i2] = ' ';
	        }
	        
	}

}


void init_horiz(int *snake, char *board) {
        for(int i1 = 0; i1 < 5; i1++) {
		snake[i1] = 45 + i1;
	}
	for(int i2 = 0; i2 < 200; i2++) {
	        for(int i1 = 0; i1 < 5; i1++) {
	                if(snake[i1] == i2) {
	                        board[i2] = '*';
	               }
	        }
	        if(board[i2] != '*'){
	                board[i2] = ' ';
	        }
	        
	}

}

int main() {
	char *board = (char*)malloc(200*sizeof(char));
	int *snake = (int*)malloc(5*sizeof(int));
    int counter = 0;
	init_vert(&snake[0], &board[0]);
	int orientation = 1;
	
	time_t start_time = time(NULL);
    time_t end_time = start_time+30;
    while(time(NULL) < end_time){
    	frame(&board[0]);
    	usleep(16000);
    	counter++;
    	if(counter % 10 == 0 && counter != 0){
    		proceed(board, snake, orientation);
    		}
    }
   
  
return 0;
}
