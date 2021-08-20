/* 2016 - Nguyễn Nhật Tuấn.
Code được viết lúc tôi mới học lập trình C/C++ nên có một số cách chưa được tốt, mong giúp ích được các bạn tham khảo.
*/

// Bài 289/78/SBT Thầy NTTMK: Hãy xuất mảng theo yêu cầu: Các phần tử chẵn nằm trên một hàng, các phần tử lẻ nằm ở hàng tiếp theo.

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
void Swap(int *x, int *y)
{
	*x += *y;
	*y = *x - *y; // y = x.
	*x -= *y; // x = y.
}

// Sắp xếp theo yêu cầu đề bài.
void SapXep(int n, int a[])
{
	for (int i = 0; i < n; i++)
	{
		for (int j = n - 1; j > i; j--)
		{
			if (a[j] % 2 == 0)
			{
				Swap(&a[j], &a[j - 1]);
			}
		}
	}
}

int main()
{
	int a[SLPT], n;

	do
	{
		printf("Nhap vao so luong phan tu n[1, %d]: ", SLPT);
		scanf("%d", &n);

		if (n <= 0 || n > SLPT)
		{
			system("cls");
			printf("Ban nhap sai, nhap lai.");
		}
	} while (n <= 0 || n > SLPT);

	NhapMang(n, a);
	printf("\nMang ban dau sau khi nhap la: ");
	XuatMang(n, a);

	SapXep(n, a);
	printf("\n\nMang sau khi sap xep chan dung 1 hang va le cung vay: ");
	XuatMang(n, a);

	getch();
	return 0;
}
