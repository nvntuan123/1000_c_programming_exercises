#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Ngay hien tai
    int iDay;
    int iMonth;
    int iYear;

    int iYesterday;
    int iLastMonth;
    int iLastYear;

    int iTomorrow;
    int iNextMonth;
    int iNextYear;

    printf("Ngay: ");
    scanf("%d", &iDay);
    printf("Thang: ");
    scanf("%d", &iMonth);
    printf("Nam: ");
    scanf("%d", &iYear);

    char bCheckLeapYear = (!(iYear % 400) || (!(iYear % 4) && (iYear % 100)));
    char bCheckMonth = (iMonth > 0 && iMonth < 13);
    char bCheckDay = (iDay > 0);
    switch (iMonth)
    {
    case 4: case 6: case 9: case 11:
        bCheckDay = iDay < 31;
        break;
    case 2:
        bCheckDay = bCheckLeapYear ? (iDay < 30) : (iDay < 29);
        break;
    default:
        bCheckDay = iDay < 32;
        break;
    }

    if ((iYear > 0) && bCheckMonth && bCheckDay)
    {
        iYesterday = iTomorrow = iDay;
        iLastMonth = iNextMonth = iMonth;
        iLastYear = iNextYear = iYear;

        short sDaySum = 0;

        // Hom qua.
        switch (iMonth - 1)
        {
        case 4: case 6: case 9: case 11:
            sDaySum = 30;
            break;
        case 2:
            sDaySum = bCheckLeapYear ? 29 : 28;
            break;
        default:
            sDaySum = 31;
            break;
        }
        if (iDay == 1)
        {
            iYesterday = sDaySum;
            if (iMonth == 1)
            {
                iLastMonth = 12;
                iLastYear = iYear - 1;
            }
            else
            {
                iLastMonth = iMonth - 1;
            }
        }
        else
        {
            iYesterday = iDay - 1;
        }
        printf("Hom qua: %02d/%02d/%d\n", iYesterday, iLastMonth, iLastYear);

        // Ngay mai.
        switch (iMonth)
        {
        case 4: case 6: case 9: case 11:
            sDaySum = 30;
            break;
        case 2:
            sDaySum = bCheckLeapYear ? 29 : 28;
            break;
        default:
            sDaySum = 31;
            break;
        }
        iTomorrow = (iTomorrow % sDaySum) + 1;
        if (iTomorrow == 1)
        {
            iNextMonth = (iNextMonth % 12) + 1;
        }
        iNextYear += ((iNextMonth == 1) && (iTomorrow == 1));
        printf("Ngay mai: %02d/%02d/%d\n", iTomorrow, iNextMonth, iNextYear);
    }
    else
    {
        printf("Ngay thang nam nhap vao khong hop le!\n");
    }
}
