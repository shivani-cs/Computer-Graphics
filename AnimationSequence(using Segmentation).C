#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include<dos.h>

int xmax, ymax,midx,midy,w=50;
void Hospital( int, int );
void man(int ,int);
void Talk(int ,int);
void manstatic(int hfx,int hfy)  ;

union REGS i, o;
int x,y,button,status;
int initmouse()
{
   i.x.ax = 0;
   int86(0X33,&i,&o);
   return ( o.x.ax );
}
 
void showmouseptr()
{
   i.x.ax = 1;
   int86(0X33,&i,&o);
}
 
void getmousepos(int *button, int *x, int *y)
{
   i.x.ax = 3;
   int86(0X33,&i,&o);
 
   *button = o.x.bx;
   *x = o.x.cx;
   *y = o.x.dx;
}

void callroute(){
	int hfx,hfy;
	hfx = getmaxx()/2;
  hfy = getmaxx()/2;
  Hospital(hfx,hfy);
  man(hfx,hfy);
  Talk(hfx,hfy);
};

void overview()
{
setlinestyle(3,4, 1);
   line(midx,0 ,midx, midy-w);
   line(midx,midy+w ,midx,ymax);
   line(0,midy ,midx-w, midy);
   line(midx+w,midy,xmax,midy);
   setlinestyle(0,1, 1);
   line(midx-w,0 ,midx-w, midy-w);
   line(midx-w,midy+w ,midx-w,ymax);
   line(0,midy-w ,midx-w, midy-w);
   line(midx+w,midy-w,xmax,midy-w);
   line(midx+w,0 ,midx+w, midy-w);
   line(midx+w,midy+w ,midx+w,ymax);
   line(0,midy+w ,midx-w, midy+w);
   line(midx+w,midy+w,xmax,midy+w);
   circle(midx,midy,10);
   setcolor(10);
   outtextxy(midx-130,30,"AADAR");
   outtextxy(midx-135,45,"MEDICAL");
   outtextxy(midx-132,60,"CENTER");
   setcolor(15);
   rectangle(midx-150,15,midx-60,85);
   setcolor(10);
   outtextxy(xmax-75,midy-120,"AADAR");
   outtextxy(xmax-85,midy-105,"SHOPPING");
   outtextxy(xmax-68,midy-90,"MALL");
   setcolor(15);
   rectangle(xmax-100,midy-135,xmax-10,midy-65);
   setcolor(10);
   outtextxy(midx-130,ymax-65,"AADAR");
   outtextxy(midx-133,ymax-50,"SPORTS");
   outtextxy(midx-127,ymax-35,"CLUB");
   setcolor(15);
   rectangle(midx-150,ymax-80,midx-60,ymax-15);

   circle(70,ymax-100,70);
   rectangle(60,ymax-128,80,ymax-72);
   line(65,ymax-123,75,ymax-123);
   line(65,ymax-77,75,ymax-77);
}

void car(int left,int top,int right,int bottom,int ch)
{
if(ch==75 || ch==77)
	{
	rectangle(left,top,right,bottom);
	rectangle(left+10,top+1,right-10,bottom-1);
	setfillstyle(1,14);
	floodfill((left+right)/2,(top+bottom)/2,15);
	}
else
	{
	if(ch==72)
	{
	rectangle(left,top,right,bottom);
	rectangle(left+1,top+10,right-1,bottom-10);
	setfillstyle(1,14);
	floodfill((left+right)/2,(top+bottom)/2,15);
	}
	else
	{
	rectangle(left,top,right,bottom);
	rectangle(left-1,top+10,right+1,bottom-10);
	setfillstyle(1,14);
	floodfill((left+right)/2,(bottom+top)/2,15);
	}
	}
}


int main(void)
{
   int gdriver = DETECT, gmode, errorcode;
   int i,j,left,top,right,bottom,t1,t2;
   int ch;

   initgraph(&gdriver, &gmode, "c:\\tc\\bgi");

   errorcode = graphresult();
   if (errorcode != grOk)
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1);
   }
   xmax = getmaxx();
   ymax = getmaxy();
   midx=xmax/2;
   midy=ymax/2;
   settextstyle(1,0,5);
   outtextxy(50,50,"WELCOME  TO  AADAR  CITY");
   settextstyle(0,0,0);
   getch();
   cleardevice();
   setcolor(getmaxcolor());
   i=0;
   j=midy;
   left=i;
   right=i+60;
   top=j-40;
   bottom=j-10;
   ch=75;
   do{
   cleardevice();
   overview();
   car(left,top,right,bottom,ch);
   ch=getch();
   switch(ch)
	{
	case 72:i=midx;
		left=i-40;right=i-10;
		top=j-70;
		bottom=j-10;
		j--;break;
	case 75:j=midy;
		left=i;
		right=i+60;
		top=j-40;
		bottom=j-10;
		i--;break;
	case 77:j=midy;
		left=i;
		right=i+60;
		top=j-40;
		bottom=j-10;
		i++;break;
	case 80:i=midx;
		left=i+40;right=i+10;
		top=j-60;
		bottom=j;
		j++;
	}
	if(top == 30 && left < midx )
		callroute();
   }while(ch!=27);


   getch();
   closegraph();
   return 0;
}


