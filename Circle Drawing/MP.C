#include<stdio.h>
#include<graphics.h>
#include<quadrant.h>
#include<dos.h>

union REGS i,o;
int x,y,button;

int initmouse()
{
	i.x.ax=0;
	int86(51,&i,&o);
	return (o.x.ax);
}

void showmouseptr()
{
	i.x.ax=1;
	int86(51,&i,&o);
}

void getmousepos(int *button,int *x,int *y)
{
	i.x.ax=3;
	int86(51,&i,&o);
	*button = o.x.bx;
	*x = o.x.cx;
	*y = o.x.dx;
}


void plot(int xc,int yc,int x,int y)
{
	putpixel(xc + x , yc + y ,15);
	putpixel(xc - x , yc + y ,15);
	putpixel(xc + x , yc - y ,15);
	putpixel(xc - x , yc - y ,15);
	putpixel(xc + y , yc + x ,15);
	putpixel(xc - y , yc + x ,15);
	putpixel(xc + y , yc - x ,15);
	putpixel(xc - y , yc - x ,15);

}

void MP(int xc,int yc,int r)
{
int x=0,y=r;
int p=1-r;

plot(xc,yc,x,y);

while(x<y)
{
	x++;
	if(p<0)
		p += 2*x+1;
	else
	{
		y--;
		p += 2*(x-y)+1;
	}
	plot(xc,yc,x,y);
	delay(50);
}
}


void main()
{

int ch;
int xc,yc,r;
int gd=DETECT,gm;
initgraph(&gd,&gm,"c:\\tc\\bgi");

do{
clrscr();
cleardevice();
quad();
printf("\nMenu:-\n1.Circle Drawing using Keyboard\n2.Circle Drawing using Mouse\n3.Exit");
printf("\nEnter Your Choice:");
scanf("%d",&ch);
switch(ch)
{
	case 1:printf("\nEnter Center Coordinates:");
		scanf("%d%d",&xc,&yc);
		printf("\nEnter Radius:");
		scanf("%d",&r);
		MP(getmaxx()/2+xc,getmaxy()/2-yc,r);
		break;
	case 2: printf("\nEnter Radius:");
		scanf("%d",&r);
		initmouse();
		showmouseptr();
		while(1)
		{
			getmousepos(&button,&x,&y);
			if((button&1)==1)
			{
				xc=x;
				yc=y;
				break;
			}
		}

		delay(100);
		putpixel(xc,yc,15);
		circle(xc,yc,4);
		getch();
		MP(xc,yc,r);
		break;
	case 3:exit(0);
	default:printf("Invalid Choice!!!");
}
getch();
}while(ch!=3);

closegraph();
}