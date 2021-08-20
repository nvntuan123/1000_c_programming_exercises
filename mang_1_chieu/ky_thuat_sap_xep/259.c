// Bài 258/74/SBT Thầy NTTMK: Hãy sắp xếp các số hoàn thiện trong mảng các số nguyên giảm dần, các giá trị khác giữ nguyên giá trị và vị trí.

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

// Kiểm tra số hoàn thiện.
int KTSoHoanThien(int n)
{
	int tong = 0;
	for (int i = 1; i < n; i++)
	{
		if (n % i == 0)
		{
			tong += i;
		}
	}
	if (tong == n)
	{
		return 1;
	}
	return 0;
}

// Hoán vị.
void HoanVi(int *a, int *b)
{
	*a -= *b;
	*b += *a; // b = a.
	*a = *b - *a; // a = b.
}

// Sắp xếp các số hoàn thiện trong mảng các số nguyên giảm dần.
void SapXepHoanThienGiamDan(int n, int a[])
{
	for (int i = 0; i < n; i++)
	{
		if (KTSoHoanThien(a[i]) == 1)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (KTSoHoanThien(a[j]) == 1)
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

	SapXepHoanThienGiamDan(n, a);
	printf("\n\nMang sau khi sap xep so hoan thien giam dan la: ");
	XuatMang(n, a);

	getch();
	return 0;
}
