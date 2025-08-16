#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <ncurses.h>

void frame(char *board, int score){ 
clear();  
int width = 20;
int height = 10; // Рисуем верхнюю и нижнюю границы на 22 столбца (от 0 до 21) 
for(int i = 0; i < width + 2; ++i){ 
    mvaddch(0, i, '-'); 
    mvaddch(height + 1, i, '-'); 
} // Рисуем вертикальные границы на столбцах 0 и 21 
for(int i = 0; i < height + 2; ++i){ 
    mvaddch(i, 0, '|'); 
    mvaddch(i, width + 1, '|');
} // Рисуем игровое поле с отступом 1, чтобы оно было внутри границ 
for (int i = 0; i < 200; i++){ 
    int y = i / width; 
    int x = i % width; 
    mvaddch(y + 1, x + 1, board[i]); 
    } 
mvprintw(height + 2, 0, "Score: %d", score);
refresh(); 
}

/*void frame(char *board) {
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
	
}*/
int generate_apples(char *board, int *snake){
	int apple = 0;
	int repeat = 1;
		while(repeat == 1){
			int found = 0;
			apple = rand() % 199;
			for(int i1 = 0; i1 < 10; i1++){
				if(snake[i1] == apple){
					found = 1;
				}
			}
			if(found == 0){
			repeat = 0;
			}
		}
board[apple] = '0';

return apple;	
}


void proceed(char *board, int *arr, char direction, int tail){
	int reg = arr[tail];
	for(int i1 = tail; i1 >= 1; i1--){
    		arr[i1] = arr[i1-1];
    		//printf("Previous %d, and present %d", arr[i1], arr[i1-1]);
    		board[arr[i1]] = '*';
    	}
	switch(direction){
	case 'a':
		 if (arr[1]%20 == 0){
			arr[0] += 19;
		}
		else{ 
			arr[0] -= 1;
			}
			break;
    case 'd':
    	if((arr[1]+1)%20 == 0){
			arr[0] -= 19;
		}
		else{ 
			arr[0] += 1;
			} 
			break;   
	case 'w':
		if(arr[1] < 20){
			arr[0] += 180;
		}
		else{ 
			arr[0] -= 20;
			} 
			break;
    case 's':
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

/*void elongateTail(char *board, int *arr, int tail, char direction){
switch(direction){
	case 'a':
		 arr[tail] = arr[tail-1] + 1;
			break;
    case 'd':
    	arr[tail] = arr[tail-1] + 1;
			break;  
	case 'w':
		if(arr[tail-1]>=180){
			arr[tail] = arr[tail-1] - 179;
		}
		else{
		arr[tail] = arr[tail-1] + 20;
		}
			break;
    case 's':
    	if(arr[tail-1] < 20){
			arr[tail] = arr[tail-1] + 179;
		}
		else{
		arr[tail] = arr[tail-1] - 20;
		}
			break;
    default:
        arr[tail] = arr[tail-1] + 1;
	}
	board[arr[tail]] = '*';
}*/

int main() {
	srand(time(NULL));
	initscr(); 
	cbreak(); 
	noecho(); 
	nodelay(stdscr, TRUE); 
	keypad(stdscr, TRUE);
	char *board = (char*)malloc(200*sizeof(char));
	int *snake = (int*)malloc(200*sizeof(int));
    int counter = 0;
    int apple = 0;
    int score = 0;
    int tail = 4;
	init_vert(&snake[0], &board[0]);
	//char orientation = 'a';
	char ch = 'a';

	//time_t start_time = time(NULL);
    //time_t end_time = start_time+30;
    /*while(ch == ERR time(NULL) < end_time){
    	ch = getch();
    	frame(&board[0]);
        usleep(16000);
        counter++;
        if(counter % 10 == 0 && counter != 0){
    	   proceed(board, snake, orientation);
    	   }    
    	}*/
    apple = generate_apples(board, snake);
    while(ch != 'e'){
    char chnow = ch;
    ch = getch();
    if(ch == ERR){
    	ch = chnow;
    }
    frame(&board[0], score);
    usleep(16000);
    counter++;
    if(counter % 10 == 0 && counter != 0){
      proceed(board, snake, ch, tail);
      }    
    for(int i = 1; i < tail; i++){
    	if(snake[0] == snake[i]){
    		return 0;
    	}
    }
    if(snake[0] == apple){ 
    	score++;
    	tail++;
    	//elongateTail(board, snake, tail, ch);
    	//return 0;// Очищаем старую позицию яблока, устанавливая пробел 
    	board[apple] = ' '; // Генерируем новое яблоко и получаем его новую позицию 
    	apple = generate_apples(board, snake); 
    	}
}

   
  
return 0;
}
