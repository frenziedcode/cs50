#include <cs50.h>
#include <stdio.h>
#include <string.h>

bool numCheck(long numCard);
void cardType(long numCard);

int main(void)
{
    long int numCard = get_long("Number: ");

    if (numCheck(numCard) == true)
    {
        printf("%ld\n", numCard);
        cardType(numCard);
    }
    else
    {
        printf("INVALID\n");
    }

    return 0;
}

bool numCheck(long int numCard)
{
    long int rev_Num, remainder;
    int sum = 0;
    int sumOther = 0;
    int finalResult = 0;
    int pickNum = 1;

    const long int save_numCard = numCard;

    while (numCard != 0)
    {
        remainder = numCard % 10;
        rev_Num = rev_Num * 10 + remainder;
        numCard = numCard / 10;

        if (pickNum == 0)
        {
            int sumRemainder = remainder * 2;
            if (sumRemainder > 9)
            {
                int lastNum, firstNum;
                lastNum = sumRemainder % 10;
                firstNum = sumRemainder / 10;

                sum += lastNum + firstNum;
            }
            else
                sum += sumRemainder;

            pickNum = 1;
        }
        else
        {
            sumOther += remainder;
            pickNum = 0;
        }
    }

    finalResult = (sumOther + sum) % 10;
    if (finalResult == 0)
        return true;
    else
        return false;
}

void cardType(long numCard)
{
    int length_cardNum = 0;
    char str_numCard[25];

    sprintf(str_numCard, "%ld", numCard);
    length_cardNum = strlen(str_numCard);
    printf("%i\n", length_cardNum);

    if ((length_cardNum == 15 && str_numCard[0] == '3'))
    {
        if (str_numCard[1] == '4' || str_numCard[1] == '7')
            printf("AMEX\n");
        else
            printf("INVALID\n");
    }
    else if (length_cardNum == 16 && str_numCard[0] == '5')
        if (str_numCard[1] >= '1' && str_numCard[1] <= '5')
            printf("MASTERCARD\n");
        else
            printf("INVALID\n");
    else if ((length_cardNum == 16 || length_cardNum == 13) && str_numCard[0] == '4')
        printf("VISA\n");
    else
        printf("INVALID\n");
}