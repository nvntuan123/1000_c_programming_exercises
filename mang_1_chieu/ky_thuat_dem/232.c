// Bài 232/71/SBT Thầy NTTMK: Hãy liệt kê các giá trị xuất hiện trong dãy quá một lần. Lưu ý : Mỗi giá trị liệt kê một lần.

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

// đếm số phần tử trùng.
int DemSoPhanTuTrung(int n, double a[], int vitricandem)
{
	int dem = 1; // tính lun nó.
	for (int i = vitricandem + 1; i < n; i++)
	{
		if (a[vitricandem] == a[i])
		{
			dem++;
		}
	}
	return dem;
}

// Kiểm tra mảng có phần tử xuất hiện quá 1 lần hay không.
int KTPTCoXuatHienQuaMotLan(int n, double a[])
{
	for (int i = 0; i < n; i++)
	{
		int phantuxuathien = DemSoPhanTuTrung(n, a, i);
		if (phantuxuathien == 2)
		{
			return 1;
		}
	}
	return 0;
}

// Liệt kê các giá trị xuất hiện trong dãy quá một lần.
void LKGT(int n, double a[])
{
	if (KTPTCoXuatHienQuaMotLan(n, a) == 1)
	{
		printf("\n\nCac gia tri xuat hien qua 1 lan: ");
		for (int i = 0; i < n; i++)
		{
			int PTtrung = KTPTTrung(n, a, i);
			if (PTtrung == 1)
			{
				continue;
			}

			int demphantutrung = DemSoPhanTuTrung(n, a, i);
			if (demphantutrung != 1)
			{
				printf("%lf ", a[i]);
			}
		}
	}
	else
	{
		printf("\n\nKhong co gia tri xuat hien qua 1 lan.");
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
	printf("\nMang a sau khi nhap la: ");
	XuatMang(n, a);

	LKGT(n, a);

	getch();
	return 0;
}
