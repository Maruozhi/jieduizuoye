#define _CRT_SECURE_NO_WARNINGS 1


#include<stdio.h>
#include<stdlib.h>






/*��Ϊ���������ֵ��������㣬�����־�Ϊ����������ֻ��Ҫ��д����*/
//�����з����Ļ��򲿷�
void jianhua(int &b1,int &b2) {
	//b1Ϊ���ӣ�b2Ϊ��ĸ
	int i = b2-1;
	while (i > 0) {
		if(b2%i==0)
			if (b1 % i == 0) {
				b2 = b2 / i;
				b1 = b1 / i;
			}
		i--;
	}	
}



//����
void chufa(int str1,int str2,float &sum,int a[]) {
	int c = 0;
	sum = str1 / str2;
	 c = str1 / str2;//cΪ����������������
	int r = str1 % str2;//rΪ����
	//'?'��Ϊ���λ�ã�ǰ���������⵽�ʺ���ֹͣ��ӡ
	if (r == 0) {
		//����
		 a[0] = c;
		 a[1] = '?';
	}
	else if (c == 0) {
		jianhua(r, str2);
		a[0] = r;
		a[1] = '/';
		a[2] = str2;
		a[3] = '?';
	}
	else {
		jianhua(r, str2);
		a[0] = c;
		a[1] = '\'';
		a[2] = r;
		a[3] = '/';
		a[4] = str2;
	}


}



//����
//����i:��ǰ�ж��������ȱȶԴ𰸣�
int chachong(int i,int daan[100],int timu[100][10]) {
	int j = i-1;
	for (; j >= 0; j--) {
		if (daan[i] == daan[j])//�ȶԴ�
			if (timu[i][1] == timu[j][1])//�ȶ��������
				if ((timu[i][0] == timu[j][0] && timu[i][2] == timu[j][2]) || (timu[i][0] == timu[j][2] && timu[i][2] == timu[j][0]
					)) {
					return 1;
				}
	}
}


//��������
//����n����r���ڵ�����
//�涨:nӦ�ô���0,С��100��r����С��10
void shengcheng(int n, int r, int daan[100], int timu[100][10]) {
	if (n < 1 || r < 10 || n>100) {
		printf("�涨:nӦ�ô���0,С��100��r����С��10");
		return;
	}



	int i = 0;
	float sum = 0;
	for (; i < n; i++) {
		int num1 = rand() % r;
		int num2 = rand() % r;
		int fuhao[4] = { '+','-','*','/' };
		int f = rand() % 4;
		int a[5] = { 0,0,0,0,0 };
		switch (f)
		{

		case 0:
			//�ӷ�
			sum = num1 + num2;
			a[0] = sum;
			a[1] = '?';
			break;
		case 1:
			//����
			sum = num1 - num2;
			a[0] = sum;
			a[1] = '?';
			break;
		case 2:
			//�˷�
			sum = num1 * num2;
			a[0] = sum;
			a[1] = '?';
			break;
		case 3:
			//����

			chufa(num1, num2, sum, a);
			break;


		default:
			break;
		}

		//�Ѵ𰸺���Ŀ��������
		daan[i] = (int)sum;
		timu[i][0] = num1;
		timu[i][1] = fuhao[f];
		timu[i][2] = num2;
		timu[i][3] = '=';
		timu[i][4] = a[0];
		timu[i][5] = a[1];
		if (a[1] != '?') {
			timu[i][6] = a[2];
			timu[i][7] = a[3];
			if (a[3] != '?') {
				timu[i][8] = a[4];
				timu[i][9] = '?';
			}
		}
		int flag = 0;
		flag= chachong(i, daan, timu);
		if (flag == 1)i--;
	}
}



//��ӡ��Ŀ
void dayintimu(int n,int timu[100][10]) {
	for (int i = 0; i < n; i++) {
		printf("%d", timu[i][0]);
		printf("%c", timu[i][1]);
		printf("%d", timu[i][2]);
		printf("%c", timu[i][3]);
		printf("?\n");
	}
}
//��ӡ��
void dayindaan(int n,int timu[100][10]) {
	for (int i = 0; i < n; i++) {
		printf("%d", timu[i][4]);
		if (timu[i][5] != '?') {
			printf("%c", timu[i][5]);
			printf("%d", timu[i][6]);
			if (timu[i][7] != '?') {
				printf("%c", timu[i][7]);
				printf("%d", timu[i][8]);
			}
		}
		printf("\n");
	}
}



int main() {
	int daan[100] = {0};
	int timu[100][10] = { 0 };
	int n = 0;
	int r = 0;
	printf("������������Ŀ��\n");
	scanf("%d", &n);
	printf("��������Ŀ��Χ\n");
	scanf("%d", &r);
	shengcheng(n, r,daan,timu);
	dayintimu(n, timu);
	dayindaan(n, timu);
}