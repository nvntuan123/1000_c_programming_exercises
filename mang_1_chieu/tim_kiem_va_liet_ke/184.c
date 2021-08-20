/* 2016 - Nguyễn Nhật Tuấn.
Code được viết lúc tôi mới học lập trình C/C++ nên có một số cách chưa được tốt, mong giúp ích được các bạn tham khảo.
*/

// Bài 184/65/SBT Thầy NTTMK: Hãy liệt kê các vị trí mà giá trị tại đó là số nguyên tố trong mảng một chiều các số nguyên.

#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <math.h>
#define SLPT 100

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

// Kiểm tra SNT.
int KTSNT(int a)
{
	if (a < 2)
	{
		return 0;
	}
	else if (a == 2)
	{
		return 1;
	}
	else
	{
		if (a % 2 == 0)
		{
			return 0;
		}
		else
		{
			for (int i = 3; i <= sqrt((double)a); i += 2)
			{
				if (a % i == 0)
				{
					return 0;
				}
			}
			return 1;
		}
	}
}

// Kiểm tra mảng có SNT hay không.
int KTMSNT(int n, int a[])
{
	for (int i = 0; i < n; i++)
	{
		if (KTSNT(a[i]) == 1)
		{
			return 1;
		}
	}
	return 0;
}

void ViTriSNT(int n, int a[])
{
	if (KTMSNT(n, a) == 1)
	{
		printf("\n\nVi tri SNT: ");
		for (int i = 0; i < n; i++)
		{
			if (KTSNT(a[i]) == 1)
			{
				printf("%d ", i);
			}
		}
	}
	else
	{
		printf("\n\nMang khong co SNT.");
	}
}

int main()
{
	int a[SLPT], n;

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

	ViTriSNT(n, a);

	getch();
	return 0;
}
