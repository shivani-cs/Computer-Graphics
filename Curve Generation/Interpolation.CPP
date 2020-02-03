#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<stdlib.h>
#include<math.h>

void flower()
{
	int x[5],y[5],px,py,i,ry,rx,sx,sy;
	float j;
	double t;
	x[0]=320,x[1]=280,x[2]=320,x[3]=360,x[4]=320;
	y[0]=240,y[1]=160,y[2]=80,y[3]=160,y[4]=240;
	setcolor(13);
	outtextxy(320,0,"FLOWER");
	setcolor(GREEN);
	line(x[0],y[0],x[0],y[0]+220);
	for(j=0.0;j<6.2;j+=(3.14/6))
	{
	for(t=0.0;t<=1.0;t+=0.001)
	{
		px=(1-t)*(1-t)*(1-t)*(1-t)*x[0]+4*(1-t)*(1-t)*(1-t)*t*x[1]+6*(1-t)*(1-t)*t*t*x[2]+4*(1-t)*t*t*t*x[3]+t*t*t*t*x[4];
		py=(1-t)*(1-t)*(1-t)*(1-t)*y[0]+4*(1-t)*(1-t)*(1-t)*t*y[1]+6*(1-t)*(1-t)*t*t*y[2]+4*(1-t)*t*t*t*y[3]+t*t*t*t*y[4];
		rx=320+(px-320)*cos(j)-(py-240)*sin(j);
		ry=240+(px-320)*sin(j)+(py-240)*cos(j);
		putpixel(rx,ry,5);
		delay(1);
	}
	}
	for(j=0;j<6.2;j+=(3.14/6))
	{
		sx=320+cos(j)+60*sin(j);
		sy=240+sin(j)-60*cos(j);
		setfillstyle(10,5);
		floodfill(sx,sy,5);
	}
	setcolor(14);
	circle(320,240,15);
	setfillstyle(9,14);
	floodfill(320,240,14);
	x[0]=320,y[0]=400,x[1]=360,y[1]=380,x[2]=400,y[2]=420;
	for(t=0.0;t<=1.0;t+=0.001)
	{
		px=(1-t)*(1-t)*x[0]+2*(1-t)*t*x[1]+t*t*x[2];
		py=(1-t)*(1-t)*y[0]+2*(1-t)*t*y[1]+t*t*y[2];
		putpixel(px,py,2);
		delay(1);
	}
	x[0]=400,y[0]=420,x[1]=360,y[1]=440,x[2]=340,y[2]=393;
	for(t=0.0;t<=1.0;t+=0.001)
	{
		px=(1-t)*(1-t)*x[0]+2*(1-t)*t*x[1]+t*t*x[2];
		py=(1-t)*(1-t)*y[0]+2*(1-t)*t*y[1]+t*t*y[2];
		putpixel(px,py,2);
		delay(1);
	}
	setfillstyle(9,GREEN);
	floodfill(350,400,2);
}

void marigold()
{
	int x[5],y[5],px,py,i,fy,fx,sx,sy;
	float j;
	double t;
	x[0]=320,x[1]=300,x[2]=320,x[3]=360,x[4]=320;
	y[0]=240,y[1]=400,y[2]=80,y[3]=160,y[4]=240;
	setcolor(13);
	outtextxy(320,0,"MARIGOLD");
	setcolor(GREEN);
	line(x[0],y[0],x[0],y[0]+220);
	for(j=0;j<6.2;j+=(3.14/24))
	{
	for(t=0.0;t<=1.0;t+=0.001)
	{
		px=(1-t)*(1-t)*(1-t)*(1-t)*x[0]+4*(1-t)*(1-t)*(1-t)*t*x[1]+6*(1-t)*(1-t)*t*t*x[2]+4*(1-t)*t*t*t*x[3]+t*t*t*t*x[4];
		py=(1-t)*(1-t)*(1-t)*(1-t)*y[0]+4*(1-t)*(1-t)*(1-t)*t*y[1]+6*(1-t)*(1-t)*t*t*y[2]+4*(1-t)*t*t*t*y[3]+t*t*t*t*y[4];
		fx=320+(px-320)*cos(j)-(py-240)*sin(j);
		fy=240+(px-320)*sin(j)+(py-240)*cos(j);
		putpixel(fx,fy,14);
		delay(1);
	}
	}
	setcolor(6);
	circle(320,240,15);
	setfillstyle(10,6);
	floodfill(320,240,6);
	x[0]=320,y[0]=400,x[1]=360,y[1]=380,x[2]=400,y[2]=420;
	for(t=0.0;t<=1.0;t+=0.001)
	{
		px=(1-t)*(1-t)*x[0]+2*(1-t)*t*x[1]+t*t*x[2];
		py=(1-t)*(1-t)*y[0]+2*(1-t)*t*y[1]+t*t*y[2];
		putpixel(px,py,2);
		delay(1);
	}
	x[0]=400,y[0]=420,x[1]=360,y[1]=440,x[2]=340,y[2]=393;
	for(t=0.0;t<=1.0;t+=0.001)
	{
		px=(1-t)*(1-t)*x[0]+2*(1-t)*t*x[1]+t*t*x[2];
		py=(1-t)*(1-t)*y[0]+2*(1-t)*t*y[1]+t*t*y[2];
		putpixel(px,py,2);
		delay(1);
	}
	setfillstyle(9,GREEN);
	floodfill(350,400,2);
}

