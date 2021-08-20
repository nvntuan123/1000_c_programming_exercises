/* 2016 - Nguyễn Nhật Tuấn.
Code được viết lúc tôi mới học lập trình C/C++ nên có một số cách chưa được tốt, mong giúp ích được các bạn tham khảo.
*/

// Bài 158/61/SBT Thầy NTTMK: Cho mảng một chiều các số thực, hãy tìm giá trị x sao cho đoạn [-x,x] chứa tất cả các giá trị trong mảng.

#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <math.h>
#define Max 100

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

// Cách 1:
//// Chuyển các phần tử thành dương.
//void ChuyenMang(int n, double a[], int &nb, double b[])
//{
//	nb = 0;
//	for (int i = 0; i < n; i++)
//	{
//		if (a[i] < 0)
//		{
//			b[nb++] = - a[i];
//		}
//		else
//		{
//			b[nb++] = a[i];
//		}
//	}
//}
//
//// Tìm max của mảng mới chuyển được. Max chính là x.
//double TimMax(int nb, double b[])
//{
//	double max = b[0];
//	for (int i = 0; i < nb; i++)
//	{
//		max < b[i]? max = b[i]: max;
//	}
//	return max;
//}

// Cách 2:
double KTMangToanDuong(int n, double a[])
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] < 0)
		{
			return 0;
		}
	}
	return 1;
}

double KTMangToanAm(int n, double a[])
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] > 0)
		{
			return 0;
		}
	}
	return 1;
}

void DoiMang(int n, double a[], int nb, double b[])
{
	nb = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] < 0)
		{
			b[nb++] = - a[i];
		}
		else
		{
			b[nb++] = a[i];
		}
	}
}

double TimMax(int nb, double b[])
{
	double max = b[0];
	for (int i = 0; i < nb; i++)
	{
		max < b[i]? max = b[i] : max;
	}
	return max;
}

double XuLy(int n, double a[])
{
	if (KTMangToanDuong(n, a) == 1)
	{
		int max = 0;
		for (int i = 0; i < n; i++)
		{
			max < a[i]? max = a[i] : max;
		}
		return max;
	}
	else if (KTMangToanAm(n, a) == 1)
	{
		int min = 0;
		for (int i = 0; i < n; i++)
		{
			min > a[i]? min = a[i] : min;
		}
		return - min;
	}
	else
	{
		int max = 0;
		for (int i = 0; i < n; i++)
		{
			if (a[i] > 0)
			{
				max = a[i];
				break;
			}
		}
		for (int j = 0; j < n; j++)
		{
			if (a[j] < 0)
			{
				max < - a[j]? max = - a[j] : max;
			}
			else
			{
				max < a[j]? max = a[j] : max;
			}
		}
		return max;
	}
}

int main()
{
	int n;
	double a[Max];

	do
	{
		printf("Nhap vao so luong phan tu n: ");
		scanf("%d", &n);

		if (n <= 0 || n > Max)
		{
			system("cls");
			printf("Ban nhap sai, xin kiem tra lai n thuoc (0, 100].\n\n");
		}
	} while (n <= 0 || n > Max);

	NhapMang(n, a);
	printf("\nMang a sau khi nhap la: ");
	XuatMang(n, a);

	int nb;
	double b[Max];

	// Cách 1:
	//ChuyenMang(n, a, nb, b);
	//printf("\n\nMang b sau khi doi cac phan tu thanh gia tri duong: ");
	//XuatMang(nb, b);

	//printf("\n\nGia tri x tim duoc sao cho doan [-x, x] chua tat ca ca gia tri trong mang a: %lf", TimMax(nb, b));

	// Cách 2;
	printf("\n\nGia tri x tim duoc sao cho [-x, x] chua tat ca cac gia tri trong mang a: %lf", XuLy(n, a));

	getch();
	return 0;
}
