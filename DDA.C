#include<stdio.h>
#include<conio.h>
#include<graphics.h>
int sign(int a);
void main()
{
 int ch,x,y,x1,x2,y1,y2,dx,dy,step,i,j,th;
 int gd = DETECT, gm = 0;
 detectgraph(&gd, &gm);
 initgraph(&gd,&gm, "C:\\TURBOC3\\BGI");
 printf("Enter type of line: \n1.Thin line \n2.Dotted line \n3.Dash line \n4.Thick line ");
 scanf("%d", &ch);
 printf("Enter the 1st points: ");
 scanf("%d %d",&x1,&y1);
 printf("Enter the 2nd points: ");
 scanf("%d %d",&x2,&y2);
 dx = x2-x1;
 dy = y2-y1;
 if(dx >= dy)
 step = dx;
 else
 step = dy;
 dx /= step;
 dy /= step;
 x = x1 + 0.5*sign(dx);
 y = y1 + 0.5*sign(dy);
 i = 1;
 switch(ch)
 {
 case 1:
 while(i<=step)
 {
  x = x+dx;
  y = y+dy;
  putpixel(x,y,RED);
  delay(50);
  i++;
 }
 break;
 case 2:
 while(i<=step)
 {
  x = x+2+dx;
  y = y+2+dy;
  putpixel(x,y,RED);
  delay(50);
  i++;
 }
 break;
 case 3:
 while(i<=step)
 {
  x = x+dx;
  y = y+dy;
  if(i%5)
  putpixel(x,y,RED);
  delay(50);
  i++;
 }
 break;
 case 4:
 printf("\nEnter thickness ");
 scanf("%d",&th);
 while(i<=step)
 {
  x = x+dx;
  y = y+dy;
  for(j=0;j<th;j++)
  putpixel(x+j,y,RED);
  delay(50);
  i++;
 }
 break;
 default:
 printf("Wrong choice");
 }
 getch();
}
int sign(int a)
{
 if(a>0)
 return 1;
 else if(a==0)
 return 0;
 else
 return -1;
}



