/* 2016 - Nguyễn Nhật Tuấn.
Code được viết lúc tôi mới học lập trình C/C++ nên có một số cách chưa được tốt, mong giúp ích được các bạn tham khảo.
*/

// Bài 164/62/SBT Thầy NTTMK: Cho mảng một chiều các số nguyên hãy viết hàm tìm giá trị đầu tiên trong mảng thỏa tính chất số gánh.(ví dụ:12321).

#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <math.h>
#define Max 100

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

int KTSoGanh(int n)
{
	int a = 0, b = 0;
	int soluongchuso = log10((double)n);
	int temp = n; // lưu biến phụ
	while (temp != 0)
	{
		a = temp % 10;
		temp /= 10;
		b += a * pow((double)10, soluongchuso--);
	}
	if (b == n)
	{
		return 1;
	}
	return 0;
}

int TimSoGanhDauTien(int n, int a[])
{
	for (int i = 0; i < n; i++)
	{
		if (KTSoGanh(a[i]) == 1)
		{
			return a[i];
		}
	}
	return 0;
}

int main()
{
	int a[Max], n;

	do
	{
		printf("Nhap vao so luong phan tu n: ");
		scanf("%d", &n);

		if (n <= 0 || n > Max)
		{
			system("cls");
			printf("Ban nhap sai, xin kiem tra lai (n > 0 va n <= 100).\n\n");
		}
	} while (n <= 0 || n > Max);

	NhapMang(n, a);
	printf("\nMang a sau khi nhao la: ");
	XuatMang(n, a);

	if (TimSoGanhDauTien(n, a) != 0)
	{
		printf("\n\nSo ganh dau tien trong mang la: %d", TimSoGanhDauTien(n, a));
	}
	else
	{
		printf("\n\nMang khong co so ganh.");
	}

	getch();
	return 0;
}
