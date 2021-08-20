// Bài 268/76/SBT Thầy NTTMK: Hãy tạo mảng b từ mảng a các giá tri 0, 1 để mảng có tính "tính chẵn lẻ" (taomangchanle).

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

// Xuất mảng.
void XuatMang(int n, int a[])
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
}

// Tạo mảng b.
void TaoMang(int n, int x[], int *m, int y[])
{
	(*m) = 0;
	for (int i = 0; i < n; i++)
	{
		if (x[i] % 2 == 0)
		{
			y[(*m)++] = 0;
		}
		else
		{
			y[(*m)++] = 1;
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

	TaoMang(na, a, &nb, b);
	printf("\n\nMang b sau khi tao cac gia tri 0, 1 tu mang a: ");
	XuatMang(nb, b);

	getch();
	return 0;
}
