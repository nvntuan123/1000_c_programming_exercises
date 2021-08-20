/* 2016 - Nguyễn Nhật Tuấn.
Code được viết lúc tôi mới học lập trình C/C++ nên có một số cách chưa được tốt, mong giúp ích được các bạn tham khảo.
*/

// Bài 193/66/SBT Thầy NTTMK: Cho mảng một chiều các số nguyên. Hãy viết hàm liệt kê các giá trị trong mảng có dạng 3^k. Nếu mảng không tồn tại giá trị có dạng 3^k thì hàm sẽ trả về giá trị 0.

#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <math.h>
#define SLPT 100

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
	printf("\n\n");
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
}

// Kiểm tra giá trị 3^k.
int KTSmu(int n)
{
	// Cách 1:
	while (n != 1)
	{
		int a = n % 3;
		if (a != 0)
		{
			return 0;
		}
		n /= 3;
	}
	return 1;

	// Cách 2:
	/*int mu = 0, t = 0;
	while (t < n)
	{
		t = pow(3.0, mu++);
		if (t == n)
		{
			return 1;
		}
	}
	return 0;*/
}

// Kiểm tra mảng có số dạng 3^k không.
int KTGT(int n, int a[])
{
	for (int i = 0; i < n; i++)
	{
		if (KTSmu(a[i]) == 1)
		{
			return 1;
		}
	}
	return 0;
}

// Liệt kê giá trị có dạng 3^k.
void LKGT(int n, int a[])
{
	if (KTGT(n, a) == 1)
	{
		printf("\n\nGia tri dang 3^k: ");
		for (int i = 0; i < n; i++)
		{
			if (KTSmu(a[i]) == 1)
			{
				printf("%d ", a[i]);
			}
		}
	}
	else
	{
		printf("\n\nMang khong co gia tri dang 3^k.");
	}
}

int main()
{
	int a[SLPT], n;

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
	printf("\nMang a sau khi nhap la: ");
	XuatMang(n, a);

	LKGT(n, a);

	getch();
	return 0;
}
