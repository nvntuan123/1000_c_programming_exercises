/* 2016 - Nguyễn Nhật Tuấn.
Code được viết lúc tôi mới học lập trình C/C++ nên có một số cách chưa được tốt, mong giúp ích được các bạn tham khảo.
*/

// Bài 251/73/SBT Thầy NTTMK: Hãy cho biết các phần tử trong mảng có bằng nhau không ?

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

// Kiểm mảng có bằng nhau hay không ?
int KiemTraMangBangNhau(int n, int a[])
{
	int check = 1; // true.
	for (int i = 0; i < n - 1; i++)
	{
		if (a[i] != a[i + 1])
		{
			check = 0; // False.
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

	int mangbangnhau = KiemTraMangBangNhau(n, a);
	if (mangbangnhau == 0)
	{
		printf("\n\nCac phan tu trong mang khong bang nhau.");
	}
	else
	{
		printf("\n\nCac phan tu trong mang bang nhau.");
	}

	getch();
	return 0;
}
