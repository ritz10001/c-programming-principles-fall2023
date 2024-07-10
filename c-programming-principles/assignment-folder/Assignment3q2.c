#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>



int main(){

    int times;
    printf("Enter number of moves: ");
    scanf("%d", &times);
    if(times<=0){
        printf("That's an invalid number!\n");
        return 0;
    }
    srand(time(0));

    int x=0;
    int y=0;
    float distance;
    int randomnum;

    for(int i=0;i<times;i++){
        randomnum = rand()%4; //0:South, 1:North, 2:West, 3:East
        if(randomnum==0){
            y+=-1;
            printf("Move South at point (%d,%d)\n",x,y);
        }
        else if(randomnum==1){
            y+=1;
            printf("Move North at point (%d,%d)\n",x,y);
        }
        else if(randomnum==2){
            x+=-1;
            printf("Move West at point (%d,%d)\n",x,y);
        }
        else if(randomnum==3){
            x+=1;
            printf("Move East at point (%d,%d)\n",x,y);
        }

    }
    distance=sqrt(pow(x,2)+pow(y,2));
    printf("The distance from origin = %f \n", distance);
    
    return 0;
}