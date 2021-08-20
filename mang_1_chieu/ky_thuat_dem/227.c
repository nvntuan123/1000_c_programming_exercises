/* 2016 - Nguyễn Nhật Tuấn.
Code được viết lúc tôi mới học lập trình C/C++ nên có một số cách chưa được tốt, mong giúp ích được các bạn tham khảo.
*/

// Bài 227/71/SBT Thầy NTTMK: Hãy xác định số lượng các phần tử kề nhau mà cả hai số trái dấu nhau.

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

// Số lượng các phần tử kề nhau mà cả hai số trái dấu nhau.
double PhanTuKeNhauTraiDau(int n, double a[])
{
	int dem = 0;
	for (int i = 0; i < n; i++)
	{
		if (i == 0)
		{
			if ((a[i] > 0 && a[i + 1] < 0) || (a[i] < 0 && a[i + 1] > 0))
			{
				dem++;
			}
		}
		else if (i == n - 1)
		{
			if ((a[i] > 0 && a[i - 1] < 0) || (a[i] < 0 && a[i - 1] > 0))
			{
				dem++;
			}
		}
		else
		{
			if (a[i] > 0)
			{
				if ((a[i - 1] < 0) || (a[i + 1] < 0))
				{
					dem++;
				}
			}
			else
			{
				if ((a[i - 1] > 0) || (a[i + 1] > 0))
				{
					dem++;
				}
			}
		}
	}
	return dem;
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

	int demso = PhanTuKeNhauTraiDau(n ,a);
	if (demso == 0)
	{
		printf("\n\nMang khong co phan tu ke nhau ma ca hai so trai dau nhau.");
	}
	else
	{
		printf("\n\nSo luong phan tu ke nhau ma ca hai so trai dau nhau: %d", demso);
	}

	getch();
	return 0;
}
