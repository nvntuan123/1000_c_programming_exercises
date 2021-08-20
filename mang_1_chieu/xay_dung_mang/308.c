// Bài 308/80/SBT Thầy NTTMK: Cho mảng một chiều các số thực a. Hãy tạo mảng b từ mảng a, sao cho mảng b chỉ chứa các giá trị âm.

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
		printf("%.3lf ", a[i]);
	}
}

// Kiểm tra mảng a có số âm hay không ?
int KiemTraMangAm(int na, double a[])
{
	int check = 0; // False.
	for (int i = 0; i < na; i++)
	{
		if (a[i] < 0)
		{
			check =  1; // True.
		}
	}
	return check;
}

// Tạo mảng b chứa các giá trị âm của mảng a.
void TaoMangAm(int na, double a[], int *nb, double b[])
{
	(*nb) = 0;
	for (int i = 0; i < na; i++)
	{
		if (a[i] < 0)
		{
			b[(*nb)++] = a[i];
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

	if (KiemTraMangAm(na, a) == 1)
	{
		TaoMangAm(na, a, &nb, b);
		printf("\n\nMang b sau khi tao tu mang a chua cac gia tri am la: ");
		XuatMang(nb, b);
	}
	else
	{
		printf("\n\nMang a khong co gia tri am.");
	}

	getch();
	return 0;
}
