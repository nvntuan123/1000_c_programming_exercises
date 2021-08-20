/* 2016 - Nguyễn Nhật Tuấn.
Code được viết lúc tôi mới học lập trình C/C++ nên có một số cách chưa được tốt, mong giúp ích được các bạn tham khảo.
*/

// Bài 154/60/SBT Thầy NTTMK:Hãy tìm "vị trí giá trị âm lớn nhất" trong mảng các số thực. Nếu mảng không có giá trị âm thì trả về -1.

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

int ViTriGiaTriAmLonNhat(int n, float a[])
{
	int vtln = -1, i, j;
	for (i = 0; i < n; i++)
	{
		if (a[i] < 0)
		{
			vtln = i;
			break;
		}
	}
	for (j = 0; j < n; j++)
	{
		if (a[j] < 0)
		{
			if (a[vtln] < a[j])
			{
				vtln = j;
			}
		}
	}
	return vtln;
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

	if (ViTriGiaTriAmLonNhat(n, a) == -1)
	{
		printf("\n\nMang khong co gia tri am.");
	}
	else
	{
		printf("\n\nVi tri gia tri am lon nhat: %d", ViTriGiaTriAmLonNhat(n, a));
	}

	getch();
	return 0;
}
