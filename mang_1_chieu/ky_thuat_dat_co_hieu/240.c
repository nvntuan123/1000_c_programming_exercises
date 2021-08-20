/* 2016 - Nguyễn Nhật Tuấn.
Code được viết lúc tôi mới học lập trình C/C++ nên có một số cách chưa được tốt, mong giúp ích được các bạn tham khảo.
*/

// Bài 240/72/SBT Thầy NTTMK: Hãy kiểm tra mảng số nguyên có tồn tại giá trị không hay không ? Nếu không tồn tại giá trị không trả về giá trị 0,ngược lại trả về 1.

#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <Windows.h>
#include <time.h>
#define SLPT 100

//void NhapMang(int n, double a[])
//{
//	for (int i = 0; i < n; i++)
//	{
//		printf("\nNhap vao phan tu thu %d: ", i + 1);
//		scanf("%lf", &a[i]);
//	}
//}

void XuatMang(int n, double a[])
{
	for (int i = 0; i < n; i++)
	{
		printf("%.3lf ", a[i]);
	}
}

// Kiểm có tồn tại số 0 hay không.
int KiemTraTonTai0(int n, double a[])
{
	int check = 0; // Giả sử chưa có.
	for (int i = 0; i < n; i++)
	{
		if (a[i] == 0)
		{
			check = 1;
		}
	}
	return check;
}

int main()
{
	int n = 10;
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

	// reset.
	srand(time(NULL));
	// random từ -50 -> 50.
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 101 - 50; // Chú ý: random chỉ chơi được với số nguyên.
	}

	/*NhapMang(n, a);*/
	printf("\nMang a sau khi nhap la: ");
	XuatMang(n, a);

	int kiemtra = KiemTraTonTai0(n, a);
	if (kiemtra == 0)
	{
		printf("\n\nMang a khong ton tai gia tri 0.");
	}
	else
	{
		printf("\n\nMang a ton tai gia tri 0.");
	}

	getch();
	return 0;
}
