// Bài 256/74/SBT Thầy NTTMK: Hãy sắp xếp các giá trị trong mảng các số nguyên giảm dần.

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

// Hoán vị.
void HoanVi(int *a, int *b)
{
	int tam = *a;
	*a = *b;
	*b = tam;
}

// Sắp xếp các giá trị trong mảng các số thực tăng dần.
void SapXepGiamDan(int n, int a[])
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i] < a[j])
			{
				HoanVi(&a[i], &a[j]);
			}
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
			printf("Ban nhap sai, xin kiem tra lai (n > 0 va n <= 100),\n\n");
		}
	} while (n <= 0 || n > SLPT);

	NhapMang(n, a);
	printf("\nMang sau khi nhap la: ");
	XuatMang(n, a);

	SapXepGiamDan(n, a);
	printf("\n\nMang sau khi sap xep giam dan la: ");
	XuatMang(n, a);

	getch();
	return 0;
}
