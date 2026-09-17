#include<stdio.h>
int main()
{
int x, y, min;
printf("Enter x: ");
scanf("%d", &x);
printf("Enter y: ");
scanf("%d", &y);
if (x > y)
min = y;
else
min = x;
printf("The minimum of %d and %d is: %d\n", x, y, min);
return 0;
}

