/* 2016 - Nguyễn Nhật Tuấn.
Code được viết lúc tôi mới học lập trình C/C++ nên có một số cách chưa được tốt, mong giúp ích được các bạn tham khảo.
*/

// Bài 277/77/SBT Thầy NTTMK: Hãy xóa tất cả các "số nguyên tố" có trong mảng số nguyên.

#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <Windows.h>
#define SLPT 100

int i;

// Nhập mảng.
void NhapMang(int n, int a[])
{
	for (i = 0; i < n; i++)
	{
		printf("\nNhap vao phan tu thu %d: ", i + 1);
		scanf("%d", &a[i]);
	}
}

// Xuất Mảng
void XuatMang(int n, int a[])
{
	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
}

// Hàm xóa phần tử.
void XoaPhanTu(int *n, int a[], int vitricanxoa)
{
	// Cách 1:
	/*for (int i = vitricanxoa; i < n - 1; i++)
	{
		a[i] = a[i + 1];
	}*/

	// Cách 2:
	for (int i = vitricanxoa + 1; i < (*n); i++)
	{
		a[i - 1] = a[i];
	}
	(*n)--;
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

// Xóa các SNT có trong mảng.
void XoaSNT(int *n, int a[])
{
	for (int i = 0; i < (*n); i++)
	{
		if (KTSNT(a[i]))
		{
			XoaPhanTu(&n, a, i);
			i--; // Cập nhật lại i.
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
	printf("\nMang sau khi nhap la: ");
	XuatMang(n, a);

	XoaSNT(&n, a);
	printf("\n\nMang sau khi xoa SNT la: ");
	XuatMang(n, a);

	getch();
	return 0;
}
