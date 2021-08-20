/* 2016 - Nguyễn Nhật Tuấn.
Code được viết lúc tôi mới học lập trình C/C++ nên có một số cách chưa được tốt, mong giúp ích được các bạn tham khảo.
*/

// Bài 218/69/SBT Thầy NTTMK: Đếm số lượng giá trị đối xứng trong mảng các số nguyên.

#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <Windows.h>
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

// Kiểm tra số đối xứng.
int KTDoiXung(int n)
{
	int temp = n, b = 0;
	int soluongchuso = log10((double)temp); // phải + 1 nửa mới ra.
	while (temp != 0)
	{
		int a = temp % 10;
		temp /= 10;
		b += a * pow(10.0, soluongchuso--);
	}
	if (b == n)
	{
		return 1;
	}
	return 0;
}

// Số lượng giá trị đối xứng.
int SLDX(int n, int a[])
{
	int dem = 0;
	for (int i = 0; i < n; i++)
	{
		if (KTDoiXung(a[i]) == 1)
		{
			dem++;
		}
	}
	return dem;
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

	int demso = SLDX(n, a);
	if (demso == 0)
	{
		printf("\n\nMang khong co so doi xung.");
	}
	else
	{
		printf("\n\nSo luong gia tri doi xung: %d", demso);
	}

	getch();
	return 0;
}
