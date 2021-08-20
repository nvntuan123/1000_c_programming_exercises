// Bài 286/78/SBT Thầy NTTMK: Hãy "dịch trái xoay vòng" các phần tử trong mảng.

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
void Swap(double *a, double *b)
{
	*a += *b;
	*b = *a - *b; // b = a.
	*a -= *b; // a = b.
}

// Dịch trái xoay vòng.
void DichTraiXoayVong(int n, double a[], int k)
{
	k %= n; // Vì 5 lần dịch = 0 lần dịch (mảng như ban đầu), 6 lần = 1 lần, 7 lần = 2 lần...
	for (int i = 1; i <= k; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			Swap(&a[j], &a[j + 1]);
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
	printf("\nMang bau dau sau khi nhap la: ");
	XuatMang(n, a);

	int k;
	printf("\n\nNhap vao so lan can xoay k = ");
	scanf("%d", &k);

	DichTraiXoayVong(n, a, k);
	printf("\nMang sau khi dich trai xoay vong %d lan la: \n", k);
	XuatMang(n, a);

	getch();
	return 0;
}
