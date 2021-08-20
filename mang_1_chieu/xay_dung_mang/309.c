// Bài 309/81/SBT Thầy NTTMK: Cho mảng một chiều các số thực a. Hãy tạo mảng b từ mảng a, với b[i] = tổng các phần tử lân cận với a[i] trong mảng a.

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
		printf("%.3lf ", a[i]);
	}
}

// Tạo mảng.
void TaoMang(int na, int *nb, double a[], double b[])
{
	(*nb) = 0;
	for (int i = 0; i < na; i++)
	{
		if (i == 0)
		{
			b[(*nb)++] = a[i + 1];
		}
		else if (i == na - 1)
		{
			b[(*nb)++] = a[i - 1];
		}
		else
		{
			b[(*nb)++] = a[i - 1] + a[i + 1];
		}
	}
}

int main()
{
	int na, nb;
	double a[SLPT], b[SLPT];

	do
	{
		printf("Nhap vao so luong phan tu n: ");
		scanf("%d", &na);

		if (na <= 0 || na > SLPT)
		{
			system("cls");
			printf("Ban nhap sai, xin kiem tra lai (n > 0 va n <= 100).\n\n");
		}
	} while (na <= 0 || na > SLPT);

	NhapMang(na, a);
	printf("\nMang a sau khi nhap la: ");
	XuatMang(na, a);

	TaoMang(na, &nb, a, b);
	printf("\n\nMang b sau khi tao tu mang a la: ");
	XuatMang(nb, b);

	getch();
	return 0;
}
