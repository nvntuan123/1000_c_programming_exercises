/* 2016 - Nguyễn Nhật Tuấn.
Code được viết lúc tôi mới học lập trình C/C++ nên có một số cách chưa được tốt, mong giúp ích được các bạn tham khảo.
*/

// Bài 186/65/SBT Thầy NTTMK: Hãy liệt kê các vị trí trong mảng một chiều các số thực mà giá trị tại các vị trí đó bằng giá trị âm đầu tiên trong mảng.

#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <Windows.h>
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

// Kiểm tra số âm
double KTSA(int n, double a[])
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] < 0)
		{
			return a[i];
		}
	}
	return 0;
}

// Liệt kê số âm.
void LKSA(int n, double a[])
{
	if (KTSA(n, a) == 0)
	{
		printf("\n\nMang khong co so am.");
	}
	else
	{
		printf("\n\nVi tri so am = so am dau tien: ");
		int vitri = 0;
		for (int i = 0; i < n; i++)
		{
			if (KTSA(n, a) == a[i])
			{
				vitri = i;
				break;
			}
		}
		
		for (int j = vitri; j < n; j++)
		{
			if (KTSA(n, a) == a[j])
			{
				printf("%d ", j);
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
	printf("\nMang a sau khi nhap la: ");
	XuatMang(n, a);

	LKSA(n, a);

	getch();
	return 0;
}
