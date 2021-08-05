
/////////////////////////////////////////////////////////////////////////////////
//  
//  Function Name : SumDigitR
//  Input: Integer
//  Output: Integer
//  Description : Accept a number from user and return the addition of digit using recursion function.
//  Date: 05/08/2021
//  Author: Hrutik Takke
//
///////////////////////////////////////////////////////////////////////////////

// Addition of all digits of number
// Input : 5328
// Output : 18

#include<stdio.h>

int SumDigitR(int iNo)
{
    static int iSum = 0;
    if(iNo != 0)
    {
        iSum = iSum + (iNo % 10);
        iNo = iNo / 10;
        SumDigitR(iNo);
    }
    return iSum;
}

int SumDigitI(int iNo)
{
    int iSum = 0;
    while(iNo != 0)
    {
        iSum = iSum + (iNo % 10);
        iNo = iNo / 10;
    }
    return iSum;
}
   
int main()
{
    int iValue = 0, iRet = 0;
    printf("Enter number\n");
    scanf("%d",&iValue);
    
    iRet = SumDigitR(iValue);
    printf("Addition of digits is : %d\n",iRet);
    
    return 0;
}
