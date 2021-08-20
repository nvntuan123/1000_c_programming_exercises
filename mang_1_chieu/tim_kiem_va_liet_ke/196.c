/* 2016 - Nguyễn Nhật Tuấn.
Code được viết lúc tôi mới học lập trình C/C++ nên có một số cách chưa được tốt, mong giúp ích được các bạn tham khảo.
*/

// Bài 196/66/SBT Thầy NTTMK: Hãy liệt kê các số âm trong mảng một chiều các số thực.

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

// Kiểm tra mảng có phần từ âm hay không?
double KTPTA(int n, double a[])
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] < 0)
		{
			return 1;
		}
	}
	return 0;
}

// Liệt kê giá trị âm.
void LKGTA(int n, double a[])
{
	if (KTPTA(n, a) == 1)
	{
		printf("\n\nGia tri am: ");
	for (int i = 0; i < n; i++)
	{
		if (a[i] < 0)
		{
			printf("%lf ", a[i]);
		}
	}
	}
	else
	{
		printf("\n\nMang khong co gia tri am.");
	}
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

	LKGTA(n, a);

	getch();
	return 0;
}
