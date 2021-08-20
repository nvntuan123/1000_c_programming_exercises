/* 2016 - Nguyễn Nhật Tuấn.
Code được viết lúc tôi mới học lập trình C/C++ nên có một số cách chưa được tốt, mong giúp ích được các bạn tham khảo.
*/

// Bài 167/63/SBT Thầy NTTMK: Hãy tìm giá trị thỏa điều kiện toàn chữ số lẻ và là giá trị lớn nhất thỏa điều kiện ấy trong mảng một chiều các
// số nguyên (nếu mảng không có giá trị nào thỏa điều kiện như trên thì hàm sẽ trả về giá trị 0).

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

int KiemTraChuSoLe(int n)
{
	while (n != 0)
	{
		int a = n % 10;
		if (a % 2 == 0)
		{
			return 0;
		}
		n /= 10;
	}
	return 1;
}

int XuLy(int n, int a[])
{
	int max = 0, i, j;
	for (i = 0; i < n; i++)
	{
		if (KiemTraChuSoLe(a[i]) == 1)
		{
			max = a[i];
			break;
		}
	}

	if (max != 0)
	{
		for (j = 0; j < n; j++)
		{
			if (KiemTraChuSoLe(a[j]) == 1)
			{
				/*if (max < a[j])
				{
					max = a[j];
				}*/
				max < a[j]? max = a[j] : max;
			}
		}
	}
	return max;
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

	if (XuLy(n, a) == 0)
	{
		printf("\n\nMang khong co gia tri toan chu so le.");
	}
	else
	{
		printf("\n\nGia tri lon nhat toan chu so le: %d", XuLy(n, a));
	}

	getch();
	return 0;
}
