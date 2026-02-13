#include <bits/stdc++.h>
using namespace std;

bool prime[200001];
void sieve() {
    for(int i=0;i <= 200000;i++) {
        prime[i] = true;
    }
    prime[0] = prime[1] = false;
    for(int i = 2; i <= sqrt(200000);i++) {
        if(prime[i]) {
            for(int j=i*i; j <= 200000;j += i) {
                prime[j] = false;
            }
        }
    }
}

int n,k, stt;
int x[30];

void Try(int i) {

    if(i > k) {
        stt++;
        if(prime[stt]) {
            cout << stt << ": ";
            for(int j = 1; j <= k;j++) cout << x[j] << ' ';
            cout << '\n';
        }
        return;
    }

    for(int j=x[i-1]+1; j <= n-k+i;j++) {
        x[i] = j;
        Try(i+1);
    }

}

int main() {
    sieve();

    memset(x,0,sizeof(x));
    cin >> n >> k;
    stt = 0;
    Try(1);


    return 0;
}

