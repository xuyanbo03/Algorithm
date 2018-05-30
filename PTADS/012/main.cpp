#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
using namespace std;
const int inf=0x3f3f3f3f;
const double epx=1e-10;
typedef long long ll;
const ll INF=1e18;
int N=10010;

int main(){
	int k;
	cin>>k;
	int a[N]={0};
	for(int i=0;i<k;i++){
		cin>>a[i];
	}
	
	int ThisSum=a[0];
	int MaxSum=a[0];
	int count=0;
	int left=0;
	int right=0;
	for(int i=0;i<k;i++){
		ThisSum+=a[i];
		count++;
		if(ThisSum>MaxSum){
			MaxSum=ThisSum;
			left=i-count+1;
			right=i;
		}else if(ThisSum<0){
			ThisSum=0;
			count=0;
		}
	}
	
	cout<<MaxSum<<" "<<left<<" "<<right<<endl;
	return 0;
}

//01-¸´ÔÓ¶È2 Maximum Subsequence Sum£¨25 ·Ö£©
//Given a sequence of K integers { N
//?1
//?? , N
//?2
//?? , ..., N
//?K
//??  }. A continuous subsequence is defined to be { N
//?i
//?? , N
//?i+1
//?? , ..., N
//?j
//??  } where 1¡Üi¡Üj¡ÜK. The Maximum Subsequence is the continuous subsequence which has the largest sum of its elements. For example, given sequence { -2, 11, -4, 13, -5, -2 }, its maximum subsequence is { 11, -4, 13 } with the largest sum being 20.
//
//Now you are supposed to find the largest sum, together with the first and the last numbers of the maximum subsequence.
//
//Input Specification:
//Each input file contains one test case. Each case occupies two lines. The first line contains a positive integer K (¡Ü10000). The second line contains K numbers, separated by a space.
//
//Output Specification:
//For each test case, output in one line the largest sum, together with the first and the last numbers of the maximum subsequence. The numbers must be separated by one space, but there must be no extra space at the end of a line. In case that the maximum subsequence is not unique, output the one with the smallest indices i and j (as shown by the sample case). If all the K numbers are negative, then its maximum sum is defined to be 0, and you are supposed to output the first and the last numbers of the whole sequence.
//
//Sample Input:
//10
//-10 1 2 3 4 -5 -23 3 7 -21
//Sample Output:
//10 1 4
