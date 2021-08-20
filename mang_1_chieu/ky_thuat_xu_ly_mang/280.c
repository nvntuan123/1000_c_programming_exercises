/* 2016 - Nguyễn Nhật Tuấn.
Code được viết lúc tôi mới học lập trình C/C++ nên có một số cách chưa được tốt, mong giúp ích được các bạn tham khảo.
*/

// Bài 280/77/SBT Thầy NTTMK: Hãy đưa số một về đầu mảng.

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

// Hoán vị.
void Swap(double *a, double *b)
{
	 *a += *b;
	 *b = *a - *b; // b = a.
	 *a -= *b; // a = b.
}

// Đưa số 1 về đầu mảng đây ^_^.
void DuaMotVeDau(int n, double a[])
{
	// Nổi bọt.
	for (int i = 0; i < n; i++)
	{
		for (int j = n - 1; j > i; j--)
		{
			if (a[j] == 1)
			{
				Swap(&a[j], &a[j - 1]);
			}
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

	DuaMotVeDau(n, a);
	printf("\n\nMang sau khi dua so 1 ve dau mang: ");
	XuatMang(n, a);

	getch();
	return 0;
}
