#include <stdio.h>
int obratno(int);
int main()
{
    int broj;
    printf("vnesi broj:\n");
    scanf("%d",&broj);
    printf("brojot %d obratno e %d\n",broj,obratno(broj));
    return 0;
}
int obratno(int broj){
    int a,b,delenik,obratenBroj;
    obratenBroj=0;
    delenik=1;
    a=0;
    b=broj;
    while(b!=0){
        a++;
        b=b/10;
        delenik*=10;
    }
    delenik=delenik/10;
    while(a!=0)
    {
       obratenBroj=obratenBroj+((broj%10)*delenik);
       delenik/=10;
       broj/=10;
       a--;
    }

    return obratenBroj;
}

