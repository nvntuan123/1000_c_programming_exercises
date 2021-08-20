// Bài 166/63/SBT Thầy NTTMK: Cho mảng một chiều các số nguyên. Hãy viết hàm tìm giá trị đầu tiên trong mảng có dạng 2^k. Nếu mảng không tồn
// tại giá trị có dạng 2^k thì hàm sẽ trả về giá trị 0.

#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <math.h>
#define Max 100

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
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
}

int KiemTra(int n)
{
	// Cách 1:
	/*if (log10((double)n) / log10(2.0) == int (log10((double)n) / log10(2.0)))
	{
		return 1;
	}
	return 0;*/

	// Cách 2:
	/*while (n != 1)
	{
		if (n % 2 != 0)
		{
			return 0;
		}
		n /= 2;
	}
	return 1;*/

	// Cách 3:
	int t = 0, s = 0;
	while (t < n)
	{
		t = pow(2.0, s++);
		if (t == n)
		{
			return 1;
		}
	}
	return 0;
}

int SoDauTien(int n, int a[])
{
	for (int i = 0; i < n; i++)
	{
		if (KiemTra(a[i]) == 1)
		{
			return a[i];
		}
	}
	return 0;
}

int main()
{
	int a[Max], n;

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

	if (SoDauTien(n, a) != 0)
	{
		printf("\n\nGia tri dau tien tong mang a co dang 2^k la: %d", SoDauTien(n, a));
	}
	else
	{
		printf("\n\nKhong co gia tri 2^k trong mang a.");
	}

	getch();
	return 0;
}
