#include <iostream>
#include <GL/GL.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include <ctime>
#include  <sstream>
#include <fstream> 
using namespace std;
int board[20],count=0,level,levels,b,c,score;
double k,l;
int mode,m=0;
int chessboard[100][100]={};
int queens,d=0;
float W; float H;
int n=queens;
char quote[20][20],notes[18],pla[40],exe[4],scores[17],numbers[20];
int x[10];
int a[100][20][20]={};
char sc[5],sc1[5],sc2[5],sc3[5],sc4[5],highs[15],yours[20];

class player
{
	public:
	char name[10];
	int score;
}p[30],pq[6];
void init(void)
{
 glClearColor(0.0,0.0,0.0,0.0);
 
}

void opef()
{
	int i,Result;
	char data[10];
	 ifstream infile; 
	 
	infile.open("scores.dat",ios::in);

	for(i=0;i<25;i++)
	{ 
	
  		 infile >> data; 
 		 strcpy(p[i].name,data);
   		 infile >> data; 
   		 stringstream convert(data);
		 if ( !(convert >> Result) )
   		  		 Result = 0;
  		 
	   p[i].score=Result;
		
	} 
    infile.close();
}

void closf()
{
	int i;
	char data[10];
	int data1;
	ofstream outfile;
    outfile.open("scores.dat",ios::out);
    for(i=0;i<25;i++)
    {
    	strcpy(data,p[i].name);
    	outfile << data << endl;
    	data1=p[i].score;
    	outfile << data1 << endl;
    	 
		
	}
	
    
	
    outfile.close();
}
void sort()
{
	int i,j,k,x,y,z,dummy;
	char data[10];
	if(level=1)
	{
		i=0;
	}else if(level=2)
	{
		i=5;
	}else if(level=3)
	{
		i=10;
	}else if(level=4)
	{
		i=15;
	}else if(level=5)
	{
		i=20;
	}
	k=i+5;
	for(x=i,j=0;j<5;j++,x++)
	{		
		pq[j].score=p[x].score;
		strcpy(pq[j].name,p[x].name);
		
	}
	for(y=0;y<5;y++)
	{
		for(z=0;z<5;z++)
		{
			if(pq[z].score<pq[z+1].score)
			{
				strcpy(data,pq[z].name);
				strcpy(pq[z].name,pq[z+1].name);
				strcpy(pq[z+1].name,data);
				
				
				dummy=pq[z].score;
				pq[z].score=pq[z+1].score;
				pq[z+1].score=dummy;
				
			}
		}
	}
	for(x=i,j=0;j<5;j++,x++)
	{
		p[x].score=pq[j].score;
		strcpy(p[x].name,pq[j].name);
	}
}

