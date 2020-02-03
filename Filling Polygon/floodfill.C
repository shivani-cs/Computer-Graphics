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
	int x1,y1,x2,y2,x3,y3,x,y;
	int gd,gm;
	gd=DETECT;
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	pf("\n ENter coordinates of triangle");
	sf("%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3);
	line(x1,y1,x2,y2);
	line(x2,y2,x3,y3);
	line(x3,y3,x1,y1);
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