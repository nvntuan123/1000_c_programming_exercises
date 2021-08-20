// Bài 248/73/SBT Thầy NTTMK: Hãy kiểm tra mảng có giảm dần hay không ?

#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <math.h>
#include <time.h>
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

// Kiểm mảng có giảm dần hay không ?
int KiemTraMangGiamDan(int n, int a[])
{
	int check = 1;
	for (int i = 0; i < n - 1; i++)
	{
		if (a[i] < a[i + 1])
		{
			check = 0;
		}
	}
	return check;
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

	int manggiamdan = KiemTraMangGiamDan(n, a);
	if (manggiamdan == 0)
	{
		printf("\n\nMang khong giam dan.");
	}
	else
	{
		printf("\n\nMang giam dan.");
	}

	getch();
	return 0;
}
