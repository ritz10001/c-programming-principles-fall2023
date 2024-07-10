#include<stdio.h>

int main(){


    int hours;
    int minutes;
    char *ampm;

    printf("enter the hours part of the time\n");

    scanf("%d", &hours);

    printf("enter the minutes part of the time\n");

    scanf("%d", &minutes);

    if(hours>23 || minutes>59 || minutes<0 || hours<0){
        printf("invalid format. \n");
        return 0;
    }
    else if(hours==0){
        ampm="AM";
    }
   
    else if(hours>=12){
        ampm = "PM";
    }
    else if(hours<12){
        ampm = "AM";
    }

    printf("the time in the required format %d:%d %s", (hours==0 || hours==12)?12:hours%12, minutes, ampm);

    return 0;

}