
/////////////////////////////////////////////////////////////////////////////////
//  
//  Function Name : main
//  Input:--
//  Output:--
//  Description : Create a Singly circular Linked List in C++ to perform All functions.
//  Date: 04/08/2021
//  Author: Hrutik Takke
//
///////////////////////////////////////////////////////////////////////////////

// Singly Circular Linked List

#include<iostream>
using namespace std;

typedef struct node
{
   int data;
   struct node *next;
}NODE,*PNODE;

class SinglyCL
{
 private:
    PNODE Head;
    PNODE Tail;
    int iSize;
    
 public:
    SinglyCL()
    {
        Head = NULL;
        Tail = NULL;
        iSize = 0;
    }
    
    void InsertFirst(int iNo)
    {
        PNODE newn = NULL;
        
        newn = new NODE;
        newn->data = iNo;
        newn->next = NULL;
        
        if((Head == NULL) && (Tail == NULL))    // LL is empty
        {
            Head = newn;
            Tail = newn;
        }
        else    // LL contains atleast one node
        {
            newn->next = Head;
            Head = newn;
        }
        iSize++;
        Tail -> next = Head;
    }
    
    void InsertLast(int iNo)
    {
        PNODE newn = NULL;
        
        newn = new NODE;
        newn->data = iNo;
        newn->next = NULL;
        
        if((Head == NULL) && (Tail == NULL))    // LL is empty
        {
            Head = newn;
            Tail = newn;
        }
        else    // LL contains atleast one node
        {
            Tail->next = newn;
            Tail = Tail->next;      // Tail = newn;
        }
        iSize++;
        Tail -> next = Head;
    }
    
    int Count()
    {
        return iSize;
    }
    
    void Display()
    {
        PNODE temp = Head;
        int i = 0;
        for(i=1; i <= iSize; i++)
        {
            cout<<temp->data<<"\t";
            temp = temp -> next;
        }
        cout<<"\n";
    }
    
    void DeleteFirst()
    {
        if(iSize == 0)    // Empty LL
        {
            return;
        }
        else if(iSize == 1)   // Single node    if (Head == Tail)
        {
            delete Head;
            Head = NULL;
            Tail = NULL;
            iSize--;
        }
        else        // More than one node
        {
            Head = Head -> next;
            delete(Tail->next);
            Tail->next = Head;
            iSize--;
        }
    }
    
    void DeleteLast()
    {
        if(iSize == 0)    // Empty LL
        {
            return;
        }
        else if(iSize == 1)   // Single node
        {
            delete Head;
            Head = NULL;
            Tail = NULL;
            iSize--;
        }
        else        // More than one node
        {
            PNODE temp = Head;
            int i = 0;
            for(i = 1; i < iSize-1; i++)
            {
                temp = temp -> next;
            }
            delete Tail;
            Tail = temp;
            Tail->next = Head;
            iSize--;
        }
    }

    void InsertAtPos(int iPos, int iValue)
     {
       int i = 0;
       PNODE Temp = Head;
       PNODE Newn = NULL;
       Newn = new NODE;
       Newn->data = iValue;
       Newn->next = NULL;

       if((iPos < 0) || (iPos > iSize+1))
       {
         return;
       }
       if(iPos == 1)
       {
          InsertFirst(iValue);
       }
       else if(iPos == iSize+1)
       {
         InsertLast(iValue);
       }
       else
       {
          for(i = 1; i< iPos-1; i++)
          {
             Temp = Temp->next;
          }
          Newn->next = Temp->next;
          Temp->next = Newn;
          iSize++;
       }
     }

     void DeleteAtPos(int iPos)
     {
       int i = 0;
       PNODE Target = NULL;
       PNODE Temp = Head;

       if((iPos < 0) || (iPos > iSize))
       {
         return;
       }
       if(iPos == 1)
       {
          DeleteFirst();
       }
       else if(iPos == iSize)
       {
         DeleteLast();
       }
       else
       {
          for(i=1; i< iPos-1 ; i++)
          {
            Temp = Temp->next;  
          }
           Target = Temp->next;
           Temp->next = Target->next;
           delete(Target); 
           iSize--;
       }
     }
};

int main()
{
    SinglyCL obj;
    int iChoice = 1, iRet = 0, iPos = 0, iValue = 0;
    
    while(iChoice != 0)
    {
        cout<<"Enter your choice\n";
        cout<<"1 : Insert First\n";
        cout<<"2 : Insert Last\n";
        cout<<"3 : Insert at position\n";
        cout<<"4 : Delete first \n";
        cout<<"5 : Delete Last\n";
        cout<<"6 : Delete at position \n";
        cout<<"7 : Display the contents\n";
        cout<<"8 : Count the elements\n";
        cout<<"0 : Exit the application\n";
        cin>>iChoice;
        
        switch(iChoice)
        {
            case 1:
                cout<<"Enter number\n";
                cin>>iValue;
                obj.InsertFirst(iValue);
                break;
                
            case 2:
                cout<<"Enter number\n";
                cin>>iValue;
                obj.InsertLast(iValue);
                break;
                
            case 3:
                cout<<"Enter number\n";
                cin>>iValue;
                cout<<"Enter position\n";
                cin>>iPos;
                obj.InsertAtPos(iValue,iPos);
                break;
                
            case 4:
                obj.DeleteFirst();
                break;
                
            case 5:
                obj.DeleteLast();
                break;
                
            case 6:
                cout<<"Enter the position\n";
                cin>>iPos;
                obj.DeleteAtPos(iPos);
                break;
                
            case 7:
               obj.Display();
                break;
                
            case 8:
               iRet = obj.Count();
                cout<<"Number of nodes are : "<<iRet<<"\n";
                break;
                
            case 0:
                cout<<"Thank you for using the application\n";
                break;
                
            default:
                cout<<"Please enter proper option\n";
                break;
        }// End of switch
    }// End of while
    return 0;
} // End of main































