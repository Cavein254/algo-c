#include <stdio.h>

/**
program to compute the area of a circle
**/
//a = pi r*2
double area_circle(double radius)
{
  return 3.14 * radius * radius;
}
int main(void)
{
  double radius;
  radius = 12;
  printf("Enter the radius to calculate \n");
  scanf("%lf", &radius);
  double area = area_circle(radius);
  printf("The area of the circle is %f \n", area);
  
}
