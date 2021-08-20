// Bài 250/73/SBT Thầy NTTMK: Hãy cho biết các phần tử trong mảng có lập thành cấp số cộng không ? Nếu có hãy chỉ ra công sai d.

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

// Kiểm tra cấp số cộng.
double CapSoCong(int n, double a[])
{
	double check = fabs(a[0] - a[1]); // True. Đồng thời check cũng là công sai d cần tìm.
	for (int i = 0; i < n - 2; i++)
	{
		double x = fabs(a[i] - a[i + 1]); // i = 0 -> khoảng cách = |a0 - a1|.
		double y = fabs(a[i + 1] - a[i + 2]); // i = 0 -> khoang cách tiếp theo = |a1 - a2|.
		if (x != y) // So sánh xem 2 số có = hay không.
		{
			check = 0; // False (không =).
			break; // Dừng vòng lặp ngay.
		}
	}
	return check;
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

	double capsocong = CapSoCong(n, a);
	if (capsocong == 0)
	{
		printf("\n\nCac phan tu trong mang khong lap thanh cap so cong.");
	}
	else
	{
		printf("\n\nCac phan tu trong mang lap thanh cap so cong. Va cong sai d = %lf", capsocong);
	}

	getch();
	return 0;
}
