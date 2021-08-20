// Bài 281/77/SBT Thầy NTTMK: Hãy đưa các số chẵn trong mảng về đầu mảng, số lẻ về cuối mảng và các phần tử 0 nằm ở giữa.

#include <stdio.h>
#include <conio.h>
#include <math.h>
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
	// Troll ^_^.
	*a = *a - *b;
	*b = *a + *b; // b = a.
	*a = *b - *a; // a = b.
}

// Đưa các số chẵn về đầu.
void DuaSoChanVeDau(int n, int a[])
{
	for (int i = 0; i < n; i++)
	{
		for (int j = n - 1; j > i; j--)
		{
			if (a[j] % 2 == 0 && a[j] != 0)
			{
				Swap(&a[j], &a[j - 1]);
			}
		}
	}
}

// Tìm vị trí số lẻ đầu tiên sau khi chuyển tất cả các số chẵn về đầu mảng.
int TimViTriLeDau(int n, int a[])
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] % 2 != 0)
		{
			return i;
		}
	}
	return -1;
}

// Đưa số vào giữa.
void DuaSo0VaoGiua(int n, int a[])
{
	int vitriledau = TimViTriLeDau(n, a); // Tìm vị trí đầu tiên là số lẻ sau khi chuyển các số chẵn về đầu mảng.
	printf("\n\n%d", vitriledau);
	for (int i = 0; i < n; i++)
	{
		if (a[i] == 0)
		{
			for (int j = i; j > vitriledau; j--) // j = i chạy từ vị trí có số 0 đầu tiên phát hiện được.
			{
				Swap(&a[j], &a[j - 1]);
				if (j == vitriledau + 1)
				{
					vitriledau++; // Loại bỏ vị trị vừa đưa số vào giữa.
				}
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

	DuaSoChanVeDau(n, a);
	printf("\n\nMang sau khi sap xep theo yeu cau la: ");
	XuatMang(n, a);

	DuaSo0VaoGiua(n, a);
	printf("\n\nMang sau khi sap xep theo yeu cau la: ");
	XuatMang(n, a);

	getch();
	return 0;
}
