#include<stdio.h>
struct Date
{
    int day;
    int month;
    int year;
   
};

 void initDate(struct Date* ptrDate)
    {
        ptrDate->day = 3;
        ptrDate->month = 3;
        ptrDate->year = 2024;
    }

   
    void acceptDateFromConsole(struct Date* ptrDate)
    {
        printf("ENTER DAY - ");
        scanf("%d",&ptrDate->day);
        printf("\nENTER MONTH - ");
        scanf("%d",&ptrDate->month );
        printf("\nENTER YEAR - ");
        scanf("%d",&ptrDate->year );
    }

     void printDateOnConsole(struct Date* ptrDate)
    {
       printf("DATE - %d / %d / %d \n",ptrDate->day,ptrDate->month,ptrDate->year);
    }




int main()
{
    int choice;
    struct Date d1;
    do
    {
        printf("0. EXIT\n");
        printf("1. SET DEFAULT DATE\n");
        printf("2. ENTER DATE\n");
        printf("3. DISPLAY DATE\n");
        printf("ENTER YOUR CHOICE\n");
        scanf("%d",&choice);

        switch(choice)
        {
            case 0:
                printf("THANK YOU FOR USING OUR APP......\n");
                break;
            
            case 1:
                initDate(&d1);
                break;

            case 2:
                acceptDateFromConsole(&d1);
                break;

            case 3:
                printDateOnConsole(&d1);
                break;

            default:
                printf("WRONG CHOICE ......\n");
                break;

        }
    }while(choice != 0);
    
    
}