#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<vector>
#include<map>
#include<sstream>
#include<algorithm>
using namespace std;
const int inf=0x3f3f3f3f;
const double epx=1e-10;
typedef long long ll;
const ll INF=1e18;

const int EAST = 0;
const int SOUTH = 1;
const int SOUTHWEST = 2;
const int NORTHEAST = 3;
struct {
    int drow;
    int dcol;
}direct[4] = {{0, 1}, {1, 0}, {1, -1}, {-1, 1}};

const int N = 500;
int a[N][N];

int main(){
	int n; 
    cin >> n;
    for(int i=0; i<n; i++){
    	for(int j=0; j<n; j++){
    		cin >> a[i][j];
		}
	} 
    int row=0, col=0, next=EAST;
    cout << a[row][col];
    while(row != n - 1 || col != n - 1) {
        row += direct[next].drow;
        col += direct[next].dcol;
        cout << " " << a[row][col];

        if(next == EAST && row == 0)  
            next = SOUTHWEST;  
        else if(next == EAST && row == n - 1)  
            next = NORTHEAST;  
        else if(next == SOUTH && col == 0)  
            next = NORTHEAST;  
        else if(next == SOUTH && col == n - 1)  
            next = SOUTHWEST;  
        else if(next == SOUTHWEST && row == n - 1)  
            next = EAST;  
        else if(next == SOUTHWEST && col == 0)  
            next = SOUTH;  
        else if(next == NORTHEAST && col == n - 1)  
            next = SOUTH;  
        else if(next == NORTHEAST && row == 0)  
            next = EAST;  
    }
    cout << endl;
	return 0;
}

