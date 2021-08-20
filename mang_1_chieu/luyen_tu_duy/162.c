// Bài 162/62/SBT: Cho mảng một chiều các số thực. Hãy viết hàm tìm một vị trí trong mảng thỏa hai điều kiện: Có hai giá trị lân cận và giá trị
// tại vị trí đó bằng tích hai giá trị lân cận. Nếu như mảng không tồn tại giá trị như vậy thì hàm trả về giá trị -1.

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
	printf("\n\n");
	for (int i = 0; i < n; i++)
	{
		printf("%lf ", a[i]);
	}
}

// Xử lý.
int TimViTriMang(int n, double a[])
{
	for (int i = 1; i < n - 1; i++)
	{
		if (a[i] == (a[i - 1] * a[i + 1]))
		{
			return i;
		}
	}
	return -1;
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

	int check = TimViTriMang(n, a);
	if (check == -1)
	{
		printf("\n\nMang khong co vi tri thoa yeu cau de bai.");
	}
	else
	{
		printf("\n\nVi tri thoa yeu cau de bai la: %d", check);
	}

	getch();
	return 0;
}
