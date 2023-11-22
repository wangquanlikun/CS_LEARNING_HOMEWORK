#include<stdio.h>
#include<string.h>

#define MAX 1000

int adjust(char a[MAX], char b[MAX]){
    if(a[0] == '\0' || b[0] == '\0')
        return a[0] == '\0' && b[0] == '\0';
    
    if (b[0] >= 'a' && b[0] <= 'z'){
        if(a[0] != b[0])
            return 0;
        else if(a[0] == b[0])
            return 1 && adjust(&a[1], &b[1]);
    }
    else if(b[0] == '*'){
        for (int i = 0; i < MAX; i++){
            if(adjust(&a[i],&b[1])==1)
                return 1;
            if(a[i]=='\0')
                break;
        }
        return 0;
    }
    else if(b[0] == '?')
        return 1 && adjust(&a[1], &b[1]);
}

int main(){
    char a[MAX] = {0}, b[MAX] = {0};
    scanf("%s", a);
    scanf("%s", b);
    printf("%s", adjust(a, b) == 1 ? "true" : "false");
    return 0;
}