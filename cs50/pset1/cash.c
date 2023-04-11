#include "cs50.h"
#include <stdio.h>

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes (int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    // Ask for cents owned
    int cents = get_cents();

    // Calculate no of quarters to give customer
    int quarters = calculate_quarters(cents);
    cents = cents - quarters * 25;

    //Calculate no of dimes to give customer
    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;

    // Calculate no of nickels to give customer
    int nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;

    // Calculate the no of pennies to give customer
    int pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;

    // Sum coins
    int coins = quarters + dimes + nickels + pennies;

    // Print no of coins to give customer
    printf("%i\n", coins);
    return 0;
}




int get_cents(void)
{
    int cents;
    do
    {
        cents = get_int("changed owned: ");
    }
    while(cents < 1);
    return cents;
}


int calculate_quarters(int cents)
{
    int quarters = cents / 25;
    return quarters;
}


int calculate_dimes(int cents)
{
    int dimes = cents / 10;
    return dimes;
}


int calculate_nickels(int cents)
{
    int nickels = cents / 5;
    return nickels;
}


int calculate_pennies(int cents)
{
    int pennies = cents;
    return pennies;
}
