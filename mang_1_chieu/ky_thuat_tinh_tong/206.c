/* 2016 - Nguyễn Nhật Tuấn.
Code được viết lúc tôi mới học lập trình C/C++ nên có một số cách chưa được tốt, mong giúp ích được các bạn tham khảo.
*/

// Bài 206/68/SBT Thầy NTTMK: Tính tổng các giá trị lớn hơn các giá trị xung quanh trong mảng một chiều các số thực.

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
	printf("\n\n");
	for (int i = 0; i < n; i++)
	{
		printf("%lf ", a[i]);
	}
}

// Tính tổng các giá trị lớn hơn các giá trị xung quanh trong.
double TongGiaTri(int n, double a[])
{
	double tong = 0;
	for (int i = 1; i < n - 1; i++)
	{
		if (a[i] > a[i - 1] && a[i] > a[i + 1])
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

	double tong = TongGiaTri(n, a);
	if (tong != 0)
	{
		printf("\n\nTong cac gia tri lon hon cac gia tri xung quanh la: %lf", tong);
	}
	else
	{
		printf("\n\nMang khong co gia tri lon hon cac gia tri xung quanh.");
	}

	getch();
	return 0;
}
