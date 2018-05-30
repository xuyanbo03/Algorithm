#include "bits/stdc++.h"
using namespace std;

typedef struct PloyNode *Ploynomial;

struct PloyNode {
	int coef; //ϵ��
	int expon; //ָ��
	Ploynomial link;
};

void Attach(int c, int e, Ploynomial *pRear) {  //��ΪҪ�޸�ָ���ֵ�������Ҫ����ָ���ָ��
	Ploynomial p;
	p = (Ploynomial)malloc(sizeof(struct PloyNode));
	p->coef = c;
	p->expon = e;
	p->link = NULL;
	(*pRear)->link = p;
	*pRear = p; //�޸�pReal
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
		Attach(c, e, &Rear);//��ΪҪ�޸�ָ���ֵ����˱��봫���ַ
	}
	//ɾ�����õ�ͷ���
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
	free(t);//ɾ�����õ�ͷ���
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
	// ��ð�ݰѶ���ʽ����ָ����������
	t1 = p;
	while (t1->link) {
		t2 = p;
		while (t2->link) {
			if (t2->expon < t2->link->expon) {//����λ��
				swap(t2->expon, t2->link->expon);
				swap(t2->coef, t2->link->coef);
			} else if (t2->expon == t2->link->expon) { //ָ����ȣ��ϲ�
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



//02-���Խṹ2 һԪ����ʽ�ĳ˷���ӷ����㣨20 �֣�
//��ƺ����ֱ�������һԪ����ʽ�ĳ˻���͡�
//
//�����ʽ:
//�����2�У�ÿ�зֱ��ȸ�������ʽ������ĸ���������ָ���ݽ���ʽ����һ������ʽ������ϵ����ָ��������ֵ��Ϊ������1000�������������ּ��Կո�ָ���
//
//�����ʽ:
//�����2�У��ֱ���ָ���ݽ���ʽ����˻�����ʽ�Լ��Ͷ���ʽ�������ϵ����ָ�������ּ��Կո�ָ�������β�����ж���ո������ʽӦ���0 0��
//
//��������:
//4 3 4 -5 2  6 1  -2 0
//3 5 20  -7 4  3 1
//�������:
//15 24 -25 22 30 21 -10 20 -21 8 35 6 -33 5 14 4 -15 3 18 2 -6 1
//5 20 -4 4 -5 2 9 1 -2 0
