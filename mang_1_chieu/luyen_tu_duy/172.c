/* 2016 - Nguyễn Nhật Tuấn.
Code được viết lúc tôi mới học lập trình C/C++ nên có một số cách chưa được tốt, mong giúp ích được các bạn tham khảo.
*/

// Bài 172/63/SBT Thầy NTTMK: Cho mảng một chiều các số nguyên dương. Hãy viết hàm tìm bội chung nhỏ nhất của tất cả các phần tử trong mảng.

#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#define Max 100

void NhapMang(unsigned int n, int a[])
{
	for (int i = 0; i < n; i++)
	{
		do
		{
			printf("\nNhap vao phan tu thu %d: ", i + 1);
			scanf("%d", &a[i]);

			if (a[i] <= 0)
			{
				printf("Ban nhap, xin kiem tra lai (n > 0 va n <= 100).\n\n");
			}
		} while (a[i] <= 0);
	}
}

void XuatMang(unsigned int n, int a[])
{
	printf("\n\n");
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
}

// Tìm BCNN của 2 số.
int BCNN(int a, int b)
{
	int tich = a * b;
	while (a - b)
	{
		if (a > b)
		{
			a -= b;
		}
		else
		{
			b -= a;
		}
	}
	return tich / a;
}

int TimBCNN(unsigned int n, int a[])
{
	int temp = a[0];
	for (int i = 1; i < n; i++)
	{
		temp = BCNN(temp, a[i]);
	}
	return temp;
}

int main()
{
	int a[Max];
	unsigned int n;

	int tieptuc;

	do
	{
		do
		{
			printf("Nhap vao so luong phan tu n: ");
			scanf("%d", &n);

			if (n <= 0 || n > Max)
			{
				printf("Ban nhap, xin kiem tra lai (n > 0 va n <= 100).\n\n");
			}
		} while (n <= 0 || n > Max);

		NhapMang(n, a);
		printf("\nMang a sau khi nhap la: ");
		XuatMang(n, a);

		printf("\n\nBCNN = %d", TimBCNN(n, a));

		printf("\n\nBan muon tiep tuc hay khong tiep tuc (1 - Yes, 0 - No): ");
		scanf("%d", &tieptuc);

		if (tieptuc == 1)
		{
			system("cls");
		}
	} while (tieptuc == 1);

	return 0;
}
