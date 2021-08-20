// Bài 150/60/SBT Thầy NTTMK:Hãy tìm "giá trị âm lớn nhất" trong mảng các số thực. Nếu mảng không có giá trị âm thì trả về giá trị 0.

#include <stdio.h>
#include <conio.h>
#include <windows.h>
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

float GiaTriAmLonNhat(int n, float a[])
{
	float max = 0;
	int i, j;
	for (i = 0; i < n; i++)
	{
		if (a[i] < 0)
		{
			max = a[i];
			break;
		}
	}

	for (j = i + 1; j < n; j++)
	{
		/*if (a[j] < 0)
		{
			if(max < a[j])
			{
				max = a[j];
			}
		}*/
		// Có thể làm thế này.
		if(a[j] < 0 && max < a[j])
		{
			max = a[i];
		}
	}
	return max;
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
			system("cls");
			printf("Ban nhap sai, xin kiem tra lai (n > 0 va n <= 100).\n\n");
		}
	} while (n <= 0 || n > Max);

	NhapMang(n, a);
	printf("\nMang sau khi nhap la: ");
	XuatMang(n, a);

	if (GiaTriAmLonNhat(n, a) == 0)
	{
		printf("\n\nMang khong co gia tri am.");
	}
	else
	{
		printf("\n\nGia tri am lon nhat: %f", GiaTriAmLonNhat(n, a));
	}

	getch();
	return 0;
}
