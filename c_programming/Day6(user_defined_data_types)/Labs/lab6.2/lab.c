#include<stdio.h>
#include"STD_TYPES.h"
typedef struct emplyees
{
    u16 salary ;
    u16 bonus ;
    u16 deduction;
}emplyees;

int main()
{
    emplyees Ahmed , Amr , Waleed;
    printf("Please Enter Ahmed Salary :");
    scanf("%hd",&Ahmed.salary);
    printf("Please Enter Ahmed Bonus :");
    scanf("%hd",&Ahmed.bonus);
    printf("Please Enter Ahmed Deduction:");
    scanf("%hd",&Ahmed.deduction);
    printf("Please Enter Amr Salary :");
    scanf("%hd",&Amr.salary);
    printf("Please Enter Amr Bonus :");
    scanf("%hd",&Amr.bonus);
    printf("Please Enter Amr Deduction:");
    scanf("%hd",&Amr.deduction);
    printf("Please Enter Waleed Salary :");
    scanf("%hd",&Waleed.salary);
    printf("Please Enter Waleed Bonus :");
    scanf("%hd",&Waleed.bonus);
    printf("Please Enter Waleed Deduction:");
    scanf("%hd",&Waleed.deduction);
    u64 total_value = Ahmed.bonus+Ahmed.salary-Ahmed.deduction+Amr.salary+Amr.bonus-Amr.deduction+Waleed.salary+Waleed.bonus-Waleed.deduction;
    printf("Total value needed is : %lld\n",total_value);
}
