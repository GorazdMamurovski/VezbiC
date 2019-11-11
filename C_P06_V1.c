#include <stdio.h>

int main()
{
    float cel1,cel2;
    int far;
    for(far =0;far<212;far++){
        cel1 = (5.0/9.0) * (far - 32);
        far++;
        cel2 = (5.0/9.0) * (far - 32);
        printf("%+10.3f %+10.3f\n",cel1,cel2);

    }
    return 0; /* uspeshen kraj */

}
