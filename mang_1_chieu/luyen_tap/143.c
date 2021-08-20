// Bài 143/59/SBT Thầy NTTMK:Viết hàm tìm "số chẵn đầu tiên" trong mảng một chiều các số nguyên. Nếu mảng không có giá trị chẵn thì hàm sẽ trả về giá trị không chẵn là -1.

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

int SoChanDauTien(int n, int a[])
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] % 2 == 0)
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

	if (SoChanDauTien(n, a) != -1)
	{
		printf("\n\nSo chan dau tien trong mang la: %d", SoChanDauTien(n, a));
	}
	else
	{
		printf("\n\nKhong co so chan trong mang.");
	}

	getch();
	return 0;
}
