/* 2016 - Nguyễn Nhật Tuấn.
Code được viết lúc tôi mới học lập trình C/C++ nên có một số cách chưa được tốt, mong giúp ích được các bạn tham khảo.
*/

// Bài 157/61/SBT Thầy NTTMK: Cho mảng một chiều các số thực, hãy tìm đoạn [a,b] sao cho đoạn này chứa tất cả các giá trị trong mảng.

#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <Windows.h>
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

double Maxx(int n, double a[])
{
	double max = a[0];
	for (int i = 0; i < n; i++)
	{
		max < a[i]? max = a[i]: max;
	}
	return max;
}

double Min(int n, double a[])
{
	double min = a[0];
	for (int i = 0; i < n; i++)
	{
		min > a[i]? min = a[i] : min;
	}
	return min;
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
	printf("\nMang sau khi nhap la: ");
	XuatMang(n, a);

	printf("\n\n=> doan nay [%lf, %lf] chua tat ca cac gia tri trong mang.", Min(n, a), Maxx(n, a));

	getch();
	return 0;
}
