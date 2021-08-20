// Bài 156/61/SBT Thầy NTTMK: Hãy tìm một vị trí trong mảng một chiều các số thực mà giá trị tại vị trí đó là giá trị "gần giá trị x nhất".

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

void XuLy(int n, double a[], int *nb, double b[], int x)
{
	*nb = 0;
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
			else if (a == 0)
			{
				b[(*nb)++] = x;
			}
			else
			{
				b[(*nb)++] = x - a[i];
			}
		}
		else if (x == 0)
		{
			if (a[i] > 0)
			{
				b[(*nb)++] = a[i];
			}
			else if (n == 0)
			{
				b[(*nb)++] = x;
			}
			else
			{
				b[(*nb)++] = - a[i];
			}
		}
		else
		{
			if (a[i] > 0)
			{
				b[(*nb)++] = a[i] - x;
			}
			else if (a[i] == 0)
			{
				b[(*nb)++] = - x;
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
	}
}

double Min(int n, double a[], int nb, double b[])
{
	int vtnn = 0, i, j;
	for (i = 0; i < n; i++)
	{
		if (b[vtnn] > b[i])
		{
			vtnn = i;
		}
	}

	for (j = 0; j < n; j++)
	{
		if (vtnn == j)
		{
			return a[j];
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
	printf("\nMang ban dau sau khi nhap la: ");
	XuatMang(n, a);

	int x;
	printf("\nNhap gia tri x de tim khoang cach gan nhat: ");
	scanf("%d", &x);

	int nb;
	double b[Max];

	XuLy(n, a, &nb, b, x);
	XuatMang(nb, b);
	printf("\n\nGia tri trong mang co khoang cach gan x nhat: %lf", Min(n, a, nb, b));

	getch();
	return 0;
}
