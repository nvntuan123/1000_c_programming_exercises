// Bài 243/72/SBT Thầy NTTMK: Hãy kiểm tra mảng số nguyên có tồn tại số nguyên tố hay không ? Nếu có trả về 1,nếu không trả về 0.

#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <Windows.h>
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
			return 1;
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

// Kiểm tra SNT có trong mảng.
int KiemTraMangCoSNT(int n, int a[])
{
	int check = 0; // Giả sử chưa có.
	for (int i = 0; i < n; i++)
	{
		if (KTSNT(a[i]) == 1)
		{
			check = 1;
		}
	}
	return check;
}

int main()
{
	int a[SLPT], n = 10;

	/*do
	{
		printf("Nhap vao so luong phan tu n: ");
		scanf("%d", &n);

		if (n <= 0 || n > SLPT)
		{
			system("cls");
			printf("Ban nhap sai, xin kiem tra lai (n > 0 va n <= 100).\n\n");
		}
	} while (n <= 0 || n > SLPT);*/

	// reset time.
	srand(time(NULL));

	// ramdom từ 0 -> 100.
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 100;
	}

	/*NhapMang(n, a);
	printf("\nMang a sau khi nhap la: ");*/
	XuatMang(n, a);

	int kiemtraSNT = KiemTraMangCoSNT(n, a);
	if (kiemtraSNT == 1)
	{
		printf("\n\nMang co ton tai SNT.");
	}
	else
	{
		printf("\n\nMang khong ton tai SNT.");
	}

	getch();
	return 0;
}
