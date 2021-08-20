// Bài 151/60/SBT Thầy NTTMK: Hãy tìm "số nguyên tố lớn nhất" trong mảng một chiều các số nguyên. Nếu mảng không có số nguyên tố thì trả về giá trị 0.

#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <Windows.h>
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
			for (int i = 3; i <= sqrt((double)n); i++)
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

int SoNguyenToDauTien(int n, int a[])
{
	int max = 0, i, j;
	for (i = 0; i < n; i++)
	{
		if (KTSNT(a[i]) == 1)
		{
			max = a[i];
			break;
		}
	}
	for (j = i + 1; j < n; j++)
	{
		if (KTSNT(a[j]) == 1)
		{
			if (max < a[j])
			{
				max = a[j];
			}
		}
	}
	return max;
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
			printf("Ban nhap sai, xin kiem tra lai (n > 0 va n <= 100).\n\n");
		}
	} while (n <= 0 || n > Max);

	NhapMang(n, a);
	printf("\nMang sau khi nhap la: ");
	XuatMang(n, a);

	if (SoNguyenToDauTien(n, a) == 0)
	{
		printf("\n\nMang khong co so nguyen to.");
	}
	else
	{
		printf("\n\nSo nguyen to lon nhat trong mang: %d", SoNguyenToDauTien(n, a));
	}

	getch();
	return 0;
}
