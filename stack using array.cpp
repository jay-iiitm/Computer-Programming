#include<iostream>
using namespace std;

int stack[100],choice,n=100,top,x,i;
void push(void);
void pop(void);
void display(void);
int main()

{
	
	top=-1;
cout<<"\n1.PUSH\n 2.POP\n 3.DISPLAY\n 4.EXIT";

    do
    {
        cout<<"\n Enter the Choice:";
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                push();
                break;
            }
            case 2:
            {
                pop();
                break;
            }
            case 3:
            {
                display();
                break;
            }
            case 4:
            {
            cout<<"exit point";
                break;
            }
            default:
            {
                cout<<"\n Please Enter a Choice(1/2/3/4)";
            }
                
        }
    }
    while(choice!=4);
return 0;
}
void push()
{
    if(top>=n-1)
    {
        cout<<"\n\tSTACK is over flow";
        
    }
    else
    {
        cout<<" Enter a value to be pushed:";
        cin>>x;
        top+=1;
        stack[top]=x;
    }
}
 void pop()
{
    if(top<=-1)
    {
        cout<<"\n\t Stack is under flow";
    }
    else
    {
        cout<<"\n\t The popped elements is : " <<stack[top];
        top--;
    }
}

 void display()
{
    if(top>=0)
    {
        cout<<"\n The elements in STACK : ";
        for(i=top; i>=0; i--)
            cout<<stack[i]<<" ";
        cout<<"\n Press Next Choice";
    }
    else
    {
        cout<<"\n The STACK is empty";
    }
   
}

