#include <stdio.h>

void fibonaci() {
    int N ;
    printf("Tell the number of terms:");
    scanf(" %d",&N);
    int first_term = 0;
    int second_term = 1;

    for(int i = 0 ; i < N; i++)
    {
        printf("%d  %d \n",first_term,second_term);
        int new_term =  first_term + second_term;
        first_term = new_term;
        second_term = second_term + new_term;
    }
}
int main() {
    fibonaci();


    return 0;
}