/* 2016 - Nguyễn Nhật Tuấn.
Code được viết lúc tôi mới học lập trình C/C++ nên có một số cách chưa được tốt, mong giúp ích được các bạn tham khảo.
*/

// Bài 271/76/SBT Thầy NTTMK: Xóa các phần tử có chỉ số k trong mảng.

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
		printf("%lf ", a[i]);
	}
}

// Xóa pt có chỉ số k.
void XoaPhanTu(int *n, double a[], int vitricanxoa)
{
	for (int i = vitricanxoa; i < (*n) - 1; i++)
	{
		a[i] = a[i + 1];
	}
	(*n)--;
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

	int k;

	do
	{
		printf("\n\nNhap vao chi so can xoa phan tu k: ");
		scanf("%d", &k);

		if (k <= 0 || k > n)
		{
			printf("\nBan nhap sai, xin kiem tra lai (k > 0 va k <= n).");
		}
	} while (k <= 0 || k > n);

	XoaPhanTu(&n, a, k);
	printf("\nMang sau khi xoa phan tu co chi so k: ");
	XuatMang(n, a);

	getch();
	return 0;
}
