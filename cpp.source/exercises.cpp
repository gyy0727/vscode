#include<stdio.h>
int main()
{
  float pi=3.14,r,h,Circumference,Circulararea,Spheresurfacearea,Spherevolum,Cylindervolume;
  printf("请输入圆的半径和高：");
  scanf("%f%f",&r,&h);
  Circumference=2*pi*r;
  Circulararea=pi*r*r;
  Spheresurfacearea=4*pi*r*r;
  Spherevolum=4/3*pi*r*r*r;
  Cylindervolume=pi*r*r*h;
  printf("圆周长为%.2f\n",Circumference);
  printf("圆面积为%.2f\n",Circulararea);
  printf("源表面积为%.2f\n",Spheresurfacearea);
  printf("圆球体积为%.2f\n",Spherevolum);
  printf("圆柱体积为%.2f\n",Cylindervolume);
  return 0;
}