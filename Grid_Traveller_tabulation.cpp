// Same Grid traveller problem but now with tabulation

// Time Complexity ( O(m*n) )   Space-Complexity ( ( O(m*n) ) )

#include <iostream>
#include <vector>
#include <array>
using namespace std;

void GridTravel(int m, int n){
    array<array<int,100>,100> arr;

    for(int i=0; i<=m; i++)
        for(int j=0; j<=n; j++)
            arr[i][j] = 0;

    arr[1][1] = 1;   

    for(int i=0; i<=m; i++)                         //tabulation
        for(int j=0; j<=n; j++){
            if(i+1 <= m)
                arr[i+1][j] += arr[i][j];
            
            if(j+1 <= n)
                arr[i][j+1] += arr[i][j];
        }

    cout<<arr[m][n];
}

int main(){
    GridTravel(3,3);
    return 0;
}