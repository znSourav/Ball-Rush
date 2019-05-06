#include<GL/glut.h>
#include<textures.h>
#include<bits/stdc++.h>

using namespace std;

extern bool gameStart,jumping;
extern void endGame();
extern float charOffset, jumpOffset;
extern int position ,score, lc, rc , levels;
extern int leftObs[1000], rightObs[1000];
float lineObj = 0.0, heightObj = 0.0, offsetObj = 0, line, height, offsetX;
int m=0,i=0,cnt=0;

struct points{
  float offset;
  float line;
  float height;

  bool operator < (const points &a) const {
    return a.offset> offset;
  }
};

set< points >mapOne, mapTwo, mapThree;
set< points >::iterator oneit = mapOne.begin(), twoit = mapTwo.begin(), threeit = mapThree.begin();


void drawChar(float angle, float jumpOffset, float shiftAngle)
{
  glPushMatrix();
  glTranslatef(0.0, jumpOffset, -2.0);
  glRotatef(angle, 0.0, 1.0, 0.0);
  glRotated(shiftAngle, 0.0, 1.0, 1.0);
  glColor3f(0.0f, 0.3f, 1.0f);

//  GLfloat c[] = {0.0, 0.3, 1.0, 1};
//  glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, c);

  //Position,Height Of Ball
  glTranslatef(0.0f, 0.75f, 0.0f);
  glutSolidSphere(0.60f, 20, 20);
  glPopMatrix();
}

