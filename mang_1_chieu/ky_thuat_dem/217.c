/* 2016 - Nguyễn Nhật Tuấn.
Code được viết lúc tôi mới học lập trình C/C++ nên có một số cách chưa được tốt, mong giúp ích được các bạn tham khảo.
*/

// Bài 217/69/SBT Thầy NTTMK: Đếm số lượng giá trị dương chia hết cho 7 trong mảng một chiều các số nguyên.

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
	printf("\n\n");
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
}

// Đếm số lượng giá trị dương chia hết cho 7.
int DemSoLuong(int n, int a[])
{
	int dem = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] > 0 && a[i] % 7 == 0)
		{
			dem++;
		}
	}
	return dem;
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

	int demso = DemSoLuong(n, a);
	if (demso != 0)
	{
		printf("\n\nSo luong gia tri duong va chia het cho 7 la: %d", demso);
	}
	else
	{
		printf("\n\nKhong co gia tri duong va chia het cho 7.");
	}

	getch();
	return 0;
}
