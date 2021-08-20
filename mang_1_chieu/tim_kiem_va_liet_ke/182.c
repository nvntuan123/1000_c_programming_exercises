/* 2016 - Nguyễn Nhật Tuấn.
Code được viết lúc tôi mới học lập trình C/C++ nên có một số cách chưa được tốt, mong giúp ích được các bạn tham khảo.
*/

// Bài 182/65/SBT Thầy NTTMK: Cho mảng một chiều các số thực. Hãy viết hàm liệt kê tất cả các giá trị trong mảng có ít nhất một lân cận trái dấu với nó.

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
	for (int i = 0; i < n; i++)
	{
		printf("%lf ", a[i]);
	}
}

// Kiểm tra giá trị có ít nhất 1 lân cận trái dấu.
double KTGT(int n, double a[])
{
	for (int i = 0; i < n; i++)
	{
		if (i == 0)
		{
			if (a[i] > 0)
			{
				if (a[i + 1] < 0)
				{
					return 1;
				}
			}
			else
			{
				if (a[i + 1] > 0)
				{
					return 1;
				}
			}
		}
		else if (i == n - 1)
		{
			if (a[i] > 0)
			{
				if (a[i - 1] < 0)
				{
					return 1;
				}
			}
			else
			{
				if (a[i - 1] > 0)
				{
					return 1;
				}
			}
		}
		else
		{
			if (a[i] > 0)
			{
				if (a[i - 1] < 0 || a[i + 1] < 0)
				{
					return 1;
				}
			}
			else
			{
				if (a[i - 1] > 0 || a[i + 1] > 0)
				{
					return 1;
				}
			}
		}
	}
	return 0;
}

// Liệt kê giá trị có ít nhất 1 lân cận trái dấu.
void LKGT(int n, double a[])
{
	if (KTGT(n, a) == 1)
	{
		printf("\n\nCac gia tri thoa yeu cau: ");
		for (int i = 0; i < n; i++)
		{
			if (i == 0)
			{
				if (a[i] > 0)
				{
					if (a[i + 1] < 0)
					{
						printf("%lf ", a[i]);
					}
				}
				else
				{
					if (a[i + 1] > 0)
					{
						printf("%lf ", a[i]);
					}
				}
			}
			else if (i == n - 1)
			{
				if (a[i] > 0)
				{
					if (a[i - 1] < 0)
					{
						printf("%lf ", a[i]);
					}
				}
				else
				{
					if (a[i - 1] > 0)
					{
						printf("%lf ", a[i]);
					}
				}
			}
			else
			{
				if (a[i] > 0)
				{
					if (a[i - 1] < 0 || a[i + 1] < 0)
					{
						printf("%lf ", a[i]);
					}
				}
				else
				{
					if (a[i - 1] > 0 || a[i + 1] > 0)
					{
						printf("%lf ", a[i]);
					}
				}
			}
		}
	}
	else
	{
		printf("\n\nMang khong co gia tri thoa yeu cau.");
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

	LKGT(n, a);

	getch();
	return 0;
}
