#include <bits/stdc++.h>
using namespace std;


int n;
string s;

bool rev() {
    int l=0, r= s.length()-1;
    while(l < r) {
        if(s[l] != s[r]) return false;
        ++l;--r;
    }
    return true;
}

void Try(int i) {
    if(i >= n) {
        if(rev()) {
            for(int j=0; j < n;j++) cout << s[j] << ' ';
        }
        return;
    }
    for(int j='0';j <= '1';j++) {
        s[i] = j;
        Try(i+1);
    }
}

int main() {

    cin >> n;
    s = string(n,'0');
    Try(0);

}
