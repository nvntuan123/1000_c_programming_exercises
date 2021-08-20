// Bài 222/70/SBT Thầy NTTMK: Hãy đếm số lượng phần tử cùng lớn hơn hoặc nhỏ hơn các phần tử xung quanh.

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
	printf("\n\n");
	for (int i = 0; i < n; i++)
	{
		printf("%lf ", a[i]);
	}
}

// đếm số lượng phần tử cùng lớn hơn hoặc nhỏ hơn các phần tử xung quanh.
double DemPhanTuCucTri(int n, double a[])
{
	int dem = 0;
	for (int i = 1; i < n - 1; i++)
	{
		if (a[i] > a[i - 1] && a[i] > a[i + 1])
		{
			dem++;
		}
		if (a[i] < a[i - 1] && a[i] < a[i + 1])
		{
			dem++;
		}
	}
	return dem;
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
	printf("\nMang a sau khi nhap la: ");
	XuatMang(n, a);

	int demso = DemPhanTuCucTri(n, a);
	if (demso == 0)
	{
		printf("\n\nMang khong co cuc tri.");
	}
	else
	{
		printf("\n\nSo luong cuc tri la: %d", demso);
	}

	getch();
	return 0;
}
