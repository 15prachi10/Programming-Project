#include <stdio.h>

int main()
{
    float Principle, Rate, Time, CI;
    
    /*Input Principle, Time and Rate*/
    printf("Enter Principle (amount): "); 
    scanf("%f", &Principle);
    printf("Enter Time: "); 
    scanf("%f", &Time);
    printf("Enter Rate: "); 
    scanf("%f", &Rate);
    
    /*Calculate compound interest*/
    CI = Principle * (pow((1 + Rate/100), Time));
    
    /*Print the resultant CI*/
    printf("Compound interest = %f", CI);
    
    

    return 0;
}
