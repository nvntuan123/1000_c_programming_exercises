// Bài 221/69/SBT Thầy NTTMK: Hãy cho biết sự tương quan giữa số lượng số chẵn và số lượng số lẻ trong mảng các số nguyên.

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

// Sự tương quan giữa số lượng số chẵn và số lượng số lẻ trong mảng.
int TuongQuanChanLe(int n, int a[])
{
	int demchan = 0, demle = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] % 2 == 0)
		{
			demchan++;
		}
		else
		{
			demle++;
		}
	}
	if (demchan == demle)
	{
		return 0;
	}
	else if (demchan > demle)
	{
		return -1;
	}
	return 1;
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

	int demso = TuongQuanChanLe(n, a);
	if (demso == -1)
	{
		printf("\n\nSo chan nhieu hon so le.");
	}
	else if (demso == 0)
	{
		printf("\n\nSo chan bang so le.");
	}
	else
	{
		printf("\n\nSo chan it hon so le.");
	}

	getch();
	return 0;
}
