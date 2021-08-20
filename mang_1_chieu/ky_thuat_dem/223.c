/* 2016 - Nguyễn Nhật Tuấn.
Code được viết lúc tôi mới học lập trình C/C++ nên có một số cách chưa được tốt, mong giúp ích được các bạn tham khảo.
*/

// Bài 223/70/SBT Thầy NTTMK: Hãy đếm số lượng "số nguyên tố" có trong mảng một chiều các số nguyên.

#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <Windows.h>
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
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
}

// Kiễm tra SNT.
int KTSNT(int n)
{
	if (n < 2)
	{
		return 0;
	}
	else if (n == 2)
	{
		return 1;
	}
	else
	{
		if (n % 2 == 0)
		{
			return 0;
		}
		else
		{
			for (int i = 3; i <= sqrt((double)n); i++)
			{
				if (n % i == 0)
				{
					return 0;
				}
			}
			return 1;
		}
	}
}

// đếm số lượng số nguyên tố.
int DemSNT(int n, int a[])
{
	int dem = 0;
	for (int i = 0; i < n; i++)
	{
		if (KTSNT(a[i]) == 1)
		{
			dem++;
		}
	}
	return dem;
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

	int demso = DemSNT(n, a);
	if (demso == 0)
	{
		printf("\n\nMang khong co so nguyen to.");
	}
	else
	{
		printf("\n\nSo luong so nguyen to trong: %d", demso);
	}

	getch();
	return 0;
}
