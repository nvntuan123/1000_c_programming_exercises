// Bài 144/59/SBT Thầy NTTMK:Tìm "số nguyên tố đầu tiên" trong mảng một chiều các số nguyên. Nếu mảng không có số nguyên tố thì trả về giá trị -1.

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

int KTSNT(int n)
{
	if (n < 2)
	{
		return 0;
	}
	else if (n == 2)
	{
		return 1;
	}
	else
	{
		if (n % 2 == 0)
		{
			return 0;
		}
		else
		{
			for (int i = 3; i < sqrt((double)n); i += 2)
			{
				if (n % i == 0)
				{
					return 0;
				}
			}
			return 1;
		}
	}
}

int SNTdautien(int n, int a[])
{
	for (int i = 0; i < n; i++)
	{
		if (KTSNT(a[i]) == 1)
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

	if (SNTdautien(n, a) != -1)
	{
		printf("\n\nSo nguyen to dau tien trong mang la: %d", SNTdautien(n, a));
	}
	else
	{
		printf("\n\nMang khong co so nguyen to.");
	}

	getch();
	return 0;
}
