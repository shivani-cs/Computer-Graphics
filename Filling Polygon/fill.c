#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#define ROUND(a)((int)(a+0.5))
#define pf printf
#define sf scanf
struct stack
{
	int x;
	int y;
	struct stack *next;
}*p,*temp,*head=NULL;
typedef struct stack t1;
void push(int,int);
void pop();
void main()
{
	void flood(int x,int y,int old,int new);
	int i,x,y,n,a[20][1];
	int gd,gm;
	gd=DETECT;
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	pf("\nEnter the no. of edges of polygon:");
	sf("%d",&n);

	pf("\nEnter the coordinates  of polygon:");
	pf("\n");
	for(i=0;i<n;i++)
	{
		printf("\tX %d Y%d",i,i);
		scanf("%d%d",&a[i][0],&a[i][1]);
	}

	a[n][0]=a[0][0];
	a[n][1]=a[0][1];

	for(i=0;i<n;i++)
	{
		line(a[i][0],a[i][1],a[i+1][0],a[i+1][1]);
	}

	pf("\nEnter seed point");
	sf("%d%d",&x,&y);
	flood(x,y,0,4);
	getch();
}
void flood(int x,int y,int old,int new)
{
	if(getpixel(x,y)==new)
		return;
	push(x,y);
	putpixel(x,y,new);
	delay(50);
	while(head!=NULL)
	{
		pop();
		x=p->x;
		y=p->y;
		if(getpixel(x+1,y)==old)
		{
			putpixel(x+1,y,new);
			delay(5);
			push(x+1,y);
		}
		if(getpixel(x-1,y)==old)
		{
			putpixel(x-1,y,new);
			delay(5);
			push(x-1,y);
		}
		if(getpixel(x,y+1)==old)
		{
			putpixel(x,y+1,new);
			delay(5);
			push(x,y+1);
		}
		if(getpixel(x,y-1)==old)
		{
			putpixel(x,y-1,new);
			delay(5);
			push(x,y-1);
		}
	}
}
void push(int x1,int y1)
{
	temp=(t1 *)malloc(sizeof(t1));
	temp->x=x1;
	temp->y=y1;
	if(head==NULL)
	{
		head=temp;
		temp->next=NULL;
	}
	else
	{
		temp->next=head;
		head=temp;
	}
}
void pop()
{
	p=head;
	head=head->next;
}