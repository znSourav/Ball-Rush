#include <windows.h>
#include <GL/glut.h>
#include "game.h"
#include "textures.h"
#include <bits/stdc++.h>

using namespace std;

float rotAngle, charOffset, jumpOffset, shiftAngle, speed = 0;
int shifting, pa, position = 0, score = 0, lc = 0, rc = 0, levels = 1;
bool jumping, gameStart = false, game = false;
int leftObs[1000], rightObs[1000];
char dis[1004];

void main_menu(char *string, float x, float y)
{
  glMatrixMode(GL_PROJECTION);
  glPushMatrix();
  glLoadIdentity();
  int w = glutGet( GLUT_WINDOW_WIDTH );
  int h = glutGet( GLUT_WINDOW_HEIGHT );
  glOrtho( 0, w, 0, h, -1, 1 );

  glMatrixMode(GL_MODELVIEW);
  glPushMatrix();
  glLoadIdentity();

  glDisable( GL_DEPTH_TEST );
  glDisable( GL_LIGHTING );

  glColor3f(255, 255, 255);

  glRasterPos2i(x, y);
  void *font = GLUT_BITMAP_HELVETICA_18;
  for (char* c=string; *c != '\0'; c++){
    glutBitmapCharacter(font, *c);
  }

  glMatrixMode(GL_PROJECTION);
  glPopMatrix();
  glMatrixMode(GL_MODELVIEW);

}

void drawString(char *string)
{
  glMatrixMode(GL_PROJECTION);
  glPushMatrix();
  glLoadIdentity();
  int w = glutGet( GLUT_WINDOW_WIDTH );
  int h = glutGet( GLUT_WINDOW_HEIGHT );
  glOrtho( 0, w, 0, h, -1, 1 );

  glMatrixMode(GL_MODELVIEW);
  glPushMatrix();
  glLoadIdentity();

  glDisable( GL_DEPTH_TEST );

  glDisable( GL_LIGHTING );
  glColor3f(255, 255, 255);

  glRasterPos2i(650, 745);
  void *font = GLUT_BITMAP_TIMES_ROMAN_24;
  for (char* c=string; *c != '\0'; c++)
  {
      glutBitmapCharacter(font, *c);
  }

  glEnable( GL_LIGHTING );
  glMatrixMode(GL_PROJECTION);
  glPopMatrix();
  glMatrixMode(GL_MODELVIEW);
  glPopMatrix();
  glEnable (GL_DEPTH_TEST);
}

