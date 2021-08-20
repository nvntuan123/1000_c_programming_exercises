// Bài 219/69/SBT Thầy NTTMK Đếm số lần xuất hiện của giá trị x trong mảng một chiều các số thực.

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

// Đếm số lần xuất hiện của giá trị x.
int DSLanXuatHien(int n, double a[], double x)
{
	int dem = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] == x)
		{
			dem++;
		}
	}
	return dem;
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

	double x;
	printf("\n\nNhap vao gia tri x: ");
	scanf("%lf", &x);

	int demso = DSLanXuatHien(n, a, x);
	if (demso == 0)
	{
		printf("\nMang khong co so bang x.");
	}
	else
	{
		printf("\nSo luong gia tri bang x la: %d", demso);
	}

	getch();
	return 0;
}
