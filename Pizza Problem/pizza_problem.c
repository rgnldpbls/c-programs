#include <stdio.h>

int main()
{
    int pizes, iprice;
    double Pi=3.14, area;
    double rad, fprice;
    double pten, ptwe, pfour;
    char name [80];
    
    printf("Please enter your username: ");
    scanf("%s",name);
    
    printf("Domino's offer three different sizes:\n");
    printf("10 inches diameter\n");
    printf("12 inches diameter\n");
    printf("14 inches diameter\n");
    
    printf("\nThe pizza costing:\n");
    printf("P178.00\tP259.00\tP314.00\n");
    
    printf("\nPlease input the diameter of the pizza: ");
    scanf("%d",&pizes);
    
    printf("Please enter the price of the pizza: ");
    scanf("%d",&iprice);
    
    rad=pizes/2;
    area=Pi*(rad*rad);
    fprice=iprice/area;
    
    printf("\nThe area of the pizza is %.2lf\n",area);
    printf("The price is %.2lf\n",fprice);
    
    switch(iprice)
    {
    case 178:
        rad=10/2;
        area=Pi*(rad*rad);
        pten=178/area;
            
        rad=12/2;
        area=Pi*(rad*rad);
        ptwe=178/area;
            
        rad=14/2;
        area=Pi*(rad*rad);
        pfour=178/area;
            
        if(pten<ptwe && pten<pfour)
        {
            printf("The price of 10 diameter inch pizza per square inch is P%.2lf and it is least expensive.",pten);
        }
        else if(ptwe<pten && ptwe<pfour)
        {
            printf("The price of 12 diameter inch pizza per square inch is P%.2lf and it is least expensive.",ptwe);
        }
        else if(pfour<pten && pfour<ptwe)
        {
            printf("The price of 14 diameter inch pizza per square inch is P%.2lf and it is least expensive.",pfour);
        }
        break;
    case 259:
        rad=10/2;
        area=Pi*(rad*rad);
        pten=259/area;
            
        rad=12/2;
        area=Pi*(rad*rad);
        ptwe=259/area;
            
        rad=14/2;
        area=Pi*(rad*rad);
        pfour=259/area;
        
         if(pten<ptwe && pten<pfour)
        {
            printf("The price of 10 diameter inch pizza per square inch is P%.2lf and it is least expensive.",pten);
        }
        else if(ptwe<pten && ptwe<pfour)
        {
            printf("The price of 12 diameter inch pizza per square inch is P%.2lf and it is least expensive.",ptwe);
        }
        else if(pfour<pten && pfour<ptwe)
        {
            printf("The price of 14 diameter inch pizza per square inch is P%.2lf and it is least expensive.",pfour);
        }
        break;
    case 314:
        rad=10/2;
        area=Pi*(rad*rad);
        pten=259/area;
            
        rad=12/2;
        area=Pi*(rad*rad);
        ptwe=259/area;
            
        rad=14/2;
        area=Pi*(rad*rad);
        pfour=259/area;
        
        if(pten<ptwe && pten<pfour)
        {
            printf("The price of 10 diameter inch pizza per square inch is P%.2lf and it is least expensive.",pten);
        }
        else if(ptwe<pten && ptwe<pfour)
        {
            printf("The price of 12 diameter inch pizza per square inch is P%.2lf and it is least expensive.",ptwe);
        }
        else if(pfour<pten && pfour<ptwe)
        {
            printf("The price of 14 diameter inch pizza per square inch is P%.2lf and it is least expensive.",pfour);
        }
        break;
    default:
        printf("Invalid Input!\nPlease Try Again.");
    }
    printf("\n\nThank you for using the program.");
    return 0;
}
