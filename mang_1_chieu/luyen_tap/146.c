// Bài 146/59/SBT Thầy NTTMK:Tìm "giá trị âm đầu tiên" trong mảng một chiều các số thực. Nếu mảng không có giá trị âm thì trả về giá trị -1.

#include <stdio.h>
#include <conio.h>
#include <windows.h>
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

float GiaTriAmdautien(int n, float a[])
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] < 0)
		{
			return a[i];
		}
	}
	return 1;
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

	float am = GiaTriAmdautien(n, a);
	if (am == 1)
	{
		printf("\n\nMang khong co phan tu am.");
	}
	else
	{
		printf("\n\nGia tri am dau tien trong mang la: %f", am);
	}

	getch();
	return 0;
}
