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

    int iDigit;
    double iReverseNumber;
    iDigit = iReverseNumber = 0;

	int iExponent = log10((double)iN);

	while (iN != 0)
	{
		iDigit = iN % 10;
		iN /= 10;
        iReverseNumber += iDigit * pow((double)10, (double)iExponent--);
	}

	printf("\nSo dao nguoc la: %d.", (int)iReverseNumber);
}