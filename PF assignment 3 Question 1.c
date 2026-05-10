#include<stdio.h>

void calculateRepayment(float loan, float interestRate, int years)
{
    if(years == 0 || loan <= 0)
    {
        printf("Loan fully repaid or no years remaining\n");
        return;
    }

    float installment = 4000;

    float interest = loan * interestRate / 100;
    loan = loan + interest;

    loan = loan - installment;

    if(loan > 5000)
    {
        printf("Extra payment of 500 applied\n");
        loan = loan - 500;
    }

    if(loan < 0)
    {
        loan = 0;
    }

    printf("Year %d: Remaining loan = %f\n", years, loan);

    calculateRepayment(loan, interestRate, years - 1);
}

int main()
{
    float loan = 10000;
    float interestRate = 5;
    int years = 3;

    printf("Loan Repayment Schedule\n");
    printf("------------------------\n");

    calculateRepayment(loan, interestRate, years);

    return 0;
}