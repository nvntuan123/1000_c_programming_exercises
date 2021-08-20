/* 2016 - Nguyễn Nhật Tuấn.
Code được viết lúc tôi mới học lập trình C/C++ nên có một số cách chưa được tốt, mong giúp ích được các bạn tham khảo.
*/

// Bài 270/76/SBT Thầy NTTMK: Viết chương trình thực hiện các yêu cầu sau: Nhập mảng n số nguyên từ bàn phím sao cho khi nhập xong các phần tử trong mảng được sắp xếp theo thừ tự tăng dần (nhapbaotoan).

#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <Windows.h>
#define SLPT 100

// Hoán vị.
void Swap(int *a, int *b)
{
	// Troll ^_^
	*b += *a;
	*a = *b - *a; // a = b.
	*b -= *a; // b = a.
}

// Nhập mảng xuất mảng.
void NhapMang(int n, int a[])
{
	for (int i = 0; i < n; i++)
	{
		printf("\nNhap vao phan tu thu %d: ", i + 1);
		scanf("%d", &a[i]);

		if (i >= 1 && i < n)
		{
			int max = i;
			for (int j = i - 1; j >= 0; j--)
			{
				if (a[max] < a[j])
				{
					Swap(&a[max], &a[j]);
					max--; // max đặt trong if hay ngoài if đều được.
				}
			}
		}
	}
}

// Xuất Mảng.
void XuatMang(int n, int a[])
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
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
	printf("\nMang sau khi nhap la: ");
	XuatMang(n, a);

	getch();
	return 0;
}
