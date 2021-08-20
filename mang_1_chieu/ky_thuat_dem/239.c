// Bài 238/72/SBT Thầy NTTMK: (*) Hãy đếm số lượng số nguyên tố phân biệt trong mảng các số nguyên.

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

// Kiểm tra số nguyên tố.
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

// Kiểm tra phần tử trùng.
int KTPTTrung(int n, double a[], int vitricankiemtra)
{
	for (int i = vitricankiemtra - 1; i >= 0; i--)
	{
		if (a[vitricankiemtra] == a[i])
		{
			return 1;
		}
	}
	return 0;
}

// đếm số lượng số nguyên tố phân biệt.
int DemSNTPhanBiet(int n, double a[])
{
	int dem = 0;
	for (int i = 0; i < n; i++)
	{
		if (KTSNT(a[i]) == 1)
		{
			int phantutrung = KTPTTrung(n, a, i);
			if (phantutrung == 1)
			{
				continue;
			}
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

	int demso = DemSNTPhanBiet(n, a);
	if (demso == 0)
	{
		printf("\n\nMang khong co so nguyen to.");
	}
	else
	{
		printf("\n\nSo luong so nguyen to phan biet: %d", demso);
	}

	getch();
	return 0;
}