void drawString (void * font, char *s, float x, float y, float z)
{
     unsigned int i;
     glRasterPos3f(x, y, z);

     for (i = 0; i < strlen (s); i++)
          glutBitmapCharacter (font, s[i]);
}
void displaymenu()
{
m=0;
for(int i=0;i<levels;i++){
glPushMatrix();
glLineWidth(2.5); 
glColor3f(0.50,0.60,0.70);
glBegin(GL_LINES);
glVertex3f(0.0, 75*i, 0.0);
glVertex3f(75*levels,75*i , 0);
glEnd();
glPopMatrix();
glPushMatrix();
glColor3f(0.70,0.60,0.50);
drawString(GLUT_BITMAP_HELVETICA_18, quote[i], 200,(75)*(i)+40 , 0); 
     
glPopMatrix();
}
}
void displaysols()
{
	
for(int i=0;i<=3;i++){
glPushMatrix();
glLineWidth(2.5); 
glColor3f(0.50,0.60,0.70);
glBegin(GL_LINES);
glVertex3f(0.0, i*(75*levels)/4, 0.0);
glVertex3f(75*levels,i*(75*levels)/4 , 0);

glEnd();

glPopMatrix();

 }
 glPushMatrix();
glLineWidth(2.5); 
glColor3f(0.50,0.60,0.70);
glBegin(GL_LINES);
glVertex3f((75*levels)/2,0.0, 0.0);
glVertex3f((75*levels)/2,75*(levels)-130 , 0.0);

glEnd();


glPopMatrix();
strcpy(numbers,"4 QUEENS\n");
glPushMatrix();
	glColor3f(0.60, 0.50, 0.60);
drawString(GLUT_BITMAP_HELVETICA_18, numbers, 95,320 , 0); 
glPopMatrix();
strcpy(numbers,"5 QUEENS\n");
glPushMatrix();
	glColor3f(0.60, 0.50, 0.60);
drawString(GLUT_BITMAP_HELVETICA_18, numbers, 350,320 , 0); 
glPopMatrix();
strcpy(numbers,"6 QUEENS\n");
glPushMatrix();
	glColor3f(0.60, 0.50, 0.60);
drawString(GLUT_BITMAP_HELVETICA_18, numbers, 95,180 , 0); 
glPopMatrix();
strcpy(numbers,"7 QUEENS\n");
glPushMatrix();
	glColor3f(0.60, 0.50, 0.60);
drawString(GLUT_BITMAP_HELVETICA_18, numbers, 350,180 , 0); 
glPopMatrix();
strcpy(numbers,"8 QUEENS\n");
glPushMatrix();
	glColor3f(0.60, 0.50, 0.60);
drawString(GLUT_BITMAP_HELVETICA_18, numbers, 95,60 , 0); 
glPopMatrix();
strcpy(numbers,"GO   TO   LEVELS\n");
glPushMatrix();
	glColor3f(0.60, 0.50, 0.60);
drawString(GLUT_BITMAP_HELVETICA_18, numbers, 320,60 , 0); 
glPopMatrix();
strcpy(numbers,"SELECT NUMBER OF QUEENS\n");

glPushMatrix();
	glColor3f(0.50, 0.80, 0.60);
drawString(GLUT_BITMAP_HELVETICA_18, numbers, 130,460 , 0); 
glPopMatrix();
}

void displayboard()
{
	if(m==0)
	{
		time_t btime=time(NULL);
		k=btime;	}
for(int i=0;i<queens;i++)
{
	for(int j=0;j<queens;j++)
{
	glPushMatrix();
	
	 if((i+j)%2==0)
	glColor3f(1.0, 1.0, 1.0);
	else
	glColor3f(0.0, 0.0, 0.0);
	
 glBegin(GL_POLYGON);
   glVertex2f((levels*75/queens)*i, (levels*75/queens)*j);
   glVertex2f((levels*75/queens)*(i+1), (levels*75/queens)*j);
  glVertex2f((levels*75/queens)*(i+1), (levels*75/queens)*(j+1));
glVertex2f((levels*75/queens)*(i), (levels*75/queens)*(j+1));
glEnd();
if(chessboard[queens-1-j][i]==1)
{
	glPushMatrix();
	glColor3f(0.40, 0.60, 0.150);
 glBegin(GL_POLYGON);
   glVertex2f(((levels*75/queens)*i)+((levels*75/queens)*2/10), (levels*75/queens)*j);
  glVertex2f(((levels*75/queens)*i)+((levels*75/queens)/2), ((levels*75/queens)*j)+((levels*75/queens))*2/10);
  
    glVertex2f(((levels*75/queens)*i)+((levels*75/queens)*8/10), (levels*75/queens)*j);
 glVertex2f(((levels*75/queens)*i)+((levels*75/queens)), ((levels*75/queens)*j)+((levels*75/queens))*8/10);
 glVertex2f(((levels*75/queens)*i)+((levels*75/queens)*8/10), ((levels*75/queens)*j)+((levels*75/queens)*6/10));
glVertex2f(((levels*75/queens)*i)+((levels*75/queens)*5/10), ((levels*75/queens)*j)+((levels*75/queens))); 
glVertex2f(((levels*75/queens)*i)+((levels*75/queens)*2/10), ((levels*75/queens)*j)+((levels*75/queens)*6/10));
 glVertex2f(((levels*75/queens)*i), ((levels*75/queens)*j)+((levels*75/queens))*8/10);

 glEnd();
  

glPopMatrix();
}

}

}


}

