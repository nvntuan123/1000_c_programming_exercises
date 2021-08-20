// Bài 160/62/SBT Thầy NTTMK: Cho mảng một chiều các số thực hãy viết hàm tìm giá trị âm cuối cùng lớn hơn giá trị -1. Nếu mảng không có giá trị thỏa điều kiện trên thì hàm sẽ trả về giá trị không chẵn là 0.

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

double GiaTriAmCuoiCung(int n, double a[])
{
	for (int i = n - 1; i >= 0; i--)
	{
		if (a[i] < -1)
		{
			return a[i];
		}
	}
	return 0;
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

	if (GiaTriAmCuoiCung(n, a) == 0)
	{
		printf("\n\nKhong co gia tri am cuoi cung nho hon -1.");
	}
	else
	{
		printf("\n\nGia tri am cuoi cung lon hon -1 la: %lf", GiaTriAmCuoiCung(n, a));
	}

	getch();
	return 0;
}
