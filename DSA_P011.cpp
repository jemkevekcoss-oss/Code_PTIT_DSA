#include <bits/stdc++.h>

using namespace std;



int n,m;
char a[1005][1005];
int cnt = 0;// Dem so vat can

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

void input() {
    cin >> n >> m;
    for(int i=0; i < n;i++) {
        for(int j=0 ; j < m;j++) {
            cin >> a[i][j];
        }
    }
}

void solve(int i,int j) {
    a[i][j] = '.'; //Coi nhu da duyet qua
    for(int k=0; k < 4;k++) {
        int i1 = i + dx[k];
        int j1 = j + dy[k];
        if((i1>=0&&i1<n) && (j1>=0&&j1<m) && a[i1][j1] == '#') {
            solve(i1,j1);
        }
    }

}

int main() {


    for(int i=0; i < n;i++) {
        for(int j=0 ; j < m;j++) {
            if(a[i][j] == '#') {
                ++cnt;
                solve(i,j);
            }
        }
    }
    cout << cnt;



}





/*
5 6
.#....
..#...
..#..#
...##.
.#....
*/








//Co the su dung BFS:
/*
void BFS(int i,int j) {
    queue <pair<int,int>> q;
    q.push({i,j});
    a[i][j] = '.'; //Danh dau da duyet qua
    while(!q.empty()) {
        pair<int,int> p = q.front();
        q.pop();
        for(int k=0; k < 4;k++) {
            int i1 = p.first + dx[k];
            int j1 = p.second + dy[k];
            if((i1>=0&&i1<n) && (j1>=0&&j1<m) && a[i1][j1] == '#') {
                q.push({i1,j1});
                a[i1][j1] = '.';
            }
        }

    }

}
*/



