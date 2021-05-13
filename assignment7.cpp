#include <iostream>
#include <string>
using namespace std;

class node
{
public:
    int seatcode;
    bool booking;
    node* pre;
    node* next;
};

class rows
{
public:
    node* start;
    node* last;
    static int counter;

    rows()
    {
        counter+=1;
        start = NULL;
        last = NULL;

        this->create(counter);
    }

    void create(int rowno)
    {
        int id=(10*rowno) + 1;
        for (int i=0;i<7;i++)
        {
            node* temp = new node;
            temp->booking = false;
            temp->seatcode = id;
            if (start == NULL)
            {
                start = temp;
                last = temp;
                last->next = start;
                start->pre = last;
            }
            else
            {
                last->next = temp;
                temp->pre = last;
                last = last->next;
                last->next = start;
                start->pre = last;
            }
            id+=1;

        }
    }

    void book()
    {
        int seatno,seatcount,direction;
        cout<<"From which seat do you want to book?"<<endl;
        cin>>seatno;
        cout<<"How many seats do you want to book?"<<endl;
        cin>>seatcount;
        cout<<"Which direction do you want to book?\n\t1.Right\n\t2.Left"<<endl;
        cin>>direction;
        node* temp=start;
        for(int i=1;i<seatno;i++)
        {
            temp=temp->next;
        }
        temp->booking=true;
        if(direction==1)
        {
            for(int j=1;j<seatcount;j++)
            {
                temp=temp->next;
                temp->booking=true;
            }
        }
        else if(direction==2)
        {
            for(int j=1;j<seatcount;j++)
            {
                temp=temp->pre;
                temp->booking=true;
            }
        }

        cout<<"Seats booked.\nSeatcode: ";
        this->dispseatcode();


    }

    void cancel()
    {
        int seatnos;
        cout<<"How many seats do you need to cancel?"<<endl;
        cin>>seatnos;
        for (int i=0;i<seatnos;i++)
        {
            int seating;
            node* current= start;
            cout<<"Enter the seat code: "<<endl;
            cin>>seating;
            do
            {
                if (current->seatcode == seating)
                {
                    if(current->booking==true)
                    {
                        current->booking=false;
                        break;
                    }
                    else
                    {
                        cout<<"This seat was never booked!"<<endl;
                    }
                }
                current=current->next;

            }while(current!=start);
        }
    }

    void dispseatcode()
    {
        node* temp=start;
        do
        {
            if(temp->booking==true)
            {
                cout<<temp->seatcode<<" ";
            }
            temp=temp->next;
        }while(temp!=start);
        cout<<endl;
    }
};
int rows::counter = 0;


void show(node* temp)
{
    node* n=temp;
    do
    {
        if (n->booking == false)
        {
            cout<<"O ";
        }
        else
        {
            cout<<"X ";
        }

        n=n->next;
    }while(n!=temp);
    cout<<endl;
}

int main()
{
    rows r1,r2,r3,r4,r5,r6,r7,r8,r9,r10;
    node *heads[10];
    heads[0]=r1.start;
    heads[1]=r2.start;
    heads[2]=r3.start;
    heads[3]=r4.start;
    heads[4]=r5.start;
    heads[5]=r6.start;
    heads[6]=r7.start;
    heads[7]=r8.start;
    heads[8]=r9.start;
    heads[9]=r10.start;
    while(1)
    {
        int choice;
        cout<<"What do you wish to perform?\n1.Book tickets.\n2.Cancel tickets.\n3.Display the seating arrangement\n4.Exit"<<endl;
        cout<<"\nEnter Choice: ";
        cin>>choice;
        if(choice==1)
        {
            int rowno;
            cout<<"Which row seats do you want to book? Enter row number(1-10): ";
            cin>>rowno;
            switch(rowno)
            {
            case 1:
                r1.book();
                break;
            case 2:
                r2.book();
                break;
            case 3:
                r3.book();
                break;
            case 4:
                r4.book();
                break;
            case 5:
                r5.book();
                break;
            case 6:
                r6.book();
                break;
            case 7:
                r7.book();
                break;
            case 8:
                r8.book();
                break;
            case 9:
                r9.book();
                break;
            case 10:
                r10.book();
                break;
            default:
                cout<<"Enter a valid row number please."<<endl;
            }
        }

        else if(choice==2)
        {
            int rowcan;
            cout<<"Which row tickets do you wish to cancel? Enter the row number(1-10): ";
            cin>>rowcan;
            switch(rowcan)
            {
            case 1:
                r1.cancel();
                break;
            case 2:
                r2.cancel();
                break;
            case 3:
                r3.cancel();
                break;
            case 4:
                r4.cancel();
                break;
            case 5:
                r5.cancel();
                break;
            case 6:
                r6.cancel();
                break;
            case 7:
                r7.cancel();
                break;
            case 8:
                r8.cancel();
                break;
            case 9:
                r9.cancel();
                break;
            case 10:
                r10.cancel();
                break;
            default:
                cout<<"Enter valid row number please."<<endl;
            }
        }
        else if(choice==3)
        {
            for (int i=0;i<10;i++)
            {
                show(heads[i]);
            }
        }
        else
        {
            cout<<"Enter a valid choice number please."<<endl;
        }
    }
    return 0;
}
