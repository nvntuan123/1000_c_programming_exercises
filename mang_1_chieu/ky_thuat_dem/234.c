// Bài 234/71/SBT Thầy NTTMK: Cho hai mảng số thực a,b. Đếm số lượng giá trị chỉ xuất hiện một trong hai mảng.

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

// Kiểm tra phần tử trong mảng a có xuất hiện trong mảng b hay không?
int KiemTraXuatHienTrong(int n, double a[], double phantucankiemtra)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] == phantucankiemtra)
		{
			return 0;
		}
	}
	return 1;
}

// Đếm số lượng giá trị chỉ xuất hiện trong mảng a.
int DemGiaTria(int n, double a[], double b[])
{
	int dem = 0;
	for (int i = 0; i < n; i++)
	{
		int phantutrung = KTPTTrung(n, a, i);
		if (phantutrung == 1)
		{
			continue;
		}

		int demphantu = KiemTraXuatHienTrong(n, b, a[i]);
		if (demphantu == 1)
		{
			dem++;
		}
	}
	return dem;
}

// Đếm số lượng giá trị chỉ xuất hiện trong mảng b.
int DemGiaTrib(int n, double a[], double b[])
{
	int dem = 0;
	for (int i = 0; i < n; i++)
	{
		int phantutrung = KTPTTrung(n, b, i);
		if (phantutrung == 1)
		{
			continue;
		}

		int demphantu = KiemTraXuatHienTrong(n, a, b[i]);
		if (demphantu == 1)
		{
			dem++;
		}
	}
	return dem;
}

int main()
{
	int n;
	double a[SLPT], b[SLPT];

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

	printf("\nNhap mang a.\n");
	NhapMang(n, a);
	printf("\nMang a sau khi nhap la: ");
	XuatMang(n, a);

	printf("\n\nNhap mang b.\n");
	NhapMang(n, b);
	printf("\nMang b sau khi nhap la: ");
	XuatMang(n, b);

	int demso = DemGiaTria(n, a, b) + DemGiaTrib(n, a, b);
	if (demso == 0)
	{
		printf("\n\nKhong co gia tri chi xuat hien 1 trong 2 mang.");
	}
	else
	{
		printf("\n\nSo luong gia tri xuat hien 1 trong 2 mang: %d", demso);
	}

	getch();
	return 0;
}
