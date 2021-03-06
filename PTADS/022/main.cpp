#include "bits/stdc++.h"
using namespace std;

typedef struct PloyNode *Ploynomial;

struct PloyNode {
	int coef; //系数
	int expon; //指数
	Ploynomial link;
};

void Attach(int c, int e, Ploynomial *pRear) {  //因为要修改指针的值，因此需要传入指针的指针
	Ploynomial p;
	p = (Ploynomial)malloc(sizeof(struct PloyNode));
	p->coef = c;
	p->expon = e;
	p->link = NULL;
	(*pRear)->link = p;
	*pRear = p; //修改pReal
}

Ploynomial ReadPloy() {
	Ploynomial p, Rear, t;
	int c, e, N;
	cin >> N;
	if (!N) return NULL;
	p = (Ploynomial)malloc(sizeof(struct PloyNode));
	p->link = NULL;
	Rear = p;
	while (N--) {
		cin >> c >> e;
		Attach(c, e, &Rear);//因为要修改指针的值，因此必须传入地址
	}
	//删除无用的头结点
	t = p;
	p = p->link;
	free(t);
	return p;
}

Ploynomial Add(Ploynomial p1, Ploynomial p2) {
	if (!p1) return p2;
	if (!p2) return p1;
	Ploynomial t1, t2, p, Rear, t;
	t1 = p1;
	t2 = p2;
	p = (Ploynomial)malloc(sizeof(struct PloyNode));
	p->link = NULL;
	Rear = p;
	while (t1&&t2) {
		if (t1->expon == t2->expon) {
			int sum = t1->coef + t2->coef;
			if (sum) Attach(sum, t1->expon, &Rear);
			t1 = t1->link;
			t2 = t2->link;
		} else if (t1->expon > t2->expon) {
			Attach(t1->coef, t1->expon, &Rear);
			t1 = t1->link;
		} else {
			Attach(t2->coef, t2->expon, &Rear);
			t2 = t2->link;
		}
	}
	while (t1) {
		Attach(t1->coef, t1->expon, &Rear);
		t1 = t1->link;
	}
	while (t2) {
		Attach(t2->coef, t2->expon, &Rear);
		t2 = t2->link;
	}
	t = p;
	p = p->link;
	free(t);//删除无用的头结点
	return p;
}
Ploynomial Mult(Ploynomial p1, Ploynomial p2) {
	if (!p1 || !p2) return NULL;
	Ploynomial t1, t2, p, Rear, t;
	t1 = p1;
	p = (Ploynomial)malloc(sizeof(struct PloyNode));
	p->link = NULL;
	Rear = p;

	while (t1) {
		t2 = p2;
		while (t2) {
			Attach(t1->coef*t2->coef, t1->expon + t2->expon, &Rear);
			t2 = t2->link;
		}
		t1 = t1->link;
	}
	t = p;
	p = p->link;
	free(t);
	// 用冒泡把多项式按照指数降序排列
	t1 = p;
	while (t1->link) {
		t2 = p;
		while (t2->link) {
			if (t2->expon < t2->link->expon) {//交换位置
				swap(t2->expon, t2->link->expon);
				swap(t2->coef, t2->link->coef);
			} else if (t2->expon == t2->link->expon) { //指数相等，合并
				t = t2->link;
				t2->coef += t->coef;
				t2->link = t->link;
				free(t);
			}
			t2 = t2->link;
		}
		t1 = t1->link;
	}


	return p;
}

void PrintPloy(Ploynomial p) {
	if (!p) {
		cout << "0 0";
		return;
	}
	bool ans = true;
	if (p->coef) {
		cout << p->coef << ' ' << p->expon;
		ans = false;
	}
	p = p->link;
	while (p) {
		if (p->coef) {
			cout << ' ' << p->coef << ' ' << p->expon;
			ans = false;
		}
		p = p->link;
	}
	if (ans) cout << "0 0";
}
int main() {
	Ploynomial p1, p2, pp, ps;
	p1 = ReadPloy();
	p2 = ReadPloy();
	pp = Mult(p1, p2);
	PrintPloy(pp);
	cout << endl;
	ps = Add(p1, p2);
	PrintPloy(ps);
	return 0;
}



//02-线性结构2 一元多项式的乘法与加法运算（20 分）
//设计函数分别求两个一元多项式的乘积与和。
//
//输入格式:
//输入分2行，每行分别先给出多项式非零项的个数，再以指数递降方式输入一个多项式非零项系数和指数（绝对值均为不超过1000的整数）。数字间以空格分隔。
//
//输出格式:
//输出分2行，分别以指数递降方式输出乘积多项式以及和多项式非零项的系数和指数。数字间以空格分隔，但结尾不能有多余空格。零多项式应输出0 0。
//
//输入样例:
//4 3 4 -5 2  6 1  -2 0
//3 5 20  -7 4  3 1
//输出样例:
//15 24 -25 22 30 21 -10 20 -21 8 35 6 -33 5 14 4 -15 3 18 2 -6 1
//5 20 -4 4 -5 2 9 1 -2 0
