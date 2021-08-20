/* 2016 - Nguyễn Nhật Tuấn.
Code được viết lúc tôi mới học lập trình C/C++ nên có một số cách chưa được tốt, mong giúp ích được các bạn tham khảo.
*/

// Bài 288/78/SBT Thầy NTTMK: Hãy xuất các phần tử trong mảng theo yêu cầu: Các phần tử chẵn có màu vàng, các phần tử lẻ có màu trắng.

// 14 vàng 7 trắng.

#include <stdio.h>
#include <conio.h>
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

// Hàm tô màu.
void textcolor(int x)
{
	HANDLE mau;
	mau=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau,x);
}

// Chẵn màu vàng, lẻ màu trắng.
void InMau(int n, int a[])
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] % 2 == 0)
		{
			textcolor(14);
			printf("%d ", a[i]);
		}
		else
		{
			textcolor(7);
			printf("%d ", a[i]);
		}
	}
}

int main()
{
	int a[SLPT], n;

	do
	{
		printf("Nhap vao so luong phan tu n[1, %d]: ", SLPT);
		scanf("%d", &n);

		if (n <= 0 || n > SLPT)
		{
			system("cls");
			printf("Ban nhap sai, nhap lai.");
		}
	} while (n <= 0 || n > SLPT);

	NhapMang(n, a);
	printf("\nMang ban dau sau khi nhap la: ");
	XuatMang(n, a);

	printf("\n\nMang sau khi to mau: ");
	InMau(n, a);

	getch();
	return 0;
}
