#include<stdio.h>
#include<conio.h>
#include<graphics.h>
void main()
{
 int x,y,xc,yc,rx,ry,p;
 int gd = DETECT, gm = 0;
 detectgraph(&gd,&gm);
 initgraph(&gd,&gm, "C:\\TURBOC3\\BGI");
 printf("\nEnter center coordinates: ");
 scanf("%d%d",&xc,&yc);
 printf("Enter axes: ");
 scanf("%d%d",&rx,&ry);
 x = 0;
 y = ry;
 p = (ry*ry)-(rx*rx*ry)+((rx*rx)/4);
 do
 {
  putpixel(xc+x, yc-y, 6);
  putpixel(xc-x, yc+y, GREEN);
  putpixel(xc+x, yc+y, GREEN);
  putpixel(xc-x, yc-y, 6);
  delay(50);
  if(p<0)
  {
   x++;
   p = p+(2*ry*ry*x)+(ry*ry);
  }
  else
  {
   x++;
   y--;
   p = p+(2*ry*ry*x+ry*ry)-(2*rx*rx*y);
  }
 }while((2*x*ry*ry)<(2*y*rx*rx));
 p = ((float)x+0.5)*((float)x+0.5)*ry*ry+(y-1)*(y-1)*rx*rx-rx*rx*ry*ry;
 do
 {
  putpixel(xc+x, yc-y, WHITE);
  putpixel(xc-x, yc+y, WHITE);
  putpixel(xc+x, yc+y, WHITE);
  putpixel(xc-x, yc-y, WHITE);
  delay(50);
  if(p>0)
  {
   y--;
   p = p-(2*rx*rx*y)+(rx*rx);
  }
  else
  {
   y--;
   x++;
   p = p+(2*ry*ry*x)-(2*rx*rx*y)-(rx*rx);
  }
 }while(y >= 0);
 getch();
}