void Hospital(int hfx,int hfy){

  //*****BOUNDERY***********************************************************
  line(10,10,(getmaxx())-10,10);
  line(10+2,10+2,(getmaxx())-10-2,10+2);

  settextstyle(1,0,5);
  outtextxy(50,50,"AADAR MEDICAL CENTER");
  settextstyle(0,0,0);
  line(10,10,10,getmaxy()-10);
  line(10+2,10+2,10+2,getmaxy()-10-2);

  line( (getmaxx())-10, (getmaxy())-10, 10, (getmaxy())-10);
  line( (getmaxx())-10-2, (getmaxy())-10-2, 10+2, (getmaxy())-10-2);

  line( (getmaxx())-10, (getmaxy())-10,(getmaxx())-10, 10 );
  line( (getmaxx())-10-2, (getmaxy())-10-2,(getmaxx())-10-2, 10+2 );
  //************************************************************************

  line( 12,hfy-100,getmaxx()-12 ,hfy-100);

  rectangle(hfx-80,hfy-200,hfx-20,hfy-100); // DOOR
  //rectangle(left,top,right,bottom)

  //*****FURNITURE***********************************************************

  rectangle(40,hfy-50,100,hfy-30); //
  rectangle( 45,hfy-30,51,hfy-10); //TABLE
  rectangle( 95,hfy-30,89,hfy-10); //


  rectangle(40,hfy+10,100,hfy+30); //
  rectangle( 45,hfy+30,51,hfy+50); //TABLE
  rectangle( 95,hfy+30,89,hfy+50); //


  ellipse(40 , hfy+80, 0, 360,15,10);
  rectangle(30 , hfy+88,35,hfy+100);
  rectangle(30+15 , hfy+88,50,hfy+100);

  ellipse(40+70 , hfy+80, 0, 360,15,10);
  rectangle(30+70 , hfy+88,35+70,hfy+100);
  rectangle(30+15+70 , hfy+88,50+70,hfy+100);
  rectangle(hfx +100,hfy-60,hfx+200,hfy-8);
  circle((getmaxx())-45,(getmaxy())-70,8);
  line(getmaxx()-45,getmaxy()-62,getmaxx()-45,getmaxy()-40);
  line(getmaxx()-45,getmaxy()-46,getmaxx()-35,getmaxy()-52);
  line(getmaxx()-45,getmaxy()-46,getmaxx()-55,getmaxy()-52);
  rectangle(getmaxx()-60,getmaxy()-40,getmaxx()-30,getmaxy()-13);

  circle(150,150,10);
  circle(150,150,12);
  line(150,150,156,150);
  line(150,150,158,153);

  //**************************************************************************


  line(hfx+138,hfy-60,hfx+145,hfy-63);
  line(hfx+162,hfy-60,hfx+155,hfy-63);
  sector(hfx+150,hfy-75,0,360,9,10);
  ellipse(hfx+150,hfy-75,0,360,12,11);

  ///****
  line(hfx+150,hfy-86,hfx+150,hfy-93);//
  line(hfx+150,hfy-93,hfx+158,hfy-91);// NURSE  HAT
  line(hfx+150,hfy-93,hfx+142,hfy-91);//
  line(hfx+158,hfy-91,hfx+158,hfy-84);
  line(hfx+142,hfy-91,hfx+142,hfy-84);
  //***
  setcolor(0);
  circle(hfx+146,hfy-77,3);
  circle(hfx+154,hfy-77,3);
  circle(hfx+146,hfy-77,1);
  circle(hfx+154,hfy-77,1);
  setcolor(5);
  setlinestyle(0,0,2);
  line(hfx+147,hfy-70,hfx+153,hfy-70);
  setcolor(15);


}
void man(int hfx,int hfy){
   int i=1,j=1,k=1;
   setcolor(15);
  do{
  cleardevice();
  Hospital(hfx,hfy);
  circle(300+i, 400-j ,12);
  line(300+i,412-j,300+i,430-j);
  line(300+i,415-j,296+i,428-j);
  line(300+i,415-j,304+i,428-j);
  line(300+i,430-j,307+i+k,440-j-k);
  line(300+i,430-j,293+i-k,440-j+k);
  i++;j++;
  k=-k;
  delay(10);
  }while(i<98);
  getch();
}

void manstatic(int hfx,int hfy){
     int  i =98,j=98,k=1;
      Hospital(hfx,hfy);
  circle(300+i, 400-j ,12);
  line(300+i,412-j,300+i,430-j);
  line(300+i,415-j,296+i,428-j);
  line(300+i,415-j,304+i,428-j);
  line(300+i,430-j,307+i+k,440-j-k);
  line(300+i,430-j,293+i-k,440-j+k);

}



void Talk(int hfx,int hfy){
	 int opt;
	 char *array;
	 outtextxy(hfx+150,hfy-110,"HOW MAY I HELP YOU??");
	 getch();

	 cleardevice();
	 manstatic(hfx,hfy);
	 getch();
	 outtextxy(hfx-53,hfy-29,"I'M HERE FOR");
	 outtextxy(hfx-43,hfy-21,"->H1N1");
	 outtextxy(hfx-43,hfy-12,"->COMMON COLD") ;
	 outtextxy(hfx-54,hfy-2,"->ERH.. NEVERNMIND");

	//*********************************

   status = initmouse();

   if ( status == 0 )
      printf("Mouse support not available.\n");
   else
   {
      showmouseptr();

      getmousepos(&button,&x,&y);

      while(!kbhit())
      {
	 getmousepos(&button,&x,&y);

	 if( button == 1 )
	 {
	    button = -1;
	    cleardevice();
	    opt=y;
			manstatic(hfx,hfy);
			switch(opt){
			case (300):
			case (301):
			case (302):	outtextxy(hfx+90,hfy-110,"WE DON'T HAVE H1N1 VACCINE");
			break;
			case 309:
			case 310:
			case 311:	outtextxy(hfx+125,hfy-110,"WAIT IN LINE");
			break;
			case 318:
			case 319:
			case 320:	outtextxy(hfx+125,hfy-110,"THANKS FOR VISITING!");
			break;
			}
	    }
      }
   }

	///*******************************
	 getch();

}