/* 2016 - Nguyễn Nhật Tuấn.
Code được viết lúc tôi mới học lập trình C/C++ nên có một số cách chưa được tốt, mong giúp ích được các bạn tham khảo.
*/

// Bài 180/65/SBT Thầy NTTMK: Hãy liệt kê các giá trị trong mảng mà thỏa điều kiện nhỏ hơn trị tuyệt đối của giá trị đứng liền sau nó và lớn
// hơn giá trị đứng liền trước nó.

#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <Windows.h>
#define Max 100

// Nhập mảng.
void NhapMang(int n, double a[])
{
	for (int i = 0; i < n; i++)
	{
		printf("\nNhap vao phan tu thu %d: ", i + 1);
		scanf("%lf", &a[i]);
	}
}

// Xuất mảng.
void XuatMang(int n, double a[])
{
	printf("\n\n");
	for (int i = 0; i < n; i++)
	{
		printf("%lf ", a[i]);
	}
}

// Kiểm tra số theo yêu cầu.
int KT(int n, double a[])
{
	for (int i = 1; i <= n - 2; i++)
	{
		if (a[i] < fabs(a[i + 1]) && a[i] > a[i - 1])
		{
			return 1;
		}
	}
	return 0;
}

// Xuất số theo yêu cầu
void XuatSo(int n, double a[])
{
	if (KT(n, a) == 1)
	{
		printf("\n\nSo thoa yeu cau: ");
		for (int i = 1; i <= n - 2; i++)
		{
			// Cách 1:
			/*if (a[i] < abs(a[i + 1]) && a[i] > a[i - 1])
			{
				printf("%lf ", a[i]);
			}*/

			// Cách 2:
			if(a[i] >= fabs(a[i + 1]))
			{
				continue;
			}
			if(a[i] > a[i - 1])
			{
				printf("%lf ", a[i]);
			}
		}
	}
	else
	{
		printf("\n\nMang khong co so thoa yeu cau.");
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

	XuatSo(n, a);

	getch();
	return 0;
}
