#define  _CRT_SECURE_NO_WARNINGS 1
//��1��2��3��4�����֣�����ɶ��ٸ�������ͬ�����ظ����ֵ���λ�������Ƕ��٣�

//#include<stdio.h>
//#include<stdlib.h>
//
//int main()
//{
//	int i = 0;
//	int j = 0;
//	int k = 0;
//	for (i = 1; i < 5; i++)
//	{
//		for (j = 1; j < 5; j++)
//		{
//			for (k = 1; k < 5; k++)
//			{
//				if (i != j&&i!=k&&j != k)
//				{
//					printf("%d%d%d", i, j, k);
//				}
//				printf("\n");
//			}
//		}
//	}
//	system("pause");
//	return 0;
//}

//��ҵ���ŵĽ�������������

//#include<stdio.h>
//#include<stdlib.h>
//
//int main()
//{
//	double i = 0;
//	double bouns1, bouns2, bouns3, bouns4, bouns5, bouns;
//	printf("���������ĵ�������\n");
//	scanf("%lf", &i);
//	bouns1 = 100000 * 0.1;
//	bouns2 = bouns1 + 100000 * 0.075;
//	bouns3 = bouns2 + 200000 * 0.05;
//	bouns4 = bouns3 + 200000 * 0.03;
//	bouns5 = bouns4 + 400000 * 0.015;
//	if (i < 100000)
//	   {
//			bouns = i*0.1;		
//		}
//	else if (i < 200000)
//	{
//		bouns = bouns1 + (i - 100000)*0.075;
//	}
//	else if (i < 400000)
//	{
//		bouns = bouns2 + (i - 200000)*0.05;
//	}
//	else if (i < 600000)
//	{
//		bouns = bouns3 + (i - 400000)*0.03;
//	}
//	else if (i < 1000000)
//	{
//		bouns = bouns4 + (i - 600000)*0.015;	
//	}
//	else if(i>1000000)
//	{
//		bouns = bouns5 + (i - 1000000)*0.01;	
//	}
//	printf("���Ϊ%lf", bouns);
//	system("pause");
//	return 0;
//}

//����ĳ��ĳ��ĳ�գ��ж���һ������һ��ĵڼ��죿

//#include<stdio.h>
//#include<stdlib.h>
//int main()
//{
//	int year,month,day,leap,sum;
//	printf("���������ڣ���ʽΪ�꣬�£��գ����磺2019��4��28��\n");
//	scanf("%d��%d��%d", &year, &month, &day);
//	switch(month)
//	{
//		case 1:
//			sum = 0;
//			break;
//		case 2:
//			sum = 31;
//			break;
//		case 3:
//			sum = 59;
//			break;
//		case 4:
//			sum = 90;
//			break;
//		case 5:
//			sum = 120; 
//			break;
//		case 6:
//			sum = 151;
//			break;
//		case 7:
//			sum = 181; 
//			break;
//		case 8:
//			sum = 212;
//			break;
//		case 9:
//			sum = 243; 
//			break;
//		case 10:
//			sum = 273; 
//			break;
//		case 11:
//			sum = 304;
//			break;
//		case 12:
//			sum = 334;
//			break;
//	}
//	sum = sum + day;
//	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
//	{
//		leap=1;
//	}
//	else
//	{
//		leap=0;
//	}
//	if (leap == 1 && month > 2)
//	{
//		sum++;
//	}
//	printf("%d", sum);
//	system("pause");
//	return 0;
//}

//��һ���������ֽ�������

//#include<stdio.h>
//#include<stdlib.h>
//
//int main()
//{
//	int a, b, c;
//	printf("������������\n");
//	scanf("%d %d %d", &a, &b, &c);
//	int t = 0;
//	if (a > b)
//	{
//		t = a;
//		a = b;
//		b = t;
//	}
//	if (a > c)
//	{
//		t = a; 
//		a = c;
//		c = t;
//	}
//	if (b > c)
//	{
//		t = b;
//		b = c;
//		c = t;
//	}
//	printf("%d %d %d", a, b, c);
//	system("pause");
//	return 0;
//}
//#include<stdio.h>
//#include<stdlib.h>
//int main()
//{
//	int n = 0;
//	printf("������һ����\n");
//	scanf("%d", &n);
//	printf("%d=", n);
//	int i = 0;
//	for (i = 2; i <=n; i++)
//	{
//		while (n%i == 0)
//		{
//			printf("%d", i);
//			n /= i;
//			if (n != 1)
//			{
//				printf("*");
//			}
//		}
//	}
//	printf("\n");
//	system("pause");
//	return 0;
//}

//#include<stdio.h>
//#include<stdlib.h>
//
//int main()
//{
//	int i = 0;
//	char j = 0;
//	printf("������ɼ�\n");
//	scanf("%d", &i);
//	j = (i >= 90) ? 'A' : ((i >= 60) ? 'B' : 'C');
//	printf("%c\n", j);
//	system("pause");
//	return 0;
//}

//�������������Լ������С������

//#include<stdio.h>
//#include<stdlib.h>
//
//int main()
//{
//	int i, j, m, n;
//	printf("������������\n");
//	scanf("%d %d", &i, &j);
//	int k = i*j;
//	int c = i%j;
//	if (i%j == 0)
//	{
//	m=j;
//	n = k / j;
//	
//	}
//	else
//	{
//		while (i%j != 0)
//		{
//			i = j;
//			j = c;
//			c = i%j;
//		}
//	}
//		m = j;
//		n = k / j;
//	
//	printf("���Լ��=%d  ��С������=%d", m, n);
//	system("pause");
//	return 0;
//}

//����һ���ַ����ֱ�ͳ�Ƴ�����Ӣ����ĸ���ո����ֺ������ַ��ĸ�����

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int i = 0;
	int j = 0;
	int m = 0;
	int n = 0;
	char c[99];
	printf("������һ���ַ���\n");
	gets(c);
	char *p =&c[0];
	while (*p!='\0')
	{
		if (*p >= 'a'&&*p <= 'z' || *p >= 'A'&&*p <= 'Z')
		{
			i++;
		}
		else if (*p >= '1' &&*p <= '9')
		{
			j++;
		}
		else if (*p == ' ')
		{
			m++;
		}
		else
		{
			n++;
		}
		p++;
	}
		printf("��ĸ=%d ����=%d �ո�=%d ����=%d", i, j, m, n);
		system("pause");
		return 0;
}






