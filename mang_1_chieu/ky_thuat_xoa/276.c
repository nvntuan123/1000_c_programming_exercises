/* 2016 - Nguyễn Nhật Tuấn.
Code được viết lúc tôi mới học lập trình C/C++ nên có một số cách chưa được tốt, mong giúp ích được các bạn tham khảo.
*/

// Bài 276/77/SBT Thầy NTTMK: Hãy xóa tất cả các phần tử có giá trị trùng với x.

#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <Windows.h>
#define SLPT 100

// Nhập mảng.
void NhapMang(int n, double a[])
{
	for (int i = 0; i < n; i++)
	{
		printf("\nNhap vao phan tu thu %d: ", i + 1);
		scanf("%lf", &a[i]);
	}
}

// Xuất mảng.
void XuatMang(int n, double a[])
{
	for (int i = 0; i < n; i++)
	{
		printf("%.3lf ", a[i]);
	}
}

// Hàm xóa phần tử.
void XoaPhanTu(int *n, double a[], int vitricanxoa)
{
	// Cách 1:
	/*for (int i = vitricanxoa; i < n - 1; i++)
	{
		a[i] = a[i + 1];
	}*/

	// Cách 2:
	for (int i = vitricanxoa + 1; i < (*n); i++)
	{
		a[i - 1] = a[i];
	}
	(*n)--;
}

// Xóa phần tử trùng với x.
void XoaPhanTuTrungX(int *n, double a[], double x)
{
	for (int i = 0; i < (*n); i++)
	{
		if (a[i] == x)
		{
			XoaPhanTu(&n, a, i);
			i--;
		}
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
	printf("\nMang sau khi nhap la: ");
	XuatMang(n, a);

	double x;
	printf("\n\nNhap vao x = ");
	scanf("%lf", &x);

	XoaPhanTuTrungX(&n, a, x);
	printf("\nMang sau khi xoa phan tu trung voi x: ");
	XuatMang(n, a);

	getch();
	return 0;
}
