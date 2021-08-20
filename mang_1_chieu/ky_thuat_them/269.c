/* 2016 - Nguyễn Nhật Tuấn.
Code được viết lúc tôi mới học lập trình C/C++ nên có một số cách chưa được tốt, mong giúp ích được các bạn tham khảo.
*/

// Bài 276/77/SBT Thầy NTTMK: Hãy thêm một giá trị x vào trong mảng tăng mà vẫn giữ nguyên tính đơn điệu tăng của mảng.

#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <Windows.h>
#define SLPT 100

void NhapMang(int n, double a[])
{
	for (int i = 0; i < n; i++)
	{
		/*printf("\nNhap vao phan tu thu %d: ", i + 1);
		scanf("%lf", &a[i]);
		while (a[i] <= a[i - 1])
		{
			if (a[i] <= a[i - 1])
			{
				printf("\nMang phai tang dan.\n");
			}
			printf("\nNhap vao phan tu thu %d: ", i + 1);
			scanf("%lf", &a[i]);
		}*/
		do // do while hay hon :D.
		{
			printf("\nNhap vao phan tu thu %d: ", i + 1);
			scanf("%lf", &a[i]);

			if (a[i] <= a[i - 1])
			{
				printf("\nMang phai tang dan.\n");
			}
		} while (a[i] < a[i - 1]);
	}
}

void XuatMang(int n, double a[])
{
	for (int i = 0; i < n; i++)
	{
		printf("%lf ", a[i]);
	}
}

// Kiểm tra x có lớn hơn giá trị nào trong mảng hay không.
int KiemTra(int n, double a[], double x)
{
	int check = -1; // False.
	for (int i = n - 1; i >= 0; i--)
	{
		if (x > a[i])
		{
			check = i + 1; // True.
			break;
		}
	}
	return check;
}

// Chèn x vào đầu mảng nếu như x nhỏ hơn mọi giá trị trong mảng.
void ChenXVaoDauMang(int *n, double a[], double x)
{
	for (int i = *n; i > 0; i--)
	{
		a[i] = a[i - 1];
	}
	a[0] = x;
	(*n)++;
}

// Thêm x vào mảng mà vẫn giữ tính đơn điệu tăng của mảng.
void ChenX(int *n, double a[], double x, int vitricanthem)
{
	// Cách 1:
	//for (int i = n; i > vitricanthem; i--)
	//{
	//	a[i] = a[i - 1];
	//}

	// Cách 2:
	for (int i = (*n) - 1; i >= vitricanthem; i --)
	{
		a[i + 1] = a[i];
	}
	a[vitricanthem] = x;
	(*n)++;
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

	double x;
	printf("\n\nNhap vao x: ");
	scanf("%lf", &x);

	int KT = KiemTra(n, a, x);
	if (KT == -1)
	{
		ChenXVaoDauMang(&n, a, x);
		printf("\nMang sau khi chen van giu tinh dieu don tang dan la:\n\n");
		XuatMang(n, a);
	}
	else
	{
		ChenX(&n, a, x, KT);
		printf("\nMang sau khi chen van giu tinh dieu don tang dan la:\n\n");
		XuatMang(n, a);
	}

	getch();
	return 0;
}
