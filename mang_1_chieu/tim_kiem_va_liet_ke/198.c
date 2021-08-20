// Bài 198/67/SBT Thầy NTTMK: Hãy liệt kê các vị trí mà giá trị tại vị trí đó là giá trị lớn nhất trong mảng một chiều các số thực.

#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <Windows.h>
#define SLPT 100

void NhapMang(int n, double a[])
{
	for (int i = 0; i < n; i++)
	{
		printf("\nNhap vao phan tu thu %d: ", i + 1);
		scanf("%lf", &a[i]);
	}
}

void XuatMang(int n, double a[])
{
	for (int i = 0; i < n; i++)
	{
		printf("%lf ", a[i]);
	}
}

// Kiểm tra giá trị lớn nhất.
double GTLN(int n, double a[])
{
	double max = a[0];
	for (int i = 0; i < n; i++)
	{
		if (max < a[i])
		{
			max  = a[i];
		}
	}
	return max;
}

// Liệt kê giá trị lớn nhất.
void LKGTLN(int n, double a[])
{
	printf("\n\nVi tri co gia tri max: ");
	for (int i = 0; i < n; i++)
	{
		if (GTLN(n, a) == a[i])
		{
			printf("%d ", i);
		}
	}
}

int main()
{
	int n;
	double a[SLPT];

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

	LKGTLN(n, a);

	getch();
	return 0;
}
