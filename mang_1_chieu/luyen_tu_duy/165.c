/* 2016 - Nguyễn Nhật Tuấn.
Code được viết lúc tôi mới học lập trình C/C++ nên có một số cách chưa được tốt, mong giúp ích được các bạn tham khảo.
*/

// Bài 165/62/SBT Thầy NTTMK: Hãy tìm giá trị đầu tiên trong mảng một chiều các số nguyên có chữ số đầu tiên là chữ số lẻ. Nếu mảng không tồn
// tại giá trị như vậy thì hàm sẽ trả về giá trị 0.

#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <math.h>
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

int KTSoLeDauTien(int n)
{
	int slcs = log10((double)n);

	int a = n / pow((double)10, slcs);
	if (a % 2 != 0)
	{
		return 1;
	}
	return 0;

}

int LeDauTien(int n, int a[])
{
	for (int i = 0; i < n; i++)
	{
		if (KTSoLeDauTien(a[i]) == 1)
		{
			return a[i];
		}
	}
	return 0;
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
			system("cls");
			printf("Ban nhap sai, xin kiem tra lai (n > 0 va n <= 100).\n\n");
		}
	} while (n <= 0 || n > Max);

	NhapMang(n, a);
	printf("\nMang a sau khi nhap la: ");
	XuatMang(n, a);

	if (LeDauTien(n, a) == 0)
	{
		printf("\n\nMang khong co gia tri co chu so dau tien le.");
	}
	else
	{
		printf("\n\nGia tri dau tien co chu so dau tien la so le: %d", LeDauTien(n, a));
	}

	getch();
	return 0;
}
