#include <bits/stdc++.h>
using namespace std;

int n,k;
int x[1005];
int a[1005];

vector <vector<int>> res;

void input() {
    cin >> n >> k;
    for(int i=0; i < n;i++) cin >> a[i];

}

void Try(int i,int start,int sum) {

    if(sum == k) {
        vector <int> tmp;
        for(int t = 1; t <= i-1;t++) {
            tmp.push_back(x[t]);
        }
        res.push_back(tmp);
        return;
    }

    for(int j=start; j < n;j++) {
        x[i] = a[j];
        if(sum + a[j] > k) continue;
        Try(i+1,j+1,sum+a[j]);

    }
}

int main() {

    input();
    Try(1,0,0);

    for(int i = res.size()-1; i >= 0;i--) {
        for(int j = 0; j < res[i].size();j++) {
            cout << res[i][j] << ' ';
        }
        cout << '\n';
    }

    cout << res.size();

}

/*
5 50
5 10 15 20 25

*/
