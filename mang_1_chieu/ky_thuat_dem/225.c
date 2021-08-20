/* 2016 - Nguyễn Nhật Tuấn.
Code được viết lúc tôi mới học lập trình C/C++ nên có một số cách chưa được tốt, mong giúp ích được các bạn tham khảo.
*/

// Bài 225/70/SBT Thầy NTTMK: Hãy đếm số lượng các giá trị lớn nhất có trong mảng một chiều các số thực.

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

// Tìm Max.
double Max(int n, double a[])
{
	double max = a[0];
	for (int i = 0; i < n; i++)
	{
		if (max < a[i])
		{
			max = a[i];
		}
	}
	return max;
}

// đếm số lượng các giá trị lớn nhất.
int DemMax(int n, double a[])
{
	int dem = 0;
	double max = Max(n, a);
	for (int i = 0; i < n; i++)
	{
		if (max == a[i])
		{
			dem++;
		}
	}
	return dem;
}

int main()
{
	int n;
	double a[SLPT];

	do
	{
		printf("Nhap vap sp luong phan tu n: ");
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

	int demso = DemMax(n, a);
	printf("\n\nSo luong gia tri lon nhat: %d", demso);

	getch();
	return 0;
}
