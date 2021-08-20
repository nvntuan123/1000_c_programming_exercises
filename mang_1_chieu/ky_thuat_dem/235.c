// Bài 235/71/SBT Thầy NTTMK: Cho hai mảng a, b. Liệt kê các giá trị chỉ xuất hiện 1 trong 2 mảng.

#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <math.h>
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

// Kiểm tra phần tử có trùng trong mảng còn lại không.
int KTPTTrungTrongMangConLai(int n, double a[], double phantucankiemtra)
{
	for (int i = 0; i < n; i++)
	{
		if (phantucankiemtra == a[i])
		{
			return 1;
		}
	}
	return 0;
}

// Kiểm tra phần tử có tồn tại không.
int KTPhanTuTonTai(int n, double a[], double b[])
{
	for (int i = 0; i < n; i++)
	{
		if (KTPTTrungTrongMangConLai(n, b, a[i]) == 0)
		{
			return 1;
		}
	}
	return 0;
}

// Liệt kê các giá trị chỉ xuất hiện trong mảng a.
void LKCacGiaTriTrongManga(int n, double a[], double b[])
{
	if (KTPhanTuTonTai(n, a, b) == 1)
	{
		printf("\n\nCac gia tri chi xuat hien 1 trong 2 mang: ");
		for (int i = 0; i < n; i++)
		{
			int phantutrung = KTPTTrung(n, a, i);
			if (phantutrung == 1)
			{
				continue;
			}

			int kiemtraphantumangconlai = KTPTTrungTrongMangConLai(n, b, a[i]);
			if (kiemtraphantumangconlai == 0)
			{
				printf("%lf ", a[i]);
			}
		}
	}
	else
	{
		printf("\n\nKhong co gia tri chi xuat hien 1 trong 2 mang.");
	}
}

// Liệt kê các giá trị chỉ xuất hiện trong mảng b.
void LKCacGiaTriTrongMangb(int n, double a[], double b[])
{
	if (KTPhanTuTonTai(n, a, b) == 1)
	{
		for (int i = 0; i < n; i++)
		{
			int phantutrung = KTPTTrung(n, b, i);
			if (phantutrung == 1)
			{
				continue;
			}

			int kiemtraphantumangconlai = KTPTTrungTrongMangConLai(n, a, b[i]);
			if (kiemtraphantumangconlai == 0)
			{
				printf("%lf ", b[i]);
			}
		}
	}
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

	NhapMang(n, a);
	printf("\nMang a sau khi nhap la: ");
	XuatMang(n, a);

	printf("\n");
	NhapMang(n, b);
	printf("\nMang b sau khi nhap la: ");
	XuatMang(n, b);

	LKCacGiaTriTrongManga(n, a, b);
	LKCacGiaTriTrongMangb(n, a, b);

	getch();
	return 0;
}
