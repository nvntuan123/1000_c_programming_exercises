// Bài 155/61/SBT Thầy NTTMK:Hãy tìm giá trị trong mảng các số thực "xa giá trị x nhất".

#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <math.h>
#define Max 100

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

void XuLy(int n, double a[], int *nb, double b[], double x)
{
	double khoangcach = 0;
	(*nb) = 0;
	for (int i = 0; i < n; i++)
	{
		if (x > 0)
		{
			if (a[i] > 0)
			{
				if (a[i] < x)
				{
					b[(*nb)++] = x - a[i];
				}
				else if (a[i] == x)
				{
					b[(*nb)++] = x - a[i];
				}
				else
				{
					b[(*nb)++] = a[i] - x;
				}
			}
			else if (a[i] == 0)
			{
				b[(*nb)++] = x;
			}
			else
			{
				b[(*nb)++] = x - a[i];
			}
		}
		else if (x < 0)
		{
			if (a[i] > 0)
			{
				b[(*nb)++] = a[i] - x;
			}
			else if (a[i] == 0)
			{
				b[(*nb)++] = x - a[i];
			}
			else
			{
				if (a[i] > x)
				{
					b[(*nb)++] = a[i] - x;
				}
				else if (a[i] == x)
				{
					b[(*nb)++] = x - a[i];
				}
				else
				{
					b[(*nb)++] = x - a[i];
				}
			}
		}
		else
		{
			if (a[i] > 0)
			{
				b[(*nb)++] = a[i];
			}
			else if (a[i] == 0)
			{
				b[(*nb)++] = a[i] = x;
			}
			else
			{
				b[(*nb)++] = - a[i];
			}
		}
	}
}

double GiaTriKhoangCachXaX(int n, double a[], int nb, double b[])
{
	int vitrimax = 0;
	for (int i = 0; i < nb; i++)
	{
		if (b[vitrimax] < b[i])
		{
			vitrimax = i;
		}
	}

	for (int i = 0; i < n; i++)
	{
		if (vitrimax == i)
		{
			return a[i];
		}
	}
}

int main()
{
	int n;
	double a[Max];

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

	double x;
	printf("\n\nNhap vao gia tri x de tim gia tri xa nhat: ");
	scanf("%lf", &x);

	int nb;
	double b[Max];

	XuLy(n, a, &nb, b, x);
	printf("\nMang cac phan tu khoang cach xa x nhat: ");
	XuatMang(nb, b);
	printf("\n\nGia tri trong mang ban dau xa x nhat la: %lf", GiaTriKhoangCachXaX(n, a, nb, b));

	getch();
	return 0;
}
