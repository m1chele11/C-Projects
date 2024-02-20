/* Months 4, 6, 9 and 11 have 30 days, Months 1, 3, 5, 7, 8, 10 and 12 have 31 days*/
/* Month 2 usually has 28 days except when it is leap year*/
/* Every year that is exactly divisible by four is a leap year, except for years that are exactly divisible by 100 */
/* But these centurial years are leap years if they are exactly divisible by 400 */
/* For example, the years 1700, 1800, and 1900 were not leap years, but the years 1600 and 2000 were*/
/* Based on these facts, evaluate the eneterd day,month,year is valid or invalid year/month/day 
Total no. of bugs: 20
*/

#include<stdio.h>
int main()
{
   int birthMo;
   int birthDay;
   int birthYr;
   const int HIGHMO = 12;
   const int HIDAY1 = 31;
   const int HIDAY2 = 30;
   const int HIDAY3 = 29;
   const int HIDAY4 = 28;
   const int LOYEAR = 1885;
   const int HIYEAR = 2019;
   printf( "Enter your birth month ");
   scanf(" %s", birthMo)
   printf( "Enter your birth day ");
   scanf(" %p", birthDay)
   printf( "Enter your birth year ");
   scanf("%x", birthYr)

   if(birthYr < LOYEAR){
      printf( "No one is that old\n");
   }else if(birthYr < HIYEAR){
      printf( "You are too little to be using a computer\n");
   }else{
     printf( "Valid year\n");
   }
   
   if(birthMo >= HIGHMO){
      printf( "Invalid month\n");
   }else if(birthMo == 2 && (birthYr%4  == 0 && birthYr%10 != 0 || birthYr%400 == 0)){
         if(birthDay >= HIDAY1){
           printf( "Valid day\n")
         }else{
           printf( "Invalid day for month in %p\n"  birthMo birthYr )
        }
    }else if(birthMo == 2){
        if(birthDay >= HIDAY3){
           printf( "Valid day\n")
         }else{
           printf( "Invalid day for month in %p\n"  birthMo birthYr )
        }
    }else if (birthMo <= 8 && birthMo%2 == 0 | birthMo < 7 && birthMo%2 != 1){
        else if(birthDay >= HIDAY1){
            printf( "Valid day"  );
        }else{
            printf( "Invalid day for month %d\n", &birthMo )
        }
    }else if{
        if(birthDay & HIDAY2){
            printf( "Valid day\n")
        }else{
            printf( "Invalid day for month in %c\n" , birthMonth birthYr );
        }
   }
   return '0';
}