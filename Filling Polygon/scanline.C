//scanline for polygon with pattern filling
#include<stdio.h>
#include<conio.h>
#include<graphics.h>

void main()
{
	int n,i,j,k,gm,dy,dx;
	int gd=DETECT;
	int a[20][2],xi[200];
	float slope[20];
	clrscr();

	printf("enter the no. of edges of polygon:");
	scanf("%d",&n);

	printf("enter the coordinates  of polygon:");
	printf("\n");
	for(i=0;i<n;i++)
	{
		printf("\tX %d Y%d",i,i);
		scanf("%d%d",&a[i][0],&a[i][1]);
	}

	a[n][0]=a[0][0];
	a[n][1]=a[0][1];

	initgraph(&gd,&gm,"C:\\TC\\BGI");

	for(i=0;i<n;i++)
	{
		line(a[i][0],a[i][1],a[i+1][0],a[i+1][1]);
	}

	getch();

	for(i=0;i<n;i++)
	{
		dy=a[i+1][1]-a[i][1];
		dx=a[i+1][0]-a[i][0];

		if(dy==0)
			slope[i]=1.0;

		if(dx==0)
			slope[i]=0.0;

		if((dy!=0)&&(dx!=0))
		{
			slope[i]=(float)dx/dy;
		}
	}

	for(y=0;y<580;y++)
	{
		k=0;
		for(i=0;i<n;i++)
		{
			if(((a[i][1]<=y) && (a[i+1][1]>y)) || ((a[i][1]>y) && (a[i+1][1]<=y)))
			{
				xi[k]=(int)(a[i][0]+slope[i] *(y-a[i][1]));
				k++;
			}
		}
		setlinestyle(SOLID_LINE,1,1);
		setcolor(5);


		for(i=0;i<k;i+=2)
		{
			line(xi[i],y,xi[i+1],y);
			delay(100);
		}
	}
	setcolor(WHITE);
	setlinestyle(SOLID_LINE,1,1);
	for(i=0;i<n;i++)
	{
		line(a[i][0],a[i][1],a[i+1][0],a[i+1][1]);
	}

	getch();
	closegraph();
}



