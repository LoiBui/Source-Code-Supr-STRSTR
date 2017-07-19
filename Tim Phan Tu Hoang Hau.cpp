#include <stdio.h>
#include <conio.h>

void Nhap(int a[][100], int m, int n)
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

void Xuat(int a[][100], int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%4d", a[i][j]);
		}
		printf("\n");
	}
}

int KiemTraTrenHang(int a[][100], int m, int n, int Hang)
{
	int max = a[Hang][0];

	for (int i = 0; i < n; i++)
	{
		if (max < a[Hang][i])
		{
			max = a[Hang][i];
		}
	}
	return max;

}

int KiemTraTrenCot(int a[][100], int m, int n, int Cot)
{
	int max = a[0][Cot];

	for (int i = 0; i < m; i++)
	{
		if (max < a[i][Cot])
		{
			max = a[i][Cot];
		}
	}
	return max;
}

int KiemTraTrenDuongCheoChinh(int a[][100], int m, int n, int Hang, int Cot)
{
	int StartX = Hang;
	int StartY = Cot;

	while (StartX >= 0 && StartY >= 0)
	{
		StartX--;
		StartY--;
	}
	StartX++;
	StartY++;
	

	int EndX = Hang;
	int EndY = Cot;

	while (EndX < m && EndY < n)
	{
		EndX++;
		EndY++;
	}
	EndX--;
	EndY--;
	

	int max = a[Hang][Cot];
	while (StartX <= EndX && StartY <= EndY)
	{
		if (a[StartX][StartY] > max)
		{
			max = a[StartX][StartY];
		}
		StartX++;
		StartY++;
	}
	
	return max;
}

int KiemTraTrenDuongCheoPhu(int a[][100], int m, int n, int Hang, int Cot)
{
	int StartX = Hang;
	int StartY = Cot;
	while (StartX >= 0 && StartY < n)
	{
		StartX--;
		StartY++;
	}
	StartX++;
	StartY--;
	//printf("\nStartX = %d && StartY = %d", StartX, StartY);

	int EndX = Hang;
	int EndY = Cot;
	while (EndX < m && EndY >= 0)
	{
		EndX++;
		EndY--;
	}
	EndX--;
	EndY++;
	//printf("\nEndX = %d && EndY = %d", EndX, EndY);

	int max = a[Hang][Cot];
	while (StartX <= EndX && StartY >= EndY)
	{
		if (max < a[StartX][StartY])
		{
			max = a[StartX][StartY];
		}
		StartX++;
		StartY--;
	}
	//printf("\nmax = %d", max);
	return max;
	
}

void Processing(int a[][100], int m, int n)
{
	
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int Check1 = KiemTraTrenCot(a, m, n, j);
			int Check2 = KiemTraTrenHang(a, m, n, i);
			int Check3 = KiemTraTrenDuongCheoChinh(a, m, n, i, j);
			int Check4 = KiemTraTrenDuongCheoPhu(a, m, n, i, j);

			if (Check1 == Check2 && Check1 == Check3 && Check1 == Check4)
			{
				printf("\nPhan Tu Hoang Hau La: %d va tai vi tri %d va %d", a[i][j], i, j);
			}
		}
	}

}
int main()
{
	int a[100][100], m, n;
	printf("Nhap Vao So Dong Va So Cot: ");
	scanf_s("%d%d", &m, &n);

	Nhap(a, m, n);
	Xuat(a, m, n);

	Processing(a, m, n);

	_getch();
	return 0;
}