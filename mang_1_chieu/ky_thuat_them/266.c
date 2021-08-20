// Bài 266/75/SBT Thầy NTTMK: Hãy thêm 1 phần tử có giá tri x vào mảng tại vị trí k.

#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <math.h>
#define SLPT 100

void NhapMang(int na, double a[])
{
	for (int i = 0; i < na; i++)
	{
		printf("\nNhap vao phan tu thu %d: ", i + 1);
		scanf("%lf", &a[i]);
	}
}

void XuatMang(int na, double a[])
{
	printf("\n\n");
	for (int i = 0; i < na; i++)
	{
		printf("%lf ", a[i]);
	}
}

// Thêm phần tử x.
void ThemPhanTu(int *n, double a[], int vitricanthem, double phantucanthem)
{
	for (int i = (*n) - 1; i >= vitricanthem; i--)
	{
		a[i + 1] = a[i];
	}
	a[vitricanthem] = phantucanthem;
	(*n)++;
}

int main()
{
	int n;
	double a[SLPT];

	// Nhập mảng a.
	do
	{
		printf("Nhap vao so luong phan tu n: ");
		scanf("%d", &n);

		if (n <= 0 || n > SLPT)
		{
			system("cls");
			printf("Ban nhap sai, xin kiem tra lai (na > 0 va na <= 100.\n\n)");
		}
	} while (n <= 0 || n > SLPT);

	NhapMang(n, a);
	printf("\nMang sau khi nhap la: ");
	XuatMang(n, a);

	int k;
	double x;

	do
	{
		printf("\n\nNhap vao vi tri can them: ");
		scanf("%d", &k);

		if (k < 0 || k > n)
		{
			printf("\nBan nhap sai, vi tri can them (vi tri >= 0 va <= n).");
		}
	} while (k < 0 || k > n);
	printf("\nNhap vao phan tu can them: ");
	scanf("%lf", &x);

	ThemPhanTu(&n, a, k, x);
	printf("\nMang sau khi them phan tu la: ");
	XuatMang(n, a);

	getch();
	return 0;
}
