/* 2016 - Nguyễn Nhật Tuấn.
Code được viết lúc tôi mới học lập trình C/C++ nên có một số cách chưa được tốt, mong giúp ích được các bạn tham khảo.
*/

// Bài 237,238(*)/72/SBT Thầy NTTMK: Hãy tìm một giá trị có số lần xuất hiện nhiều nhất trong mảng các số nguyên.

#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <Windows.h>
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
	for (int i = 0; i < na; i++)
	{
		printf("%lf ", a[i]);
	}
}

// Kiềm phần tử trùng.
int KTPTTrung(int na, double a[], int vitricankiemtra)
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

// Đếm số lần giá trị xuất hiện trong mảng a.
int DemSoLanGiaTriXuatHienTrongManga(int na, double a[], int vitricandem)
{
	int dem = 0;
	for (int i = 0; i < na; i++)
	{
		if (a[vitricandem] == a[i])
		{
			dem++;
		}
	}
	return dem;
}

// Đếm và tách giá trị có số lần xuất hiện trong mảng sang màng b.
void TachSo(int na, double a[], int *nb, double b[])
{
	(*nb) = 0;
	for (int i = 0; i < na; i++)
	{
		int phantutrung = KTPTTrung(na, a, i);
		if (phantutrung == 1)
		{
			continue;
		}

		int dem = DemSoLanGiaTriXuatHienTrongManga(na, a, i);
		b[(*nb)++] = dem;
	}
}

// Tìm Max trong mảng b.
double TimMaxTrongMangb(int nb, double b[])
{
	double max = b[0];
	for (int i = 0; i < nb; i++)
	{
		if (max < b[i])
		{
			max = b[i];
		}
	}
	return max;
}

// TÌm giá trị xuất hiện nhiều nhất trong mảng a.
void GiaTriXuatHienNhieuNhatTrongManga(int na, double a[], int nb, double b[])
{
	for (int i = 0; i < na; i++)
	{
		int phantutrung = KTPTTrung(na, a, i);
		if (phantutrung == 1)
		{
			continue;
		}

		int dem = DemSoLanGiaTriXuatHienTrongManga(na, a, i);
		if (TimMaxTrongMangb(nb, b) == 1)
		{
			printf("\n\nMang a khong gia tri xuat hien nhieu nhat.");
			break;
		}
		else
		{
			if (dem == TimMaxTrongMangb(nb, b))
			{
				printf("\n\nGia tri xuat hien nhieu nhat trong mang: %lf\nSo lan xuat hien: %d", a[i], dem);
			}
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

	TachSo(na, a, &nb, b);
	GiaTriXuatHienNhieuNhatTrongManga(na, a, nb, b);

	getch();
	return 0;
}