void startGame()
{
  glClearColor(0.0039, 0.06, 0.13, 0.0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluOrtho2D(0.0, 800.0, 0.0, 600.0);
  glClear(GL_COLOR_BUFFER_BIT);

  glutFullScreen();
  glClear(GL_COLOR_BUFFER_BIT);
  main_menu("Press SPACE to start  Game ", 500, 500);
  glutSwapBuffers();
}

void endGame()
{

  glutFullScreen();
  glClearColor(0.0039, 0.06, 0.13, 0.0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluOrtho2D(0.0, 800.0, 0.0, 600.0);
  glClear(GL_COLOR_BUFFER_BIT);

  string str,quote = "Score : ", disString = "";
  stringstream ss;
  ss << score;
  str = ss.str();
  disString = quote+str;
  for(int i=0;i<disString.size();i++){
    dis[i] = disString[i];
  }
  main_menu("GAME OVER !!! ", 550, 600);
  main_menu("Your Final ", 500, 500);
  main_menu(dis, 600, 500);
  glutSwapBuffers();

}


void initChar()
{
  if(rotAngle<180){
    rotAngle += 2;
  }
  if(rotAngle==180){

  }
  if(jumping){
    if(jumpOffset<=2.0){
      jumpOffset+=0.15;
    }
    else{
      jumping = false;
    }
  }
  else{
    if(jumpOffset>0.0){
      jumpOffset-=0.15;
    }
    if(jumpOffset<0.0){
      jumpOffset = 0.0;
    }
  }

  if(shifting==1){
    if(shiftAngle<=25){
      shiftAngle+=2;
    }
    else{
      shifting = 0;
    }
  }
  else if(shifting==-1){
    if(shiftAngle>=-25){
      shiftAngle-=2;
    }
    else{
      shifting=0;
    }
  }
  else{
    if(shiftAngle>0){
      shiftAngle-=2;
    }
    if(shiftAngle<0){
      shiftAngle+=2;
    }
  }

  //MOVING IN THE ROADS SPEED
  if(position==1 and charOffset<2.5){
    charOffset+=0.25;
  }
  else if(position==-1 and charOffset>-2.5){
    charOffset-=0.25;
  }
  else if(position==0 and charOffset<0){
    if(charOffset>-0.15){
      charOffset = 0.0;
    }
    else{
      charOffset+=0.25;
    }
  }
  else if(position==0 and charOffset>0){
    if(charOffset<0.15){
      charOffset=0.0;
    }
    else{
      charOffset-=0.25;
    }
  }

}


void drawHUB()
{
  glDisable(GL_DEPTH_TEST);
  glMatrixMode(GL_PROJECTION);
  glPushMatrix();
  glLoadIdentity();
  gluOrtho2D(0.0, 1.0, 1.0, 0.0);
  glMatrixMode(GL_MODELVIEW);
  glPushMatrix();
  glLoadIdentity();

  texture::hub();

  glMatrixMode(GL_PROJECTION);
  glPopMatrix();
  glMatrixMode(GL_MODELVIEW);
  glPopMatrix();
  glEnable(GL_DEPTH_TEST);
}

void display()
{
  glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
  glLoadIdentity();
  initCamera();
  if(levels == 1) drawSceneOne(-charOffset);
  else if(levels == 2) drawSceneTwo(-charOffset);
  else if(levels == 3) drawSceneThree(-charOffset);


  if(gameStart){
    initChar();
    drawChar(rotAngle, jumpOffset, shiftAngle);
  }

  string str,quote = "Score : ", disString = "";
  stringstream ss;
  ss << score;
  str = ss.str();
  disString = quote+str;

  for(int i=0;i<disString.size();i++){
    dis[i] = (char)disString[i];
  }

  drawString(dis);
  glutSwapBuffers();
}

void timer(int)
{
	glutPostRedisplay();
  glutTimerFunc(10, timer, 0);
}

void init()
{
  glEnable(GL_TEXTURE_2D);
  glutFullScreen();
  GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
  GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
  GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
  GLfloat light_position[] = { 0.0f, 6.0f, 8.0f, 0.0f };

  GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
  GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
  GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
  GLfloat high_shininess[] = { 100.0f };

  glEnable(GL_DEPTH_TEST);
  glEnable(GL_LIGHT0);
  glEnable(GL_NORMALIZE);
  glEnable(GL_COLOR_MATERIAL);
  glEnable(GL_LIGHTING);


  glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
  glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
  glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
  glLightfv(GL_LIGHT0, GL_POSITION, light_position);

  glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
  glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
  glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
  glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);


  for(int i=0;i<500;i++){
    pa = - rand() % 13 + (-5);
    leftObs[lc] = pa;
    lc++;
  }

  for(int i=0;i<500;i++){
    pa = rand() % 8 + 6;
    rightObs[rc] = pa;
    rc++;
  }

}

void reshape(int w,int h)
{
  glLoadIdentity();
  glViewport(0, 0, (GLsizei)w, (GLsizei)h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(45.0, (GLfloat)w/(GLfloat)h, 1.0, 800.0);
  glMatrixMode(GL_MODELVIEW);
}

void startRun()
{
  gameStart = true; levels = 1;
  rotAngle = 0, jumpOffset = 0,  shiftAngle = 0;
  charOffset = 0, position = 0;
  jumping = false;
}

void keyboard(unsigned char key, int x, int y)
{
  switch(key){
    case char(32):
      if(!game){
        glutDisplayFunc(display);
        init();
        startGame();

        game = true;
        gameStart = true;
      }
      else{
        if(jumpOffset==0.0){
          PlaySound(TEXT("C:\\Users\\Sourav\\Desktop\\Image Load\\sound\\Jump.wav"), NULL, SND_ASYNC|SND_FILENAME);
          jumping = true;
        }
      }
      break;

    case char(27):
      exit(0);
      break;
    case 'w':
      if(jumpOffset==0.0){
        jumping = true;
        PlaySound(TEXT("C:\\Users\\Sourav\\Desktop\\Image Load\\sound\\Jump.wav"), NULL, SND_ASYNC|SND_FILENAME);
      }
      break;

    case 'd':
      PlaySound(TEXT("C:\\Users\\Sourav\\Desktop\\Image Load\\sound\\SlideX.wav"), NULL, SND_ASYNC|SND_FILENAME);
      shiftAngle = 0.0;
      shifting = 1;
      position++;
      if(position>1){
        position = 1;
      }
      break;

    case 'a':
      PlaySound(TEXT("C:\\Users\\Sourav\\Desktop\\Image Load\\sound\\SlideX.wav"), NULL, SND_ASYNC|SND_FILENAME);
      shiftAngle = 0.0;
      shifting = -1;
      position--;
      if(position<=-1){
        position = -1;
      }
      break;

    default:
      break;
  }
}


int main(int argc, char**argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(640,480);
    glutCreateWindow("Ball Rush");
    glutDisplayFunc(startGame);
    glutReshapeFunc(reshape);

    glutKeyboardFunc(keyboard);
    glutTimerFunc(0, timer, 0);

    glutMainLoop();
    return 0;
}
