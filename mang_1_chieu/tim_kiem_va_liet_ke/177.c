// Bài 177/64/SBT Thầy NTTMK: Hãy liệt kê các số giá trị trong mảng một chiều các số thực thuộc đoạn [x,y] cho trước.

#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <math.h>
#define Max 100

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

int KT(int n, double a[], double x, double y)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] >= x && a[i] <= y)
		{
			printf("%lf ", a[i]);
			return 1;
		}
	}
	return 0;
}

void Tim(int n, double a[], double x, double y)
{
	if (KT(n, a, x, y) == 1)
	{
		printf("\nGia tri chan thuoc doan [%lf, %lf]: ", x, y);
		for (int i = 0; i < n; i++)
		{
			if (a[i] >= x && a[i] <= y)
			{
				printf("%lf ", a[i]);
			}
		}
	}
	else
	{
		printf("\nMang khong co gia tri thuoc doan [%lf, %lf].", x, y);
	}
}

int main()
{
	int n;
	double a[Max];

	do
	{
		printf("Nhap vao so luong phan tu n: ");
		scanf("%d", &n);

		if (n <= 0 || n > Max)
		{
			system("cls");
			printf("Ban nhap sai, xin kiem tra lai (n > 0 va n <= 100).\n\n");
		}
	} while (n <= 0 || n > Max);

	NhapMang(n, a);
	printf("\nMang a sau khi nhap la: ");
	XuatMang(n, a);

	double x, y;
	printf("\n\nNhap vao x: ");
	scanf("%lf", &x);
	printf("\nNhap vao y: ");
	scanf("%lf", &y);

	Tim(n, a, x, y);

	getch();
	return 0;
}
