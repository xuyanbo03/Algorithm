#include<iostream>
using namespace std;
#define Null -1

struct node {
	char V;
	int L,R;
} T1[10],T2[10]; // 静态链表

int build(node T[]) {
	int n;
	char c1,c2;
	cin>>n;
	if(n==0)
		return Null;

	int visited[10]= {0}; // 用来寻找根节点
	for(int i=0; i<n; i++) {
		cin>>T[i].V>>c1>>c2;
		if(c1=='-')
			T[i].L=Null;
		else {
			T[i].L=c1-'0';
			visited[T[i].L]=1;// 该节点i被指向了
		}
		if(c2=='-')
			T[i].R=Null;
		else {
			T[i].R=c2-'0';
			visited[T[i].R]=1;// 该节点i被指向了
		}
	}
	for(int i=0; i<n; i++)
		if(visited[i]==0)//未被指向的即根节点
			return i;
}

bool isomorphism(int r1,int r2) {
	if(r1==Null&&r2==Null)// 两棵树都是空树
		return true;
	if((r1==Null&&r2!=Null)||(r1!=Null&&r2==Null))// 一棵树空一棵树不空
		return false;
	if(T1[r1].V!=T2[r2].V)// 树节点值value不相等
		return false;
	if(T1[r1].L==Null&&T2[r2].L==Null)// 两者左子树皆空 转而判断右子树
		return isomorphism(T1[r1].R,T2[r2].R);

	if(T1[r1].L!=Null&&T2[r2].L!=Null &&
	        T1[T1[r1].L].V==T2[T2[r2].L].V)// 两者左子树皆不空 并且左子树的值相等
		return (isomorphism(T1[r1].L,T2[r2].L)&&
		        isomorphism(T1[r1].R,T2[r2].R));// 转而二路递归判断两者的子树
	else
		return (isomorphism(T1[r1].L,T2[r2].R)&&
		        isomorphism(T1[r1].R,T2[r2].L));// 两者左子树有一个空 或 皆不空但值不相等 则交换左右子树再判断
}

int main() {
	int R1,R2;
	R1=build(T1);
	R2=build(T2);
	if(isomorphism(R1,R2))
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;
	return 0;
}




//03-树1 树的同构（25 分）
//给定两棵树T1和T2。如果T1可以通过若干次左右孩子互换就变成T2，则我们称两棵树是“同构”的。例如图1给出的两棵树就是同构的，因为我们把其中一棵树的结点A、B、G的左右孩子互换后，就得到另外一棵树。而图2就不是同构的。
//现给定两棵树，请你判断它们是否是同构的。
//输入格式:
//输入给出2棵二叉树树的信息。对于每棵树，首先在一行中给出一个非负整数N (≤10)，即该树的结点数（此时假设结点从0到N?1编号）；随后N行，第i行对应编号第i个结点，给出该结点中存储的1个英文大写字母、其左孩子结点的编号、右孩子结点的编号。如果孩子结点为空，则在相应位置上给出“-”。给出的数据间用一个空格分隔。注意：题目保证每个结点中存储的字母是不同的。
//
//输出格式:
//如果两棵树是同构的，输出“Yes”，否则输出“No”。
//
//输入样例1（对应图1）：
//8
//A 1 2
//B 3 4
//C 5 -
//D - -
//E 6 -
//G 7 -
//F - -
//H - -
//8
//G - 4
//B 7 6
//F - -
//A 5 1
//H - -
//C 0 -
//D - -
//E 2 -
//输出样例1:
//Yes
//输入样例2（对应图2）：
//8
//B 5 7
//F - -
//A 0 3
//C 6 -
//H - -
//D - -
//G 4 -
//E 1 -
//8
//D 6 -
//B 5 -
//E - -
//H - -
//C 0 2
//G - 3
//F - -
//A 1 4
//输出样例2:
//No
