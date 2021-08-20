/* 2016 - Nguyễn Nhật Tuấn.
Code được viết lúc tôi mới học lập trình C/C++ nên có một số cách chưa được tốt, mong giúp ích được các bạn tham khảo.
*/

// Bài 242/72/SBT Thầy NTTMK: Hãy kiểm tra mảng số nguyên có tồn tại giá trị chẵn hay không ? Nếu không tồn tại giá trị chẵn thì trả về giá trị 0, ngược lại trả về 1.

#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <Windows.h>
#include <time.h>
#define SLPT 100

//void NhapMang(int n, int a[])
//{
//	for (int i = 0; i < n; i++)
//	{
//		printf("\nNhap vao phan tu thu %d: ", i + 1);
//		scanf("%d", &a[i]);
//	}
//}

void XuatMang(int n, int a[])
{
	printf("\n\n");
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
}

// Kiểm tra mảng có số chẵn.
int KTSC(int n, int a[])
{
	int check = 0; // Giả sử chưa có.
	for (int i = 0; i < n; i++)
	{
		if (a[i] % 2 == 0)
		{
			check = 1;
		}
	}
	return check;
}

int main()
{
	int a[SLPT], n = 10;

	/*do
	{
		printf("Nhap vao so luong phan thu n: ");
		scanf("%d", &n);

		if (n <= 0 || n > SLPT)
		{
			system("cls");
			printf("Ban nhap sai, xin kiem tra lai (n > 0 va n <= 100).\n\n");
		}
	} while (n <= 0 || n > SLPT);*/

	// reset time.
	srand(time(NULL));

	// ramdom từ -101 -> 200.
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 302 - 101;
	}

	/*NhapMang(n, a);
	printf("\n\nMang a sau khi nhap la: ");*/
	XuatMang(n, a);

	int kiemtrachan = KTSC(n, a);
	if (kiemtrachan == 1)
	{
		printf("\n\nMang ton tai gia tri chan.");
	}
	else
	{
		printf("\n\nMang khong ton tai gia tri chan.");
	}

	getch();
	return 0;
}
