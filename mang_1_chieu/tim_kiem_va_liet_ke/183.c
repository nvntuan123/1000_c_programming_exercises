/* 2016 - Nguyễn Nhật Tuấn.
Code được viết lúc tôi mới học lập trình C/C++ nên có một số cách chưa được tốt, mong giúp ích được các bạn tham khảo.
*/

// Bài 183/65/SBT Thầy NTTMK: Hãy liệt kê các vị trí mà giá trị tại vị trí đó là giá trị lớn nhất trong mảng một chiều các số thực.

#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <Windows.h>
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
	printf("\n\n");
	for (int i = 0; i < n; i++)
	{
		printf("%lf ", a[i]);
	}
}

// Tìm max.
double Maxx(int n, double a[])
{
	double max = a[0];
	for (int i = 1; i < n; i++)
	{
		if (a[i] > max)
		{
			max = a[i];
		}
	}
	return max;
}

// Liệt kê vị trí có giá trị lớn nhất.
void LKGTLN(int n, double a[])
{
	printf("\n\nVi tri phan tu lon nhat: ");
	for (int i = 0; i < n; i++)
	{
		if (Maxx(n, a) == a[i])
		{
			printf("%d ", i);
		}
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
			printf("Ban nhap sai, xin kiem tra lai (n > 0 va n <= 100).\n\n");
		}
	} while (n <= 0 || n > Max);

	NhapMang(n, a);
	printf("\nMang a sau khi nhap la: ");
	XuatMang(n, a);

	LKGTLN(n, a);

	getch();
	return 0;
}
