#include <bits/stdc++.h>
using namespace std;

int n;
int x[1005];
bool ktr() {
    int l=1,r=n;
    while(l<r) {
        if(x[l]!= x[r]) return false;
        l++;r--;
    }
    return true;
}

void Try(int pos) {
    if(pos > n) {
        if(ktr()) {
            for(int k=1;k<=n;k++) cout << x[k] << ' ';
            cout << '\n';
        }
        return;
    }
    for(int j=0;j<=1;j++) {
        x[pos] = j;
        Try(pos+1);
    }
}


int main() {
    cin >> n;
    Try(1);


}
