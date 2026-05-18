#include <stdio.h>
#include <stdlib.h>

enum {operand,lparen, rparen, plus, minus, times, divide, mod, eos};

int stack[50] = { 0 };
int top = -1;


int pop() {
	if (top == -1) {
		exit(1);

	}
	return stack[top--];
}
void push(int i) {
	if (top > 50) {
		exit(1);
	}
	stack[++top] = i;
}

void print_token(int t, char* arr, int *idx) {
	switch(t) {
	case plus:
		printf("+"); arr[(*idx)++] = '+';break;
	case minus:
		printf("-");arr[(*idx)++] = '-'; break;
	case mod:
		printf("%%");arr[(*idx)++] = '%';break;
	case times:
		printf("*");arr[(*idx)++] = '*'; break;
	case divide:
		printf("/");arr[(*idx)++] = '/';break;
	}
}

char* transition_postfix(char * arr) {
	static int isp[] = { 0,0, 19,12,12,13,13,13,0 };
	static int icp[] = { 0,20, 19,12,12,13,13,13,0 };
	int idx = 0;
	char symbol;
	char *tarr= (char*)malloc(sizeof(char)*50);
	int tidx = 0;
	top = 0;
	stack[top] = eos;
	while ((symbol = get_token(arr, &idx)) != eos) {
		if (symbol == operand) {
			printf("%d", arr[idx - 1] - '0');
			tarr[tidx++] = arr[idx - 1];
		}
		else if (symbol == rparen) {
			while (symbol != lparen) {
				symbol = pop();
				print_token(symbol, tarr, &tidx);
							
			}
			

		}
		else {
			while (isp[stack[top]] >= icp[symbol]) {
				print_token(pop(), tarr, &tidx);
			}
			push(symbol);
		}
	}
	while ((symbol = pop())!=eos) {
		print_token(symbol, tarr, &tidx);
	}
	tarr[tidx] = '\0';
	return tarr;
}



int get_token(char *arr, int *idx) {
	char c = arr[(*idx)++];

	switch(c) {
		case('('): return lparen;
		case(')'): return rparen;
		case('+'): return plus;
		case('-'): return minus;
		case('/'): return divide;
		case('%'): return mod;
		case('*'): return times;
		case('\0'): return eos;
		default: return operand;
	}



}

void eval(char* arr) {
	int idx = 0;
	char symbol;
	top = -1;
	while ((symbol = get_token(arr, &idx)) != eos) {
		if (symbol == operand) {
			push(arr[idx - 1] - '0');
		}
		else{
			int op2 = pop();
			int op1 = pop();
			switch (symbol) {
			case plus: push(op1 + op2);
				break;
			case minus:push(op1 - op2);
				break;
			case divide:push(op1 / op2);
				break;
			case mod:push(op1 % op2);
				break;
			case times:push(op1 * op2);
				break;

			}
		}
	}
	printf("\n%d", pop());
	
}

int main() {

	FILE* in;
	fopen_s(&in, "in.txt", "r");
	char arr[50] = { 0 };
	char* tra;
	fscanf_s(in, "%s", arr, 50);
	tra = transition_postfix(arr);
	eval(tra);
}