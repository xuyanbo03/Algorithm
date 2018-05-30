#include<stack>
#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>

using namespace std;
int M,N,K;
int check_stack(vector<int> &v) {
	stack<int> sta;
	sta.push(0);    //dummy element, as sential
	int cap = M + 1;    //stack capacity
	int idx = 0;        //index of vector v
	int num = 1;        //to push to stack
	while(idx != N) {
		while(v[idx]>sta.top()&&sta.size()<cap&&idx<=N)
			sta.push(num++);
		if(v[idx]==sta.top()) {
			sta.pop();
			idx++;
		} else //sta.size>=cap; idx>N
			return 0;   //false
	}
	return 1;   //true
}
int main() {
	//int M,N,K;
	cin>>M>>N>>K;
	vector<int> vec(N,0);   //N pop number
	for(int i = 0; i!=K; ++i) {
		//input to vec
		copy_n(istream_iterator<int>(cin),N,vec.begin());
		cout << (check_stack(vec)?"YES":"NO")<<endl;
	}
}



//02-线性结构4 Pop Sequence（25 分）
//Given a stack which can keep M numbers at most. Push N numbers in the order of 1, 2, 3, ..., N and pop randomly. You are supposed to tell if a given sequence of numbers is a possible pop sequence of the stack. For example, if M is 5 and N is 7, we can obtain 1, 2, 3, 4, 5, 6, 7 from the stack, but not 3, 2, 1, 7, 5, 6, 4.
//
//Input Specification:
//Each input file contains one test case. For each case, the first line contains 3 numbers (all no more than 1000): M (the maximum capacity of the stack), N (the length of push sequence), and K (the number of pop sequences to be checked). Then K lines follow, each contains a pop sequence of N numbers. All the numbers in a line are separated by a space.
//
//Output Specification:
//For each pop sequence, print in one line "YES" if it is indeed a possible pop sequence of the stack, or "NO" if not.
//
//Sample Input:
//5 7 5
//1 2 3 4 5 6 7
//3 2 1 7 5 6 4
//7 6 5 4 3 2 1
//5 6 4 3 7 2 1
//1 7 6 5 4 3 2
//Sample Output:
//YES
//NO
//NO
//YES
//NO
