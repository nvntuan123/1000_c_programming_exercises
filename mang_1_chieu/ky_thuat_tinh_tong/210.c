// Bài 210/68/SBT Thầy NTTMK: Tính tổng các giá trị có chữ số đầu tiên là chữ số chẵn trong mảng các số nguyên.

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
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
}

// Kiểm tra chữ số đầu tiên chắn.
int ChuSoChan(int n)
{
	int soluongchuso = log10((double)n); // ở đây k + 1 vì xuống dưới khỏi phải -.
	int chusodau = n / pow(10.0, soluongchuso);
	if (chusodau % 2 == 0)
	{
		return 1;
	}
	return 0;
}

// Tính tổng các giá trị có chữ số đầu tiên là chữ số chẵn.
int TongChuSoDauChan(int n, int a[])
{
	int tong = 0;
	for (int i = 0; i < n; i++)
	{
		if (ChuSoChan(a[i]) == 1)
		{
			tong += a[i];
		}
	}
	return tong;
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

	int tong = TongChuSoDauChan(n, a);
	if (tong == 0)
	{
		printf("\n\nMang khong co gia tri co chu so dau tien chan.");
	}
	else
	{
		printf("\n\nTong gia tri co chu so dau tien chan: %d", tong);
	}

	getch();
	return 0;
}
