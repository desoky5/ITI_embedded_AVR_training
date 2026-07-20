#include<stdio.h>
typedef struct 
{
    int hour ;
    int minute;
    int second;
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
    printf("Enter start time:");
    scanf("%d %d %d",&time1.hour,&time1.minute,&time1.second);
    printf("Enter end time :");
    scanf("%d %d %d",&time2.hour,&time2.minute,&time2.second);
    diff(time1,time2,&diff_struct);
    printf("TIME DIFFERENCE : %d:%d:%d - %d:%d:%d = %d:%d:%d\n",time1.hour,time1.minute,time1.second,time2.hour,time2.minute,time2.second,diff_struct.hour,diff_struct.minute,diff_struct.second);

}