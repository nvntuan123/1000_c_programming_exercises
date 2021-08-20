// Bài 290/78/SBT Thầy NTTMK: Hãy đảo ngược thứ tự các số chẵn và các số lẻ trong mảng mà vẫn giữ nguyên vị trí tương đối của chúng.

#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#define SLPT 100

// Nhập mảng.
void NhapMang(int n, int a[])
{
	for (int i = 0; i < n; i++)
	{
		printf("\nNhap vao phan tu thu %d: ", i + 1);
		scanf("%d", &a[i]);
	}
}

// Xuất mảng.
void XuatMang(int n, int a[])
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
}

// Hoán vị.
void Swap(int *a, int *b)
{
	*a += *b;
	*b = *a - *b; // b = a.
	*a -= *b; // a = b.
}

// đếm số chẵn.
int DemSoChan(int n, int a[])
{
	int dem = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] % 2 == 0)
		{
			dem++;
		}
	}
	return dem;
}

// Đếm số lẻ.
int DemSole(int n, int a[])
{
	int dem = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] % 2 != 0)
		{
			dem++;
		}
	}
	return dem;
}

// Tìm vị trí có phần tử chẵn đầu tiên ở cuối mảng.
int TimViTriChan(int n, int a[], int vitricandoicho)
{
	for (int i = n - 1; i > vitricandoicho; i--)
	{
		if (a[i] % 2 == 0)
		{
			return i;
		}
	}
	return -1;
}

// Tìm vị trị có phần tử lẻ đầu tiễn ở cuối mảng.
int TimViTriLe(int n, int a[], int vitricandoicho)
{
	for (int i = n - 1; i > vitricandoicho; i--)
	{
		if (a[i] % 2 != 0)
		{
			return i;
		}
	}
	return -1;
}

// Sắp xếp chẵn 1 hàng lẽ 1 hàng.
void SapXep(int n, int a[])
{
	int soluongsochan = DemSoChan(n, a); // Đếm số chẵn có trong mảng để đổi chỗ.
	int soluongsole = DemSole(n, a); // Đếm số lẻ có trong mảng để đổi chỗ.
	for (int i = 0; i < n; i++)
	{
		if (a[i] % 2 == 0)
		{
			if (soluongsochan > 0)
			{
				int check = TimViTriChan(n, a, i);
				for (int j = check - 1; j >= i; j--)
				{
					if (a[j] % 2 == 0)
					{
						Swap(&a[j], &a[check]);
						check = j;
					}
				}
			}
			soluongsochan--;
		}
		else
		{
			if (soluongsole > 0)
			{
				int check = TimViTriLe(n, a, i);
				for (int j = check - 1; j >= i; j--)
				{
					if (a[j] % 2 != 0)
					{
						Swap(&a[j], &a[check]);
						check = j;
					}
				}
			}
			soluongsole--;
		}
	}
}

int main()
{
	int a[SLPT], n;

	do
	{
		printf("Nhap vao so luong phan tu n[1, %d]: ", SLPT);
		scanf("%d", &n);

		if (n <= 0 || n > SLPT)
		{
			system("cls");
			printf("Ban nhap sai, nhap lai.");
		}
	} while (n <= 0 || n > SLPT);

	NhapMang(n, a);
	printf("\nMang ban dau sau khi nhap la: ");
	XuatMang(n, a);

	int demchan = DemSoChan(n, a);
	int demle = DemSole(n, a);
	// Troll tí ^_^
	if (!demchan)
	{
		printf("\n\nMang khong co so chan de sap xep.");
	}
	else if (!demle)
	{
		printf("\n\nMang khong co so le de sap xep.");
	}
	else
	{
		SapXep(n, a);
		printf("\n\nMang sau khi sap xep: \n");
		XuatMang(n, a);
	}

	getch();
	return 0;
}
