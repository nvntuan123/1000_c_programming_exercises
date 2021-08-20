/* 2016 - Nguyễn Nhật Tuấn.
Code được viết lúc tôi mới học lập trình C/C++ nên có một số cách chưa được tốt, mong giúp ích được các bạn tham khảo.
*/

// Bài 211/68/SBT Thầy NTTMK:Tính trung bình cộng các số nguyên tố trong mảng một chiều các số nguyên.

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
	printf("\n\n");
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
}

// Kiểm tra SNT.
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
			for (int i = 3; i <= sqrt((double)n); i += 2)
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

// Tính trung bình cộng các số nguyên tố.
double TrungBinhCongSNT(int n, int a[])
{
	int tong = 0, dem = 0;
	for (int i = 0; i < n; i++)
	{
		if (KTSNT(a[i]) == 1)
		{
			tong += a[i];
			dem++;
		}
	}
	if (dem != 0)
	{
		/*double TBC = tong / (1.0 * dem);*/
		return (double)tong / dem;
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

	double TBcong = TrungBinhCongSNT(n, a);
	if (TBcong == 0)
	{
		printf("\n\nMang khong co SNT.");
	}
	else
	{
		printf("\n\nTrung binh cong cac SNT: %lf", TBcong);
	}

	getch();
	return 0;
}
