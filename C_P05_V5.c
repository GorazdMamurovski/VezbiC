#include <stdio.h>

int main()
{
    int i;
    i =0;
    while(i<100){
        if(i%3==0)
        {
            i++;
            continue;
        }
        else
        {
            printf("%d ne e deliv so 3\n",i);
        }
        i++;
    }

    return 0;
}
