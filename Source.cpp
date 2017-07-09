#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <Windows.h>

void textcolor(int x)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}

void Processing(char *s1, char *s2)
{
	int length1 = strlen(s1);
	int length2 = strlen(s2);

	//Bui Cong Loi
	//Cong
	char p[200];
	strcpy_s(p, s1);
	bool check;
	int idx;
	int start, end;
	for (int i = 0; i < length1; i++)
	{
		if (s1[i] == s2[0])
		{
			check = true;
			idx = i + 1;
			for (int j = 1; j < length2; j++)
			{
				if (s1[idx++] != s2[j])
				{
					check = false;
					break;
				}
			}
			if (check == true)
			{
				start = i;
				end = i + length2 - 1;
				for (int k = start; k <= end; k++)
				{
					textcolor(12);
					printf("%c", p[k]);
				}
			}
		}
		if (i < start || i > end)
		{
			textcolor(7);
			printf("%c", s1[i]);
		}
		
	}
	
}

int main()
{
	char s1[200] = "Bui Cong Loi, Cong Loi Bui";
	char s2[200] = "Cong";

	/*int vt = Processing(s1, s2);
	if (vt == -1)
	{
		printf("\nKhong tim thay vi tri");
	}
	else
	{
		printf("\nVi tri : %d", vt);
	}*/
	//puts(s1);
	Processing(s1, s2);

	_getch();
	return 0;
}