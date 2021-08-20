// Bài 257/74/SBT Thầy NTTMK: Hãy sắp xếp các giá trị tại các vị trí lẻ trong mảng tăng dần. Các giá trị khác giữ nguyên giá trị và vị trí.

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

// Sắp xếp các giá trị tại các vị trí lẻ trong mảng tăng dần.
void SapXepViTriLeTangDan(int n, double a[])
{
	for (int i = 1; i < n; i += 2)
	{
		for (int j = i + 2; j < n; j += 2)
		{
			if (a[i] > a[j])
			{
				HoanVi(&a[i], &a[j]);
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
			printf("Ban nhap sai, xin kiem tra lai (n > 0 va n <= 100),\n\n");
		}
	} while (n <= 0 || n > SLPT);

	NhapMang(n, a);
	printf("\nMang sau khi nhap la: ");
	XuatMang(n, a);

	SapXepViTriLeTangDan(n, a);
	printf("\n\nMang sau khi sap xep cac gia tri tai vi tri le tang dan la: ");
	XuatMang(n, a);

	getch();
	return 0;
}
