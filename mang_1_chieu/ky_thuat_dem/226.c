// Bài 226/70/SBT Thầy NTTMK: Hãy xác định số lượng các phần tử kề nhau mà cả hai đều chẵn.

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
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
}

// Xác định số lượng các phần tử kề nhau mà cả hai đều chẵn.
int SoLuongKeChan(int n, int a[])
{
	int dem = 0;
	for (int i = 0; i < n; i++)
	{
		if (i == 0)
		{
			if (a[i] % 2 == 0 && a[i + 1] % 2 == 0)
			{
				dem++;
			}
		}
		else if (i == n - 1)
		{
			if (a[i] % 2 == 0 && a[i - 1] % 2 == 0)
			{
				dem++;
			}
		}
		else
		{
			if ((a[i] % 2 == 0 && a[i - 1] % 2 == 0) || (a[i] % 2 == 0 && a[i + 1] % 2 == 0))
			{
				dem++;
			}
		}
	}
	return dem;
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
			printf("Ban nhap sai, xin kiem tra lai (n > 0 va n <= 100).\n\n");
		}
	} while (n <= 0 || n > SLPT);

	NhapMang(n, a);
	printf("\nMang a sau khi nhap la: ");
	XuatMang(n, a);

	int demso = SoLuongKeChan(n, a);
	if (demso == 0)
	{
		printf("\n\nMang khong co phan tu ke nhau ma ca hai deu chan.");
	}
	else
	{
		printf("\n\nSo luong cac phan tu ke nhau ma ca hai den chan: %d",demso);
	}

	getch();
	return 0;
}
