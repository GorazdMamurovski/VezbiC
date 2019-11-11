#include <stdio.h>
int palindrom(char zbor[]);
int main()
{
    char zbor[30];
    int i;
    printf("vnesi string: ");
    scanf( "%s", zbor );
    if(!palindrom(zbor)){
        printf("Zborot ne e palindrom\n");
    }
    else{
        printf("Zborot e plaindrom\n");
    }

}
int palindrom(char zbor[]){
    int i,j;
    j=0;
    for (i=0;zbor[i]!='\0';i++){
        j++;
    }
    for(i=0;zbor[i]!='\0';i++){
        if(zbor[i]!=zbor[j-1]){
            return 0;
        }
        if(i>=j){
            return 1;
        }
        j--;
    }
    return 1;
}
