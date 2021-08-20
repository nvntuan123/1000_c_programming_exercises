// Bài 283/77/SBT Thầy NTTMK: Hãy đảo ngược mảng ban đầu.

#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <windows.h>
#define SLPT 100

// Nhập mảng.
void NhapMang(int n, double a[])
{
	for (int i = 0; i < n; i++)
	{
		printf("\nNhap vao phan tu thu %d: ", i + 1);
		scanf("%lf", &a[i]);
	}
}

// Xuất mảng.
void XuatMang(int n, double a[])
{
	for (int i = 0; i < n; i++)
	{
		printf("%.2lf ", a[i]);
	}
}

// Hoán vị.
void Swap(double *a, double *b)
{
	*a -= *b;
	*b += *a; // b = a.
	*a = *b - *a; // a = b.
}

// đảo mảng.
void DaoMang(int n, double a[])
{
	for (int i = 0; i < n; i++)
	{
		for (int j = n - 1; j > i; j--)
		{
			Swap(&a[j], &a[j - 1]);
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
	printf("\nMang ban dau sau khi nhap la: ");
	XuatMang(n, a);

	DaoMang(n, a);
	printf("\n\nMang sau khi dao nguoc la: ");
	XuatMang(n, a);

	getch();
	return 0;
}
