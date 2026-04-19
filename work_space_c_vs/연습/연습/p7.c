#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int row;
	int col;
	int dir;
}element;

int top = -1;
element stack[25] = {0};
struct {
	int vert;
	int horiz;
}move[8];

element pop() {
	if (top == -1) {
		fprintf(stderr, "stack empty");
		exit(1);
	}

	return stack[top--];
}

void push(element temp) {
	if (top >= 25) {
		fprintf(stderr, "stack full");
		exit(1);
	}
	stack[++top] = temp;
}

int findPath(int maze[7][7], int mark[7][7], int startR, int startC, int finishR, int finishC){
	int nextR, nextC, find = 0;
	int dir, row, col;
	element position;
	position.col = startC; position.row = startR;
	position.dir = 0;
	mark[startR][startC] = 1;
	push(position);
	top = 0;
	while (!find && top != -1) {
		position = pop();
		row = position.row; col = position.col; dir = position.dir;
		while (!find && dir < 8) {
			nextR = row + move[dir].vert;
			nextC = col + move[dir].horiz;
			if (row == finishR && col == finishC) {
				position.row = row; position.col = col; position.dir = dir;
				push(position);
				find = 1;
				break;
			}
			else if (!mark[nextR][nextC] && !maze[nextR][nextC]) {
				dir++; 
				position.row = row; position.col = col; position.dir = dir;
				push(position);
				row = nextR; col = nextC; dir = 0;
				mark[nextR][nextC] = 1;
				}
			else {
				dir++;
			}
		}
	}
	if (!find) {
		printf("No path\n");
		return 0;
	}
	else {
		return 1;
	}
	
}

void printpath(int maze[7][7], int mark[7][7]) {
	int p=0;

	for (int i = 1; i < 6; i++) {
		for (int j = 1; j < 6; j++) {
			p = 0;
			for (int k = 0; k <= top; k++) {
				if (stack[k].col == j && stack[k].row == i) {
					printf("x ");
					p = 1;
				}
			}
			if (!p) {
				printf("%d ", maze[i][j]);
				
			}
		}
		printf("\n");
	}
}

int main() {

	move[0].vert = -1; move[0].horiz = 0;   move[1].vert = -1; move[1].horiz = 1;
	move[2].vert = 0;  move[2].horiz = 1;   move[3].vert = 1;  move[3].horiz = 1;
	move[4].vert = 1;  move[4].horiz = 0;   move[5].vert = 1;  move[5].horiz = -1;
	move[6].vert = 0;  move[6].horiz = -1;  move[7].vert = -1; move[7].horiz = -1;
	FILE* in;
	fopen_s(&in, "in.txt", "r");
	int mark[7][7] = { 0 };
	int maze[7][7] = { 0 };
	int startR, startC, finishR, finishC;
	scanf_s("%d %d", &startR, &startC);
	scanf_s("%d %d", &finishR, &finishC);

	for (int i = 1; i < (5 + 1); i++) {
		for (int j = 1; j < 5 + 1; j++) {
			fscanf_s(in, "%d", &maze[i][j]);
		}
	}
	
	for (int i = 0; i < (5 + 2); i++) {
		maze[0][i] = 1;
		maze[i][0] = 1;
		maze[5 + 1][i] = 1;
		maze[i][5 + 1] = 1;
	}

	
	if (findPath(maze, mark, startR, startC, finishR, finishC)) {
		printpath(maze, mark);
	}
}