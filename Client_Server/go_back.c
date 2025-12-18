
#include<stdio.h>
int main(){
    int w, s=0, ack, i;
    printf("enter window size\n");
    scanf("%d",&w);

    while(1){
        for(i = 0; i < w; i++){
            printf("Frame %d has been transmitted.\n", s);
            s++;

            if (s == 7)  // ✔ kept exactly like your program
                break;

        printf("\nPlease enter the last Acknowledgement received.\n");
        scanf("%d",&ack);

        if(ack == w)
            break;
        else
            s = ack;     // ✔ kept exactly like your program
    }
}
    return 0;
}
