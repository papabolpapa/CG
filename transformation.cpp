#include<iostream>
#include<GL/glut.h>
#include<math.h>
#include<vector>
using namespace std;

int edge;
vector<int>xpoint;
vector<int>ypoint;
int ch;


void init()
{
    glClearColor(1.0,1.0,1.0,0.0);
    glMatrixMode(GL_PROJECTION);

    gluOrtho2D(0,640,0,480);
    glClear(GL_COLOR_BUFFER_BIT);
}

void scale()
{
    glColor3f(0,0,1);
    glBegin(GL_POLYGON);

          for(int i=0;i<edge;i++)
          {
              glVertex2i(xpoint[i]-320,ypoint[i]-240);
          }
    glEnd();
    glFlush();

    cout<<"Enter sx and sy";
    int sx;
    int sy;
    cin>>sx>>sy;

    for(int i=0;i<edge;i++)
    {
        xpoint[i]=(xpoint[i]-320)*sx;
        ypoint[i]=(ypoint[i]-240)*sy;
    }

    glColor3f(1,0,0);
    glBegin(GL_POLYGON);

          for(int i=0;i<edge;i++)
          {
              glVertex2i(xpoint[i],ypoint[i]);
          }
    glEnd();
    glFlush();
}

void translation()
{
   glColor3f(0,1,0);
   glBegin(GL_POLYGON);

       for(int i=0;i<edge;i++)
       {
           glVertex2i(xpoint[i],ypoint[i]);
       }
   glEnd();
   glFlush();

   cout<<"Enter tx and ty";
   int tx;
   int ty;
   cin>>tx>>ty;

   for(int i=0;i<edge;i++)
   {
       xpoint[i]=xpoint[i]+tx;
       ypoint[i]=ypoint[i]+ty;
   }

   glColor3f(0,1,1);
   glBegin(GL_POLYGON);

       for(int i=0;i<edge;i++)
       {
          glVertex2i(xpoint[i],ypoint[i]);
       }
    glEnd();
    glFlush();
}

void reflection()
{

   char reflection;
   cout<<"Enter the axis of reflection";
   cin>>reflection;

   if(reflection=='x'||reflection=='X')
   {
      glColor3f(1,0,0);
      glBegin(GL_POLYGON);

            for(int i=0;i<edge;i++)
            {
               glVertex2i(xpoint[i],(ypoint[i]*-1)+480);
            }
       glEnd();
       glFlush();
   }
   else if(reflection=='y'||reflection=='Y')
   {
       glColor3f(1,0,0);
       glBegin(GL_POLYGON);

           for(int i=0;i<edge;i++)
           {
               glVertex2i((xpoint[i]*-1)+640,ypoint[i]);
           }
       glEnd();
       glFlush();
   }
}

void draw()
{
    if(ch==3)
    {
    glColor3f(0,1,0);
    glBegin(GL_LINES);
    glVertex2i(0,240);
    glVertex2i(640,240);
    glEnd();
    glFlush();

    glColor3f(0,1,0);
    glBegin(GL_LINES);
    glVertex2i(320,0);
    glVertex2i(320,480);
    glEnd();
    glFlush();

    glColor3f(1.0,0,0);
        glBegin(GL_POLYGON);
            for(int i=0;i<edge;i++){
                glVertex2i(xpoint[i],ypoint[i]);
            }
        glEnd();
        glFlush();

    }
    if(ch==1)
    {
       scale();
    }
    else if(ch==2)
    {
       translation();
    }
    else if(ch==3)
    {
       reflection();
    }
}

int main(int argc,char** argv)
{
    cout<<"Enter 1 for scaling";
    cout<<"Enter 2 for translation";
    cout<<"Enter 3 for reflection";
    cin>>ch;

    if(ch==1||ch==2||ch==3)
    {
        cout<<"\nEnter the number of edges\n";
        cin>>edge;
        cout<<"\nEnter\t"<<edge<<"points of polygon\n";

        int xpointnew,ypointnew;

        for(int i=1;i<=edge;i++)
        {
           cout<<"\nEnter\t"<<i<<"st"<<"point of polygon\n";
           cin>>xpointnew>>ypointnew;

           xpoint.push_back(xpointnew+320);
           ypoint.push_back(ypointnew+240);
        }

          glutInit(&argc,argv);
          glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
          glutInitWindowPosition(200,200);
          glutInitWindowSize(640,480);
          glutCreateWindow("2D");
          init();
          glutDisplayFunc(draw);
          glutMainLoop();
    }
    else{
        cout<<"Enter right option and try again..";
    }
    return 0;
}