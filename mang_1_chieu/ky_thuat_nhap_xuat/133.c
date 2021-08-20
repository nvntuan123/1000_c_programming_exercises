/* 26/02/2016 3:31 - Nguyễn Nhật Tuấn.
Code được viết lúc tôi mới học lập trình C/C++ nên có một số cách chưa được tốt, mong giúp ích được các bạn tham khảo.
*/

// Bài 133/57/SBT Thầy NTTMK:Viết hàm liệt kê các vị trí mà giá trị tại đó là giá trị âm trong mảng một chiều các số thực. 

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

void ViTriSoAm(int n, float a[])
{
	for(int i = 0; i < n; i++)
	{
		if (a[i] < 0)
		{
			printf("%d ", i);
		}
	}
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

	printf("\n\nCac vi tri tai do co gia tri am la: ");
	ViTriSoAm(n, a);
}
