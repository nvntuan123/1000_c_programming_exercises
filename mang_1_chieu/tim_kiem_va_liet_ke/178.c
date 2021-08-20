// Bài 178/64/SBT Thầy NTTMK: Hãy liệt kê các số giá trị chẵn trong mảng một chiều các số nguyên thuộc đoạn [x,y] cho trước (x,y là các số nguyên ).

#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <windows.h>
#define Max 100

// Nhập mảng.
void NhapMang(int n, int a[])
{
	for (int i = 0; i < n; i++)
	{
		printf("\nNhap vao phan tu thu %d: ", i + 1);
		scanf("%d", &a[i]);
	}
}

// Xuất mảng.
void XuatMang(int n, int a[])
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
}

// Kiểm tra số chẵn.
int KTSC(int n, int a[])
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] % 2 == 0)
		{
			return 1;
		}
	}
	return 0;
}

// Liệt kê số chẵn thuộc đoạn [x, y].
void KTChan(int n, int a[], int x, int y)
{
	if (KTSC(n, a) == 1)
	{
		printf("\nGia tri chan thuoc doan [%d, %d]: ", x, y);
		for (int i = 0; i < n; i++)
		{
			if (a[i] % 2 == 0)
			{
				if (a[i] >= x && a[i] <= y)
				{
					printf("%d ", a[i]);
				}
			}
		}
	}
	else
	{
		printf("\nMang khong co so thoa yeu cau.");
	}
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
	printf("\nMang a sau khi nhap la: ");
	XuatMang(n, a);

	int x, y;
	do
	{
		printf("\n\nNhap vao x = ");
		scanf("%d", &x);
		printf("\nNhap vao y = ");
		scanf("%d", &y);

		if (x <= 0 || y <= 0)
		{
			system("cls");
			printf("x hoac y nhap sai.");
		}
	} while (x <= 0 || y <= 0);

	KTChan(n, a, x, y);

	getch();
	return 0;
}
