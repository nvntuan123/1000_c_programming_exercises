// Bài 258/74/SBT Thầy NTTMK: Hãy sắp xếp các số nguyên tố trong mảng các số nguyên tăng dần, các giá trị khác giữ nguyên giá trị và vị trí.

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

// Kiểm tra SNT
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
			for (int i = 3; i <= sqrt((double)n); i += 2)
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

// Hoán vị.
void HoanVi(int *a, int *b)
{
	int tam = *a;
	*a = *b;
	*b = tam;
}

// Sắp xếp các số nguyên tố trong mảng các số nguyên tăng dần.
void SapXepSNTTangDan(int n, int a[])
{
	for (int i = 0; i < n; i++)
	{
		if (KTSNT(a[i]))
		{
			for (int j = i + 1; j < n; j++)
			{
				if (KTSNT(a[j]))
				{
					if (a[i] > a[j])
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
			printf("Ban nhap sai, xin kiem tra lai (n > 0 va n <= 100),\n\n");
		}
	} while (n <= 0 || n > SLPT);

	NhapMang(n, a);
	printf("\nMang sau khi nhap la: ");
	XuatMang(n, a);

	SapXepSNTTangDan(n, a);
	printf("\n\nMang sau khi sap xep cac SNT tang dan la: ");
	XuatMang(n, a);

	getch();
	return 0;
}
