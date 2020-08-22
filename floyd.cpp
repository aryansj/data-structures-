#include<bits/stdc++.h>
using namespace std;

int main(){
    int c, f, i, j, k;
    cin >> c >> f;
    int arr[c][c];
    for(i = 0; i < c; i++)
        for(j = 0; j < c; j++){
            arr[i][j] = INT_MAX;
            if( i == j )
                arr[i][j] = 0;
        }    

    for(i = 0; i < f; i++){
        int x, y, p;
        cin >> x >> y >> p;
        arr[x-1][y-1] = p;
        arr[y-1][x-1] = p;
    }

     for(k = 0; k < c; k++){
         for(i = 0; i < c; i++){
             for(j = 0; j < c; j++){
                 if( arr[i][k] != INT_MAX && arr[k][j] != INT_MAX)
                    arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
             }
         }
    }
    int maxPrice = 0;
    for(i = 0; i < c; i++){
        for(j = 0; j < c; j++){
             maxPrice = max(maxPrice, arr[i][j]);
        }
    }

    cout << maxPrice << endl;
    return 0;
}