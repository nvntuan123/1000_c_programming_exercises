// Bài 140/58/SBT Thầy NTTMK:Hãy tìm "giá trị dương nhỏ nhất" trong mảng một chiều các số thực. Nếu mảng không có giá trị dương thì trả về 1.

#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#define Max 100

void NhapMang(int n, float a[])
{
	for (int i = 0; i < n; i ++)
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

float giatriduongnhonhat(int n, float a[])
{
	float min = 0;
	int i, j;
	for (i = 0; i < n; i++)
	{
		if (a[i] > 0)
		{
			min = a[i]; break;
		}
	}

	for (j = i; j < n; j++)
	{
		if (a[j] > 0)
		{
			if (min > a[j])
			{
				min = a[j];
			}
		}
	}
	if (min == 0)
	{
		return -1;
	}
	return min;
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

	if (giatriduongnhonhat(n, a) != -1)
	{
		printf("\n\nGia tri duong nhat trong mang: %f", giatriduongnhonhat(n, a));
	}
	else
	{
		printf("\n\nKhong co phan tu duong trong mang.");
	}

	getch();
	return 0;
}
