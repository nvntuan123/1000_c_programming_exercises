/* 2016 - Nguyễn Nhật Tuấn.
Code được viết lúc tôi mới học lập trình C/C++ nên có một số cách chưa được tốt, mong giúp ích được các bạn tham khảo.
*/

// Bài 191/66/SBT Thầy NTTMK: Hãy liệt kê các giá trị cực đại trong mảng một chiều các số thực. Một phần tử được gọi là cực đại khi lớn hơn
// các phần tử lân cận.

#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <math.h>
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

// Kiểm tra số cực đại.
double KTCD(int n, double a[])
{
	for (int i = 0; i < n; i++)
	{
		if (i == 0)
		{
			if (a[i] > a[i + 1])
			{
				return 1;
			}
		}
		else if (i == n - 1)
		{
			if (a[i] > a[i - 1])
			{
				return 1;
			}
		}
		else
		{
			if (a[i] > a[i + 1] && a[i] > a[i - 1])
			{
				return 1;
			}
		}
	}
	return 0;
}

// Liệt kê số cực đại.
void LKSCD(int n, double a[])
{
	if (KTCD(n, a) == 1)
	{
		printf("\n\nGia tri cuc dai: ");
		for (int i = 0; i < n; i++)
		{
			if (i == 0)
			{
				if (a[i] > a[i + 1])
				{
					printf("%lf ", a[i]);
				}
			}
			else if (i == n - 1)
			{
				if (a[i] > a[i - 1])
				{
					printf("%lf ", a[i]);
				}
			}
			else
			{
				if (a[i] > a[i + 1] && a[i] > a[i - 1])
				{
					printf("%lf ", a[i]);
				}
			}
		}
	}
	else
	{
		printf("\n\nMang khong co so cuc dai.");
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
	printf("\nMang a sau khi nhap la: ");
	XuatMang(n, a);

	LKSCD(n, a);

	getch();
	return 0;
}
