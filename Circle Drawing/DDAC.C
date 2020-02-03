#include<stdio.h>
#include<graphics.h>
#include<quadrant.h>
#include<dos.h>
#include<math.h>

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


void DDAC(float xc,float yc,float r)
{
	float x=r,y=0.0;
	float e;
	int n=0;
	while(pow(2,n++) < r);

	e = 1.0/(pow(2,n-1));

	do{
		x=x+e*y;
		y=y-e*x;
		delay(10);
		putpixel(xc+x,yc-y,15);
	}while(y<e || (r-x)>e);
}


void main()
{

int ch;
float xc,yc,r;
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
		scanf("%f%f",&xc,&yc);
		printf("\nEnter Radius:");
		scanf("%f",&r);
		DDAC(getmaxx()/2+xc,getmaxy()/2-yc,r);
		break;
	case 2:initmouse();
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


		while(1)
		{
			getmousepos(&button,&x,&y);
			if((button&1)==1)
			{
				break;
			}
		}

		delay(100);
		putpixel(x,y,15);
		circle(x,y,4);
		getch();
		r=sqrt((xc-x)*(xc-x)+(yc-y)*(yc-y));
		DDAC(xc,yc,r);
		break;
	case 3:exit(0);
	default:printf("Invalid Choice!!!");
}
getch();
}while(ch!=3);

closegraph();
}