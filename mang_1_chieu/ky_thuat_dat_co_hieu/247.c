/* 2016 - Nguyễn Nhật Tuấn.
Code được viết lúc tôi mới học lập trình C/C++ nên có một số cách chưa được tốt, mong giúp ích được các bạn tham khảo.
*/

// Bài 247/73/SBT Thầy NTTMK: Ta định nghĩa một mảng có tính chẵn lẻ, khi tổng của hai phần tử liên tiếp trong mảng luôn luôn là số lẻ. Hãy viết hàm kiểm tra mảng a có tính chẵn lẻ hay không ?

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

// Kiểm mảng có tính chất chẵn lẻ không.
int KiemTraMangChanLe(int n, int a[])
{
	int check = 1;
	for (int i = 0; i < n - 1; i++)
	{
		int tonghaigiatrilienke = a[i] + a[i + 1];
		if (tonghaigiatrilienke % 2 == 0)
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

	int mangchanle = KiemTraMangChanLe(n, a);
	if (mangchanle == 0)
	{
		printf("\n\nMang khong co tinh chat chan le.");
	}
	else
	{
		printf("\n\nMang co tinh chat chan le.");
	}

	getch();
	return 0;
}