void displayregd()
	{
	
	glPushMatrix();
	glColor3f(0.60, 0.50, 0.60);
drawString(GLUT_BITMAP_HELVETICA_18,notes , 140,350 , 0); 
glPushMatrix();
glLineWidth(2.5); 
glColor3f(0.750, 0.250, 0.60);
glBegin(GL_LINES);
glVertex3f(0.0, 50, 0.0);
glVertex3f(75*levels, 50, 0);
glEnd();
glPopMatrix();
glPushMatrix();
glLineWidth(2.5); 
glColor3f(0.750, 0.250, 0.60);
glBegin(GL_LINES);
glVertex3f(0.0, 100, 0.0);
glVertex3f(75*levels, 100, 0);
glEnd();
glPopMatrix();
	glPushMatrix();
	glColor3f(0.60, 0.50, 0.60);
drawString(GLUT_BITMAP_HELVETICA_18, pla, 250,65 , 0); 
glPopMatrix();
     glPushMatrix();
glLineWidth(2.5); 
glColor3f(0.750, 0.250, 0.60);
glBegin(GL_LINES);
glVertex3f(0.0, 0.0, 0.0);
glVertex3f(75*levels, 0.0, 0);
glEnd();
glPopMatrix();
glPushMatrix();
glLineWidth(2.5); 
glColor3f(0.750, 0.250, 0.60);
glBegin(GL_LINES);
glVertex3f(0.0, 50, 0.0);
glVertex3f(75*levels, 50, 0);
glEnd();
glPopMatrix();
glPushMatrix();
	glColor3f(0.60, 0.50, 0.60);
drawString(GLUT_BITMAP_HELVETICA_18,exe, 250,25 , 0); 
glPopMatrix();
    if(((b>90)&&level<3)||((b>80)&&level>=3&&levels<=5))
    {
    	for(int d=0;d<3;d++)
    	{
    		glPushMatrix();
    		glColor3f(0.250,0.215,0.0);
    		glBegin(GL_POLYGON);
   glVertex2f(200+70*d,250);
   glVertex2f(230+70*d,280);
  glVertex2f(200+70*d,310);
glVertex2f(170+70*d,280);
glEnd();
glPopMatrix();
    	}
    }
    else if(((b>60)&&level<3)||((b>40)&&level>=3&&level<=5))
    {
    	for(int d=0;d<2;d++)
    	{
    		glPushMatrix();
    		glColor3f(0.250,0.215,0.0);
    		glBegin(GL_POLYGON);
   glVertex2f(200+70*d,250);
   glVertex2f(230+70*d,280);
  glVertex2f(200+70*d,310);
glVertex2f(170+70*d,280);
glEnd();
glPopMatrix();
    	}
    		glPushMatrix();
    		glColor3f(0.250,0.215,0.0);
    		glLineWidth(2);
    		glBegin(GL_LINES);
   glVertex2f(200+70*2,250);
   glVertex2f(230+70*2,280);
glVertex2f(230+70*2,280);
  glVertex2f(200+70*2,310);
  glVertex2f(200+70*2,310);
glVertex2f(170+70*2,280);
glVertex2f(170+70*2,280);
glVertex2f(200+70*2,250);
glEnd();

glPopMatrix();
    }
    else
    {
    		glPushMatrix();
    		glColor3f(0.250,0.215,0.0);
    		glBegin(GL_POLYGON);
   glVertex2f(200,250);
   glVertex2f(230,280);
  glVertex2f(200,310);
glVertex2f(170,280);
glEnd();
glPopMatrix();
    	for(int d=1;d<3;d++)
    	{
    		glPushMatrix();
    		glColor3f(0.250,0.215,0.0);
    		glLineWidth(2);
    		glBegin(GL_LINES);
   glVertex2f(200+70*d,250);
   glVertex2f(230+70*d,280);
glVertex2f(230+70*d,280);
  glVertex2f(200+70*d,310);
  glVertex2f(200+70*d,310);
glVertex2f(170+70*d,280);
glVertex2f(170+70*d,280);
glVertex2f(200+70*d,250);
glEnd();
glPopMatrix();
    	}
    }
glPopMatrix();
	
	sc[0]=b/10+48;
		sc[1]=b%10+48;
			strcpy(yours,"Your score is \n");

	glPushMatrix();
	glColor3f(0.60, 0.50, 0.60);
	drawString(GLUT_BITMAP_HELVETICA_18, yours, 140,230 , 0); 	
	drawString(GLUT_BITMAP_HELVETICA_18, sc, 270,230 , 0); 
	glPopMatrix();
	opef();
	sort();
	closf();
	sc[0]=pq[0].score/10+48;
	sc[1]=pq[0].score%10+48;
	sc1[0]=pq[1].score/10+48;
	sc1[1]=pq[1].score%10+48;
	sc2[0]=pq[2].score/10+48;
	sc2[1]=pq[2].score%10+48;
	sc3[0]=pq[3].score/10+48;
	sc3[1]=pq[3].score%10+48;
	sc4[0]=pq[4].score/10+48;
	sc4[1]=pq[4].score%10+48;
	
	
	strcat(pq[0].name,"\n");
	strcat(pq[1].name,"\n");
	strcat(pq[2].name,"\n");
	strcat(pq[3].name,"\n");
	strcat(pq[4].name,"\n");
	
	
	strcat(sc,"\n");
	strcat(sc1,"\n");
	strcat(sc2,"\n");
	strcat(sc3,"\n");
	strcat(sc4,"\n");
	
	
	strcpy(highs,"HIGH SCORES :\n");

	
	glPushMatrix();
	glColor3f(0.60, 0.50, 0.60);
	
	drawString(GLUT_BITMAP_HELVETICA_18,highs, 150,210 , 0);
	drawString(GLUT_BITMAP_HELVETICA_18,pq[0].name, 200,190 , 0);
	drawString(GLUT_BITMAP_HELVETICA_18,sc, 150,190, 0);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.60, 0.50, 0.60);
	
	drawString(GLUT_BITMAP_HELVETICA_18,pq[1].name, 200,170 , 0);
	drawString(GLUT_BITMAP_HELVETICA_18,sc1, 150,170 , 0); 
	glPopMatrix();
	
	glPushMatrix();
	glColor3f(0.60, 0.50, 0.60);
	drawString(GLUT_BITMAP_HELVETICA_18,pq[2].name, 200,150 , 0);
	drawString(GLUT_BITMAP_HELVETICA_18,sc2, 150,150 , 0);
	glPopMatrix();
	
	glPushMatrix();
	glColor3f(0.60, 0.50, 0.60);
	drawString(GLUT_BITMAP_HELVETICA_18,pq[3].name, 200,130 , 0);
	drawString(GLUT_BITMAP_HELVETICA_18,sc3, 150,130 , 0); 
	glPopMatrix();
	
	glPushMatrix();
	glColor3f(0.60, 0.50, 0.60);
	drawString(GLUT_BITMAP_HELVETICA_18,pq[4].name, 200,110 , 0);
	drawString(GLUT_BITMAP_HELVETICA_18,sc4, 150,110 , 0);
	glPopMatrix();

}
void display()
{
 glClear(GL_COLOR_BUFFER_BIT);
 if(mode==3)
 {
 	glClear(GL_COLOR_BUFFER_BIT);
 glPushMatrix();
 displayregd();
 glPopMatrix();
 glutSwapBuffers();
 }
 if(mode==0)
 {m=0;
 count=0;
 	glClear(GL_COLOR_BUFFER_BIT);
 glPushMatrix();
 displaymenu();
 glPopMatrix();
 glutSwapBuffers();
 }
else if(mode==1)
 {

 glPushMatrix();
 displayboard();
 glPopMatrix();
 glutSwapBuffers();
}
else if(mode==4)
{
	glClear(GL_COLOR_BUFFER_BIT);
 glPushMatrix();
 displaysols();
 glPopMatrix();
 glutSwapBuffers();
}



}

