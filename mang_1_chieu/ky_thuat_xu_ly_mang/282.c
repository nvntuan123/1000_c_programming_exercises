/* 2016 - Nguyễn Nhật Tuấn.
Code được viết lúc tôi mới học lập trình C/C++ nên có một số cách chưa được tốt, mong giúp ích được các bạn tham khảo.
*/

// Bài 282/77/SBT Thầy NTTMK: Hãy đưa các số chia hết cho 3 về đầu mảng.

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
	// Troll :))
	*a += *b;
	*b = *a - *b; // b = a.
	*a -= *b; // a = b.
}

// Đưa phần tử chia hết cho 3 về đầu mảng.
void Dua3VeDau(int n, int a[])
{
	// PP nổi bọt.
	for (int i = 0; i < n; i++)
	{
		for (int j = n - 1; j > i; j--)
		{
			if (a[j] % 3 == 0)
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

	Dua3VeDau(n, a);
	printf("\n\nMang sau khi dua so 3 ve dau mang la: ");
	XuatMang(n, a);

	getch();
	return 0;
}
