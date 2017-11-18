#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

char s[10];

//È«ÅÅÁÐÄ£°å 
//void Permutation(char *pStr,char *pBegin){
//	if(*pBegin == '\0'){
//		printf("%s\n",pStr);
//	}else{
//		for(char* pCh = pBegin;*pCh != '\0';pCh++){
//			swap(*pBegin,*pCh);
//			Permutation(pStr,pBegin+1);
//			swap(*pBegin,*pCh);
//		}
//	}
//} 

int main() {
	while(cin>>s){
		int len=strlen(s);
		sort(s,s+len);
		do{
			cout<<s<<endl;
		}while(next_permutation(s,s+len));
	}
	return 0;
}
