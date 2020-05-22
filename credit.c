#include <stdio.h>
#include <cs50.h>

int main(void)
{

 long cardnum;
 int numdig = 0;
 int sumdig1 = 0;
 int sumdig2 = 0;
 int sumdigfinal = 0;
 long firsttwodig=0;

 cardnum = get_long("Number: ");
 long newNum = cardnum;

/* calculate the number of digits in the card number provided by user */
while (newNum != 0) {
    newNum = (newNum - (newNum % 10))/10;
    numdig++;
}

newNum = cardnum;

/* calculate the first sum of product digits */
while (newNum != 0) {
     for (int x=1; x <= numdig; x++) {
         if (x % 2 == 0) {
             long twodignum = 2*(newNum % 10);
             if (twodignum >= 10) {
                 sumdig1 = sumdig1 + (twodignum % 10) + (twodignum - (twodignum % 10))/10;
             }
             else {
             sumdig1 = sumdig1 + twodignum;
             }
         }
         newNum = (newNum - (newNum % 10))/10;

     }
     /* printf("Sum of digit products: %i \n", sumdig1); */

 }

/* calculate the sum of digits that were not multiplied by 2 */
newNum = cardnum;
while (newNum != 0) {
    for (int p=1; p <= numdig; p++) {
        if (p % 2 != 0) {
            sumdig2 = sumdig2 + (newNum % 10);
        }
        newNum = (newNum - (newNum % 10))/10;
    }
}
sumdigfinal = sumdig1 + sumdig2;

/* for debugging only
printf("The sum of the remaining digits is: %i \n", sumdig2);
printf("The checksum value is: %i \n", sumdigfinal);
printf("Number of digits in card is: %i \n", numdig);
*/

/* calculate first two digits of card number */
newNum = cardnum;
while (newNum > 99) {
    newNum = (newNum - (newNum % 10))/10;
    firsttwodig = newNum;
}


/* determine if card # is valid and if so, what type of card it is */
if (sumdigfinal % 10 == 0) {
    if (numdig == 15 && (firsttwodig == 34 || firsttwodig == 37)) {
        printf("AMEX\n");
    }
    else if (numdig == 16 && (firsttwodig > 50 && firsttwodig < 56)) {
        printf("MASTERCARD\n");
    }
    else if ((numdig == 13 || numdig == 16) && (firsttwodig - (firsttwodig % 10)) == 40) {
        printf("VISA\n");
    }
    else {
        printf("INVALID\n");
    }
}
else if (sumdigfinal % 10 != 0) {
    printf("INVALID\n");
}

}