void reshape(int w, int h)
{
glViewport(0,0, (GLsizei)w, (GLsizei)h);
 glMatrixMode (GL_PROJECTION);
 glLoadIdentity();
gluOrtho2D(0, W, 0, H);
 glMatrixMode(GL_MODELVIEW);
 glLoadIdentity();
}
void copy(int w)
{
	if(w==0)
	{
		for(int o=0;o<queens;o++){
	for(int p=0;p<queens;p++){
		chessboard[o][p]=0;
	}
	}
	}
	
	for(int o=0;o<queens;o++){
	for(int p=0;p<queens;p++){
		chessboard[o][p]=a[w][o][p];
	}
	}
		

}

void print(int n)
{
 int i,j;
 
 
 
 
count++;
 for(i=1;i<=n;i++)
 {
  
  for(j=1;j<=n;j++) 
  {
   if(board[i]==j)
    a[count][i-1][j-1]=1; 
   else
    a[count][i-1][j-1]=0;
  }
 }

 
 
 
}
 

int placea(int row,int column)
{
 int i;
 for(i=1;i<=row;++i)
 {
  if(board[i]==column)
   return 0;
  else
   if(abs(board[i]-column)==abs(i-row))
    return 0;
 }
 
 return 1; 
}
 

void queen(int row,int n)
{
	
 int column;
 for(column=1;column<=n;column++)
 {
  if(placea(row,column))
  {
   board[row]=column; 
      if(row==n) 
    print(n); 
   else 
    queen(row+1,n);
  }
 }
 
}


