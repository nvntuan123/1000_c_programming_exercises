/* 2016 - Nguyễn Nhật Tuấn.
Code được viết lúc tôi mới học lập trình C/C++ nên có một số cách chưa được tốt, mong giúp ích được các bạn tham khảo.
*/

// Bài 192/66/SBT Thầy NTTMK: Hãy liệt kê các giá trị trong mảng một chiều các số nguyên có chữ số đầu tiên là chữ số chẵn.

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

// Kiểm tra số chữ số đầu tiên là số chẵn.
int KTCSChan(int n)
{
	int soluongchuso = log10((double)n);
	int chusodau = n / pow((double)10, soluongchuso);
	if (chusodau % 2 == 0)
	{
		return 1;
	}
	return 0;
}

// Kiểm tra giá trị có chữ số đầu tiên là số chẵn.
int KTGT(int n, int a[])
{
	for (int i = 0; i < n; i++)
	{
		if (KTCSChan(a[i]) == 1)
		{
			return 1;
		}
	}
	return -1;
}

// Liệt kê giá trị có chữ số đầu tiên là số chẵn.
void LKGT(int n, int a[])
{
	if (KTGT(n, a) == 1)
	{
		printf ("\n\nGia tri co chu so dau tien la chan: ");
		for (int i = 0; i < n; i++)
		{
			if (KTCSChan(a[i]) == 1)
			{
				printf("%d ", a[i]);
			}
		}
	}
	else
	{
		printf ("\n\nMang khong co gia tri co chu so dau tien la chan.");
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

	LKGT(n, a);

	getch();
	return 0;
}
