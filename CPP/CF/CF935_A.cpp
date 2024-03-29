# include<iostream>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int a, b, c;
        cin >> a >> b >> c;
        int ans = 0;
        if(b % 3 + c < 3 && b % 3 != 0)
            ans = -1;
        else{
            ans += a;
            if(b % 3 != 0)
                ans += b/3 + 1, c -= (3 - b%3);
            else
                ans += b/3;
            ans += c/3;
            if(c%3 != 0)
                ans += 1;
        }
        cout << ans << endl;
    }
    return 0;
}