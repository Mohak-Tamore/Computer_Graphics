#include<stdio.h>
#include<conio.h>
#include<graphics.h>

void flood(int x,int y,int fc,int dc)
{
 if(getpixel(x,y) == dc && getpixel(x,y) != fc)
 {
  putpixel(x,y,fc);
  flood(x+1,y,fc,dc);
  delay(10);
  flood(x-1,y,fc,dc);
  delay(10);
  flood(x,y+1,fc,dc);
  delay(10);
  flood(x,y-1,fc,dc);
  delay(10);
//  flood(x+1,y+1,fc,dc);
//  flood(x+1,y-1,fc,dc);
//  flood(x-1,y+1,fc,dc);
//  flood(x-1,y-1,fc,dc);
 }
}

void boundary(int x,int y,int fc,int bc)
{
 if(getpixel(x,y) != bc && getpixel(x,y) != fc)
 {
  putpixel(x,y,fc);
  boundary(x+1,y,fc,bc);
  boundary(x,y+1,fc,bc);
  boundary(x-1,y,fc,bc);
  boundary(x,y-1,fc,bc);
 }
}

void main()
{
 int xc,yc,r,l,b,l1,l2,b1,b2;
 int gm=0, gd = DETECT;
 initgraph(&gd,&gm, "C:\\TURBOC3\\BGI");
 printf("\nEnter center coordinates: ");
 scanf("%d%d",&xc,&yc);
 printf("\nEnter radius: ");
 scanf("%d",&r);
 printf("\nEnter length coordinates: ");
 scanf("%d%d",&l1,&l2);
 printf("Enter breadth coordinates: ");
 scanf("%d%d",&b1,&b2);
 rectangle(l1,l2,b1,b2);
 circle(xc,yc,r);
 flood(xc,yc,6,15);
 l = (l1+l2)/2;
 b = (b1+b2)/2;
 boundary(l,b,6,15);
 getch();
}