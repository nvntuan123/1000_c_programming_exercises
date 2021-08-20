// Bài 153/60/SBT Thầy NTTMK: Hãy tìm "giá trị chẵn nhỏ nhất" trong mảng một chiều các số nguyên. Nếu mảng không có giá trị chẵn thì trả về giá trị không chẵn là -1.

#include <stdio.h>
#include <conio.h>
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

int GiaTriChanNhoNhat(int n, int a[])
{
	int min = 0, i, j;
	for (i = 0; i < n; i++)
	{
		if (a[i] % 2 == 0)
		{
			min = a[i];
			break;
		}
	}
	for (j = i + 1; j < n; j++)
	{
		if (a[j] % 2 == 0)
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

	if (GiaTriChanNhoNhat(n, a) != -1)
	{
		printf("\n\nGia tri chan nho nhat la: %d", GiaTriChanNhoNhat(n, a));
	}
	else
	{
		printf("\n\nMang khong co gia tri chan.");
	}

	getch();
	return 0;
}
