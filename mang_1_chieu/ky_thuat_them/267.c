// Bài 267 & 270 /76/SBT Thầy NTTMK: Viết chương trình thực hiện các yêu cầu sau: Nhập mảng n số nguyên từ bàn phím sao cho khi nhập xong các phần tử trong mảng được sắp theo thứ tự tăng dần. (không sắp xếp sau khi nhập) (nhập bảo toàn).

#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <Windows.h>
#define SLPT 100

// Hoán vị.
void Swap(double *a, double *b)
{
	*a += *b;
	*b = *a - *b; // b = a.
	*a -= *b; // a = b.
}

void NhapMang(int n, double a[])
{
	for (int i = 0; i < n; i++)
	{
		printf("\nNhap vao phan tu thu %d: ", i + 1);
		scanf("%lf", &a[i]);

		if (i >= 1 && i < n)
		{
			int min = i;
			for (int j = i - 1; j >= 0; j--)
			{
				if (a[min] > a[j])
				{
					Swap(&a[min], &a[j]);
					min--; // min này đặt ở đây hay ở dưới cũng được. (trong TH này thôi nha)
				}
				/*min--;*/
			}
		}
	}
}

void XuatMang(int n, double a[])
{
	for (int i = 0; i < n; i++)
	{
		printf("%lf ", a[i]);
	}
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

	getch();
	return 0;
}
