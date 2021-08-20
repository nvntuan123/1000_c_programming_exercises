// Bài 147/59/SBT Thầy NTTMK:Tìm "số dương cuối cùng" trong mảng một chiều các số thực. Nếu mảng không có giá trị dương thì trả về giá trị -1.

#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <math.h>
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

float SoDuongCuoiCung(int n, float a[])
{
	for (int i = n - 1; i >= 0; i--)
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
			system("cls");
			printf("Ban nhap sai, xin kiem tra lai (n > 0 && n <= 100).\n\n");
		}
	} while (n <= 0 || n > Max);

	NhapMang(n, a);
	printf("\nMang sau khi nhap la: ");
	XuatMang(n, a);

	float soduong = SoDuongCuoiCung(n, a);
	if (soduong != -1)
	{
		printf("\n\nSo duong cuoi cung trong mang: %f", soduong);
	}
	else
	{
		printf("\n\nMang khong co gia tri duong.");
	}

	getch();
	return 0;
}
