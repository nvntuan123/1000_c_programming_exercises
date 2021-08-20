/* 2016 - Nguyễn Nhật Tuấn.
Code được viết lúc tôi mới học lập trình C/C++ nên có một số cách chưa được tốt, mong giúp ích được các bạn tham khảo.
*/

// Bài 278/77/SBT Thầy NTTMK: Hãy xóa tất cả các phần tử trùng nhau trong mảng và chỉ giữ lại duy nhất một phần tử.

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

// Kiểm tra phần tử trùng.
int KiemTraPhanTuTrung(int n, double a[], int vitricankiemtra)
{
	for (int i = vitricankiemtra - 1; i >= 0; i--)
	{
		if (a[vitricankiemtra] == a[i])
		{
			return 1;
		}
	}
	return -1;
}

// Hàm xóa phần tử.
void XoaPhanTu(int *n, double a[], int vitricanxoa)
{
	// Cách 1:
	/*for (int i = vitricanxoa; i < (*n) - 1; i++)
	{
		a[i] = a[i + 1];
	}*/

	// Cách 2:
	for (int i = vitricanxoa + 1; i < (*n); i++)
	{
		a[i - 1] = a[i];
	}
	(*n)--;
}

// Xóa các phần tử trùng chỉ giữ lại duy nhất 1 phần tử.
void XoaPhanTuTrung(int *n, double a[])
{
	for (int i = 1; i < (*n); i++)
	{
		int phantutrung = KiemTraPhanTuTrung(n, a, i);
		if (phantutrung == 1)
		{
			XoaPhanTu(&n, a, i);
			i--; // Cập nhật lại i.
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

	XoaPhanTuTrung(&n, a);
	printf("\n\nMang sau khi xoa cac phan tu trung chi giu lai duy nhat 1 phan tu: \n\n");
	XuatMang(n, a);

	getch();
	return 0;
}
