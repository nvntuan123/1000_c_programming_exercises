/* 2016 - Nguyễn Nhật Tuấn.
Code được viết lúc tôi mới học lập trình C/C++ nên có một số cách chưa được tốt, mong giúp ích được các bạn tham khảo.
*/

// Bài 214/68/SBT Thầy NTTMK: Tính trung bình nhân các số dương trong mảng một chiều các số thực.

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

// Trung bình nhân các số dương.
double TrungBinhNhan(int n, double a[])
{
	double tich = 1;
	double dem = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] > 0)
		{
			tich *= a[i];
			dem++;
		}
	}
	double TBN = pow(tich, 1 / dem);
	return TBN;
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

	double TBN = TrungBinhNhan(n, a);
	if (TBN != 0)
	{
		printf("\n\nTrung binh nhan cac so duong: %lf", TBN);
	}
	else
	{
		printf("\n\nMang khong co so duong.");
	}

	getch();
	return 0;
}
