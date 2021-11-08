#include <stdio.h>
#include <math.h>

int main()
{
    int iN;

	do
	{
		printf("Nhap vao so nguyen duong n: ");
		scanf("%d", &iN);

		if (iN <= 0)
		{
			printf("\nBan nhap sai roi, xin kiem tra lai (n > 0).\n");
		}
	} while (iN <= 0);

    if (iN < 2)
	{
		printf("\nSo %d khong la so nguyen to.", iN);
	}
	else if (iN == 2)
	{
		printf("\nSo %d la so nguyen.", iN);
	}
	else
	{
		if (iN % 2 == 0)
		{
			printf("\nSo %d khong la so nguyen to.", iN);
		}
		else
		{
			int iCheck = 1;
			for (int i = 3; i <= sqrt((double)iN); i += 2)
			{
				if (iN % i == 0)
				{
					iCheck = 0;
					break;
				}
			}
			if (iCheck == 1)
			{
				printf("\nSo %d La so nguyen to.", iN);
			}
			else
			{
				printf("\nSo %d Khong la so nguyen to.", iN);
			}
		}
	}
}