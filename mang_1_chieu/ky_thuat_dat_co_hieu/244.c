/* 2016 - Nguyễn Nhật Tuấn.
Code được viết lúc tôi mới học lập trình C/C++ nên có một số cách chưa được tốt, mong giúp ích được các bạn tham khảo.
*/

// Bài 244/73/SBT Thầy NTTMK: Hãy kiểm tra mảng số nguyên có thỏa mãn tính chất sau không : "Mảng không có tồn tại số hoàn thiện lớn hơn 256". Nếu thỏa trả về 1,nếu không trả về 0.

#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <Windows.h>
#include <time.h>
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
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
}

// Kiểm tra số hoàn thiện.
int KTSoHoanThien(int n)
{
	int tong = 0;
	for (int i = 1; i < n; i++)
	{
		if (n % i == 0)
		{
			tong += i;
		}
	}
	if (tong == n)
	{
		return 1;
	}
	return 0;
}

// Kiểm tra mảng có số hoàn thiện thỏa tính chất < 256.
int KTSHTNHon256(int n, int a[])
{
	int check = 0;
	for (int i = 0; i < n; i++)
	{
		if (KTSoHoanThien(a[i]) == 1)
		{
			if (a[i] < 256)
			{
				check = 1;
			}
		}
	}
	return check;
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

	int kiemtraSHT = KTSHTNHon256(n, a);
	if (kiemtraSHT == 0)
	{
		printf("\n\nMang khong co so hoan thien nho hon 256");
	}
	else
	{
		printf("\n\nMang co so hoan thien nho hon 256");
	}

	getch();
	return 0;
}
