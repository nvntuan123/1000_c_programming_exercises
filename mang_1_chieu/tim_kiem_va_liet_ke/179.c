// Bài 179/64/SBT Thầy NTTMK: Hãy liệt kê các giá trị trong mảng mà thỏa điều kiện lớn hơn trị tuyệt đối của giá trị đứng liền sau nó.

#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <math.h>
#define Max 100

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
	printf("\n\n");
	for (int i = 0; i < n; i++)
	{
		printf("%lf ", a[i]);
	}
}

// Kiểm tra có lớn hơn trị tuyệt đối số đứng liền sau.
double KT(int n, double a[])
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] > abs(a[i + 1]))
		{
			return 1;
		}
	}
	return 0;
}

// Xuất số lớn hơn trị tuyệt đối số đứng liền sau.
void Xuatliensau(int n, double a[])
{
	if (KT(n, a) == 1)
	{
		printf("\n\nGia tri lon hon tri tuyet doi so dung lien sau no: ");
		for (int i = 0; i < n - 1; i++)
		{
			if (a[i] > fabs(a[i + 1]))
			{
				printf("%lf ", a[i]);
			}
		}
	}
	else
	{
		printf("\n\nKhong co so thoa yeu cau.");
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

	Xuatliensau(n, a);

	getch();
	return 0;
}
