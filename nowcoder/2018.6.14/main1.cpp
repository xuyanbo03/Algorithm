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

struct star{
	int x;
	int y;
}a[100005];

int cmpp(star a1,star a2){
	if(a1.x<a2.x){
		return true;
	}else{
		return false;
	}
}

int main(){
	int n,m,t1,t2;
	int a1,a2,b1,b2;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d %d",&t1,&t2);
		a[i].x=t1;
		a[i].y=t2;
	}
	sort(a,a+n,cmpp);
//	for(int i=0;i<n;i++){
//		cout<<a[i].x<<a[i].y<<endl;
//	}
	scanf("%d",&m);
	while(m--){
		scanf("%d %d %d %d",&a1,&b1,&a2,&b2);
		int count=0,step=0;
//		int rowcha=a2-a1;
//		int colcha=b2-b1;
//		for(int i=0;i<n;i++){
//			if(a[i].x<=a2+1){
//				step++;
//			}else{
//				break;
//			}
//		}
		for(int i=0;i<n;i++){
			if(a[i].x>=a1&&a[i].x<=a2&&a[i].y>=b1&&a[i].y<=b2){
				count++;
			}
			if(a[i].x>a2+1){
				break;
			}
		}
		printf("%d\n",count);
	}
	return 0;
}

//ģ���Ż� 

//��Ŀ����
//һ��һ�������������춼��С���ǣ�ţţ�����������ģ������ڴ��������ǡ�
//ţţ������ͼ����һ��ƽ�棬���Ͻ�Ϊԭ��(����Ϊ(1, 1))��������n�����ǣ�����ÿ�����Ƕ���������(xi��yi)����ʾ��������ڵ�x�У���y�С�
//���ڣ�ţţ������m�����⣬���������������(a1, b1)(a2��b2)����ʾһ�����ε����Ͻǵĵ���������½ǵĵ����꣬����������������ж��ٿ����ǣ��߽��ϵĵ�Ҳ���Ǿ����ڣ���
//��������:
//��һ������һ������n(1��n��100000)����ʾ���ǵĿ�����
//��������n�У�ÿ������������xi��yi(1��xi��yi��1000������ʾ���ǵ�λ�á�
//Ȼ������һ������m(1��m��100000), ��ʾţţѯ������ĸ�����
//������m�У�ÿ�������ĸ�����a1��b1��a2��b2(1��a1��a2��1000), (1��b1��b2��1000��
//��Ŀ��֤�������ǲ��������ͬһ��λ�á�
//�������:
//���һ������m�У�ÿ�б�ʾ��֮��Ӧ��ÿ������Ĵ𰸡�
//ʾ��1
//����
//4
//1 1
//2 2
//3 3
//1 3
//4
//1 1 2 2
//1 1 3 3
//2 2 3 3
//1 2 2 3
//���
//2
//4
//2
//2
