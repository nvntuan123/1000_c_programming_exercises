/* 2016 - Nguyễn Nhật Tuấn.
Code được viết lúc tôi mới học lập trình C/C++ nên có một số cách chưa được tốt, mong giúp ích được các bạn tham khảo.
*/

// Bài 272/76/SBT Thầy NTTMK: Hãy xóa tất cả số lớn nhất trong mảng các số thực.

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
		printf("%lf ", a[i]);
	}
}

// Hàm xóa phần tử.
void XoaPhanTu(int *n, double a[], int vitricanxoa)
{
	// Cách 1:
	/*for (int i = vitricanxoa; i < n - 1; i++)
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

// Tìm phần tử lớn nhất.
double Max(int n, double a[])
{
	int max = 0; // Cho vị trị có phần từ lớn nhất là vị trí 0.
	for (int i = 0; i < n; i++)
	{
		if (a[max] < a[i]) // Nếu phần tử ngay vị trí đó nhỏ hơn phần tử ở vị trí khác thì
		{
			max = i; // => Cập nhật lại vị trí có phần tử lớn.
		}
	}
	return a[max];
}

// Xóa các phần tử lớn nhất trong mảng.
void XoaPhanTuLonNhat(int *n, double a[])
{
	int phantulonnhat = Max(n, a);
	for (int i = 0; i < n; i++)
	{
		if (a[i] == phantulonnhat)
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
	printf("\nMang sau khi nhap la: ");
	XuatMang(n, a);

	printf("\n\n%lf", Max(n, a));
	XoaPhanTuLonNhat(&n, a);
	printf("\n\nMang sau khi xoa cac phan tu lon nhat: ");
	XuatMang(n, a);

	getch();
	return 0;
}
