// Bài 245/73/SBT Thầy NTTMK: Hãy cho biết mảng các số nguyên có toàn số chẵn hay không ? Nếu có tồn tại giá trị lẻ trả về giá trị 0, ngược lại trả về 1.

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

// Kiểm tra mảng có toàn giá trị chẵn.
int KTMangToanChan(int n, int a[])
{
	int check = 1; // Giả sử mảng toàn chẵn.
	for (int i = 0; i < n; i++)
	{
		if (a[i] % 2 != 0)
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

	int kiemtrachan = KTMangToanChan(n, a);
	if (kiemtrachan == 0)
	{
		printf("\n\nMang ton tai gia tri le.");
	}
	else
	{
		printf("\n\nMang khong ton tai gia tri le.");
	}

	getch();
	return 0;
}
