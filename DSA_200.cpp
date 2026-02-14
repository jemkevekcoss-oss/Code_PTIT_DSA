#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
int a[5000001];

void selection_sort(int a[],int n) {
    for(int i=0; i < n-1;i++) {
        int i_min = i;
        for(int j = i+1;j < n;j++) {
            if(a[j] < a[i_min]) i_min = j;
        }
        swap(a[i],a[i_min]);
    }
}
void Bubble_sort(int a[],int n) {
    for(int i=0; i < n-1;i++) {
        bool check = false;
        for(int j=0; j < n-i-1;j++) {
            if(a[j] > a[j+1]) {
                check = true;
                swap(a[j],a[j+1]);
            }
        }
        if(!check) break;
    }
}

void insertion_sort(int a[],int n) {

    for(int i=1; i < n;i++) {
        int key = a[i];
        int pos = i-1;
        while(pos >= 0 && a[pos] > key) {
            a[pos+1] = a[pos];
            --pos;
        }
        a[pos+1] = key;
    }
}

int Partition(int a[],int l,int r) {
    int pivot = a[r];
    int i = l-1;
    for(int j = l; j < r;j++) {
        if(a[j] <= pivot) {
           swap(a[++i],a[j]);
        }
    }
    swap(a[++i],a[r]);
    return i;
}
void quick_sort(int a[],int l,int r) {
    if(l < r) {
        int pos = Partition(a,l,r);
        quick_sort(a,l,pos-1);
        quick_sort(a,pos+1,r);
    }
}

void Merge(int a[],int l,int m,int r) {
    int n1 = m-l+1, n2 = r-m;
    int arr1[n1], arr2[n2];
    int idx = 0;
    for(int i=l; i <= m;i++) arr1[idx++] = a[i];
    idx = 0;
    for(int i=m+1;i <= r;i++) arr2[idx++] = a[i];

    idx = l;
    int i,j; i = j = 0;
    while(i < n1 && j < n2) {
        if(arr1[i] <= arr2[j]) a[idx++] = arr1[i++];
        else a[idx++] = arr2[j++];
    }
    while(i < n1) a[idx++] = arr1[i++];
    while(j < n2) a[idx++] = arr2[j++];
}

void merge_sort(int a[],int l,int r) {
    if(l < r) {
        int m = (r+l)/2;
        merge_sort(a,l,m);
        merge_sort(a,m+1,r);
        Merge(a,l,m,r);
    }
}

void count_sort(int arr[],int n,int pos) {
    int cnt[10] = {0}, presum[10] = {0};

    for(int i=0; i < n;i++)
        cnt[(arr[i]/pos)%10]++;

    vector <int> ans[10]; //0 -> 9
    for(int i=0; i < n;i++)
        ans[(arr[i]/pos)%10].push_back(arr[i]);

    int idx = 0;
    for(int i=0; i < 10;i++) {
        if(!ans[i].empty()) {
            for(const int& x : ans[i]) {
                arr[idx++] = x;
            }
        }
    }
}



void radix_sort(int arr[],int n) {
    int maxx = arr[0];
    for(int i=1; i < n;i++)
        maxx = max(maxx,arr[i]);

    int pos = 1;
    while((maxx/pos) > 0) {
        count_sort(arr,n,pos);
        pos *= 10;
    }
}

void cnt_sort(int a[],int n) {
    int k = -1e9;
    for(int i=0; i < n;i++) {
        k = max(k,a[i]);
    }
    int dem[5000001]; //////////////////////
    memset(dem,0,sizeof(dem));
    for(int i = 0; i < n;i++) {
        ++dem[a[i]];
    }
    for(int i=0; i <= k;i++) {
        while(dem[i]) {
            cout << i << ' ';
            --dem[i];
        }
    }
}


int main() {

    int t; cin >> t;
    while(t--) {
        cin >> n;
        for(int i=0; i < n;i++) cin >> a[i];


        if( n <= 1000) Bubble_sort(a,n);
        else if(n <= 10000) insertion_sort(a,n);
        else if(n <= 100000) quick_sort(a,0,n-1);
        else if(n <= 1000000) merge_sort(a,0,n-1);
        else if(n <= 5000000) radix_sort(a,n);

        for(int i=0; i < n;i++) cout <<  a[i] << ' ';
        cout << '\n';

    }

    return 0;
}



/*
TH1: 0 < n < 1000
  + Selection Sort, Bubble Sort, Insertion Sort.
TH2: 0 < n ≤ 10.000
  + Insertion Sort
TH3: 0 < n ≤ 100.000
  + Merge Sort, Quick Sort, Heap Sort
TH4: 0 < n ≤ 1.000.000
  + Merge Sort, Counting Sort
TH5: 0 < n ≤ 5.000.000
  + Counting Sort, Radix Sort
*/



/*
3
4
5 7 1 4
7
123 456 100 989 444 111 90
8
170 45 75 90 802 24 2 66
*/
