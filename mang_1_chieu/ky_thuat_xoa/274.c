// Bài 274/76/SBT Thầy NTTMK:Hãy xóa tất cả số chẵn trong mảng các số nguyên.

#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <Windows.h>
#define SLPT 100

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

// Hàm xóa phần tử.
void XoaPhanTu(int *n, int a[], int vitricanxoa)
{
	// Cách 1:
	/*for (int i = vitricanxoa; i < (*n) - 1; i++)
	{
		a[i] = a[i + 1];
	}*/

	// Cách 2:
	for (int i = vitricanxoa + 1; i < (*n); i++)
	{
		a[i - 1] = a[i];
	}
	(*n)--;
}

// Xóa phần tử chẵn trong mảng.
void XoaPhanTuChan(int *n, int a[])
{
	for (int i = 0; i < (*n); i++)
	{
		if (a[i] % 2 == 0)
		{
			XoaPhanTu(&n, a, i);
			i--; // Cập nhật lại i.
		}
	}
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
	printf("\nMang sau khi nhap la: ");
	XuatMang(n, a);

	XoaPhanTuChan(&n, a);
	printf("\n\nMang sau khi xoa phan tu chan la: ");
	XuatMang(n, a);

	getch();
	return 0;
}
