/* 2016 - Nguyễn Nhật Tuấn.
Code được viết lúc tôi mới học lập trình C/C++ nên có một số cách chưa được tốt, mong giúp ích được các bạn tham khảo.
*/

// Bài 137/58/SBT Thầy NTTMK: Tìm "một vị trí mà giá trị tại vị trí đó là giá trị nhỏ nhất" trong mảng một chiều các số thực.

#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#define Max 100

void NhapMang(int n, float a[])
{
	for (int i = 0; i < n; i++)
	{
		printf("\nNhap vao phan tu thu %d: ", i + 1);
		scanf("%f", &a[i]);
	}
}

void XuatMang(int n, float a[])
{
	for (int i = 0; i < n; i++)
	{
		printf("%f ", a[i]);
	}
}

int ViTriNhoNhat(int n, float a[])
{
	int vtnn = 0;
	for (int i = 1; i < n; i++)
	{
		if (a[i] < a[vtnn])
		{
			vtnn = i;
		}
	}
	return vtnn;
}

int main()
{
	int n;
	float a[Max];

	do
	{
		printf("Nhap vao so luong phan tu n: ");
		scanf("%d", &n);

		if (n <= 0 || n > Max)
		{
			system("cls");
			printf("Ban nhap sai, xin kiem tra lai (n > 0 && n <= 100).\n\n");
		}
	} while (n <= 0 || n > Max);

	NhapMang(n, a);
	printf("\nMang sau khi nhap la: ");
	XuatMang(n, a);

	int vtnn = ViTriNhoNhat(n, a);
	printf("\n\nVi tri co phan tu nho nhat: %d", vtnn);

	getch();
	return 0;
}