int  place(int a,int b)
{
	for(int g=0;g<queens;g++)
   			{
   				for(int h=0;h<queens;h++)
   				{
   					if(chessboard[g][h]==1)
   						x[h]=g;
   				}
   			}
   			
  { int j;
   for(j=0;j<a;j++) 
   { if((x[j]==b)||(abs(x[j]-b)==abs(j-a)))
    return 0; 
	}
	 return 1;
	  }
	
}


void bsearch(int first,int last)
{

	
	int mid,flag=0,f=0,g[50],d=0,h[50],u[20];
	while(flag==0&& f<=count){
		
	
	f++;
	mid=(first+last)/2;
	for(int o=0;o<queens;o++){
	for(int p=0;p<queens;p++){
	
	if(a[mid][o][p]==1)
	{
	g[o]=p;
	
	}if(chessboard[o][p]==1)
	{
		h[o]=p;
	
	}
	}
	}
	for(int q=0;q<queens;q++)
	{
		if(h[q]==g[q])
		{
			u[d]=q;
			d++;
			
		}
	
		if(h[q]>g[q])
		{
			first=mid+1;
			break;
		}
	
		if(h[q]<g[q])
		{
				last=mid-1;
			break;
		}
		
	}
if(d==queens-1)
	{
		flag=1;
	}

	
}
	if(f>count){
		copy(0);
	
}
	copy(mid);
	m=queens;
	

}
void mouse (int button, int state, int x, int y) 
{
int row, column;
switch(button) {
 case GLUT_LEFT_BUTTON:
 if(state == GLUT_DOWN)
 {  if(mode==3)
 {
 	if(y>475)
 	{
 		exit(0);
 	}
 	else if(420<y<475)
 	{
 		mode=0;
 		m=0;
 	}
 	
 }
 else if (mode==0)
 {
 	 level=(y/75);
 	
 	if(level==0)
 	{ 
	 mode=4;
	 
	 	
 }
 else if(level==6)
 {
 	exit(0);
 }else{
 
 	mode=1;
 	queens=(level+3);
 	queen(1,queens);
 time_t btime = time(NULL);
}
 }
 
 else if(mode==1)
 {
 
 m++;
  row=(y/((levels*75)/queens));
 column = (x/((levels*75)/queens));

 if(chessboard[row][column] ==1)
 {
 	m--;
 }
 chessboard[row][column] = 1;


}
else if(mode==4)

{
	if(x>(75*levels)/2&&y>3*(75*levels)/4)
	{
		mode=0;
		
	}

	else if(y>(75*levels)/4)
{

	row=(y/((75*levels)/4));
	column=(x/((75*levels)/2));
	queens=(2*(row)+column)+2;
	queen(1,queens);
		for(int o=0;o<queens;o++){
	for(int p=0;p<queens;p++){
		chessboard[o][p]=a[1][o][p];
	}
	}
		row=0;
	column=0;
	mode=1;
}



	
}
}
 glutPostRedisplay();
 break;
 case GLUT_RIGHT_BUTTON:
 if(state == GLUT_DOWN)
 {  m--;
 row= (y/((levels*75)/queens));
 column =(x/((levels*75)/queens));
 if(chessboard[row][column] ==0)
{
	m++;
}
 chessboard[row][column] = 0;}
 
 
 glutPostRedisplay();
 break;}
}
void keyboard(unsigned char key, int x, int y)
{
   switch (key) {
   	case 115:
   		{
   			bsearch(1,count);
   			b=0;
   			pq[5].score=b;
			glutPostRedisplay();
   		break;
   		}
   		
   	case 13:
   		{	
   			int l=1;
   			for(int g=0;g<queens;g++)
   			{
   				for(int h=0;h<queens;h++)
   				{
   					if(chessboard[g][h]==1)
   					{
   					
   					if(place( h, g)==0)
   					{	 l=0;
   						cout<<"HINT::"<<"you are wrong at"<<h+1<<"column"<<g+1<<"row\n"<<endl;					    
					   }
   					}
   				}
   		}
   			
   		if( l!=0&& m==queens)
   			
   			{
   				time_t dtime = time(NULL);
   				l=dtime;
   				b=100-3*(l-k);
   				pq[5].score=b;
			   	system("cls");
			   
   			
   				mode=3;
   				m=0;
   				count=0;
   			
   		
		for(int o=0;o<queens;o++){
	for(int p=0;p<queens;p++){
		chessboard[o][p]=0;
	}
	}
	
   		
   		glutPostRedisplay();
   		}
   			 else if(m!=queens)
   			 {
   			 	system("cls");
   			 	cout<<"enter all queens";
   			 }
		   break;
	}
	case 108:
			for(int o=0;o<queens;o++){
	for(int p=0;p<queens;p++){
		chessboard[o][p]=0;
	}
	}
	
   		mode=0;
   		
   		glutPostRedisplay();
   		break;
	case 114:
		m=0;

		for(int o=0;o<queens;o++){
	for(int p=0;p<queens;p++){
		chessboard[o][p]=0;
	}
	}
	glutPostRedisplay();
	break;
   		case 27:
   			cout<<"THANK YOU FOR PLAYING"<<endl;
   			exit(0);
   			break;
   
}
}


