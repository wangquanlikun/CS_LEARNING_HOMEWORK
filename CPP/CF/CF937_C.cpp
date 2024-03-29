#include<iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    for(int i=0; i<t; i++){
        int a, b;
        scanf("%d:%d", &a, &b);
        if(a < 12 && a > 0){
            printf("%02d:%02d AM\n", a, b);
        } else if(a == 12){
            printf("%02d:%02d PM\n", a, b);
        } else if(a == 0){
            printf("%02d:%02d AM\n", a + 12, b);
        } else {
            printf("%02d:%02d PM\n", a - 12, b);
        }
    }
    return 0;
}