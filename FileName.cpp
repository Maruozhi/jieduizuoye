#define _CRT_SECURE_NO_WARNINGS 1


#include<stdio.h>
#include<stdlib.h>






/*因为做两个数字的四则运算，且数字均为正整数，故只需要重写除法*/
//除法中分数的化简部分
void jianhua(int &b1,int &b2) {
	//b1为分子，b2为分母
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



//除法
void chufa(int str1,int str2,float &sum,int a[]) {
	int c = 0;
	sum = str1 / str2;
	 c = str1 / str2;//c为带分数的整数部分
	int r = str1 % str2;//r为分子
	//'?'作为检查位置，前两种情况检测到问号则停止打印
	if (r == 0) {
		//整除
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



//查重
//输入i:当前有多少条，先比对答案，
int chachong(int i,int daan[100],int timu[100][10]) {
	int j = i-1;
	for (; j >= 0; j--) {
		if (daan[i] == daan[j])//比对答案
			if (timu[i][1] == timu[j][1])//比对运算符号
				if ((timu[i][0] == timu[j][0] && timu[i][2] == timu[j][2]) || (timu[i][0] == timu[j][2] && timu[i][2] == timu[j][0]
					)) {
					return 1;
				}
	}
}


//生成运算
//生成n条，r以内的运算
//规定:n应该大于0,小于100，r不能小于10
void shengcheng(int n, int r, int daan[100], int timu[100][10]) {
	if (n < 1 || r < 10 || n>100) {
		printf("规定:n应该大于0,小于100，r不能小于10");
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
			//加法
			sum = num1 + num2;
			a[0] = sum;
			a[1] = '?';
			break;
		case 1:
			//减法
			sum = num1 - num2;
			a[0] = sum;
			a[1] = '?';
			break;
		case 2:
			//乘法
			sum = num1 * num2;
			a[0] = sum;
			a[1] = '?';
			break;
		case 3:
			//除法

			chufa(num1, num2, sum, a);
			break;


		default:
			break;
		}

		//把答案和题目填入数组
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



//打印题目
void dayintimu(int n,int timu[100][10]) {
	for (int i = 0; i < n; i++) {
		printf("%d", timu[i][0]);
		printf("%c", timu[i][1]);
		printf("%d", timu[i][2]);
		printf("%c", timu[i][3]);
		printf("?\n");
	}
}
//打印答案
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
	printf("请输入生成题目数\n");
	scanf("%d", &n);
	printf("请输入题目范围\n");
	scanf("%d", &r);
	shengcheng(n, r,daan,timu);
	dayintimu(n, timu);
	dayindaan(n, timu);
}