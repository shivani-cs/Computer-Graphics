#include<conio.h>
#include<stdio.h>
#include<iostream.h>
#include<graphics.h>
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

void refx(int n,int x[],int y[])
{
	int i,xn[MAX],yn[MAX];
	outtextxy(20,10,"REFLECTION about X-AXIS");
	for(i=0;i<n;i++)
	  yn[i]=480-y[i];
	setcolor(6);
	polygon(n,x,yn);
}

void refy(int n,int x[],int y[])
{
	int i,xn[MAX],yn[MAX];
	outtextxy(20,10,"REFLECTION about Y-AXIS");
	for(i=0;i<n;i++)
	  xn[i]=640-x[i];
	setcolor(5);
	polygon(n,xn,y);
}

void refo(int n,int x[],int y[])
{
	int i,xn[MAX],yn[MAX];
	outtextxy(20,10,"REFLECTION about ORIGIN");
	for(i=0;i<n;i++)
	{
	  xn[i]=640-x[i];
	  yn[i]=480-y[i];
	}
	setcolor(12);
	polygon(n,xn,yn);
}

void refxy(int n,int x[],int y[])
{
	int i,xn[MAX],yn[MAX];
	outtextxy(20,10,"REFLECTION about X=Y AXIS");
	for(i=0;i<n;i++)
	{
	  xn[i]=560-y[i];
	  yn[i]=560-x[i];
	}
	setcolor(13);
	polygon(n,xn,yn);
}

void refxy2(int n,int x[],int y[])
{
	int i,xn[MAX],yn[MAX];
	outtextxy(20,10,"REFLECTION about X=-Y AXIS");
	for(i=0;i<n;i++)
	{
	  xn[i]=80+y[i];
	  yn[i]=x[i]-80;
	}
	setcolor(14);
	polygon(n,xn,yn);
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
	  cout<<"REFLECTION\n1.About x-axis\n2.About y-axis\n3.About origin\n";
	  cout<<"4.About x=y axis\n5.About x=-y axis\n6.Exit\nEnter your choice :\t";
	  cin>>op;
	  cleardevice();
	  quad();
	  setcolor(2);
	  polygon(n,x,y);
	  setcolor(1);
	  switch(op)
	  {
		case 1:
		  refx(n,x,y);
		  getch();
		  break;
		case 2:
		  refy(n,x,y);
		  getch();
		  break;
		case 3:
		  refo(n,x,y);
		  getch();
		  break;
		case 4:
		  refxy(n,x,y);
		  getch();
		  break;
		case 5:
		  refxy2(n,x,y);
		  getch();
		  break;
		case 6:
		  exit(0);
		default:
		  setcolor(15);
		  outtextxy(0,0,"Invalid option");
		  getch();
	  }
	}
}