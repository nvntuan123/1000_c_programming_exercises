#include <stdio.h>

int main()
{
	int iDay;
	int iMonth;
	int iYear;

	printf("Nhap vao thang: ");
	scanf("%d", &iMonth);
	printf("Nhap vao nam: ");
	scanf("%d", &iYear);

	if (iMonth < 1 || iMonth > 12)
	{
		printf("Thang nhap vao sai! Thang phai tu 1 -> 12.\n");
		return 0;
	}
	
	if (iYear < 1)
	{
		printf("Nam nhap vao sai! Nam la gia tri duong.\n");
		return 0;
	}

	/*
	Nam nhuan la:
	TH1: Chia het cho 4 va khong chia het cho 100.
	TH2: Chia het cho 400.
	compiler -> trinh bien dich.
	*/

	if (iMonth == 2)
	{
		if ((!(iYear % 4) && (iYear % 100)) || !(iYear % 400))
		{
			iDay = 29;
		}
		else
		{
			iDay = 28;
		}
	}
	else if (iMonth == 4 || iMonth == 6 || iMonth == 9 || iMonth == 11)
	{
		iDay = 30;
	}
	else
	{
		iDay = 31;
	}
	
	printf("Thang co %d ngay.\n", iDay);
}
