// Bài 213/68/SBT Thầy NTTMK:Tính trung bình cộng các giá trị lớn hơn giá trị x trong mảng một chiều các số thực.

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

// Trung bình cộng các giá trị lớn hơn giá trị x.
double TrungBinhCongLonHonX(int n, double a[], double x)
{
	double tong = 0;
	int dem = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] > x)
		{
			tong += a[i];
			dem++;
		}
	}
	if (dem != 0)
	{
		return tong / dem;
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
	printf("\n\nNhap gia tri x: ");
	scanf("%lf", &x);

	double TBC = TrungBinhCongLonHonX(n, a, x);
	if (TBC == 0)
	{
		printf("\nMang khong co so lon hon x.");
	}
	else
	{
		printf("\nTong cac gia tri lon hon x: %lf", TBC);
	}

	getch();
	return 0;
}
