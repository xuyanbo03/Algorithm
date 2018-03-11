#include<bits/stdc++.h>
using namespace std;

int main() {
	int a,b,sum=0;
	cin>>a>>b;
	int tmp=a;
	while(tmp<=b) {
		for(int i=0; i<5&&tmp<=b; i++) {
			printf("%5d",tmp);
			sum+=tmp;
			tmp++;
		}
		cout<<endl;
	}
	cout<<"Sum = "<<sum;
	return 0;
}

