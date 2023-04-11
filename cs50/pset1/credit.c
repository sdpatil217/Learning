#include "cs50.h"
#include <stdio.h>


int calculate_digits(long long card_number);
int calculate_sum(long long card_number);
bool is_valid(int sum);
void print_card(long long card_number);


int main(void)
{
    long long card_number = get_long_long("Number: ");

    int digits = calculate_digits(card_number);

    int sum = calculate_sum(card_number);
    // printf("sum: %i\n", sum);
    // printf("digits: %i\n", digits);

    bool isvalid = is_valid(sum);

    if(!isvalid)
    {
        printf("INVALID\n");
        return 0;
    }
    
    print_card(card_number);


}

int calculate_digits(long long card_number)
{
    int digits = 0;
    do
    {
        digits++;
        card_number = card_number / 10;
    }
    while (card_number != 0);
    return digits;
}

int calculate_sum(long long card_number)
{
    int digits = calculate_digits(card_number);
    int digit [digits];
    int sum = 0;
    int i = -1;
    while (card_number != 0)
    {
        i++;
        int num = card_number % 10;
        card_number = card_number / 10;
        digit[i] = num;
    }
    for (int j = 0; j < digits; j++)
    {
        if (j == 0 || j % 2 == 0)
        {
            sum =  sum + digit[j];
        }
        else
        {
            int add = digit[j] * 2;
            if (add >= 10)
            {
                sum = sum + add % 10 + 1;
            }
            else
            {
                sum = sum + add;
            }
        }
    }
    return sum;

}


bool is_valid(int sum)
{
    if (sum % 10 == 0)
    {
        return true;
    }
    return false;
}

void print_card(long long card_number)
{
    int digits = calculate_digits(card_number);
    int digit [digits];
    //int sum = 0;
    int i = -1;
    while (card_number != 0)
    {
        i++;
        int num = card_number % 10;
        card_number = card_number / 10;
        digit[i] = num;
    }
    int first = 10 * digit[digits - 1] + digit[digits - 2];

    if ((digits == 15) && (first == 34  || first == 37))
    {
        printf("AMEX\n");
    }
    else if (digits == 16 && first > 50 && first < 56)
    {
        printf("MASTERCARD\n");
    }
    else if ((digits == 13 || digits == 16) && first > 39 && first < 50)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }

}