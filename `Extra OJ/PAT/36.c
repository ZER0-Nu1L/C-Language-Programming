#include<stdio.h>

int main(void)
{
  int i = 1;
  int sum = 0;
  while(1)
  {
    sum = i * 11 + 10;
    if( sum % 7 ==4 && sum % 6 == 5 && sum % 5 == 1)
    {
      printf("%d", sum);
      break;
    }
    i++;
  }
  
  return 0;
}
