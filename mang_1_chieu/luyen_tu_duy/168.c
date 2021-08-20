/* 2016 - Nguyễn Nhật Tuấn.
Code được viết lúc tôi mới học lập trình C/C++ nên có một số cách chưa được tốt, mong giúp ích được các bạn tham khảo.
*/

// Bài 168/63/SBT Thầy NTTMK: Cho mảng một chiều các số nguyên. Hãy viết hàm tìm giá trị lớn nhất trong mảng có dạng 5^k. Nếu mảng không tồn tại giá trị có dạng 5^k thì hàm sẽ trả về giá trị 0.

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

int KiemTra(int n)
{
	// Cách 1:
	/*while (n != 1)
	{
		if (n % 5 != 0)
		{
			return 0;
		}
		n /= 5;
	}
	return n;*/

	// Cách 2:
	int t = 0, s = 0;
	while (t < n)
	{
		t = pow(5.0, s++);
		if (t == n)
		{
			return 1;
		}
	}
	return 0;
}

int XuLy(int n, int a[])
{
	int max = 0;
	for (int i = 0; i < n; i++)
	{
		if (KiemTra(a[i]) == 1)
		{
			max = a[i];
			break;
		}
	}

	if (max != 0)
	{
		for (int j = 0; j < n; j++)
		{
			if (KiemTra(a[j]) == 1)
			{
				/*max < a[j]? max = a[j] : max;*/
				if (max < a[j])
				{
					max = a[j];
				}
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
		printf("\n\nMang khong co dang 5^k");
	}
	else
	{
		printf("\n\nGia tri lon nhat co dang 5^k la: %d", XuLy(n, a));
	}

	getch();
	return 0;
}
