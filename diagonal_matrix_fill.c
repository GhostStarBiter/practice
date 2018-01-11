#include "stdio.h"
#include <stdlib.h>


#define DOWN		1
#define RIGHT		2
#define DIAG_UP		3
#define DIAG_DOWN	4


int main(int argc, char** argv){
	if(argc < 2){
		printf("\tEnter dimension(s) of array.\n\tOne dimension - square array.\n\tTwo dimensions - rectangular.\n");
		return(EXIT_FAILURE);
	}
	int cur_elem = 0;
	int i = 0, 			//dynamic row number
		j = 0;		//dynamic col number
	int rows, columns;

	if(argc == 2){
		rows = columns = atoi(argv[1]) - 1;
	}
	else
	{
		rows = atoi(argv[1]) - 1;
		columns = atoi(argv[2]) - 1;
	}

	printf(" rows: %i,\n columns: %i. \n", rows+1, columns+1);

	int arr[rows + 1][columns + 1];

	int last_elem = (rows+1)*(columns+1) - 1;
	printf("Last elem = %i\n", last_elem);

	//***************

	cur_elem = 0;
	int state = DOWN;

	arr[i][j] = cur_elem;

	while(cur_elem < last_elem){
		printf("step - %i\n", cur_elem);
		printf("arr[%i][%i] = %i\n", i, j, arr[i][j]);
		switch(state){
		case DOWN:
			arr[++i][j] = ++cur_elem;
			if(j == 0){
				state = DIAG_UP;
			}
			if(j == columns){
				state = DIAG_DOWN;
			}
			break;
		case RIGHT:
			arr[i][++j] = ++cur_elem;
			if(i == 0){
				state = DIAG_DOWN;
			}
			else
			if(i == rows){
				state = DIAG_UP;
			}
			break;
		case DIAG_UP:
			//diagonal up
			//until reach first row or last column
			while((j < columns) && (i > 0)){
				arr[--i][++j] = ++cur_elem;
			}

			if(((j+1) <= columns) && (i == 0)){
				state = RIGHT;
			}
			else
			if(j == columns){
				state = DOWN;
			}
			break;
		case DIAG_DOWN:
			//diagonal down
			//until reach first column or last row
			while((i < rows) && (j > 0)){
				arr[++i][--j] = ++cur_elem;
			}

			if((j == 0) && ((i + 1) <= rows)){
				state = DOWN;
			}
			else
			if((i == rows) && ((j + 1) <= columns)){
				state = RIGHT;
			}
			break;
		default:
			break;
		}
	}

	//display array
	for(int r = 0; r <= rows; r++)
		{
			for(int c = 0; c <= columns; c++){
				printf("%i     ", arr[r][c]);
			}
			printf("\n");
		}

	return 0;
}