int main(int argc, char **argv)
{      
	cout<<"Enter name:";
	cin>>pq[5].name;     
	cout<<"\nwelcome to Game "<<pq[5].name<<"\n\n";  
	
void queen(int row,int n);
	cout<<"\n  --------------------\n";
	cout<<"\n  INSTRUCTIONS TO PLAY\n";
	cout<<"\n  --------------------\n";
	cout<<" \t * Left click to place a queen \n";
 	cout<<" \t * Right click to remove\n";
 	cout<<" \t * Enter to check your answer right or wrong\n";
 	cout<<" \t * l to select your levels\n";
 	cout<<" \t * r toreset board\n";
 	cout<<" \t * s to get solution in game\n";
 	cout<<" \t * Escape to exit"<<endl;
 	system("pause");
 	system("cls");
mode=0;
levels=7;

 strcpy(quote[0],"EXIT\n");
 strcpy(quote[1],"LEVEL 5 - 8 QUEENS\n");
 strcpy(quote[2],"LEVEL 4\n");
 strcpy(quote[3],"LEVEL 3\n");
 strcpy(quote[4],"LEVEL 2\n");
 strcpy(quote[5],"LEVEL 1\n");
 strcpy(quote[6],"GET SOLUTIONS\n");
strcpy(notes,"CONGRATS YOU WON\n");
strcpy(pla,"PLAY\n");
strcpy(exe,"EXIT\n");
 W = levels*75;
 H = levels*75;
glutInit(&argc, argv);
 glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
 glutInitWindowSize (W, H);
 glutInitWindowPosition(600,200);
 glutCreateWindow("N QUEENS");
init(); 
 glutDisplayFunc(display);
 glutKeyboardFunc(keyboard);
 glutMouseFunc(mouse);
 glutReshapeFunc(reshape);
 glutMainLoop();
 return 0;
}
