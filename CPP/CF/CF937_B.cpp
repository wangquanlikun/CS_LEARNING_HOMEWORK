#include<iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    for(int i=0; i<t; i++){
        int n;
        cin >> n;
        n = n << 1;
        for(int p=0; p<n; p++){
            for(int q=0; q<n; q++){
                int pp = p >> 1;
                int qq = q >> 1;
                if((pp %2 + qq %2) %2)
                    cout << ".";
                else
                    cout << "#";
            }
            cout << endl;
        }
    }
    return 0;
}