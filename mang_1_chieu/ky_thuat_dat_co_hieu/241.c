//  Bài 241/72/SBT Thầy NTTMK: Hãy kiểm tra mảng số nguyên có tồn tại hai giá trị không liên tiếp hay không ?

#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <Windows.h>
#include <time.h>
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

// Kiềm tra 2 giá trị 0 có liên tiếp không?
int KiemTraGiaTriLienKeKhong(int n, int a[])
{
	int check = 0; // Giả sử chưa có.
	for (int i = 0; i < n - 1; i++)
	{
		if (a[i] == 0 && a[i + 1] == 0)
		{
			check = 1;
		}
	}
	return check;
}

int main()
{
	int n = 10, a[SLPT];
	
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

	////reset.
	//srand(time(NULL));

	//// random từ -100 -> 100.
	//for (int i = 0; i < n; i++)
	//{
	//	a[i] = rand() % 201 - 100;
	//}

	NhapMang(n, a);
	printf("\nMang a sau khi nhap la: ");
	XuatMang(n, a);

	int kiemtra = KiemTraGiaTriLienKeKhong(n, a);
	if (kiemtra == 0)
	{
		printf("\n\nMang khong ton tai 2 gia tri = 0 lien tiep.");
	}
	else
	{
		printf("\n\nMang ton tai 2 gia tri = 0 lien tiep.");

	}

	getch();
	return 0;
}
