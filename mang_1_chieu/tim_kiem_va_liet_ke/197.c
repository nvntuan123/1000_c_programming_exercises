// Bài 197/67/SBT Thầy NTTMK: Hãy liệt kê các giá trị trong mảng một chiều các số nguyên có chữ số đầu tiên là chữ số lẻ.

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

// Kiểm tra chữ số đầu tiên lẻ.
int KTCSL(int n)
{
	int soluongchuso = log10((double)n); // nếu + 1 mới ra số lượng chữ số.
	int chusole = n / pow(10.0, soluongchuso);
	if (chusole % 2 != 0)
	{
		return 1;
	}
	return 0;
}

// Kiểm tra mảng có số chữ số đầu tiên lẻ hay không.
int KTCSDauTienLe(int n, int a[])
{
	for (int i = 0; i < n; i++)
	{
		if (KTCSL(a[i]) == 1)
		{
			return 1;
		}
	}
	return -1;
}

// Liệt kê số chữ số đầu tiên lẻ.
void LKCSDauTienLe(int n, int a[])
{
	if (KTCSDauTienLe(n, a) == 1)
	{
		printf("\n\nSo chu so dau tien le: ");
		for (int i = 0; i < n; i++)
		{
			if (KTCSL(a[i]) == 1)
			{
				printf("%d ", a[i]);
			}
		}
	}
	else
	{
		printf("\n\nMang khong co so chu so dau tien le.");
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

	LKCSDauTienLe(n, a);

	getch();
	return 0;
}
