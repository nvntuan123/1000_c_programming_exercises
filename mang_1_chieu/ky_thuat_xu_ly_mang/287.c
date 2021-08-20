// Bài 287/78/SBT Thầy NTTMK: Hãy "dịch phải xoay vòng" k lần các phần tử trong mảng.

#include <stdio.h>
#include <conio.h>
#include <Windows.h>
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
		printf("%.1lf ", a[i]);
	}
}

// Hoán vị.
void Swap(double *x, double *y)
{
	*x += *y;
	*y = *x - *y; // y = x.
	*x -= *y; // x = y.
}

// Dịch phải xoay vòng k lần.
void DichPhaiXoayVong(int n, double a[], int x)
{
	x %= n; // 5 lần dịch như không dịch lần nào (mảng như ban đầu), 6 lần = 1 lần, 7 lần = 2 lần...
	for (int i = 1; i <= x; i++)
	{
		for (int j = n - 1; j > 0; j--)
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

	int k;

	printf("\n\nNhap so lan can dich: ");
	scanf("%d", &k);

	DichPhaiXoayVong(n, a, k);
	printf("\nMang sau khi dich phai %d lan: \n", k);
	XuatMang(n, a);

	getch();
	return 0;
}
