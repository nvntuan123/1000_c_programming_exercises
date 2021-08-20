// Bài 284/77/SBT Thầy NTTMK: Hãy đảo ngược thứ tự các số chẵn có trong mảng.

#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#define SLPT 100

// Nhập mảng.
void NhapMang(int n, int a[])
{
	for (int i = 0; i < n; i++)
	{
		printf("\nNhap vao phan tu thu %d: ", i + 1);
		scanf("%d", &a[i]);
	}
}

// Xuất mảng.
void XuatMang(int n, int a[])
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
}

// Hoán vị.
void Swap(int *a, int *b)
{
	*a += *b;
	*b = *a - *b; // b = a.
	*a -= *b; // a = b.
}

// Đếm số lượng số chẵn có trong mảng.
int DemSoLuongSoChan(int n, int a[])
{
	int dem = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] % 2 == 0)
		{
			dem++;
		}
	}
	return dem;
}

// Tìm số chẵn đầu tiển từ cuối mảng ->.
int TimSoChan(int n, int a[], int vitridangxet)
{
	for (int i = n - 1; i > vitridangxet; i--)
	{
		if (a[i] % 2 == 0)
		{
			return i;
		}
	}
	return -1;
}

// đảo các số chẵn có trong mảng.
void DaoChan(int n, int a[])
{
	int soluongsochan = DemSoLuongSoChan(n, a); // Số lượng số chẵn có trong mảng.
	for (int j = 0; j < n; j++)
	{
		if (soluongsochan > 1)
		{
			if (a[j] % 2 == 0) // Chỉ đổi chỗ những phần tử chẵn.
			{
				int timchan = TimSoChan(n, a, j); // j là vị trí đang xét.
				if (timchan != -1)
				{
					for (int k = timchan - 1; k >= j; k--)
					{
						if (a[k] % 2 == 0)
						{
							Swap(&a[timchan], &a[k]);
							timchan = k; // Cập nhật lại vị trí có phần tử chẵn đang đổi chỗ.
						}
					}
				}
				soluongsochan--; // đổi chỗ các số chẵn có số lần = số lượng số chẵn - 1.
			}
		}
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
	printf("\nMang ban dau sau khi nhap la: ");
	XuatMang(n, a);

	DaoChan(n, a);
	printf("\n\nMang sau khi dao cac phan tu chan la: ");
	XuatMang(n, a);

	getch();
	return 0;
}
