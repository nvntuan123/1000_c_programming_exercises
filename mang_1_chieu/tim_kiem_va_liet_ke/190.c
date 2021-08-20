// Bài 190/66/SBT Thầy NTTMK: Hãy liệt kê các giá trị có toàn chữ số lẻ trong mảng một chiều các số nguyên.

#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <Windows.h>
#define SLPT 100

void NhapMang(int n, int a[])
{
	for (int i = 0; i < n; i++)
	{
		printf("\nNhap vao phan tu thu %d: ", i + 1);
		scanf("%d", &a[i]);
	}
}

void XuatMang(int n, int a[])
{
	printf("\n\n");
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
}

// Kiểm số có toàn chữ số lẻ (KTSTCSL).
int KTSTCSL(int n)
{
	while (n != 0)
	{
		int a = n % 10;
		if (a % 2 == 0)
		{
			return 0;
		}
		n /= 10;	
	}
	return 1;
}

// Kiểm tra mảng có số toàn chữ số lẻ.
int KTMCoSoChuSoLe(int n, int a[])
{
	for (int i = 0; i < n; i++)
	{
		if (KTSTCSL(a[i]) == 1)
		{
			return 1;
		}
	}
	return 0;
}

// Liệt kê số có toàn chữ số lẻ.
void LietKeSoToanChuSole(int n, int a[])
{
	if (KTMCoSoChuSoLe(n, a) == 1)
	{
		printf("\n\nGia tri toan chu so le: ");
		for (int i = 0; i < n; i++)
		{
			if (KTSTCSL(a[i]) == 1)
			{
				printf("%d ", a[i]);
			}
		}
	}
	else
	{
		printf("\n\nMang khong co gia tri toan chu so le.");
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
	printf("\nMang a sau khi nhap la: ");
	XuatMang(n, a);

	LietKeSoToanChuSole(n, a);

	getch();
	return 0;
}
