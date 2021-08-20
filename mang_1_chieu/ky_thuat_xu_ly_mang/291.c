/* 2016 - Nguyễn Nhật Tuấn.
Code được viết lúc tôi mới học lập trình C/C++ nên có một số cách chưa được tốt, mong giúp ích được các bạn tham khảo.
*/

// Bài 291/78/SBT Thầy NTTMK: Hãy biến đổi mảng bằng cách thay các giá trị lớn nhất bằng các giá trị nhỏ nhất và ngược lại.

#include <stdio.h>
#include <conio.h>
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

// Tìm Max.
double Max(int n, double a[])
{
	double max = a[0];
	for (int i = 1; i < n; i++)
	{
		if (max < a[i])
		{
			max = a[i];
		}
	}
	return max;
}

// Tìm min.
double Min(int n, double a[])
{
	double min = a[n - 1];
	for (int i = n - 2; i >= 0; i--)
	{
		if (min > a[i])
		{
			min = a[i];
		}
	}
	return min;
}

// Biến đổi max thành min và ngượi lại.
void MaxThanhMin(int n, double a[])
{
	double max = Max(n, a);
	double min = Min(n, a);
	for (int i = 0; i < n; i++)
	{
		if (a[i] == min)
		{
			a[i] = max;
			continue;
		}
		if (a[i] == max)
		{
			a[i] = min;
		}
	}
}

int main()
{
	int n;
	double a[SLPT];

	do
	{
		printf("Nhap vao so luong phan tu n[1, %d]: ", SLPT);
		scanf("%d", &n);

		if (n <= 0 || n > SLPT)
		{
			system("cls");
			printf("Ban nhap sai, nhap lai.\n\n");
		}
	} while (n <= 0 || n > SLPT);

	NhapMang(n, a);
	printf("\nMang ban dau sau khi nhap la: ");
	XuatMang(n, a);

	MaxThanhMin(n, a);
	printf("\n\nMang sau khi bien doi max = min va nguoc lai: ");
	XuatMang(n, a);

	getch();
	return 0;
}