void drawObs(float lineObj, float heightObj, float offsetObj)
{
  //OBSTRACLE START
  glPushMatrix();
  glTranslatef(lineObj, heightObj, -offsetObj);  // Move right and into the screen

  glBegin(GL_QUADS);
    glColor3f(0.843f, 0.368f, 0.113f);
    glVertex3f( 1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f,  1.0f);
    glVertex3f( 1.0f, 1.0f,  1.0f);

    // Bottom face (y = -1.0f)
    glColor3f(0.843f, 0.368f, 0.113f);
    glVertex3f( 1.0f, -1.0f,  1.0f);
    glVertex3f(-1.0f, -1.0f,  1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f( 1.0f, -1.0f, -1.0f);

    // Front face  (z = 1.0f)
    glColor3f(0.843f, 0.368f, 0.113f);
    glVertex3f( 1.0f,  1.0f, 1.0f);
    glVertex3f(-1.0f,  1.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f( 1.0f, -1.0f, 1.0f);

    // Back face (z = -1.0f)
    glColor3f(1.0f, 0.0f, 0.0f);     // red
    glVertex3f( 1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f,  1.0f, -1.0f);
    glVertex3f( 1.0f,  1.0f, -1.0f);

    // Left face (x = -1.0f)
    glColor3f(1.0f, 0.0f, 0.0f);     // red
    glVertex3f(-1.0f,  1.0f,  1.0f);
    glVertex3f(-1.0f,  1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f,  1.0f);

    // Right face (x = 1.0f)
    glColor3f(1.0f, 0.0f, 0.0f);     // red
    glVertex3f(1.0f,  1.0f, -1.0f);
    glVertex3f(1.0f,  1.0f,  1.0f);
    glVertex3f(1.0f, -1.0f,  1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);
  glEnd();
  glPopMatrix();
   //OBSTRACLE END
}

void drawTree(float lineObj, float heightObj, float offsetObj)
{
  glPushMatrix();
  glTranslatef(lineObj, heightObj, -offsetObj);  // Move right and into the screen

  glColor3ub (1, 129, 4);
  glBegin(GL_TRIANGLES);
  glVertex2f(0.0f, 2.50f);
  glVertex2f(2.0f, 5.0f);
  glVertex2f(4.0f, 2.5f);

  glVertex2f(0.0f, 1.50f);
  glVertex2f(2.0f, 4.0f);
  glVertex2f(4.0f, 1.50f);
  glEnd();

  glBegin(GL_POLYGON);
  glColor3ub (102, 51, 0);
  glVertex2f(1.75f, 1.5f);
  glVertex2f(2.25f, 1.5f);
  glVertex2f(2.25f, 0.0f);
  glVertex2f(1.75f, 0.0f);

  glEnd();
  glPopMatrix();
}

void drawTreeRound(float lineObj, float heightObj, float offsetObj)
{
  glPushMatrix();
  glTranslatef(lineObj, heightObj, -offsetObj);  // Move right and into the screen

  glColor3ub (128,128,128);

  float theta;
	glBegin(GL_POLYGON);
	glColor3ub(0,255,0);
	for(int i=0;i<360;i++){
    theta= i*3.1416/200;
    glVertex2f( (cos(theta))/1.25, 3+(sin(theta))/1.25 );
  }
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(0,255,0);
	for(int i=0;i<360;i++){
    theta= i*3.1416/200;
    glVertex2f( 1.25+(cos(theta))/1.25, 3+(sin(theta))/1.25 );
  }
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(0,255,0);
	for(int i=0;i<360;i++){
    theta= i*3.1416/200;
    glVertex2f(0.65+ (cos(theta))/1.25, 2.25+(sin(theta))/1.25);
  }
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(106, 56, 37);
	glVertex2f(0.35, 1.5);
	glVertex2f(1.0, 1.5);
	glVertex2f(1.0, 0);
	glVertex2f(0.35, 0);
	glEnd();

  glPopMatrix();
}

void drawTreeDesert(float lineObj, float heightObj, float offsetObj)
{
  glPushMatrix();
  glTranslatef(lineObj, heightObj, -offsetObj);  // Move right and into the screen

  glColor3ub (128,128,128);
  float theta;

	glBegin(GL_POLYGON);
	glColor3ub(213, 159, 16);
	for(int i=0;i<360;i++){
    theta= i*3.1416/200;
    glVertex2f(0.65+ (cos(theta)), 2.25+(sin(theta)));
  }
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(16, 101, 30);
	glVertex2f(0.35, 1.5);
	glVertex2f(1.0, 1.5);
	glVertex2f(1.0, 0);
	glVertex2f(0.35, 0);
	glEnd();

  glPopMatrix();
}

void drawPyramid(float lineObj, float heightObj, float offsetObj)
{
  glPushMatrix();
  glTranslatef(lineObj, heightObj, -offsetObj);  // Move right and into the screen

  glColor3ub (255,153,51);
  glBegin(GL_TRIANGLES);
  glVertex2f(3.2/2, 4.5/2);
  glVertex2f(1.0/2, 1.0/2);
  glVertex2f(5.4/2, 1.0/2);
  glEnd();

  glBegin(GL_TRIANGLES);
  glColor3ub(204,102,0);
  glVertex2f(3.2/2, 4.5/2);
  glVertex2f(0.40/2, 1.8/2);
  glVertex2f(1.00/2, 1.0/2);
  glEnd();

  glPopMatrix();
}
float trackOffset = 0;
points str;

void drawSceneOne(float offset)
{
  glDisable(GL_LIGHTING);
  if(gameStart){
    trackOffset+=0.5;
    cnt++;
    if(cnt==50){
      score++;
      cnt=0;
    }
  }
  if(trackOffset>690){
    trackOffset = 0;
    levels = 2;
  }

  glPushMatrix();

  glTranslatef(0.0, 0.0, trackOffset);
  glTranslatef(offset, 0.0, 0.0);

  texture::surrounding();

  for(offset=30,line=2.55,height=0.15;offset<690;offset+=30){
    drawObs(line,height,offset);
    str.offset= offset;   str.line= line;   str.height=height;
    mapOne.insert(str);
    line-=2.54;
    if(line<-2.55) line=2.55;
  }

  offset = 100; height = 1.5;
  drawObs(0, height, offset+5);
  str.offset = offset+5;  str.line = 0; str.height = height;
  mapOne.insert(str);

  drawObs(2.5,height,offset+10);
  str.offset = offset+10;  str.line = 2.55; str.height = height;
  mapOne.insert(str);

  drawObs(-2.5,height,offset+15);
  str.offset = offset+15;  str.line = -2.55; str.height = height;
  mapOne.insert(str);


  if (oneit == mapOne.end()) oneit = mapOne.begin();

  if(trackOffset>=oneit->offset and trackOffset<(oneit->offset)+1.0){
    if( abs(ceilf( (charOffset-oneit->line) * 100) / 100) < 0.1){
      if(jumpOffset==0.0){
        glutDisplayFunc(endGame);
      }
      else{
        if((jumpOffset-.3)<=oneit->height){
          glutDisplayFunc(endGame);
        }
      }
    }
    oneit++;
  }

  // Left OBSTRACLES
  for(offsetX=30, height=0.55, i=0;offsetX<690;offsetX+=5,i++){
    if(i>=lc) i=0;
    drawObs(leftObs[i],height,offsetX);
  }

  // Right OBSTRACLES
  for(offsetX=30, height=0.55, i=0;offsetX<690;offsetX+=5,i++){
    if(i>=rc) i=0;
    drawObs(rightObs[i],height,offsetX);
  }


  drawObs(14,1.5,50);

  texture::floor();
  texture::road();

  glTranslatef(2.5, 0.0, 0.0);
  texture::road();

  glTranslatef(-5, 0.0, 0.0);
  texture::road();

  glTranslatef(-3, 0.0, 0.0);
  texture::Leftsideroad();

  glTranslatef(5.2, 0.0, 0.0);
  texture::Rightsideroad();

  glPopMatrix();
  glEnable(GL_LIGHTING);

}

void drawSceneTwo(float offset)
{
  glDisable(GL_LIGHTING);
  if(gameStart){
    trackOffset+=0.5;
    cnt++;
    if(cnt==50){
      score++;
      cnt=0;
    }
  }
  if(trackOffset>690){
    trackOffset = 0;
    levels = 3;
  }

  glPushMatrix();

  glTranslatef(0.0, 0.0, trackOffset);
  glTranslatef(offset, 0.0, 0.0);

  texture::sky();

  for(offset=30,line=2.55,height=1.5;offset<690;offset+=30){
    drawTreeRound(line-.5,0.0,offset);
    str.offset= offset;   str.line= line;   str.height=height;
    mapTwo.insert(str);
    line-=2.54;
    if(line<-2.55) line=2.55;
  }

  offset = 100; height = 1.5;
  drawTreeRound(-.5, 0.0, offset+5);
  str.offset = offset+5;  str.line = 0; str.height = height;
  mapTwo.insert(str);

  drawTreeRound(2.0,0.0,offset+10);
  str.offset = offset+10;  str.line = 2.55; str.height = height;
  mapTwo.insert(str);

  drawTreeRound(-3.0,0.0,offset+15);
  str.offset = offset+15;  str.line = -2.55; str.height = height;
  mapTwo.insert(str);

  if (twoit == mapTwo.end()) twoit = mapTwo.begin();

  if(trackOffset>=twoit->offset and trackOffset<(twoit->offset)+1.0){
    if( abs(ceilf( (charOffset-twoit->line) * 100) / 100) < 0.1){
      if(jumpOffset==0.0){
        glutDisplayFunc(endGame);
      }
      else{
        if((jumpOffset-.3)<=twoit->height){
          glutDisplayFunc(endGame);
        }
      }
    }
    twoit++;
  }

  // Left OBSTRACLES
  for(offsetX=30, height=0.15, i=-8.5;offsetX<690;offsetX+=10){
    drawTree(i,height,offsetX); drawTree(i-4,height,offsetX);
    drawTree(i-8,height,offsetX); drawTree(i-12,height,offsetX);
  }

  // Right OBSTRACLES
  for(offsetX=30, height=0.15, i=5;offsetX<690;offsetX+=10){
    drawTree(i,height,offsetX); drawTree(i+4,height,offsetX); drawTree(i+8,height,offsetX);
  }

  texture::grass();
  texture::grassRoad();

  glTranslatef(2.5, 0.0, 0.0);
  texture::grassRoad();

  glTranslatef(-5, 0.0, 0.0);
  texture::grassRoad();

  glTranslatef(-3, 0.0, 0.0);
  texture::LeftsideGrass();

  glTranslatef(5.2, 0.0, 0.0);
  texture::RightsideGrass();

  glPopMatrix();
  glEnable(GL_LIGHTING);

}

void drawSceneThree(float offset)
{
  glDisable(GL_LIGHTING);
  if(gameStart){
    trackOffset+=0.5;
    cnt++;
    if(cnt==50){
      score++;
      cnt=0;
    }
  }
  if(trackOffset>690){
    trackOffset = 0;
    levels = 1;
  }

  glPushMatrix();

  glTranslatef(0.0, 0.0, trackOffset);
  glTranslatef(offset, 0.0, 0.0);

  texture::sun();

  for(offset=30,line=2.55,height=1.15;offset<690;offset+=30){
    drawPyramid(line-1.5,0.0,offset);
    str.offset= offset;   str.line= line;   str.height=height;
    mapThree.insert(str);
    line-=2.54;
    if(line<-2.55) line=2.55;
  }

  offset = 100; height = 1.5;
  drawPyramid(-1.5, 0.0, offset+5);
  str.offset = offset+5;  str.line = 0; str.height = height;
  mapThree.insert(str);

  drawPyramid(1.0, 0.0,offset+10);
  str.offset = offset+10;  str.line = 2.55; str.height = height;
  mapThree.insert(str);

  if (threeit == mapThree.end()) threeit = mapThree.begin();

  if(trackOffset>=threeit->offset and trackOffset<(threeit->offset)+1.0){
    if( abs(ceilf( (charOffset-threeit->line) * 100) / 100) < 0.1){
      if(jumpOffset==0.0){
        glutDisplayFunc(endGame);
      }
      else{
        if((jumpOffset-.3)<=threeit->height){
          glutDisplayFunc(endGame);
        }
      }
    }
    threeit++;
  }

  // Left OBSTRACLES
  for(offsetX=30, height=0.55, i=0;offsetX<690;offsetX+=10,i++){
    if(i>=lc) i=0;
    drawTreeDesert(leftObs[i],height,offsetX);
  }

  // Right OBSTRACLES
  for(offsetX=30, height=0.55, i=0;offsetX<690;offsetX+=10,i++){
    if(i>=rc) i=0;
    drawTreeDesert(rightObs[i],height,offsetX);
  }

  texture::desert();
  texture::desertRoad();

  glTranslatef(2.5, 0.0, 0.0);
  texture::desertRoad();

  glTranslatef(-5, 0.0, 0.0);
  texture::desertRoad();

  glTranslatef(-3, 0.0, 0.0);
  texture::LeftDesert();

  glTranslatef(5.2, 0.0, 0.0);
  texture::RightDesert();

  glPopMatrix();
  glEnable(GL_LIGHTING);

}

void initCamera()
{
  glTranslatef(0.0, -2.0, -7.0);
  glRotatef(15, 1.0, 0.0, 0.0);
}
