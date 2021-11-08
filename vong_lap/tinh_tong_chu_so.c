#include <stdio.h>

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

    int iCount = 0;
    int iDigitSum = 0;
    int iDigit = 0;

    while (iN != 0)
	{
		iDigit = iN % 10;
		iN /= 10;
        iDigitSum += iDigit;
        ++iCount;
	}
    printf("Tong chu so la: %d\n", iDigitSum);
    printf("So luong chu so: %d\n", iCount);
}