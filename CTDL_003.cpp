#include <bits/stdc++.h>
using namespace std;

int n;
int a[20];
bool ok;


void init() {
    ok = true;
    cin >> n;
    for(int i=1; i <= n;i++) a[i] = i;
}

void sinhHV() {
    int pos = n-1;
    while(pos > 0 && a[pos] > a[pos+1]) {
        --pos;
    }
    if(pos <= 0) {
        ok = false;
    }
    else {
        int j = n;
        while(a[pos] > a[j]) --j;
        swap(a[pos],a[j]);
        reverse(a+pos+1,a+n+1);
    }
}



int main() {

    init();
    int stt = 0;
    while(ok) {
        ++stt; cout << stt << ": ";
        for(int i=1; i <= n;i++) cout << a[i] << ' ';
        cout << '\n';
        sinhHV();

    }

}




/*


*/
