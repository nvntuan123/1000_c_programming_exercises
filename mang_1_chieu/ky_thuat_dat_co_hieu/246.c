// Bài 246/73/SBT Thầy NTTMK: Hãy kiểm tra mảng một chiều các số thực có đối xứng hay không ?

#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <Windows.h>
#include <time.h>
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

// Kiểm tra mảng đối xứng.
int KTMangDoiXung(int n, double a[])
{
	int check = 1; // True.
	for (int i = 0; i < n / 2; i++)
	{
		if (a[i] != a[n - 1 - i])
		{
			check = 0; // False.
		}
	}
	return check;
}

int main()
{
	int n = 5;
	double a[SLPT];

	/*do
	{
		printf("Nhap vao so luong phan tu n: ");
		scanf("%d", &n);

		if (n <= 0 || n > SLPT)
		{
			system("cls");
			printf("Ban nhap sai, xin kiem tra lai (n > 0 va n <= 100).\n\n");
		}
	} while (n <= 0 || n > SLPT);*/

	/*NhapMang(n, a);
	printf("\nMang a sau khi nhap la: ");*/

	// Chú ý: random chỉ dùng được đối với số nguyên.
	// Reset time.
	srand(time(NULL));

	// random từ -100 -> 100.
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 201 - 100;
	}
	XuatMang(n, a);

	int mangdoixung = KTMangDoiXung(n, a);
	if (mangdoixung == 0)
	{
		printf("\n\nMang khong doi xung.");
	}
	else
	{
		printf("\n\nMang doi xung.");
	}

	getch();
	return 0;
}
