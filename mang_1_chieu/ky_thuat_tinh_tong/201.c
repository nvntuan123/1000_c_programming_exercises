// Bài 201/67/SBT Thầy NTTMK: Tính tổng các giá trị dương trong mảng một chiều các số thực.

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

// Tính tổng các giá trị dương.
double TongGTduong(int n, double a[])
{
	double tong = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] > 0)
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
	} while(n <= 0 || n > SLPT);

	NhapMang(n, a);
	printf("\nMang a sau khi nhap la: ");
	XuatMang(n, a);

	if (TongGTduong(n, a) == 0)
	{
		printf("\n\nMang khong co gia tri duong.");
	}
	else
	{
		printf("\n\nTong gia tri duong: %lf", TongGTduong(n, a));
	}

	getch();
	return 0;
}
