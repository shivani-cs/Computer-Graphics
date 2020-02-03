#include <stdio.h>
#include <stdlib.h>
#include<graphics.h>
#include<conio.h>

int ARRAY_SIZE;

int array_max(int *arr, int returnIndex);
int array_min(int *arr, int returnIndex);
void draw3d(int sides, int *x, int *y, int depth);
void drawFrontView(int sides, int *x, int *y);
void drawSideView(int sides, int *x, int *y, int depth);
void drawTopView(int sides,int *x,int *y, int depth);
void drawAxis(int *x, int *y, int depth);

  int array_max(int *arr, int returnIndex){
  int i, max = arr[0], index=0;
  for(i=1;i<ARRAY_SIZE;i++){
    if(arr[i]>max)
	      {
	       max=arr[i];
	       index=i;
	      }
	  }
	  return returnIndex?index:max;
	}

	int array_min(int *arr, int returnIndex){
	  int i, min = arr[0], index=0;
	  for(i=1;i<ARRAY_SIZE;i++){
	      if(arr[i]<min)
	      {
	  min=arr[i];
	  index=i;
	      }
	  }
	  return returnIndex?index:min;
	}

	void drawAxis(int *x, int *y, int depth){
	  int maxy, minx;
	  maxy = array_max(y,0);
	  minx = array_min(x,0);

	  setcolor(BLUE);
	  //z-axis
	  line(minx+depth, maxy-depth, -depth, getmaxy());
	  //x-axis
	  line(minx+depth, maxy-depth, getmaxx(), maxy-depth);
	  //y-axis
	  line(minx+depth, maxy-depth, minx+depth, 0);
	  setlinestyle(0,1,2);
	  setfillstyle(CLOSE_DOT_FILL, WHITE);
	  floodfill(0,0,BLUE);
	  setfillstyle(CLOSE_DOT_FILL, BROWN);
	  floodfill(getmaxx(),0,BLUE);
	  setfillstyle(CLOSE_DOT_FILL, DARKGRAY);
	  floodfill(getmaxx(),getmaxy(),BLUE);
	}

	void draw3d(int sides,int *x,int *y,int depth)
	{
	  int i,j,k=0;
	  setlinestyle(0,1,1);
	  drawAxis(x, y, depth);
	  setcolor(YELLOW);
	  for(j=0;j<2;j++)
	  {
	    for(i=0;i<sides;i++)
	    {
	      if(i!=sides-1)
	      line(x[i]+k,y[i]-k,x[i+1]+k,y[i+1]-k);
	      else
	      line(x[i]+k,y[i]-k,x[0]+k,y[0]-k);

	      if(j==0)
	      line(x[i],y[i],x[i]+depth,y[i]-depth);
	    }
	    k=depth;
	  }
	}

	void drawFrontView(int sides,int *x,int *y)
	{
	    int i;
	    setlinestyle(0,1,1);
	    setcolor(LIGHTGREEN);
	    for(i=0;i<sides;i++)
	    {
	       if(i!=sides-1)
	       line(x[i],y[i],x[i+1],y[i+1]);
	       else
	       line(x[i],y[i],x[0],y[0]);
	    }
	}

	void drawSideView(int sides,int *x,int *y, int depth)
	{
	    int i, maxyIndex, minyIndex, maxxIndex;
	    maxxIndex=array_max(x,1);
	    maxyIndex=array_max(y,1);
      minyIndex=array_min(y,1);

	    setcolor(LIGHTGREEN);
	    for(i=0;i<sides-1;i++)
	    {
	 if(y[i]<y[maxyIndex] && y[i]>y[minyIndex] && x[i]<x[maxxIndex])
	 setlinestyle(3,1,1);
	 else
	 setlinestyle(0,1,1);

	 line(x[0],y[i],x[0],y[i+1]);
	 line(x[0]+depth*2,y[i],x[0]+depth*2,y[i+1]);
	 line(x[0],y[i],x[0]+depth*2,y[i]);
	 line(x[0],y[i+1],x[0]+depth*2,y[i+1]);
	    }
	}

	void drawTopView(int sides, int *x, int *y, int depth)
	{
	    int i, minyIndex, maxxIndex, minxIndex;
	    maxxIndex=array_max(x,1);
	    minxIndex=array_min(x,1);
	    minyIndex=array_min(y,1);
	    setcolor(LIGHTGREEN);
	    for(i=0;i<sides-1;i++)
	    {
	 if(x[i]<x[maxxIndex] && x[i]>x[minxIndex] && y[i]>y[minyIndex])
	 setlinestyle(3,1,1);
	 else
	 setlinestyle(0,1,1);

	 line(x[i],y[0],x[i+1],y[0]);
	 line(x[i],y[0]+depth * 2,x[i+1],y[0]+depth*2);
 line(x[i],y[0],x[i],y[0]+depth*2);
	 line(x[i+1],y[0],x[i+1],y[0]+depth*2);
	    }
	}

	void main(){
	int gd=0,gm;
	int x[20],y[20],i,sides,depth,key;
	clrscr();
	initgraph(&gd,&gm,"c:\\turboc3\\bgi");
	printf("No of sides(front view only) : ");
	scanf("%d",&sides);
	printf("Co-ordinates : ");
	for(i=0;i<sides;i++)
	{
	printf("(x%d,y%d)",i,i);
	scanf("%d%d",&x[i],&y[i]);
	}
	printf("Depth :");
	scanf("%d",&depth);
	ARRAY_SIZE=sides;
	while(1){
	key=getche();
	clrscr();
	cleardevice();
	printf("LEFT ARROW -> 3D View\nUP ARROW - > Front View\nDOWN ARROW -> Top View\nRIGHT ARROW -> Side View\nESC -> Exit");
	switch(key){
	 case 75: //left arrow
	 draw3d(sides,x,y,depth);
	 break;
	 case 72: //up arrow
	 drawFrontView(sides,x,y);
	 break;
	 case 77: //right arrow
	 drawSideView(sides,x,y,depth);
	 break;
	 case 80: //down arrow
	 drawTopView(sides,x,y,depth);
	 break;
	 case 27: //esc
	 exit(0);
	 break;
	}
	}
}

