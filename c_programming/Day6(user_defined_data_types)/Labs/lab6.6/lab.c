#include<stdio.h>
typedef struct 
{
    char hour ;
    char minute;
    char second;
}time;

void diff(time time1,time time2,time * diff_struct)
{
    diff_struct->hour = time1.hour-time2.hour;
    diff_struct->minute = time1.minute-time2.minute;
    diff_struct->second = time1.second-time2.second;
}


int main()
{
    time time1;
    time time2;
    time diff_struct;
    printf("Enter hours of time1:");
    scanf("%hhd",&time1.hour);
    printf("Enter minutes of time1:");
    scanf("%hhd",&time1.minute);
    printf("Enter seconds of time1:");
    scanf("%hhd",&time1.second);
    printf("Enter hours of time2:");
    scanf("%hhd",&time2.hour);
    printf("Enter minutes of time2:");
    scanf("%hhd",&time2.minute);
    printf("Enter seconds of time2:");
    scanf("%hhd",&time2.second);
    diff(time1,time2,&diff_struct);
    printf("TIME DIFFERENCE : %d:%d:%d - %d:%d:%d = %d:%d:%d\n",time1.hour,time1.minute,time1.second,time2.hour,time2.minute,time2.second,diff_struct.hour,diff_struct.minute,diff_struct.second);

}