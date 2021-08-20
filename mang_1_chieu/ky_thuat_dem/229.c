/* 2016 - Nguyễn Nhật Tuấn.
Code được viết lúc tôi mới học lập trình C/C++ nên có một số cách chưa được tốt, mong giúp ích được các bạn tham khảo.
*/

// Bài 229/70/SBT Thầy NTTMK: Hãy đếm số lượng các giá trị phân biệt có trong mảng.

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

// đếm số lượng các giá trị phân biệt có trong mảng.
int DemGiaTriPhanBiet(int n, double a[])
{
	int dempb = 1;
	for (int i = 1; i < n; i++)
	{
		int laplai = 0;
		for (int j = i - 1; j >= 0; j--)
		{
			if (a[i] == a[j])
			{
				laplai = 1;
				break;
			}
		}
		if (laplai == 1)
		{
			continue;
		}
		dempb++;
	}
	return dempb;
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

	int demso = DemGiaTriPhanBiet(n, a);
	if (demso == 1)
	{
		printf("\n\nMang khong co gia tri phan biet.");
	}
	else
	{
		printf("\n\nSo luong gia tri phan biet la: %d", demso);
	}

	getch();
	return 0;
}
