//TLE

#include<iostream>
#include<string>
using namespace std;

int subStringsame(string long_string, string short_string, int left, int right){
    int ans = 0;
    for(int i=left; i<=right; i++){
        if(long_string[i] != short_string[i-left])
            ans++;
        /*if ans>=2 ret save time*/
        if(ans > 1)
            return ans;
    }
    return ans;
}

string stringcpoy(string s, int left, int right){
    string temp;
    for(int i=left; i<=right; i++){
        temp += s[i];
    }
    return temp;
}

int main(){
    int t;
    cin >> t;
    for(int i=0; i<t; i++){
        int n;
        cin >> n;
        string s;
        cin >> s;
        string temp;
        int ans_1 = n;
        int notSamenum = 0;
        for(int i=0; i<n; i++){
            notSamenum = 0;
            temp += s[i];
            for(int j=0; j<n; j+= (i+1)){
                if(subStringsame(s, temp, j, j+i)){
                    notSamenum+= subStringsame(s, temp, j, j+i);
                    if(notSamenum > 1)
                        break;
                }
            }
            if(notSamenum > 1 || (i+1) << 1 > n || n % (i+1) != 0)
                continue;
            else{
                ans_1 = (i+1);
                break;
            }
        }

        int ans_2 = n;
        notSamenum = 0;
        for(int i=1; (i<<1)<n; i++){
            notSamenum = 0;
            temp = stringcpoy(s, i, (i<<1)-1);
            for(int j=0; j<n; j+= (i)){
                if(subStringsame(s, temp, j, j+i-1)){
                    notSamenum += subStringsame(s, temp, j, j+i-1);
                    if(notSamenum > 1)
                        break;
                }
            }
            if(notSamenum > 1 || i << 1 > n || n % i != 0)
                continue;
            else{
                ans_2 = i;
                break;
            }
        }

        cout << min(ans_1, ans_2) << endl;
    }
    return 0;
}