/* 2016 - Nguyễn Nhật Tuấn.
Code được viết lúc tôi mới học lập trình C/C++ nên có một số cách chưa được tốt, mong giúp ích được các bạn tham khảo.
*/

// Cách 2: Bài 155/61/SBT Thầy NTTMK:Hãy tìm giá trị trong mảng các số thực "xa giá trị x nhất".

#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <windows.h>
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

double TimGiaTriXaNhat(double a[], int n, double x)
{
	double Max = fabs(a[0] - x);
	int vitri = 0;
	for(int i = 1; i < n; i++)
	{
		if(fabs(a[i] - x) > Max)
		{
			Max = fabs(a[i] - x);
			vitri = i;
		}
	}
	return a[vitri];
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
	printf("\nMangg sau khi nhap la: ");
	XuatMang(n, a);

	double x;
	printf("\n\nNhap vao x = ");
	scanf("%lf", &x);
	printf("\n\nGia tri xa x nhat: %lf", TimGiaTriXaNhat(a, n, x));

	getch();
	return 0;
}
