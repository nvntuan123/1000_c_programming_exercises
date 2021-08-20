/* 2016 - Nguyễn Nhật Tuấn.
Code được viết lúc tôi mới học lập trình C/C++ nên có một số cách chưa được tốt, mong giúp ích được các bạn tham khảo.
*/

// Bài 254/74/SBT Thầy NTTMK: Hãy đếm số lượng giá trị trong mảng thỏa tính chất :"lớn hơn tất cả các giá trị đứng đằng trước nó".

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

// Đếm số lượng giá trị trong mảng thỏa tính chất :"lớn hơn tất cả các giá trị đứng đằng trước nó".
int DemGiaTri(int n, double a[])
{
	int dem = 0;
	for (int i = 1; i < n; i++)
	{
		int check = 1;
		for (int j = i - 1; j >= 0; j--)
		{
			if (a[i] < a[j])
			{
				check = 0;
			}
		}
		if (check == 1)
		{
			dem++;
		}
	}
	return dem;
}

int main()
{
	int n;
	double a[SLPT];

	do
	{
		printf("Nhap vao so luong phan tu na: ");
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

	int dem = DemGiaTri(n, a);
	if (dem == 0)
	{
		printf("\n\nMang khong co gia tri lon hon moi gia tri dung truoc no.");
	}
	else
	{
		printf("\n\nMang co gia tri lon hon moi gia tri dung truoc no.");
	}

	getch();
	return 0;
}
