/* 2016 - Nguyễn Nhật Tuấn.
Code được viết lúc tôi mới học lập trình C/C++ nên có một số cách chưa được tốt, mong giúp ích được các bạn tham khảo.
*/

// Bài 209/68/SBT Thầy NTTMK: Tính tổng các giá trị đối xứng trong mảng một chiều các số nguyên.

#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <Windows.h>
#define SLPT 100

void NhapMang(int n, int a[])
{
	for (int i = 0; i < n; i++)
	{
		printf("'\nNhap vao phan tu thu %d: ", i + 1);
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

// Kiểm số đối xứng.
int SoDoiXung(int n)
{
	int temp = n; // Tạo biến phụ.
	int a = 0;
	int b = log10((double)n);
	while (temp != 0)
	{
		int c = temp % 10; // Lấy số cuối.
		temp /= 10; // Loại bỏ số cuối.
		a += c * pow(10.0, b--);
	}
	if (a == n)
	{
		return 1;
	}
	return 0;
}

// Tính tổng các giá trị đối xứng.
int TongSoDoiXung(int n, int a[])
{
	int tong = 0;
	for (int i = 0; i < n; i ++)
	{
		if (SoDoiXung(a[i]) == 1)
		{
			tong += a[i];
		}
	}

	return tong;
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

	int tong = TongSoDoiXung(n, a);
	if (tong == 0)
	{
		printf("\n\nMang khong co so doi xung.");
	}
	else
	{
		printf("\n\nTong cac gia tri doi xung la: %d", tong);
	}

	getch();
	return 0;
}
