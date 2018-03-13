#include<iostream>
#include<cstdio>
using namespace std;

int main(){
	int col;
	char c;
	scanf("%d %c",&col,&c);
	int row;
	if(col%2==0){
		row=col/2;
	}else{
		row=col/2+1; 
	}
	for(int i=0;i<col;i++){
		printf("%c",c);
	}
	printf("\n");
	for(int i=0;i<row-2;i++){
		printf("%c",c);
		for(int j=1;j<col-1;j++){
			printf(" ");
		}
		printf("%c",c);
		printf("\n");
	}
	for(int i=0;i<col;i++){
		printf("%c",c);
	}
	return 0;
}

