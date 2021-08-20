// Bài 187/65/SBT Thầy NTTMK: Hãy liệt kê các vị trí mà giá trị tại các vị trí đó là giá trị dương nhỏ nhất trong mảng một chiều các số thực.

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

// Kiểm tra mảng có số dương.
double KTSD(int n, double a[])
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] > 0)
		{
			return i;
		}
	}
	return -1;
}

//Tìm số dương nhỏ nhất.
double TSDNN(int n, double a[])
{
	if (KTSD(n, a) != -1)
	{
		int vitri = KTSD(n, a);
		double min = a[vitri];
		for (int i = vitri; i < n; i++)
		{
			if (a[i] > 0)
			{
			if (min > a[i])
			{
				min = a[i];
			}
			}
		}
		return min;
	}
	return 0;
}

// Liệt kê các vị trị mà giá trị tại đó là giá trị dương nhỏ nhất.
void LKGTDNN(int n, double a[])
{
	if (TSDNN(n, a) == 0)
	{
		printf("\n\nMang khong co gia tri duong.");
	}
	else
	{
		printf("\n\nVi tri co gia tri duong nho nhat la: ");
		for (int i = 0; i < n; i++)
		{
			if (TSDNN(n, a) == a[i])
			{
				printf("%d ", i);
			}
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
			printf("Ban nhap sai, xin kiem tra lai. (n > 0 va n <= 100).\n\n");
		}
	} while (n <= 0 || n > SLPT);

	NhapMang(n, a);
	printf("\nMang a sau khi nhap la: ");
	XuatMang(n, a);

	LKGTDNN(n, a);

	getch();
	return 0;
}
