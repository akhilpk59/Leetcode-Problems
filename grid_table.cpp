#include<iostream>

using namespace std;

int main(){

    int m,n;
    cin>>m>>n;
    double arr[m+1][n+1];
    for (int i=0;i<=m;i++){
        for (int j=0;j<=n;j++){
            arr[i][j] = 0;
        }
    }
    arr[1][1] = 1;

    for (int i=0;i<=m;i++){
        for (int j=0;j<=n;j++){
            if (i!=m) arr[i+1][j] += arr[i][j];
            if (j!=n) arr[i][j+1] += arr[i][j];
        }
    }
    cout<<arr[m][n]<<endl;
    return 0;
}