// Bài 263/75/SBT Thầy NTTMK: Hãy sắp xếp các số dương trong mảng tăng dần, các số âm giảm dần.Vị trí tương đối giữa các số âm và số dương
// không đổi.

#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <Windows.h>
#define SLPT 100

void NhapMang(int n, double a[])
{
	for (int i = 0; i < n; i++)
	{
		printf("\nNhap vao phan tu thu %d: ", i + 1);
		scanf("%lf", &a[i]);
	}
}

void XuatMang(int n, double a[])
{
	for (int i = 0; i < n; i++)
	{
		printf("%lf ", a[i]);
	}
}

// Hoán vị.
void HoanVi(double *a, double *b)
{
	*a -= *b;
	*b += *a; // b = a.
	*a = *b - *a; // a = b.
}

// Sắp xếp các số dương trong mảng tăng dần, các số âm giảm dần. Vị trí tương đối giữa các số âm và số dương không đổi.
void SapXep(int n, double a[])
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] > 0)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (a[j] > 0)
				{
					if (a[i] > a[j])
					{
						HoanVi(&a[i], &a[j]);
					}
				}
			}
		}
		else
		{
			for (int j = i + 1; j < n; j++)
			{
				if (a[j] < 0)
				{
					if (a[i] < a[j])
					{
						HoanVi(&a[i], &a[j]);
					}
				}
			}
		}
	}
}

int main()
{
	int n;
	double a[SLPT];

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

	SapXep(n, a);
	printf("\n\nMang sau khi sap xep: ");
	XuatMang(n, a);

	getch();
	return 0;
}
