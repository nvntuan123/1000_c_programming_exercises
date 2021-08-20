/* 2016 - Nguyễn Nhật Tuấn.
Code được viết lúc tôi mới học lập trình C/C++ nên có một số cách chưa được tốt, mong giúp ích được các bạn tham khảo.
*/

// Bài 285/78/SBT Thầy NTTMK: Hãy đảo ngược thứ tự các số dương có trong mảng.

#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#define SLPT 100

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
	for (int i = 0; i < n; i++)
	{
		printf("%.2lf ", a[i]);
	}
}

// Hoán vị.
void Swap(double *a, double *b)
{
	*a += *b;
	*b = *a - *b; // b = a.
	*a -= *b; // a = b.
}

// Đếm số lượng số chẵn có trong mảng.
int DemSoLuongSoDuong(int n, double a[])
{
	int dem = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] > 0)
		{
			dem++;
		}
	}
	return dem;
}

// Tìm số chẵn đầu tiển từ cuối mảng ->.
int TimSoDuong(int n, double a[], int vitridangxet)
{
	for (int i = n - 1; i > vitridangxet; i--)
	{
		if (a[i] > 0)
		{
			return i;
		}
	}
	return -1;
}

// đảo các số chẵn có trong mảng.
void DaoChan(int n, double a[])
{
	int soluongsoduong = DemSoLuongSoDuong(n, a); // Số lượng số chẵn có trong mảng.
	for (int j = 0; j < n; j++)
	{
		if (soluongsoduong > 1)
		{
			if (a[j] > 0) // Chỉ đổi chỗ những phần tử chẵn.
			{
				int timduong = TimSoDuong(n, a, j); // j là vị trí đang xét.
				if (timduong != -1)
				{
					for (int k = timduong - 1; k >= j; k--)
					{
						if (a[k] > 0)
						{
							Swap(&a[timduong], &a[k]);
							timduong = k; // Cập nhật lại vị trí có phần tử chẵn đang đổi chỗ.
						}
					}
				}
				soluongsoduong--; // đổi chỗ các số chẵn có số lần = số lượng số chẵn - 1.
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
	printf("\nMang ban dau sau khi nhap la: ");
	XuatMang(n, a);

	DaoChan(n, a);
	printf("\n\nMang sau khi dao cac phan tu duong la: ");
	XuatMang(n, a);

	getch();
	return 0;
}
