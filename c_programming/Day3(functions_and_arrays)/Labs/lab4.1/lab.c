//write a C code to calculate the area of Circle and Volume of a Cylinder.
#include<stdio.h>
float area_fun(float,float);

int main()
{
    float radius , height ;
    printf("Enter the radius of the circleylinder : ");
    scanf("%f",&radius);
    printf("Enter the height of the cylinder : ");
    scanf("%f",&height);
    area_fun(radius,height);

}

float area_fun(float radius , float height)
{
    float area , volume ;
    printf("The area of the circle is : %g cm^2\n",3.14*(radius*radius));
    printf("The volume of the cylinder is : %g cm^3\n",3.14*(radius*radius)*height);
}