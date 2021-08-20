/* 2016 - Nguyễn Nhật Tuấn.
Code được viết lúc tôi mới học lập trình C/C++ nên có một số cách chưa được tốt, mong giúp ích được các bạn tham khảo.
*/

// Bài 262/75/SBT Thầy NTTMK: Hãy sắp xếp các số chẵn trong mảng các số nguyên tăng dần, các số lẻ cũng tăng dần. Vị trí tương đối giữa các số chẵn và số lẻ không đổi.

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
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
}

// Hoán vị.
void HoanVi(int *a, int *b)
{
	*a -= *b;
	*b += *a; // b = a.
	*a = *b - *a; // a = b.
}

// Sắp xếp các số chẵn trong mảng các số nguyên tăng dần, các số lẻ cũng tăng dần. Vị trí tương đối giữa các số chẵn và số lẻ không đổi.
void SapXep(int n, int a[])
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] % 2 == 0)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (a[j] % 2 == 0)
				{
					if (a[i] > a[j])
					{
						HoanVi(&a[i], &a[j]);
					}
				}
			}
		}
		else
		{
			for (int j = i + 1; j < n; j++)
			{
				if (a[j] % 2 != 0)
				{
					if (a[i] > a[j])
					{
						HoanVi(&a[i], &a[j]);
					}
				}
			}
		}
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
	printf("\nMang sau khi nhao la: ");
	XuatMang(n, a);

	SapXep(n, a);
	printf("\nMang sau khi sap xep chan tang le cung tang, vi tri tuong doi giua chan le khong doi: ");
	XuatMang(n, a);

	getch();
	return 0;
}
