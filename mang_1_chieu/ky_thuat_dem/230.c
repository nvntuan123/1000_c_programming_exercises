/* 2016 - Nguyễn Nhật Tuấn.
Code được viết lúc tôi mới học lập trình C/C++ nên có một số cách chưa được tốt, mong giúp ích được các bạn tham khảo.
*/

// Bài 230/70/SBT Thầy NTTMK: Hãy liệt kê tần suất xuất hiện của các giá trị xuất hiện trong mảng. (Lưu ý: Mỗi giá trị liệt kê một lần).

#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <Windows.h>
#define SLPT 100

void NhapMang(int n, double a[])
{
	for (int i = 0; i < n; i++)
	{
		printf("\nNhap vao phan tu thu %d: ", i + 1);
		scanf("%lf", &a[i]);
	}
}
void XuatMang(int n, double a[])
{
	printf("\n\n");
	for (int i = 0; i < n; i++)
	{
		printf("%lf ", a[i]);
	}
}


// Liệt kê tần suất xuất hiện của các giá trị xuất hiện trong mảng. (Lưu ý: Mỗi giá trị liệt kê một lần).
void LKTanSuat(int n, double a[])
{
	for (int i = 0; i < n; i++)
	{
		int dem = 0; // Dùng để đếm tần suất.
		int laplai = 0; // Dùng để kiểm tra xem giá trị có xét rồi hay chưa. laplai = 0 giả sử chưa xét.
		double linhcanh = a[i]; // Lưu giá trị để đếm số lần xuất hiện.

		// Chỉ kiểm tra những giá trị có chỉ số từng 1 trở đi.
		if (i >= 1)
		{
			for (int j = i - 1; j >= 0; j--)
			{
				if (a[i] == a[j])
				{
					laplai = 1; // Có trùng.
					break; // => dừng.
				}
			}
		}

		// Có => chạy tiếp không cần xét phía dưới.
		if (laplai == 1)
		{
			continue;
		}

		// Chạy tiếp từ i -> n - 1 nếu trùng thì tăng dem lến 1.
		for (int k = i; k < n; k++)
		{
			if (linhcanh == a[k])
			{
				dem++;
			}
		}

		// In ra số đáng xét và số tần suất.
		printf("\n\nSo %lf xuat hien %d lan.", linhcanh, dem);
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
	printf("\nMang a sau khi nhap la: ");
	XuatMang(n, a);

	LKTanSuat(n, a);

	getch();
	return 0;
}
