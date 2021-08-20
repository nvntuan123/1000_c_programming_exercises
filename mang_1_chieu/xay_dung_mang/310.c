// Bài 310/81/SBT Thầy NTTMK: Cho mảng một chiều các số nguyên a. Hãy tạo mảng b từ mảng a, sao cho mảng b chỉ chứa các số nguyên tố trong mảng a.

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

// Kiểm tra SNT.
int KiemTraSNT(int n)
{
	int check = 1; // Giả sử có SNT.
	if (n < 2)
	{
		check = 0; // Không có.
	}
	else if (n == 2)
	{
		check = 1; // Có.
	}
	else
	{
		if (n % 2 == 0)
		{
			check = 0;
		}
		else
		{
			for (int i = 3; i <= sqrt((double)n); i += 2)
			{
				if (n % i == 0)
				{
					check = 0;
				}
			}
		}
	}
	return check;
}

// Kiểm tra mảng a có SNT hay không.
int KiemTraMangCoSNT(int n, int a[])
{
	for (int i = 0; i < n; i++)
	{
		if (KiemTraSNT(a[i]) == 1)
		{
			return 1;
		}
	}
	return 0;
}

// Tạo mảng b chứa các SNT của mảng a.
void TaoMangSNT(int na, int a[], int *nb, int b[])
{
	(*nb) = 0;
	for (int i = 0; i < na; i++)
	{
		if (KiemTraSNT(a[i]) == 1)
		{
			b[(*nb)++] = a[i];
		}
	}
}

int main()
{
	int a[SLPT], b[SLPT], na, nb;

	do
	{
		printf("Nhap vao so luong phan tu n: ");
		scanf("%d", &na);

		if (na <= 0 || na > SLPT)
		{
			system("cls");
			printf("Ban nhap sai, xin kiem tra lai (n > 0 va n <= 100).\n\n");
		}
	} while (na <= 0 || na > SLPT);

	NhapMang(na, a);
	printf("\nMang a sau khi nhap la: ");
	XuatMang(na, a);

	if (KiemTraMangCoSNT(na, a) == 1)
	{
		TaoMangSNT(na, a, nb, b);
		printf("\n\nMang b sau khi tao chua cac SNT trong mang a la: ");
		XuatMang(nb, b);
	}
	else
	{
		printf("\n\nMang a khong co SNT.");
	}

	getch();
	return 0;
}
