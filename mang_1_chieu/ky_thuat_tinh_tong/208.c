/* 2016 - Nguyễn Nhật Tuấn.
Code được viết lúc tôi mới học lập trình C/C++ nên có một số cách chưa được tốt, mong giúp ích được các bạn tham khảo.
*/

// Bài 208/68/SBT Thầy NTTMK: Tính tổng các giá trị chính phương trong mảng một chiều các số nguyên.

#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <Windows.h>
#define SLPT 100

void NhapMang(int n, int a[])
{
	for (int i = 0; i < n; i++)
	{
		printf("\nNhap vao phan tu thu %d: ", i + 1);
		scanf("%d", &a[i]);
	}
}

void XuatMang(int n, int a[])
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
}

// Kiểm tra số chính phương.
int ChinhPhuong(int n)
{
	double a = sqrt((double)n);
	if (a == (int)(a))
	{
		return 1;
	}
	return 0;
}

// Tính tổng các giá trị chính phương.
int TongChinhPhuong(int n, int a[])
{
	int tong = 0;
	for (int i = 0; i < n; i++)
	{
		if (ChinhPhuong(a[i]) == 1)
		{
			tong += a[i];
		}
	}
	return tong;
}

int main()
{
	int a[SLPT], n;

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

	int tong = TongChinhPhuong(n, a);
	if (tong == 0)
	{
		printf("\n\nMang khong co so chinh phuong.");
	}
	else
	{
		printf("\n\nTong gia tri chinh phuong la: %d", tong);
	}

	getch();
	return 0;
}
