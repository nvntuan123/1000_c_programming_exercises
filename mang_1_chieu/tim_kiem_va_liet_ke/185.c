// Bài 185/65/SBT Thầy NTTMK: Hãy liệt kê các vị trí mà giá trị tại vị trí đó là số chính phương trong mảng một chiều các số nguyên.

#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <Windows.h>
#define SLPT 100

void NhapMang(int n, int a[])
{
	for (int i = 0; i < n; i++)
	{
		printf("\nNhap vao phan tu thu %d: ", i + 1);
		scanf("%d", &a[i]);
	}
}

void XuatMang(int n, int a[])
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
}

// Kiểm tra số chính phương.
int SCP(int a)
{
	if (sqrt((double)a) == int (sqrt((double)a)))
	{
		return 1;
	}
	return 0;
}

// Kiểm tra mảng có số chính phương hay không.
int KTMCP(int n, int a[])
{
	for (int i = 0; i < n; i++)
	{
		if (SCP(a[i]) == 1)
		{
			return 1;
		}
	}
	return 0;
}

// Liệt kê SCP.
void LKSCP(int n, int a[])
{
	if (KTMCP(n, a) == 1)
	{
		printf("\n\nVi tri SCP: ");
		for (int i = 0; i < n; i++)
		{
			if (SCP(a[i]) == 1)
			{
				printf("%d ", i);
			}
		}
	}
	else
	{
		printf("\n\nMang khong co SCP.");
	}
}

int main()
{
	int a[SLPT], n;

	do
	{
		printf("Nhap vao so luong phan tu n: ");
		scanf("%d", &n);

		if (n <= 0 || n > SLPT)
		{
			system("cls");
			printf("Ban nhap sai, xin kiem tra lai (n > 0 va n <= 100).\n\n");
		}
	} while (n <= 0 || n > SLPT);

	NhapMang(n, a);
	printf("\nMang a sau khi nhap la: ");
	XuatMang(n, a);

	LKSCP(n, a);

	getch();
	return 0;
}
