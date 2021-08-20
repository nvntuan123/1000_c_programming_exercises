// Bài 161/62/SBT Thầy NTTMK: Cho mảng một chiều các số nguyên hãy tìm giá trị đầu tiên trong mảng nằm trong khoảng (x,y) cho trước. Nếu mảng
// không có giá trị thỏa điều kiện trên thì hàm trả về giá trị là x.

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
	for (int i = 0; i <n; i++)
	{
		printf("%d ", a[i]);
	}
}

int Xuly(int n, int a[], int x, int y)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] >= x && a[i] <= y)
		{
			return a[i];
		}
	}
	return x;
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

	int x, y;
	printf("\n\nNhap vao x = ");
	scanf("%d", &x);
	printf("\nNhap vao y = ");
	scanf("%d", &y);

	if (Xuly(n, a, x, y) != x)
	{
		printf("\nPhan tu dau tien nam trong doan [x, y] la: %d", Xuly(n, a, x, y));
	}
	else
	{
		printf("\nKhong co phan tu nam trong doan [x, y].");
	}

	getch();
	return 0;
}
