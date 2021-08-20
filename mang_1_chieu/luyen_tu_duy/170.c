/* 2016 - Nguyễn Nhật Tuấn.
Code được viết lúc tôi mới học lập trình C/C++ nên có một số cách chưa được tốt, mong giúp ích được các bạn tham khảo.
*/

// Bài 170/63/SBT Thầy NTTMK: Cho mảng một chiều các số nguyên. Hãy viết hàm tìm số nguyên tố nhỏ nhất lớn hơn mọi giá trị có trong mảng.

#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <Windows.h>
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

int KTSNT(int n)
{
	if (n < 2)
	{
		return 0;
	}
	else if (n == 2)
	{
		return 1;
	}
	else
	{
		if (n % 2 == 0)
		{
			return 0;
		}
		else
		{
			for (int i = 3; i <= sqrt((double)n); i += 2)
			{
				if (n % i == 0)
				{
					return 0;
				}
			}
			return 1;
		}
	}
}

// Tìm SNT
int TimSNT(int n, int a[])
{
	for (int i = 0; i < n; i++)
	{
		if (KTSNT(a[i]) == 1)
		{
			return 1;
		}
	}
	return 0;
}

// Tách SNT
void TachSNT(int n, int a[], int &nb, int b[], int &nc, int c[])
{
	if (TimSNT(n, a) == 1)
	{
		nb = nc = 0;
		for (int i = 0; i < n; i++)
		{
			if (KTSNT(a[i]) == 1)
			{
				b[nb++] = a[i];
			}
			else
			{
				c[nc++] = a[i];
			}
		}
	}

}

// Tìm SNT nhỏ nhất
int TimSNTNN(int nb, int b[])
{
	int min = b[0];
	{
		for (int i = 0; i < nb; i++)
		{
			min > b[i]? min = b[i] : min;
		}
	}
	return min;
}

// So sánh SNT với các giá tri trong mảng
int SoSanh(int nb, int b[], int nc, int c[])
{
	int maxSNT = TimSNTNN(nb, b);
	for (int i = 0; i < nc; i++)
	{
		if (maxSNT <= c[i])
		{
			return 0;
		}
	}
	return maxSNT;
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
	printf("\nMang a sau khi nhap la: ");
	XuatMang(n, a);

	/*if (TimSNT(n, a) == 0)
	{
	printf("\n\nMang khong co so nguyen to.");
	}
	else if (TimSNT(n, a) == -1)
	{
	printf("\n\nSo nguyen to khong lon hon moi gia tri trong mang.");
	}
	else
	{
	printf("\n\nSo nguyen to nho nhat lon hon moi gia tri trong mang: %d", TimSNT(n, a));
	}*/

	if (TimSNT(n, a) == 1)
	{
		int b[Max], c[Max], nb ,nc;
		TachSNT(n, a, nb, b, nc, c);
		if (SoSanh(nb, b, nc, c) == 0)
		{
			printf("\n\nTim duoc so nguyen to nho nhat nhung khong lon hon cac gia tri trong mang a.", SoSanh(nb, b, nc, c));
		}
		else
		{
			printf("\n\nSo nguyen to thoa yeu cau: %d", SoSanh(nb, b, nc, c));
		}
	}
	else
	{
		printf("\n\nKhong co so nguyen to.");
	}

	getch();
	return 0;
}
