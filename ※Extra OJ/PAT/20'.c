#include<stdio.h>
int main()
{
    int a,b;
    char c;
    scanf("%d",&a);
    while(scanf("%c",&c))
    {
    switch(c)
    {
        case('+'):scanf("%d",&b);a+=b;break;
        case('-'):scanf("%d",&b);a-=b;break;
        case('*'):scanf("%d",&b);a*=b;break;
        case('/'):scanf("%d",&b);if(b==0)
        {
            printf("ERROR");return 0;
        }else
        {
            a/=b;break;
        }
        case('='):printf("%d",a);return 0;
        default:printf("ERROR");return 0;
    }
    }
    return 0;
}
