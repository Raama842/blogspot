#include<stdio.h>


#include<GL/glut.h>

#include<math.h>

GLfloat theta,xf,yf;

 

void draw()

{

glColor3f(1.0,0.0,0.0);

glBegin(GL_LINE_LOOP);

glVertex2f(100,100);

glVertex2f(150,150);

glVertex2f(200,100);

glEnd();

}

 

void display()

{

int i;

GLfloat m[16],p,q;

p=xf-xf*(cos(theta))+yf*(sin(theta));

q=yf-yf*(cos(theta))-xf*(sin(theta));

for(i=0;i<15;i++)

{

m[i]=0.0;

}

m[0]=cos(theta);

m[1]=sin(theta);

m[4]=-sin(theta);

m[5]=cos(theta);

m[12]=p;

m[13]=q;

m[10]=1;

m[15]=1;

glClear(GL_COLOR_BUFFER_BIT);

draw();

glPushMatrix();

glMultMatrixf(m);

draw();

glPopMatrix();

glFlush();

}

 

void init()

{

glClearColor(1.0,1.0,1.0,1.0);

gluOrtho2D(0,300,0,300);

}

 

int main(int argc,char **argv)

{

printf("Enter the fixed point value(xf,yf)\n");

scanf("%f%f",&xf,&yf);

printf("Enter the rotation angle\n");

scanf("%f",&theta);

theta=theta*(3.141/180);

glutInit(&argc,argv);

glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);

glutInitWindowSize(500,500);

glutCreateWindow("Rotate Triangle");

glutDisplayFunc(display);

init();

glutMainLoop();

return 0;

}
