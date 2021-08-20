/* 2016 - Nguyễn Nhật Tuấn.
Code được viết lúc tôi mới học lập trình C/C++ nên có một số cách chưa được tốt, mong giúp ích được các bạn tham khảo.
*/

// Bài 163/62/SBT: Tìm số chính phương đầu tiên trong mảng một chiều các số nguyên.

#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <math.h>
#define Max 100

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

int KTSChinhPhuong(int a)
{
	if (sqrt((double)a) == (int)(sqrt((double)a)))
	{
		return 1;
	}
	return 0;
}

int TimChinhPhuongDauTien(int n, int a[])
{
	for (int i = 0; i < n; i++)
	{
		if (KTSChinhPhuong(a[i]) == 1)
		{
			return a[i];
		}
	}
	return 0;
}

int main()
{
	int a[Max], n;

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

	if (TimChinhPhuongDauTien(n, a) != 0)
	{
	printf("\n\nSo chinh phuong dau tien trong mang a la: %d", TimChinhPhuongDauTien(n, a));
	}
	else
	{
		printf("\n\nMang khong co so chinh phuong.");
	}

	getch();
	return 0;
}
