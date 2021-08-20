/* 2016 - Nguyễn Nhật Tuấn.
Code được viết lúc tôi mới học lập trình C/C++ nên có một số cách chưa được tốt, mong giúp ích được các bạn tham khảo.
*/

// Bài 135/58/SBT Thầy NTTMK:Cách 1:Tìm "giá trị dương đầu tiên" trong mảng một chiều các số thực. Nếu mảng không có giá trị dương thì trả về giá trị -1.

#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#define Max 100

void NhapMang(int n, float a[])
{
	for (int i = 0; i < n; i++)
	{
		printf("\nNhap vao phan tu thu %d: ", i + 1);
		scanf("%f", &a[i]);
	}
}

void XuatMang(int n, float a[])
{
	for (int i = 0; i < n; i++)
	{
		printf("%f ", a[i]);
	}
}

float TimSoDuongDauTien(int n, float a[])
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] > 0)
		{
			return a[i];
		}
	}
	return -1;
}

int main()
{
	int n;
	float a[Max];

	do
	{
		printf("Nhap vao so luong phan tu n: ");
		scanf("%d", &n);

		if (n <= 0 || n > Max)
		{
			printf("Ban nhap sai, xin kiem tra lai (n > 0 && n <= 100)\n\n");
		}
	} while (n <= 0 || n > Max);

	NhapMang(n, a);
	printf("\nMang sau khi nhap la: ");
	XuatMang(n, a);

	float sd = TimSoDuongDauTien(n, a);
	if (sd != -1)
	{
		printf("\n\nSo duong dau tien trong mang la: %f", sd);
	}
	else
	{
		printf("\n\nKhong co so duong nao.");
	}

	getch();
	return 0;
}
