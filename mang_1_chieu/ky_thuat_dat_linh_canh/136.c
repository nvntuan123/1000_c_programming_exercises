// Bài 136/58/SBT Thầy NTTMK:Tìm "số chẵn cuối cùng" trong mảng một chiều các số nguyên.Nếu mảng không có giá trị chẵn thì trả về giá trị -1.

#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#define Max 100

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

int SoChanCuoiCung(int n, int a[])
{
	for (int i = n - 1; i >= 0; i--)
	{
		if (a[i] % 2 == 0)
		{
			return a[i];
		}
	}
	return -1;
}

int main()
{
	int a[Max], n;

	do
	{
		printf("Nhap vao so luong phan tu n: ");
		scanf("%d", &n);

		if (n <= 0 || n > Max)
		{
			printf("Ban nhap sai, xin kiem tra lai (n > 0 && n <= 100).\n\n");
		}
	} while (n <= 0 || n > Max);

	NhapMang(n, a);
	printf("\nMang sau khi nhap la : ");
	XuatMang(n, a);

	int sochan = SoChanCuoiCung(n, a);
	if (sochan != -1)
	{
		printf("\n\nPhan tu chan cuoi cung cua mang la: %d", sochan);
	}
	else
	{
		printf("\n\nKhong co phan tu chan trong mang.");
	}

	getch();
	return 0;
}
