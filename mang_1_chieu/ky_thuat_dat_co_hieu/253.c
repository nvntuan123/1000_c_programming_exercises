/* 2016 - Nguyễn Nhật Tuấn.
Code được viết lúc tôi mới học lập trình C/C++ nên có một số cách chưa được tốt, mong giúp ích được các bạn tham khảo.
*/

// Bài 254/74/SBT Thầy NTTMK: Hãy cho biết tất cả các phần tử trong mảng a có nằm trong mảng b hay không ?

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
	for (int i = 0; i < n; i++)
	{
		printf("%lf ", a[i]);
	}
}

// Kiểm tra từng phần tử có trong mảng b hay không.
int KiemTraTungPhanTuMangATrongMangB(int nb, double b[], double phantucanxet)
{
	int check = 0;
	for (int i = 0; i < nb; i++)
	{
		if (b[i] == phantucanxet)
		{
			check = 1;
		}
	}
	return check;
}

// Kiểm tra tất cả phần tử trong mảng a có trong mảng b hay không ?
int KiemTraMangATrongMangB(int na, double a[], int nb, double b[])
{
	int check = 0; // False.
	int dem = 0;
	for (int i = 0; i < na; i++)
	{
		int kiemtraphantu = KiemTraTungPhanTuMangATrongMangB(nb, b, a[i]);
		if (kiemtraphantu == 1)
		{
			dem++;
		}
	}
	if (dem == na)
	{
		check = 1;
	}
	return check;
}

int main()
{
	int na, nb;
	double a[SLPT], b[SLPT];

	// Nhập mảng a.
	printf("Nhap mang a.\n\n");
	do
	{
		printf("Nhap vao so luong phan tu na: ");
		scanf("%d", &na);

		if (na <= 0 || na > SLPT)
		{
			system("cls");
			printf("Ban nhap sai, xin kiem tra lai (n > 0 va n <= 100).\n\n");
		}
	} while (na <= 0 || na > SLPT);

	NhapMang(na, a);

	// Nhập mảng b.
	printf("\nNhap mang b.\n\n");
	do
	{
		printf("Nhap vao so luong phan tu nb: ");
		scanf("%d", &nb);

		if (nb <= 0 || nb > SLPT)
		{
			system("cls");
			printf("Ban nhap sai, xin kiem tra lai (n > 0 va n <= 100).\n\n");
		}
	} while (nb <= 0 || nb > SLPT);

	NhapMang(nb, b);

	// Xuất 2 mảng a, b.
	printf("\nMang a sau khi nhap la: ");
	XuatMang(na, a);
	printf("\n\nMang b sau khi nhap la: ");
	XuatMang(nb, b);

	int KiemTraPhanTu = KiemTraMangATrongMangB(na, a, nb, b);
	if (KiemTraPhanTu == 0)
	{
		printf("\n\nPhan tu trong mang a khong nam trong mang b.");
	}
	else
	{
		printf("\n\nTat ca cac phan tu trong mang a nam trong mang b.");
	}

	getch();
	return 0;
}
