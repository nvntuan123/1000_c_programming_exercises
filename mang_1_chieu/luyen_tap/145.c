/* 2016 - Nguyễn Nhật Tuấn.
Code được viết lúc tôi mới học lập trình C/C++ nên có một số cách chưa được tốt, mong giúp ích được các bạn tham khảo.
*/

// Bài 145/59/SBT Thầy NTTMK:Tìm "số hoàn thiện đầu tiên" trong mảng một chiều các số nguyên. Nếu mảng không có số hoàn thiện thì trả về giá
// trị -1.

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

int KiemTraSoHoanThien(int n)
{
	int tong = 0;
	for (int i = 1; i < n; i++)
	{
		if (n % i == 0)
		{
			tong += i;
		}
	}
	if (tong == n)
	{
		return 1;
	}
	return 0;
}

int SHThiendautien(int n, int a[])
{
	for (int i = 0; i < n; i++)
	{
		if (KiemTraSoHoanThien(a[i]) == 1)
		{
			return a[i];
		}
	}
	return -1;
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
			printf("Ban nhap sai, xin kiem tra lai (n > 0 && n <= 100).\n\n");
		}
	} while (n <= 0 || n > Max);

	NhapMang(n, a);
	printf("\nMang sau khi nhap la: ");
	XuatMang(n, a);

	for (int i = 0; i < n; i++)
	{
		if (a[i] == 447)
		{
			printf("\n%d", a[i]);
			break;
		}
	}

	if (SHThiendautien(n, a) != -1)
	{
		printf("\n\nSo hoan thien dau tien la: %d", SHThiendautien(n, a));
	}
	else
	{
		printf("\n\nMang khong co so hoan thien.");
	}

	getch();
	return 0;
}
