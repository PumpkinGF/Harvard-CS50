#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt for input
    long card;
    do
    {
        card = get_long("Number: ");
    }
    while (card < 0 || card > 10000000000000000);

    // Calculate checksum
    int card1, card2, card3, card4, card5, card6, card7, card8; // find every other digits in card number, at most 8 of them
    card1 = (card % 100 / 10) * 2;
    card2 = (card % 10000 / 1000) * 2;
    card3 = (card % 1000000 / 100000) * 2;
    card4 = (card % 100000000 / 10000000) * 2;
    card5 = (card % 10000000000 / 1000000000) * 2;
    card6 = (card % 1000000000000 / 100000000000) * 2;
    card7 = (card % 100000000000000 / 10000000000000) * 2;
    card8 = (card % 10000000000000000 / 1000000000000000) * 2;

    int card11, card12, card13, card14, card15, card16, card17, card18; // last digit, 3rd last digit, etc.
    card11 = card % 10;
    card12 = card % 1000 / 100;
    card13 = card % 100000 / 10000;
    card14 = card % 10000000 / 1000000;
    card15 = card % 1000000000 / 100000000;
    card16 = card % 100000000000 / 10000000000;
    card17 = card % 10000000000000 / 1000000000000;
    card18 = card % 1000000000000000 / 100000000000000;

    int sum1, sum2; // add the digits, for each of card1 ~ card8, the largest * 2 is 9*2 = 18, so don't need to consider > 2 digits
    sum1 = (card1/10 + card1%10) + (card2/10 + card2%10) + (card3/10 + card3%10) + (card4/10 + card4%10) + (card5/10 + card5%10) + (card6/10 + card6%10) + (card7/10 + card7%10) + (card8/10 + card8%10);
    sum2 = sum1 + (card11 + card12 + card13 + card14 + card15 + card16 + card17 + card18);

    // Check for card length and starting digits, print AMEX, MASTERCARD, VISA, or INVALID
    int length = 0;
    long original_card = card; // store the original card
    while (card > 0) // manual calculate length
    {
        card/= 10;
        length ++;
    }

    card = original_card;

    if (sum2 % 10 != 0)
    {
        printf("INVALID");
    }
    else if ((length == 13 && card/1000000000000 == 4) || (length == 16 && card/1000000000000000 == 4)) // Visa: 13 or 16 digits, starting with 4
    {
        printf("VISA");
    }
    else if (length == 15 && (card/10000000000000 == 34 || card/10000000000000 == 37))
    {
        printf("AMEX");
    }
    else if (length == 16 && ( card/100000000000000 > 50 && card/100000000000000 < 56))
    {
        printf("MASTERCARD");
    }
    else
    {
        printf("INVALID");
    }
    printf("\n");
}