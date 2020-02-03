#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>
#include<quadrant.h>
#include<dos.h>
union REGS i, o;

int initmouse()
{
   i.x.ax = 0;
   int86(51,&i,&o);
   return ( o.x.ax );
}

void showmouseptr()
{
   i.x.ax = 1;
   int86(51,&i,&o);
}

void getmousepos(int *button, int *x, int *y)
{
   i.x.ax = 3;
   int86(51,&i,&o);

   *button = o.x.bx;
   *x = o.x.cx;
   *y = o.x.dx;
}

void BRES(int xa,int ya,int xb,int yb)
{
	int dx=abs(xa-xb),dy=abs(ya-yb);
	if(dx>dy)
	{
		int p=2*dy-dx;
		int twody=2*dy;
		int twodydx=2*(dy-dx);
		int x,y,xend,yend;

		if(xa > xb)
		{
		x=xb;
		y=yb;
		xend=xa;
		yend=ya;
		}
		else
		{
		x=xa;
		y=ya;
		xend=xb;
		yend=yb;
		}
		putpixel(x,y,15);

		while(x < xend)
		{
		x++;
		if(p<0)
			p+=twody;
		else
		{
			if(y<=yend)
				y++;
			else
				y--;
			p+=twodydx;
		}
		putpixel(x,y,15);
		}
	}

	else
	{
		int p=2*dx-dy;
		int twodx=2*dx;
		int twodxdy=2*(dx-dy);
		int x,y,xend,yend;

		if(ya > yb)
		{
		y=yb;
		x=xb;
		yend=ya;
		xend=xa;
		}
		else
		{
		y=ya;
		x=xa;
		yend=yb;
		xend=xb;
		}
		putpixel(x,y,15);

		while(y < yend)
		{
		y++;
		if(p<0)
			p+=twodx;
		else
		{
			if(x<=xend)
				x++;
			else
				x--;
			p+=twodxdy;
		}
		putpixel(x,y,15);
		}
	}

}


void main()
{
int ch,xa,ya,xb,yb,button,x,y;
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
		BRES(getmaxx()/2+xa,getmaxy()/2-ya,getmaxx()/2+xb,getmaxy()/2-yb);
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
		BRES(xa,ya,xb,yb);
		break;
	case 3:exit(0);
	default:printf("Invalid Choice!!!");
}
getch();
}while(ch!=3);

getch();
closegraph();
}