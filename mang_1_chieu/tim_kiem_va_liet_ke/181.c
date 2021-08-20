/* 2016 - Nguyễn Nhật Tuấn.
Code được viết lúc tôi mới học lập trình C/C++ nên có một số cách chưa được tốt, mong giúp ích được các bạn tham khảo.
*/

// Bài 181/65/SBT Thầy NTTMK: Cho mảng một chiều các số nguyên. Hãy viết hàm liệt kê các giá trị chẵn có ít nhất một lân cận cũng là giá trị chẵn.

#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <math.h>
#define Max 100

void NhapMang(int n, int a[])
{
	for (int i = 0; i < n; i++)
	{
		printf("\nNhap vao phan tu thu %d: ", i + 1);
		scanf("%d", &a[i]);
	}
}

void XuatMang(int n, int a[])
{
	printf("\n\n");
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
}

// Kiểm tra phần tử chẵn.
int KTChan(int n, int a[])
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] % 2 == 0)
		{
			return 1;
		}
	}
	return 0;
}

// Xuất số chẳn có ít nhất 1 lân cận cũng là số chẵn.
void XuatChan(int n, int a[])
{
	if (KTChan(n, a) == 1)
	{
		printf("\n\nCac gia tri chan co it nhat 1 lan can cung la chan: ");
		for (int i = 0; i < n; i++)
		{
			if (i == 0)
			{
				if (a[i + 1] % 2 == 0)
				{
					printf("%d ", a[i]);
				}
			}
			else if (i == n - 1)
			{
				if (a[i - 1] % 2 == 0)
				{
					printf("%d ", a[i]);
				}
			}
			else
			{
				if (a[i - 1] % 2 == 0 || a[i + 1] % 2 == 0)
				{
					printf("%d ", a[i]);
				}
			}
		}
	}
	else
	{
		printf("\n\nMang a khong co so chan.");
	}
}

int main()
{
	int a[Max], n;

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

	XuatChan(n, a);

	getch();
	return 0;
}
