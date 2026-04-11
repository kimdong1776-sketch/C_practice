#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100
#define MAX_STR_SIZE 100
typedef enum { lparen, rparen, plus, minus, times, divide, mod, eos, operand }precedence;

int stack[MAX_STACK_SIZE];
int top = -1;
char str[MAX_STR_SIZE];

int eval();
precedence pop();
void push(int item);
void stack_full();
int InToPost();
precedence get_token(char *symbol, int * n);


int main() {
	printf("컴퓨터학부 2025003170 김동후\n");
	FILE* in;
	fopen_s(&in, "in.txt", "r");

	if (in == NULL) {
		fprintf(stderr, "file open err\n");
		exit(1);
	}

	fscanf_s(in, "%s", str);

	InToPost();

	fprintf(stdout, "%d", eval());
	fclose(in);
}

void push(int item) {
	if (top < 100) {
		stack[++top] = item;
		
	}
	else
		stack_full();

}

precedence pop() {
	if (top == -1) {
		return stack_empty();
	}
	else {
		return stack[top--];
	}
}

int stack_empty(){
	return 1;
}

void stack_full() {
	exit(1);
}

precedence get_token(char* symbol, int* n, char* str3) {
	*symbol = str3[(*n)++];
	switch (*symbol) {
	case '(': return lparen;
	case ')': return rparen;
	case '+': return plus;
	case '-': return minus;
	case '/': return divide;
	case '*': return times;
	case '%': return mod;
	case '\0': return eos;
	default: return operand;
	}
}

void print_token(precedence token,FILE* out) {
	switch (token) {
	case plus:
		fprintf(out, "+");
		fprintf(stdout, "+");
		break;
	case minus:
		fprintf(out, "-");
		fprintf(stdout, "-");
		break;
	case times:
		fprintf(out, "*");
		fprintf(stdout, "*");
		break;
	case divide:
		fprintf(out, "/");
		fprintf(stdout, "/");
		break;
	case mod:
		fprintf(out, "%%");
		fprintf(stdout, "%%");
		break;
	}
}


int InToPost() {
	FILE* out;
	fopen_s(&out, "out.txt", "w");

	char symbol;
	precedence token = eos;
	top = 0;
	int n = 0;
	static int isp[] = { 0, 19, 12, 12, 13, 13, 13, 0 };
	static int icp[] = { 20, 19, 12, 12, 13, 13, 13, 0 };
	stack[0] = eos;
	for (token = get_token(&symbol, &n, str); token != eos; token = get_token(&symbol, &n, str)) {
		
		if (token == operand) {
			fprintf(out, "%c", symbol);
			fprintf(stdout, "%c", symbol);
		}
		else if (token == rparen) {
			while (stack[top] != lparen) {
				print_token(pop(), out);
			}
			pop();
		}
		else { //연산자이면
			while (isp[stack[top]] >= icp[token]) {//연산자 우선순위 고려
				print_token(pop(), out); //우선순위에 안맞으면 출력
			}
			push(token); //우선순위 다 매기면 넣어주기
		}
	}
	while ((token = pop()) != eos) {
		print_token(token,out);
	}
	fprintf(stdout, "\n");
	fclose(out);
}

int eval() {
	FILE* f;
	fopen_s(&f, "out.txt", "r");

	char str1[MAX_STR_SIZE] = {0};

	fscanf_s(f,"%s", str1);
	//printf("%s", str1);
	char symbol;
	precedence token;
	int op1, op2;
	int n = 0;

	top = -1;
	token = get_token(&symbol, &n, str1);
	while (token != eos) {
		//printf("%d\n", stack[0]);
		if (token == operand) { // 숫자라면
			push(symbol - '0');
		}
		else {
			op2 = pop();
			op1 = pop();

			switch(token) {
				case plus:
					push(op1 + op2);
					break;
				case minus:
					push(op1 - op2);
					break;
				case times:
					push(op1 * op2);
					break;
				case divide:
					push(op1 / op2);
					break;
				case mod:
					push(op1 % op2);
					break;
			}
		}
		token = get_token(&symbol, &n, str1);
	}
	fclose(f);
	return pop(); //결광
}

