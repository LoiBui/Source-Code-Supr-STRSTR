#include <stdio.h>
#include <conio.h>

void NhapMang(int a[][100], int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("a[%d][%d] = ", i, j);
			scanf_s("%d", &a[i][j]);
		}
	}
}

void XuatMang(int a[][100], int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d    ", a[i][j]);
		}
		printf("\n");
	}
}

int DuongCheoChinh(int a[][100], int n)
{

  /*1  2  3  4
	5  6  7  8
	9  1  2  3
	4  5  6  7
	
	a[0][0] a[1][1] a[2][2] a[3][3]
	*/
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += a[i][i];
	}

	return sum;
}

int DuongCheoPhu(int a[][100], int n)
{
 /*   0  1  2  3

 0    1  2  3  4
 1	  5  6  7  8
 2	  9  1  2  3
 3	  4  5  6  7

	a[0][3] a[1][2] a[2][1] a[3][0]
	*/
	int sum = 0;
	int idx = n - 1;
	for (int i = 0; i < n; i++)
	{
		sum += a[i][idx--];
	}
	return sum;
}
int main()
{
	int a[100][100];
	int n;
	printf("Nhap chieu dai va chieu rong: ");
	scanf_s("%d", &n);
	printf("~~~~~~~~~~ Nhap Vao Mang ~~~~~~~~~~\n");
	NhapMang(a, n, n);
	XuatMang(a, n, n);


	printf("\nTong duong cheo chinh : %d", DuongCheoChinh(a, n));
	printf("\nTong duong cheo phu : %d", DuongCheoPhu(a, n));
	printf("\nTong duong cheo chinh va phu: %d", DuongCheoChinh(a, n) + DuongCheoPhu(a, n));



	_getch();
	return 0;
}