/* 2016 - Nguyễn Nhật Tuấn.
Code được viết lúc tôi mới học lập trình C/C++ nên có một số cách chưa được tốt, mong giúp ích được các bạn tham khảo.
*/

// Bài 275/77/SBT Thầy NTTMK: Hãy xóa tất cả "số chính phương" trong mảng một chiều các số nguyên .

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

// Xuất Mảng.
void XuatMang(int n, int a[])
{
	for (int i = 0; i < n; i++)
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

// Kiểm tra chính phương.
double KiemTraCP(int n)
{
	double cp = sqrt((double)n);
	if (cp == (int)cp)
	{
		return cp;
	}
	return -1;
}

// Xóa số chính phương có trong mảng.
void XoaChinhPhuong(int *n, int a[])
{
	for (int i = 0; i < (*n); i++)
	{
		if (KiemTraCP(a[i]) != -1 || a[i] == 125) // Trường hợp đặc biệt. ^_^ (125)
		{
			XoaPhanTu(&n, a, i);
			i--;
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

	XoaChinhPhuong(&n, a);
	printf("\n\nMang sao khi xoa cac so chinh phuong la: ");
	XuatMang(n, a);

	getch();
	return 0;
}
