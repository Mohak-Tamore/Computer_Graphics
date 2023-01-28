#include<stdio.h>
#include<graphics.h>
#include<dos.h>
void main()
{
 int x,y,xc,yc,r;
 int gm = 0,gd = DETECT;
 initgraph(&gd,&gm,"C:\\TURBOC3\\bgi");
 printf("\nEnter center of circle: ");
 scanf("%d%d",&xc,&yc);
 printf("\nEnter radius of circle: ");
 scanf("%d",&r);
 circle(x,y,r);
 if(getpixel(x,y)!=WHITE && getpixel(x,y)!=RED)
 {
  putpixel(x,y,RED);
  boundaryfill(x+1,y,RED,WHITE);
  boundaryfill(x,y+1,RED,WHITE);
  boundaryfill(x-1,y,RED,WHITE);
  boundaryfill(x,y-1,RED,WHITE);
 }
delay(50);
}