// Bài 265/75/SBT Thầy NTTMK: Cho hai mảng tăng dần, hãy trộn hai mảng lại thành một mảng được sắp thứ tự giảm dần.

#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <math.h>
#define SLPT 100

void NhapMang(int na, double a[])
{
	for (int i = 0; i < na; i++)
	{
		printf("\nNhap vao phan tu thu %d: ", i + 1);
		scanf("%lf", &a[i]);
	}
}

void XuatMang(int na, double a[])
{
	printf("\n\n");
	for (int i = 0; i < na; i++)
	{
		printf("%lf ", a[i]);
	}
}

// Hoán vị.
void HoanVi(double *a, double *b)
{
	*a = *a + *b;
	*b = *a - *b; // b = a
	*a -= *b; // a = b
}

// Trộn mảng.
void TronMang(int na, double a[], int nb, double b[], int *nc, double c[])
{
	(*nc) = 0;
	for (int i = 0; i < na; i++) // Trộn a vào c.
	{
		c[(*nc)++] = a[i];
	}

	for (int i = 0; i < nb; i++) // Trộn b vào c.
	{
		c[(*nc)++] = b[i];
	}
}

// Sắp xếp tăng dần.
void SapXepTangDan(int nc, double c[])
{
	for (int i = 0; i < nc - 1; i++)
	{
		for (int j = i + 1; j < nc; j++)
		{
			if (c[i] < c[j])
			{
				HoanVi(&c[i], &c[j]);
			}
		}
	}
}

int main()
{
	int na, nb, nc;
	double a[SLPT], b[SLPT], c[SLPT];

	// Nhập mảng a.
	do
	{
		printf("Nhap vao so luong phan tu na: ");
		scanf("%d", &na);

		if (na <= 0 || na > SLPT)
		{
			system("cls");
			printf("Ban nhap sai, xin kiem tra lai (na > 0 va na <= 100.\n\n)");
		}
	} while (na <= 0 || na > SLPT);

	NhapMang(na, a);

	// Nhập mảng b.
	do
	{
		printf("\nNhap vao so luong phan tu nb: ");
		scanf("%d", &nb);

		if (na <= 0 || nb > SLPT)
		{
			system("cls");
			printf("Ban nhap sai, xin kiem tra lai (nb > 0 va nb <= 100.\n\n)");
		}
	} while (nb <= 0 || nb > SLPT);

	NhapMang(nb, b);

	printf("\nMang a sau khi nhap la: ");
	XuatMang(na, a);
	printf("\n\nMang b sau khi nhap la: ");
	XuatMang(nb, b);

	TronMang(na, a, nb, b, nc, c);
	printf("\n\nMang c sau khi trong la: ");
	XuatMang(nc, c);

	printf("\n\nMang c sau khi sap xep giam dan la: ");
	SapXepTangDan(nc, c);
	XuatMang(nc, c);

	getch();
	return 0;
}
