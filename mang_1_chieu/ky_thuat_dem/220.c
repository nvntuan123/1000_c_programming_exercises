// Bài 220/69/SBT Thầy NTTMK:Hãy đếm số lượng giá trị có chữ số tận cùng bằng 5 trong mảng các số nguyên.

#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <windows.h>
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

// đếm số lượng giá trị có chữ số tận cùng bằng 5.
int DTanCung(int n, int a[])
{
	int dem = 0;
	for (int i = 0; i < n; i++)
	{
		int tancung = a[i] % 10;
		if (tancung == 5)
		{
			dem++;
		}
	}
	return dem;
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

	int demso = DTanCung(n, a);
	if (demso == 0)
	{
		printf("\n\nMang khong co chu so tan cung bang 5.");
	}
	else
	{
		printf("\n\nSo luong gia tri co chu so tan cung bang 5: %d", demso);
	}

	getch();
	return 0;
}
