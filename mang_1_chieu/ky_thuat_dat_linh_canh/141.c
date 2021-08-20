// Bài 140-141/58/SBT Thầy NTTMK:Hãy tìm "vị trí giá trị dương nhỏ nhất" trong mảng một chiều các số thực.Nếu mảng không có giá trị dương thì trả về 1.

#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#define Max 100

void NhapMang(int n, float a[])
{
	for (int i = 0; i < n; i++)
	{
		printf("\nNhap vao phan tu thu %d: ", i + 1);
		scanf("%f", &a[i]);
	}
}

void XuatMang(int n, float a[])
{
	for (int i = 0; i < n; i++)
	{
		printf("%f ", a[i]);
	}
}

int vitrinhonhat(int n, float a[])
{
	int vtnn = 0, i, j;
	for (i = n - 1; i >= 0; i--)
	{
		if (a[i] > 0)
		{
			vtnn = i;
			break;
		}
	}
	if (i == -1)
	{
		return i;
	}
	else
	{
		for (j = n - 1; i >= 0; j--)
		{
			if (a[j] > 0)
			{
				if (a[j] < a[vtnn])
				{
					vtnn = j;
				}
			}
		}
		return vtnn;
	}
}

int main()
{
	int n;
	float a[Max];

	do
	{
		printf("Nhap vao so luong phan tu n: ");
		scanf("%d", &n);

		if (n <= 0 || n > Max)
		{
			printf("Ban nhap sai, xin kiem tra lai (n > 0 && n <= 100).\n\n");
		}
	} while (n <= 0 || n > Max);

	NhapMang(n, a);
	printf("\nMang sau khi nhap la: ");
	XuatMang(n, a);

	int vt = vitrinhonhat(n, a);
	if (vt != -1)
	{
		printf("\n\nVi tri cua gia tri duong nho nhat trong mang la: %d", vt);
	}
	else
	{
		printf("\nKhong co phan tu duong trong mang.");
	}

	getch();
	return 0;
}
