/* 2016 - Nguyễn Nhật Tuấn.
Code được viết lúc tôi mới học lập trình C/C++ nên có một số cách chưa được tốt, mong giúp ích được các bạn tham khảo.
*/

// Bài 203/67/SBT Thầy NTTMK: Tính tổng các giá trị có chữ số hàng chục là chữ số 5 có trong mảng một chiều các số nguyên.

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

// Tính tổng các giá trị có chữ số hàng chục là chữ số 5 có trong mảng.
int TinhTong(int n, int a[])
{
	int tong = 0;
	for (int i = 0; i < n; i++)
	{
		int b = a[i]; // Tạo biến phụ.
		b %= 100;
		b /= 10;
		if (b == 5)
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
			printf("Ban nhap saim, xin kiem tra lai (n > 0 va n <= 100).\n\n");
		}
	} while (n <= 0 || n > SLPT);

	NhapMang(n, a);
	printf("\nMang a sau khi nhap la: ");
	XuatMang(n, a);

	int tong = TinhTong(n, a);
	if (tong == 0)
	{
		printf("\n\nMang khong co gia tri co chu so hang chuc bang 5.");
	}
	else
	{
		printf("\n\nTong cac gia tri co chu so hang chuc bang 5: %d", tong);
	}

	getch();
	return 0;
}
