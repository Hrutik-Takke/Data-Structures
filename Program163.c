
/////////////////////////////////////////////////////////////////////////////////
//  
//  Function Name : DisplayR
//  Input: Integer
//  Output: 
//  Description : Accept a number from user and Display from that number to zero in reverse order using recursion function.
//  Date: 04/08/2021
//  Author: Hrutik Takke
//
///////////////////////////////////////////////////////////////////////////////

#include<stdio.h>

void DisplayI(int iNo)
{
    while(iNo > 0)
    {
        printf("%d\n",iNo);
        iNo--;
    }
}

void DisplayR(int iNo)
{
    if(iNo > 0)
    {
        printf("%d\n",iNo);
        iNo--;
        DisplayR(iNo);
    }
}

int main()
{
    int iValue = 0;
    printf("Enter number\n");
    scanf("%d",&iValue);
    
    DisplayR(iValue);
    
    printf("End of main\n");
    return 0;
}
