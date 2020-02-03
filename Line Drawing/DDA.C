#include<stdio.h>
#include<quadrant.h>
#include<math.h>
#include<conio.h>
#include<dos.h>

#define round(a) ((int)(a+0.5))

union REGS i, o;
int x,y,button,status;
int initmouse()
{
   i.x.ax = 0;
   int86(0X33,&i,&o);
   return ( o.x.ax );
}

void showmouseptr()
{
   i.x.ax = 1;
   int86(0X33,&i,&o);
}

void getmousepos(int *button, int *x, int *y)
{
   i.x.ax = 3;
   int86(0X33,&i,&o);

   *button = o.x.bx;
   *x = o.x.cx;
   *y = o.x.dx;
}

void DDA(int xa,int ya,int xb,int yb)
{
int dx=xb-xa,dy=yb-ya,steps,k,j;
float xinc,yinc,x=xa,y=ya;

if(abs(dx) > abs(dy)) steps=abs(dx);
else steps=abs(dy);

xinc=dx/(float)(steps);
yinc=dy/(float)(steps);

putpixel(round(x),round(y),15);

for(k=0;k<steps;k++)
{
	x+=xinc;
	y+=yinc;
	putpixel(round(x),round(y),15);
}

}



void main()
{
int ch,xa,ya,xb,yb;
int gd=DETECT,gm;
initgraph(&gd,&gm,"c:\\tc\\bgi");

do{
clrscr();
cleardevice();
quad();
printf("\nMenu:-\n1.Line Drawing using Keyboard\n2.Line Drawing using Mouse\n3.Exit");
printf("\nEnter Your Choice:");
scanf("%d",&ch);
switch(ch)
{
	case 1:printf("Enter Coordinates:");
		scanf("%d%d%d%d",&xa,&ya,&xb,&yb);
		DDA(getmaxx()/2+xa,getmaxy()/2-ya,getmaxx()/2+xb,getmaxy()/2-yb);
		break;
	case 2:initmouse();
		showmouseptr();
		while(1)
		{
			getmousepos(&button,&x,&y);
			if((button&1)==1)
			{
				xa=x;
				ya=y;
				break;
			}
		}

		delay(100);
		putpixel(xa,ya,15);
		circle(xa,ya,4);
		getch();


		while(1)
		{
			getmousepos(&button,&x,&y);
			if((button&1)==1)
			{
				xb=x;
				yb=y;
				break;
			}
		}

		delay(100);
		putpixel(xb,yb,15);
		circle(xb,yb,4);
		getch();
		DDA(xa,ya,xb,yb);
		break;
	case 3:exit(0);
	default:printf("Invalid Choice!!!");
}
getch();
}while(ch!=3);

getch();
closegraph();
}
