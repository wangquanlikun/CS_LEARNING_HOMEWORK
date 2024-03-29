#include<iostream>
using namespace std;

bool is(int n){
    if(n == 1)
        return true;
    while(n){
        if(n%10 == 1 || n%10 == 0)
            n = n/10;
        else
            return false;
    }
    return true;
}

bool x(int n){
    if(is(n) || n == 1)
        return true;
    else{
        for(int i=2; i*i <= n; i++){
            if(n%i == 0){
                if(is(i) && x(n/i))
                    return true;
            }
        }
        return false;
    }
}

int main(){
    int t;
    cin >> t;
    for(int i=0; i<t; i++){
        int n;
        cin >> n;
        if(is(n)){
            cout << "YES" << endl;
            continue;
        }
        else{
            if(x(n))
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
    return 0;
}