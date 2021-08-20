// Bài 228/71/SBT Thầy NTTMK: Hãy xác định số lượng các phần tử kề nhau mà số đứng sau cùng dấu số đứng trước và có giá trị tuyệt đối lớn hơn.

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

// Số lượng các phần tử kề nhau mà số đứng sau cùng dấu số đứng trước và có giá trị tuyệt đối lớn hơn.
double PTKeNhauCungDau(int n, double a[])
{
	int dem = 0;
	for (int i = 1; i < n; i++)
	{
		if ((a[i] > 0 && a[i - 1] > 0) || (a[i] < 0 && a[i - 1] < 0))
		{
			if (fabs(a[i]) > fabs(a[i - 1]))
			{
				dem++;
			}
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

	int demso = PTKeNhauCungDau(n, a);
	if (demso != 0)
	{
		printf("\n\nSo luong phan tu ke nhau ma so dung sau cung dau so dung truoc va tri tuyet doi lon hon: %d", demso);
	}
	else
	{
		printf("\n\nKhong co phan tu ke nhau ma so dung sau cung dau so dung truoc va tri tuyat doi lon hon.");
	}

	getch();
	return 0;
}
