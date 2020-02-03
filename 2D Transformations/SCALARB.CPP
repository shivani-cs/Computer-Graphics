#include<conio.h>
#include<stdio.h>
#include<iostream.h>
#include<graphics.h>
#include<dos.h>
#include<math.h>
#include<stdlib.h>
#define MAX 10

class pix
{
	int x,y;
   public:
	pix()
	{x=0;y=0;}
	int getx()
	{
	    cin>>x;
	    x=x+320;
	    return x;
	}
	int gety()
	{
	     cin>>y;
	     y=240-y;
	     return y;
	}
};

void quad()
{
	int i,j;
	char c[5];
	setcolor(1);
	line(0,240,640,240);
	line(320,0,320,480);
	setcolor(15);
	//X-axis co-ordinate
	for(i=20;i<=640;i+=30)
	{
		line(i,238,i,242);
		sprintf(c,"%d",i-320);
		if(i!=320)
		  outtextxy(i-10,246,c);
	}
	//Y-axis co-ordinate
	for(i=0;i<=480;i+=30)
	{
		line(318,i,322,i);
		sprintf(c,"%d",240-i);
		if(i!=240)
		  outtextxy(324,i,c);
	}
	outtextxy(324,246,"0");
}

void polygon(int n,int x[],int y[])
{
	int i;
	for(i=0;i<n-1;i++)
		line(x[i],y[i],x[i+1],y[i+1]);
	line(x[n-1],y[n-1],x[0],y[0]);
}

void scalearb(int n,int x[],int y[])
{
	int i,xn[MAX],yn[MAX],a,b;
	float sx,sy,j;
	pix p;
	cout<<"Enter the co-ordinate of arbitrary point";
	a=p.getx();
	b=p.gety();
	do
	{
	cout<<"Enter the scaling of x and y :\n";
	cin>>sx>>sy;
	}while(sx<0.0 || sy<0.0);
	cleardevice();
	quad();
	setcolor(2);
	polygon(n,x,y);
	if(sx>=1.0)
	{
	for(j=1.0;j<=sx;j=j+0.01)
	{
		cleardevice();
		quad();
		setcolor(1);
		outtextxy(0,0,"SCALING ABOUT ARBITRARY POINT");
		for(i=0;i<n;i++)
		   xn[i]=x[i]*j+a*(1-j);
		setcolor(5);
		polygon(n,xn,y);
		delay(200);
	}
	}
	else
	{
	for(j=1.0;j>=sx;j=j-0.01)
	{
		cleardevice();
		quad();
		setcolor(1);
		outtextxy(0,0,"SCALING ABOUT ARBITRARY POINT");
		for(i=0;i<n;i++)
		   xn[i]=x[i]*j+a*(1-j);
		setcolor(5);
		polygon(n,xn,y);
		delay(200);
	}
	}
	if(sy>=1.0)
	{
	for(j=1.0;j<=sy;j=j+0.01)
	{
		cleardevice();
		quad();
		setcolor(1);
		outtextxy(0,0,"SCALING ABOUT ARBITRARY POINT");
		for(i=0;i<n;i++)
		   yn[i]=y[i]*j+b*(1-j);
		setcolor(5);
		polygon(n,xn,yn);
		delay(200);
	}
	}
	else
	{
	for(j=1.0;j>=sy;j=j-0.01)
	{
		cleardevice();
		quad();
		setcolor(1);
		outtextxy(0,0,"SCALING ABOUT ARBITRARY POINT");
		for(i=0;i<n;i++)
		   yn[i]=y[i]*j+b*(1-j);
		setcolor(5);
		polygon(n,xn,yn);
		delay(200);
	}
	}
}

void main()
{
	int gd=DETECT,gm,x[MAX],y[MAX],i,n,op;
	pix p[MAX];
	initgraph(&gd,&gm,"C:\\TC\\BGI");
	quad();
ACCEPTn:	cout<<"Enter the no. of edges of polygon : ";
		cin>>n;
	if(n<3)
	{
	    cout<<"Invalid no. of edges\n";
	    goto ACCEPTn;
	}
	cout<<"Enter co-ordinates of "<<n<<" vertices\n";
	for(i=0;i<n;i++)
	{
		cout<<"Vertex "<<i+1<<" :\t";
		x[i]=p[i].getx();
		y[i]=p[i].gety();
	}
	setcolor(2);
	polygon(n,x,y);
	getch();
	while(1)
	{
	  cleardevice();
	  cout<<"SCALING\n1.About arbitrary point\n2.Exit\nEnter your choice :\t";
	  cin>>op;
	  setcolor(1);
	  switch(op)
	  {
		case 1:
		  scalearb(n,x,y);
		  getch();
		  break;
		case 2:
		  exit(0);
		default:
		  setcolor(15);
		  outtextxy(0,0,"Invalid option");
		  getch();
	  }
	}
}