#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>
#define SIZE 100
typedef struct Queue
{
    int array[100];
    int front,rear,count;
} Q;
Q q1,q2;
typedef struct patient
{
    char name[20];
    int age;
} P;
P p[100];
int T = 0,token=0;
COORD coord = {0, 0};
int t(void);
void gotoxy (int x, int y)
{
    coord.X = x;
    coord.Y = y; // X and Y coordinates
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void EnQ(Q *q,int n)
{
    if(q->count ==  SIZE -1)
    {
        printf("Queue Fillup");
        return ;
    }
    else
    {
        q->count= q->count+1;
        q->rear = ((q->rear)+1)%SIZE;
        q->array[q->rear]=n;
    }
}
int DeQ(Q *q)
{
    if(q->count == 0)
    {

        return -1;
    }
    else
    {
        int R=q->array[q->front];
        q->count= q->count-1;
        q->front = ((q->front)+1)% SIZE;
        return R;
    }
}
void view(void)
{
    gotoxy(25,22);
    printf("Patient waiting : %d", q1.count);
    printf("  ||  Patient in counter [Token No] : %d\n\n", token);


}

void menu()
{
    struct tm *ptr;
    time_t lt;
    lt=time(NULL);
    ptr=localtime(&lt);
    gotoxy(25,2);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Doctor's Chamber Management \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(25,4);
    printf("\xDB\xDB\xDB\xDB\xB2 1. New patient  ");
    gotoxy(25,6);
    printf("\xDB\xDB\xDB\xDB\xB2 2. Current serial");
    gotoxy(25,8);
    printf("\xDB\xDB\xDB\xDB\xB2 3. View Details");
    gotoxy(25,10);
    printf("\xDB\xDB\xDB\xDB\xB2 4.Exit  ");
    gotoxy(25,12);
    printf("---------------------------------------------------------------------");
    gotoxy(25,13);
    printf(asctime(ptr));

}
int main()
{
    q1.count = 0;
    q1.front= 0;
    q1.rear = -1;
    q2.count = 0;
    q2.front= 0;
    q2.rear = -1;
    int ch;
    int i=0;


    while(1)
    {
        getch();
        system("cls");
        menu();
        gotoxy(25,15);
        printf("Enter your choice: ");
        scanf("%d", &ch);
        getchar();
        if(ch == 4)
        {
            break;
        }
        else if(ch == 1)
        {

            T++;
            gotoxy(25,17);
            printf("Enter patient name : ");
            fflush(stdin);
            gets(p[i].name);
            gotoxy(25,19);
            printf("Enter patient Age : ");
            scanf("%d",&p[i].age);
            gotoxy(25,21);
            printf("\xB2 Token No : %d \xB2", T);
            EnQ(&q1, T);
            gotoxy(25,23);
            printf("Total patient : %d\n\n", q1.count);
            gotoxy(25,25);
            printf("Patient waiting : %d", q1.count);
            printf("  ||  Patient in counter [Token No] : %d\n\n", token);
            i++;


        }
        else if(ch == 2)
        {
            int r=DeQ(&q1);
            //printf("\nr: %d",r);
            EnQ(&q2,r);
            int s= DeQ(&q2);
            token = s;
            if(r == -1)
            {
                printf("Empty Queue");
                printf("  Waiting : %d", q1.count);
            }
            else
            {
                gotoxy(25,17);
                printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
                gotoxy(25,18);
                printf("\xB2");
                gotoxy(46,18);
                printf("\xB2");
                gotoxy(25,19);
                printf("\xB2");
                gotoxy(46,19);
                printf("\xB2");
                gotoxy(25,20);
                printf("\xB2");
                gotoxy(46,20);
                printf("\xB2");
                gotoxy(25,21);
                printf("\xB2");
                gotoxy(46,21);
                printf("\xB2");
                gotoxy(25,22);
                printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
                gotoxy(30,18);
                printf("Token No :" );
                gotoxy(33,19);
                printf("  %d", s);
                gotoxy(27,21);
                printf("Proceed To Counter");

                gotoxy(25,24);
                printf("Waiting : %d\n\n", q1.count);
            }
        }
        else if(ch==3)
        {
            gotoxy(25,18);
            printf("Patient waiting : %d", q1.count);
            printf("  ||  Patient in counter [Token No] : %d\n\n", token);
            int j=0;
            int z=22,x=25;
            gotoxy(30,20);
            printf("**** Patient's List ****    \n");
            if(i == 0)
            {
                gotoxy(25,22);
                printf("!! No Patient in the list !!\n\n");
            }
            else
            {
                for(j=0; j<i; j++)
                {
                    gotoxy(x,z);
                    printf("%d. Name : %s || Age : %d",j+1, p[j].name,p[j].age);
                    z++;
                }
            }
        }

    }
    return 0;

}
