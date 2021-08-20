/* 2016 - Nguyễn Nhật Tuấn.
Code được viết lúc tôi mới học lập trình C/C++ nên có một số cách chưa được tốt, mong giúp ích được các bạn tham khảo.
*/

// Bài 171/63/SBT Thầy NTTMK: Cho mảng một chiều các số nguyên dương. Hãy viết hàm tìm ước chung lớn nhất của tất cả các phần tử trong mảng.

#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <Windows.h>
#define Max 100

void NhapMang(int n, int a[])
{
	for (int i = 0; i < n; i++)
	{
		do
		{
			printf("\nNhap vao phan tu thu %d: ", i + 1);
			scanf("%d", &a[i]);

			if (a[i] <= 0)
			{
				printf("\nNhap sai, nhap lai (a[%d] > 0).\n", i);
			}
		} while (a[i] <= 0);
	}
}

void XuatMang(int n, int a[])
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
}

int TimUSCLN(int a, int b)
{
	if (a == b)
	{
		return a;
	}
	else if (a > b)
	{
		if (a % b == 0)
		{
			return b;
		}
		else
		{
			int USCLN = 0;
			for (int i = 1; i < b; i++)
			{
				if (a % i == 0 && b % i == 0)
				{
					USCLN = i;
				}
			}
			return USCLN;
		}
	}
	else
	{
		if (b % a == 0)
		{
			return a;
		}
		else
		{
			int USCLN = 0;
			for (int i = 1; i < a; i++)
			{
				if (a % i == 0 && b % i == 0)
				{
					USCLN = i;
				}
			}
			return USCLN;
		}
	}
}

int USCLN(int n, int a[])
{
	int temp = a[0];
	for (int i = 1; i < n; i++)
	{
		temp  = TimUSCLN(temp, a[i]);
	}
	return temp;
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

	printf("\n\nUoc so chung lon nhat cua mang a la: %d", USCLN(n, a));

	getch();
	return 0;
}
