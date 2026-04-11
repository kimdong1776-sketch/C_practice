#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 25
#define MAX_MAZE_SIZE 5

typedef struct {
	int row;
	int col;
	int dir;
}element;

int top = -1;
element stack[MAX_STACK_SIZE];

struct {
	int vert;
	int horiz;
}move[8];

element stack_empty() {
	return stack[0];
}

element stack_full() {
	fprintf(stderr, "stack is full");
	exit(1);
}

element pop() {
	if (top == -1) {
		return stack_empty();
	}
	else {
		return stack[top--];
	}
}

void push(element temp) {
	if (top >= MAX_STACK_SIZE - 1) {
		stack_full();
	}
	stack[++top] = temp;
}

int find_path(int mark[7][7], int maze[7][7], int start_row, int start_col, int finish_row, int finish_col) {
	int row, col, next_row, next_col, dir, found = 0;
	element position;
	mark[start_row][start_col] = 1;
	stack[0].row = start_row; stack[0].col = start_col; stack[0].dir = 0;
	top = 0;
	while (top > -1 && !found) {
		position = pop();
		row = position.row;col = position.col; dir = position.dir;
		while (dir < 8 && !found) {	
			next_row = row + move[dir].vert;
			next_col = col + move[dir].horiz;
			if (row == finish_row && col == finish_col) {
				found = 1;	
				position.row = row; position.col = col; position.dir = dir;
				push(position);
				break;
			}
			else if (!mark[next_row][next_col] && !maze[next_row][next_col]) {
				position.row = row; position.col = col; position.dir = ++dir;
				push(position);
				row = next_row; col = next_col; dir = 0;
				mark[next_row][next_col] = 1;	

			}
			else {
				dir++;
			}
			
		}
	}
	if (found) {
		return top;
	}
	else {
		return 0;
	}
}

void print_result(FILE *out, int maze[7][7]) {
	for (int i = 1; i < 6; i++) {
		for (int j = 1; j < 6; j++) {
			int is_path = 0;
			for (int k = 0; k <= top; k++) {
				if (stack[k].row == i && stack[k].col == j) {
					is_path = 1;
					break;
				}
			}
			if (is_path) fprintf(out, "x ");
			else fprintf(out, "%d ", maze[i][j]);
		}
		fprintf(out, "\n");
	}
}

int main() {
	FILE* in;
	FILE* out;

	int maze[7][7] = { 0 };
	int mark[7][7] = { 0 };

	int start_row, start_col, finish_row, finish_col;
	
	printf("컴퓨터학부 2025003170 김동후\n");

	move[0].vert = -1; move[0].horiz = 0;   move[1].vert = -1; move[1].horiz = 1;
	move[2].vert = 0;  move[2].horiz = 1;   move[3].vert = 1;  move[3].horiz = 1;
	move[4].vert = 1;  move[4].horiz = 0;   move[5].vert = 1;  move[5].horiz = -1;
	move[6].vert = 0;  move[6].horiz = -1;  move[7].vert = -1; move[7].horiz = -1;


	if (fopen_s(&in, "in.txt", "r") != 0 || fopen_s(&out, "out.txt", "w") != 0) {
		fprintf(stderr, "file open err\n");
		exit(1);
	}

	for (int i = 1; i < (MAX_MAZE_SIZE + 1); i++) {
		for (int j = 1; j < MAX_MAZE_SIZE + 1; j++) {
			fscanf_s(in, "%d", &maze[i][j]);
		}
	}

	for (int i = 0; i < (MAX_MAZE_SIZE +2); i++) {
		maze[0][i] = 1;
		maze[i][0] = 1;
		maze[MAX_MAZE_SIZE + 1][i] = 1;
		maze[i][MAX_MAZE_SIZE + 1] = 1;
	}


	scanf_s("%d %d\n %d %d", &start_row, &start_col, &finish_row, &finish_col);

	if (find_path(mark, maze, start_row, start_col, finish_row, finish_col)) {
		print_result(out, maze);
	}
	else {
		fprintf(out, "No Path");
	}

}