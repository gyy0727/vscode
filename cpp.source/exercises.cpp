#include<stdio.h>
int main()
{
  float pi=3.14,r,h,Circumference,Circulararea,Spheresurfacearea,Spherevolum,Cylindervolume;
  printf("������Բ�İ뾶�͸ߣ�");
  scanf("%f%f",&r,&h);
  Circumference=2*pi*r;
  Circulararea=pi*r*r;
  Spheresurfacearea=4*pi*r*r;
  Spherevolum=4/3*pi*r*r*r;
  Cylindervolume=pi*r*r*h;
  printf("Բ�ܳ�Ϊ%.2f\n",Circumference);
  printf("Բ���Ϊ%.2f\n",Circulararea);
  printf("Դ�����Ϊ%.2f\n",Spheresurfacearea);
  printf("Բ�����Ϊ%.2f\n",Spherevolum);
  printf("Բ�����Ϊ%.2f\n",Cylindervolume);
  return 0;
}