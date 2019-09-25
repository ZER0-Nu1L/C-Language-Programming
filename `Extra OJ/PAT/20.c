#include<stdio.h>
#include<ctype.h>

int main(void)
{
  int sum = 0;
  int num, op;
  char ch;

  while(isspace(ch = getchar()) )
    ;
  sum = ch - '0';
  
  while(1)
  {
    ch = getchar();
    if(ch <= '9' && ch >= '0')
    {
      num = ch - '0';
  
      switch(op)
      {
        case '+':sum += num;
            break;
        case '-':sum -= num;
            break;
        case '*':sum *= num;
            break;
        case '/':
          if(num == 0)
          {
            printf("ERROR\n");
            return 0;
          }
          sum /= num;
          break;
      }
    }
    else
    {
        op = ch;
        if(op == '=')
        {
          printf("%d", sum);
          break;
        }
        if(op != '+' && op != '-' && op != '*' && op != '/')
        {
          printf("ERROR\n");
          break;
        }
    }
  }
  
  return 0;
}