void seaside()
{
	int x[5],y[5],px,py,i,j;
	double t;
//	cout<<"Enter control points of curve";
	x[0]=0,x[1]=160,x[2]=320,x[3]=480,x[4]=640;
	y[0]=300,y[1]=150,y[2]=580,y[3]=210,y[4]=320;
/*	for(i=0;i<5;i++)
		cin>>x[i]>>y[i];
*/
	setcolor(6);
	line(80,260,420,260);
	line(130,360,370,360);
	line(80,260,130,360);
	line(420,260,370,360);
	setfillstyle(2,6);
	floodfill(300,300,6);
	for(j=0;j<=60;j+=10)
	{
	for(t=0.0;t<=1.0;t+=0.001)
	{
		px=(1-t)*(1-t)*(1-t)*(1-t)*x[0]+4*(1-t)*(1-t)*(1-t)*t*x[1]+6*(1-t)*(1-t)*t*t*x[2]+4*(1-t)*t*t*t*x[3]+t*t*t*t*x[4];
		py=(1-t)*(1-t)*(1-t)*(1-t)*y[0]+4*(1-t)*(1-t)*(1-t)*t*y[1]+6*(1-t)*(1-t)*t*t*y[2]+4*(1-t)*t*t*t*y[3]+t*t*t*t*y[4]+j;
		putpixel(px,py,BLUE);
		delay(1);
	}
	}
	line(0,300,0,480);
	line(640,300,640,480);
	line(0,480,640,480);
	for(j=0;j<=60;j+=10)
	{
	setfillstyle(1,CYAN);
	floodfill(0,305+j,1);
	}
	x[0]=500,y[0]=70,x[1]=520,y[1]=80,x[2]=540,y[2]=50;
	for(t=0.0;t<=1.0;t+=0.001)
	{
		px=(1-t)*(1-t)*x[0]+2*(1-t)*t*x[1]+t*t*x[2];
		py=(1-t)*(1-t)*y[0]+2*(1-t)*t*y[1]+t*t*y[2];
		putpixel(px,py,7);
		delay(1);
	}
	x[0]=500,y[0]=70,x[1]=530,y[1]=90,x[2]=540,y[2]=50;
	for(t=0.0;t<=1.0;t+=0.001)
	{
		px=(1-t)*(1-t)*x[0]+2*(1-t)*t*x[1]+t*t*x[2];
		py=(1-t)*(1-t)*y[0]+2*(1-t)*t*y[1]+t*t*y[2];
		putpixel(px,py,7);
		delay(1);
	}
	setfillstyle(1,7);
	floodfill(520,70,7);
	for(j=0;j<=20;j++)
	putpixel(random(640),random(250),7);
}

void main()
{
	int gd=DETECT,gm,op;
	initgraph(&gd,&gm,"C:\\TC\\BGI");
	while(1)
	{
	  cleardevice();
	  cout<<"INTERPOLATION\n1.Simple Flower\n2.Marigold Flower\n3.Seaside(Waves)\n4.Exit\nEnter your choice :\t";
	  cin>>op;
	  cleardevice();
	  switch(op)
	  {
		case 1:
		  flower();
		  getch();
		  break;
		case 2:
		  marigold();
		  getch();
		  break;
		case 3:
		  seaside();
		  getch();
		  break;
		case 4:
		  exit(0);
		default:
		  setcolor(15);
		  outtextxy(0,0,"Invalid option");
		  getch();
	  }
	}
}