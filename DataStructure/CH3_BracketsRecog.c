#include<stdio.h>
#include<string.h>

#define MAX 1000
char stack[MAX];
int stacktop = 0;

void pop(char input);
void preprocess(void);
int check(void);

int main(){
    for (int i = 0; i < MAX;i++)
        stack[i] = '\0'; //初始化栈

    char input;
    while((input = getchar()) != EOF){
        if(input == '(' || input == '[' || input == '{')
            pop(input);
        else if(input == ')' || input == ']' || input == '}')
            pop(input);
        else if(input == '\n')
            break;
        else
            continue;
    }
    printf("%s", check() == 1 ? "Correct" : "Wrong");
    return 0;
}

void pop(char input){
    stack[stacktop] = input;
    stacktop += 1;
    preprocess();
    return;
}

void preprocess(){
    if(stack[stacktop-1] == ')' && stack[stacktop-2] == '('){
        stack[stacktop-2] = stack[stacktop-1] = '\0';
        stacktop -= 2;
    }
    else if(stack[stacktop-1] == ']' && stack[stacktop-2] == '['){
        stack[stacktop-2] = stack[stacktop-1] = '\0';
        stacktop -= 2;
    }
    else if(stack[stacktop-1] == '}' && stack[stacktop-2] == '{'){
        stack[stacktop-2] = stack[stacktop-1] = '\0';
        stacktop -= 2;
    }
    return;
}

int check(){
    preprocess();
    return stacktop == 0 ? 1 : 0;
}