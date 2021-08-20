/* 2016 - Nguyễn Nhật Tuấn.
Code được viết lúc tôi mới học lập trình C/C++ nên có một số cách chưa được tốt, mong giúp ích được các bạn tham khảo.
*/

// Bài 252/73/SBT Thầy NTTMK: Người ta định nghĩa một mảng được gọi là "dạng sóng" khi phần tử có trị số i lớn hơn hoặc nhỏ hơn hai phần tử xung quanh nó. Hãy viết hàm kiểm tra mảng có dạng sóng hay không ?

#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <Windows.h>
#define SLPT 100

void NhapMang(int n, double a[])
{
	for (int i = 0; i < n; i++)
	{
		printf("\nNhap vao phan tu thu %d: ", i + 1);
		scanf("%lf", &a[i]);
	}
}

void XuatMang(int n, double a[])
{
	for (int i = 0; i < n; i++)
	{
		printf("%lf ", a[i]);
	}
}

// Kiểm tra mảng dạng sóng.
int KiemTraMangDangSong(int n, double a[])
{
	int check = 1; // Giả sử là dạng sóng.
	for (int i = 1; i < n - 1; i++)
	{
		if (a[i] == a[i - 1] || a[i] == a[i + 1])
		{
			check = 0; // False.
			break;
		}
		if (a[i] > a[i - 1] && a[i] < a[i + 1])
		{
			check = 0; // False.
			break;
		}
		if (a[i] < a[i - 1] && a[i] > a[i + 1])
		{
			check = 0; // False.
			break;
		}
	}
	return check;
}

int main()
{
	int n;
	double a[SLPT];

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

	int kiemtra = KiemTraMangDangSong(n, a);
	if (kiemtra == 0)
	{
		printf("\n\nMang khong phai dang song.");
	}
	else
	{
		printf("\n\nMang dang song.");
	}

	getch();
	return 0;
}
