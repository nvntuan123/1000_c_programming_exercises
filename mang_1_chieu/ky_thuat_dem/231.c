// Bài 231/71/SBT Thầy NTTMK: Hãy liệt kê các giá trị xuất hiện trong mảng một chiều các số nguyên đúng một lần.

#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <Windows.h>
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

// Kiểm tra phần tử bị trùng.
int KTGiaTriTrung(int n, int a[], int VTCKT) // VTCKT: vị trí cần kiểm tra.
{
	for (int i = VTCKT - 1; i >= 0; i--)
	{
		if (a[VTCKT] == a[i])
		{
			return 1;
		}
	}
	return 0;
}

// đếm số lần xuất hiện của phần tử.
int DemSoLanXuatHien(int n, int a[], int VTCD) // VTCD: vị trí cần đếm.
{
	int dem = 1; // tính luôn giá trị hiện tại.
	for (int i = VTCD + 1; i < n; i++)
	{
		if (a[VTCD] == a[i])
		{
			dem++;
		}
	}
	return dem;
}

// Liệt kê phần tử xuất hiên đúng 1 lần.
void LKPTXuatHienMotLan(int n, int a[])
{
	for (int i = 0; i < n; i++)
	{
		int phantutrung = KTGiaTriTrung(n, a, i);
		if (phantutrung == 1)
		{
			continue;
		}
		int demso = DemSoLanXuatHien(n, a, i);
		if (demso == 1)
		{
			printf("\n\nGia tri %d xuat hien dung %d lan.", a[i], demso);
		}
	}
}

int main()
{
	int a[SLPT], n;

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

	LKPTXuatHienMotLan(n, a);

	getch();
	return 0;
}
