
/////////////////////////////////////////////////////////////////////////////////
//  
//  Function Name : StrlenR
//  Input: character[]
//  Output: Integer
//  Description : Accept a strig from user and return the length of string using recursion function.
//  Date: 05/08/2021
//  Author: Hrutik Takke
//
///////////////////////////////////////////////////////////////////////////////#include<stdio.h>
#include<stdlib.h>

int StrlenI(char *str)
{
    int iCnt = 0;
    while(*str != '\0')
    {
        iCnt++;
        str++;
    }
    return iCnt;
}

int StrlenR(char str[])
{
    static int iCnt = 0;
    if(*str != '\0')
    {
        iCnt++;
        str++;
        StrlenR(str);
    }
    return iCnt;
}

int main()
{
    char arr[30] = {'\0'};
    int iRet = 0;
    printf("Enter string\n");
    scanf(" %[^'\n']s",arr);
    
    iRet = StrlenI(arr);
    
    printf("String length is : %d\n",iRet);
    return 0;
}
 