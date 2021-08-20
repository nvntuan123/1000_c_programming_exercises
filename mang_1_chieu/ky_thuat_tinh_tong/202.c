// Bài 202/67/SBT Thầy NTTMK: Tính tổng các giá trị có chữ số đầu tiên là chữ số lẻ trong mảng một chiều các số nguyên.

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

// Tính tổng các giá trị có chữ số đầu tiên là chữ số lẻ.
int TongChuSoLe(int n, int a[])
{
	int tong = 0;
	for (int i = 0; i < n; i++)
	{
		int soluongchuso = log10((double)a[i]); // + 1 nũa mới là đúng nhưng mình k + vì xuống dưới khỏi phải - đi.
		int chusole = a[i] / pow(10.0, soluongchuso);
		if (chusole % 2 != 0)
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

	int tongchusole = TongChuSoLe(n, a);
	if (tongchusole == 0)
	{
		printf("\n\nMang khong co so chu so dau tien le.");
	}
	else
	{
		printf("\n\nTong so co chu so dau tien le: %d", tongchusole);
	}

	getch();
	return 0;
}
