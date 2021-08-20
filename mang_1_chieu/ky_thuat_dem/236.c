/* 2016 - Nguyễn Nhật Tuấn.
Code được viết lúc tôi mới học lập trình C/C++ nên có một số cách chưa được tốt, mong giúp ích được các bạn tham khảo.
*/

// Bài 236/81/SBT Thầy NTTMK(*): Cho hai mảng a và b. Hãy đếm số lần xuất hiện của mảng a trong mảng b ?

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

// Kiem tra phần tử trùng.
int KTPhanTuTrung(int n, double a[], int vitricankiemtra)
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

//đếm số lần xuất hiện của mảng a trong mảng b ?
void DemSoLanXuatHien(int n, double a[], double b[])
{
	printf("\n\nSo lan cac gia tri trong mang a xuat hien trong mang b:\n\tGia tri\t\tSo lan xuat hien");
	for (int i = 0; i < n; i++)
	{
		int phantutrung = KTPhanTuTrung(n, a, i);
		if (phantutrung == 1)
		{
			continue;
		}

		int dem = 0;
		for (int j = 0; j < n; j++)
		{
			if (a[i] == b[j])
			{
				dem++;
			}
		}
		printf("\n\t%lf\t\t%d ", a[i], dem);
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

	DemSoLanXuatHien(n, a, b);

	getch();
	return 0;
}
