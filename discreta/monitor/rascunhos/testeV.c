#include <stdio.h>
#include <stdlib.h>

int vaca(int a);

int main(void)
{
     
  int i = 0;
  int x = 0, y = 0, a = 5;
  
  int result = 0;

  
//  result = vaca(a);

  for(i = 0; i < 10; i++)
  {
  //    result = vaca(a);

      if(vaca(a) == 1)
      {
         x++;

      }
      else
      {
        y++;
      
      }

  
     printf("result = %d \n", vaca(a));
  }

    printf("\nx = %d e y = %d \n", x, y);

   return 0;
}


int vaca(int a)
{
    int i = 0;

    for(i = 0; i < 10; i++)
    {
        if(a > 3)
         {
            return 1;
         
         }
        
        else
        {  
            return 0;

        }
    }

   
  return 0;

}
