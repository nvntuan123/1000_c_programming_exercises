/* 2016 - Nguyễn Nhật Tuấn.
Code được viết lúc tôi mới học lập trình C/C++ nên có một số cách chưa được tốt, mong giúp ích được các bạn tham khảo.
*/

// Bài 279/77/SBT Thầy NTTMK: Hãy xóa tất cả các phần tử có tần suất xuất hiện trong mảng nhiều hơn một lần.

#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <Windows.h>
#define SLPT 100

// Nhập mảng.
void NhapMang(int n, double a[])
{
	for (int i = 0; i < n; i++)
	{
		printf("\nNhap vao phan tu thu %d: ", i + 1);
		scanf("%lf", &a[i]);
	}
}

// Xuất mảng.
void XuatMang(int n, double a[])
{
	for (int i = 0; i < n; i++)
	{
		printf("%.2lf ", a[i]);
	}
}

// Hàm xòa phần tử.
void XoaPhanTu(int *n, double a[], int vitricanxoa)
{
	// Cách 1:
	for (int i = vitricanxoa; i < (*n) - 1; i++)
	{
		a[i] = a[i + 1];
	}

	// Cách 2:
	/*for (int i = vitricanxoa + 1; i < (*n); i++)
	{
		a[i - 1] = a[i];
	}*/
	(*n)--;
}

// Xóa phần tử trùng.
void XoaPhanTuTrung(int *n, double a[], int vitricanxoa, double phantucanxoa)
{
	for (int i = vitricanxoa; i < (*n); i++)
	{
		if (a[i] == phantucanxoa)
		{
			XoaPhanTu(&n, a, i);
			i--; // Cập nhật lại i.
		}
	}

	// Thuốc chuột. ^_^
	/*printf("\n\n");
	XuatMang(n, a);*/
}

// Kiềm tra phần tử trùng.
int KiemTraPhanTuTrung(int n, double a[], int vitricankiemtra)
{
	for (int i = vitricankiemtra + 1; i < n; i++)
	{
		if (a[vitricankiemtra] == a[i])
		{
			return 1;
		}
	}
	return -1;
}

// Xóa phần tử trùng kể cả nó.
void XoaPhanTuTrungKeNo(int *n, double a[])
{
	for (int i = 0; i < (*n); i++)
	{
		int phantutrung = KiemTraPhanTuTrung(n, a, i);
		if (phantutrung == 1)
		{
			XoaPhanTuTrung(&n, a, i, a[i]);
			i--;
		}
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
	printf("\nMang ban dau sau khi nhap la: ");
	XuatMang(n, a);

	XoaPhanTuTrungKeNo(&n, a);
	printf("\n\nMang sau khi xoa cac phan tu trung nhau ke ca no:\n\n");
	XuatMang(n, a);

	getch();
	return 0;
}
