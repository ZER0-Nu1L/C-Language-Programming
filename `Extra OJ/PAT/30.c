#include<stdio.h>
#include<stdbool.h>

int main(void)
{
  bool flag = false;
  int n;
  const char* read[10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
  int a = 0;
  
  scanf("%d", &n);
  if(n < 0)
  {
    printf("fu");
    flag = true;
  }
  while(n != 0)
  {
    a = n % 10;
    n /= 10;
    if(!flag)
    {
      flag = true;
      printf("%s", read[a]);
    }
    else
    	printf(" %s", read[a]);
  }
  return 0;
}
