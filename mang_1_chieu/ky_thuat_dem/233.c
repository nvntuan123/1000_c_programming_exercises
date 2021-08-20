// Bài 233: Hãy liệt kê tần suất của các giá trị xuất hiện trong dãy. Lưu ý: mỗi giá trị liệt kêt tần suất 1 lần.

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
	for (int i  = 0; i < n; i++)
	{
		printf("%lf ", a[i]);
	}
}

// Kiểm tra phần tử có trùng hay không.
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

// đếm số lần xuất hiện của phần tử.
int TanSuat(int n, double a[], int vitricandem)
{
	int dem = 1; // tính lun phần tử đang xét.
	for (int i = vitricandem + 1; i < n; i++)
	{
		if (a[vitricandem] == a[i])
		{
			dem++;
		}
	}
	return dem;
}

// Liệt kê tần suất của các giá trị xuất hiện trong dãy. Lưu ý: mỗi giá trị liệt kêt tần suất 1 lần.
void LKTanSuat(int n, double a[])
{
	printf("\n\nTan suat xuat hien cua cac gia tri trong mang a: \n\tGia tri\t\tTan suat");
	for (int i = 0; i < n; i++)
	{
		int kiemtratrung = KTPTTrung(n, a, i);
		if (kiemtratrung == 1)
		{
			continue;
		}

		int demtansuat = TanSuat(n, a, i);
		printf("\n\t%lf\t   %d", a[i], demtansuat);
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

	LKTanSuat(n, a);

	getch();
	return 0;
}
