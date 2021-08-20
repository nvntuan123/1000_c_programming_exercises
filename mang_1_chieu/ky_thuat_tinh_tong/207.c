// Bài 207/68/SBT Thầy NTTMK: Tính tổng các phần tử "cực trị" trong mảng. Một phần tử được gọi là cực trị khi nó lớn hơn hoặc nhỏ hơn các phần tử xung quanh nó.

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

//  Tính tổng các phần tử "cực trị" trong mảng.
double TongCucTri(int n, double a[])
{
	double tong = 0;
	for (int i = 1; i < n - 1; i++)
	{
		if (a[i] > a[i - 1] && a[i] > a[i + 1])
		{
			tong += a[i];
		}
		if (a[i] < a[i - 1] && a[i] < a[i + 1])
		{
			tong += a[i];
		}
	}
	return tong;
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

	double tong = TongCucTri(n, a);
	if (tong != 0)
	{
		printf("\n\nTong cuc tri: %lf", tong);
	}
	else
	{
		printf("\n\nMang khong co cuc tri.");
	}

	getch();
	return 0;
}
