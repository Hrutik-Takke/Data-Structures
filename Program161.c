
/////////////////////////////////////////////////////////////////////////////////
//  
//  Function Name : DisplayR
//  Input:
//  Output: 
//  Description : Display 4 stars using Recursion function.
//  Date: 05/08/2021
//  Author: Hrutik Takke
//
///////////////////////////////////////////////////////////////////////////////


#include<stdio.h>          // Recursion cha program

void DisplayI()            // Iteration
{
    int i = 0;             // Local variable
    
    //    1      2     3
    for(i = 1; i <= 4; i++)
    {
        printf("*\n");  // 4
    }
}

void DisplayR()            // Recursion
{
    static int i = 1;      // 1
    if(i <= 4)             // 2
    {
        printf("*\n");     // 4
        i++;               // 3
        DisplayR();        // Recursive call
    }
}

int main()
{
    DisplayR();
    return 0;
}