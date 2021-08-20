// Bài 189/66/SBT Thầy NTTMK: Hãy liệt kê các giá trị trong mảng một chiều các số nguyên có chữ số đầu tiên là chữ số lẻ.

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

// Kiểm tra chữ số lẻ.
int KTSL(int n)
{
	int soluongchuso = log10((double)n);
	int chusole = n / pow(10.0, soluongchuso);
	if (chusole % 2 == 0)
	{
		return 0;
	}
	else
	{
		return 1;
	}

}

//Kiểm tra mảng có số chữ số là số lẻ không.
int KTCSL(int n, int a[])
{
	for (int i = 0; i < n; i++)
	{
		if (KTSL(a[i]) == 1)
		{
			return 1;
		}
	}
	return 0;
}

// Liệt kê chữ số lẻ đầu tiên.
void GiaTriChuSoLeDauTien(int n, int a[])
{
	if (KTCSL(n, a) == 1)
	{
		printf("\n\nGia tri co chu so dau tien la chu so le: ");
		for (int i = 0; i < n; i++)
		{
			if (KTSL(a[i]) == 1)
			{
				printf("%d ", a[i]);
			}
		}
	}
	else
	{
		printf("\n\nMang khong co so thoa yeu cau.");
	}
}

int main()
{
	int a[SLPT], n;

	do
	{
		printf ("Nhap vao so luong phan tu n: ");
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

	GiaTriChuSoLeDauTien(n, a);

	getch();
	return 0;
}
