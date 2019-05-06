#include<GL/glut.h>
#include<bmpLoader.h>
#include<game.h>

unsigned int roadTex=0, floorTex=0, surroundTex=0, hubTex=0, sideroadTex=0, skyTex=0, grassTex=0, grassRoadTex=0,
              sideGrassTex=0, sunTex=0, desertTex=0, sideDesertTex=0, desertRoadTex=0;

GLuint LoadTexture(const char * filename)
{
  bmpLoader bl(filename);
  GLuint texture;
  glGenTextures(1,&texture);
  glBindTexture(GL_TEXTURE_2D, texture);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, bl.width, bl.height, 0, GL_RGB, GL_UNSIGNED_BYTE, bl.textData);
  return texture;
}
namespace texture
{
  void road()
  {
    if(roadTex==0){
      roadTex = LoadTexture("C:\\Users\\Sourav\\Desktop\\Image Load\\images\\road1.bmp");
    }
    glBindTexture(GL_TEXTURE_2D, roadTex);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
    glBegin(GL_QUADS);
      glTexCoord2f(0.0, 0.0);
      glVertex3f(-0.7, 0.0, 10.0);

      glTexCoord2f(1.0, 0.0);
      glVertex3f(0.7, 0.0, 10.0);

      glTexCoord2f(1.0, 50.0);
      glVertex3f(0.7, 0.0, -690.0);

      glTexCoord2f(0.0, 50.0);
      glVertex3f(-0.7, 0.0, -690.0);

    glEnd();
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
  }

  void Leftsideroad()
  {
    if(sideroadTex==0){
      sideroadTex = LoadTexture("C:\\Users\\Sourav\\Desktop\\Image Load\\images\\sideroad.bmp");
    }
    glBindTexture(GL_TEXTURE_2D, sideroadTex);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
    glBegin(GL_QUADS);
      glTexCoord2f(0.0, 0.0);
      glVertex3f(-18.0, 0.0, 10.0);

      glTexCoord2f(1.0, 0.0);
      glVertex3f(1.0, 0.0, 10.0);

      glTexCoord2f(1.0, 50.0);
      glVertex3f(1.0, 0.0, -690.0);

      glTexCoord2f(0.0, 50.0);
      glVertex3f(-18.0, 0.0, -690.0);

    glEnd();
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
  }

  void Rightsideroad()
  {
    if(sideroadTex==0){
      sideroadTex = LoadTexture("C:\\Users\\Sourav\\Desktop\\Image Load\\images\\sideroad.bmp");
    }
    glBindTexture(GL_TEXTURE_2D, sideroadTex);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
    glBegin(GL_QUADS);
      glTexCoord2f(0.0, 0.0);
      glVertex3f(18.0, 0.0, 10.0);

      glTexCoord2f(1.0, 0.0);
      glVertex3f(5.0, 0.0, 10.0);

      glTexCoord2f(1.0, 50.0);
      glVertex3f(5.0, 0.0, -690.0);

      glTexCoord2f(0.0, 50.0);
      glVertex3f(18.0, 0.0, -690.0);

    glEnd();
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
  }

  void desertRoad()
  {
    if(desertRoadTex==0){
      desertRoadTex = LoadTexture("C:\\Users\\Sourav\\Desktop\\Image Load\\images\\desertRoad.bmp");
    }
    glBindTexture(GL_TEXTURE_2D, desertRoadTex);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
    glBegin(GL_QUADS);
      glTexCoord2f(0.0, 0.0);
      glVertex3f(-0.7, 0.0, 10.0);

      glTexCoord2f(1.0, 0.0);
      glVertex3f(0.7, 0.0, 10.0);

      glTexCoord2f(1.0, 50.0);
      glVertex3f(0.7, 0.0, -690.0);

      glTexCoord2f(0.0, 50.0);
      glVertex3f(-0.7, 0.0, -690.0);

    glEnd();
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
  }


  void grassRoad()
  {
    if(grassRoadTex==0){
      grassRoadTex = LoadTexture("C:\\Users\\Sourav\\Desktop\\Image Load\\images\\grassRoad.bmp");
    }
    glBindTexture(GL_TEXTURE_2D, grassRoadTex);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
    glBegin(GL_QUADS);
      glTexCoord2f(0.0, 0.0);
      glVertex3f(-0.7, 0.0, 10.0);

      glTexCoord2f(1.0, 0.0);
      glVertex3f(0.7, 0.0, 10.0);

      glTexCoord2f(1.0, 50.0);
      glVertex3f(0.7, 0.0, -690.0);

      glTexCoord2f(0.0, 50.0);
      glVertex3f(-0.7, 0.0, -690.0);

    glEnd();
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
  }

  void LeftsideGrass()
  {
    if(sideGrassTex==0){
      sideGrassTex = LoadTexture("C:\\Users\\Sourav\\Desktop\\Image Load\\images\\sideGrass.bmp");
    }
    glBindTexture(GL_TEXTURE_2D, sideGrassTex);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
    glBegin(GL_QUADS);
      glTexCoord2f(0.0, 0.0);
      glVertex3f(-18.0, 0.0, 10.0);

      glTexCoord2f(1.0, 0.0);
      glVertex3f(1.0, 0.0, 10.0);

      glTexCoord2f(1.0, 50.0);
      glVertex3f(1.0, 0.0, -690.0);

      glTexCoord2f(0.0, 50.0);
      glVertex3f(-18.0, 0.0, -690.0);

    glEnd();
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
  }

  void RightsideGrass()
  {
    if(sideGrassTex==0){
      sideGrassTex = LoadTexture("C:\\Users\\Sourav\\Desktop\\Image Load\\images\\sideGrass.bmp");
    }
    glBindTexture(GL_TEXTURE_2D, sideGrassTex);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
    glBegin(GL_QUADS);
      glTexCoord2f(0.0, 0.0);
      glVertex3f(18.0, 0.0, 10.0);

      glTexCoord2f(1.0, 0.0);
      glVertex3f(5.0, 0.0, 10.0);

      glTexCoord2f(1.0, 50.0);
      glVertex3f(5.0, 0.0, -690.0);

      glTexCoord2f(0.0, 50.0);
      glVertex3f(18.0, 0.0, -690.0);

    glEnd();
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
  }

  void floor()
  {
    if(floorTex==0){
      floorTex = LoadTexture("C:\\Users\\Sourav\\Desktop\\Image Load\\images\\lava.bmp");
    }
    glBindTexture(GL_TEXTURE_2D, floorTex);
    glColor3f(0.0, 1.0, 0.0);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
    glPushMatrix();
    glTranslatef(0.0, -0.1, 0.0);
    glBegin(GL_QUADS);
      glColor3f(0.5,0.5,0.5);

      glTexCoord2f(0.0, 0.0);
      glVertex3f(-5.0, 0.0, 5.0);

      glTexCoord2f(3.0, 0.0);
      glVertex3f(5.0, 0.0, 5.0);

      glTexCoord2f(3.0, 50.0);
      glVertex3f(5.0, 0.0, -695.0);

      glTexCoord2f(0.0, 50.0);
      glVertex3f(-5.0, 0.0, -695.0);
    glEnd();
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    glPopMatrix();
  }

  void grass()
  {
    if(grassTex==0){
      grassTex = LoadTexture("C:\\Users\\Sourav\\Desktop\\Image Load\\images\\grass.bmp");
    }
    glBindTexture(GL_TEXTURE_2D, grassTex);
    glColor3f(0.0, 1.0, 0.0);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
    glPushMatrix();
    glTranslatef(0.0, -0.1, 0.0);
    glBegin(GL_QUADS);
      glColor3f(0.5,0.5,0.5);

      glTexCoord2f(0.0, 0.0);
      glVertex3f(-5.0, 0.0, 5.0);

      glTexCoord2f(1.0, 0.0);
      glVertex3f(5.0, 0.0, 5.0);

      glTexCoord2f(1.0, 50.0);
      glVertex3f(5.0, 0.0, -695.0);

      glTexCoord2f(0.0, 50.0);
      glVertex3f(-5.0, 0.0, -695.0);
    glEnd();
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    glPopMatrix();
  }

  void desert()
  {
    if(desertTex==0){
      desertTex = LoadTexture("C:\\Users\\Sourav\\Desktop\\Image Load\\images\\desert.bmp");
    }
    glBindTexture(GL_TEXTURE_2D, desertTex);
    glColor3f(0.0, 1.0, 0.0);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
    glPushMatrix();
    glTranslatef(0.0, -0.1, 0.0);
    glBegin(GL_QUADS);
      glColor3f(0.5,0.5,0.5);

      glTexCoord2f(0.0, 0.0);
      glVertex3f(-5.0, 0.0, 5.0);

      glTexCoord2f(3.0, 0.0);
      glVertex3f(5.0, 0.0, 5.0);

      glTexCoord2f(3.0, 50.0);
      glVertex3f(5.0, 0.0, -695.0);

      glTexCoord2f(0.0, 50.0);
      glVertex3f(-5.0, 0.0, -695.0);
    glEnd();
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    glPopMatrix();
  }

  void LeftDesert()
  {
    if(sideDesertTex==0){
      sideDesertTex = LoadTexture("C:\\Users\\Sourav\\Desktop\\Image Load\\images\\desert.bmp");
    }
    glBindTexture(GL_TEXTURE_2D, sideDesertTex);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
    glBegin(GL_QUADS);
      glTexCoord2f(0.0, 0.0);
      glVertex3f(-18.0, 0.0, 10.0);

      glTexCoord2f(1.0, 0.0);
      glVertex3f(1.0, 0.0, 10.0);

      glTexCoord2f(1.0, 50.0);
      glVertex3f(1.0, 0.0, -690.0);

      glTexCoord2f(0.0, 50.0);
      glVertex3f(-18.0, 0.0, -690.0);

    glEnd();
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
  }

  void RightDesert()
  {
    if(sideDesertTex==0){
      sideDesertTex = LoadTexture("C:\\Users\\Sourav\\Desktop\\Image Load\\images\\desert.bmp");
    }
    glBindTexture(GL_TEXTURE_2D, sideDesertTex);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
    glBegin(GL_QUADS);
      glTexCoord2f(0.0, 0.0);
      glVertex3f(18.0, 0.0, 10.0);

      glTexCoord2f(1.0, 0.0);
      glVertex3f(5.0, 0.0, 10.0);

      glTexCoord2f(1.0, 50.0);
      glVertex3f(5.0, 0.0, -690.0);

      glTexCoord2f(0.0, 50.0);
      glVertex3f(18.0, 0.0, -690.0);

    glEnd();
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
  }

  void surrounding()
  {
    if(surroundTex==0){
      surroundTex = LoadTexture("C:\\Users\\Sourav\\Desktop\\Image Load\\images\\cave.bmp");
    }
    glBindTexture(GL_TEXTURE_2D, surroundTex);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
    glPushMatrix();
    glTranslatef(0.0, -400.0, -700.0);
    glBegin(GL_QUADS);
      glTexCoord2f(0.0, 0.0);
      glVertex2f(-640, -640);

      glTexCoord2f(1.0, 0.0);
      glVertex2f(640, -640);

      glTexCoord2f(1.0, 1.0);
      glVertex2f(640, 640);

      glTexCoord2f(0.0, 1.0);
      glVertex2f(-640, 640);
    glEnd();
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    glPopMatrix();
  }

  void sky()
  {
    if(skyTex==0){
      skyTex = LoadTexture("C:\\Users\\Sourav\\Desktop\\Image Load\\images\\sky.bmp");
    }
    glBindTexture(GL_TEXTURE_2D, skyTex);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
    glPushMatrix();
    glTranslatef(0.0, -400.0, -700.0);
    glBegin(GL_QUADS);
      glTexCoord2f(0.0, 0.0);
      glVertex2f(-640, -640);

      glTexCoord2f(1.0, 0.0);
      glVertex2f(640, -640);

      glTexCoord2f(1.0, 1.0);
      glVertex2f(640, 640);

      glTexCoord2f(0.0, 1.0);
      glVertex2f(-640, 640);
    glEnd();
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    glPopMatrix();
  }

  void sun()
  {
    if(sunTex==0){
      sunTex = LoadTexture("C:\\Users\\Sourav\\Desktop\\Image Load\\images\\sun.bmp");
    }
    glBindTexture(GL_TEXTURE_2D, sunTex);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
    glPushMatrix();
    glTranslatef(0.0, -400.0, -700.0);
    glBegin(GL_QUADS);
      glTexCoord2f(0.0, 0.0);
      glVertex2f(-640, -640);

      glTexCoord2f(1.0, 0.0);
      glVertex2f(640, -640);

      glTexCoord2f(1.0, 1.0);
      glVertex2f(640, 640);

      glTexCoord2f(0.0, 1.0);
      glVertex2f(-640, 640);
    glEnd();
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    glPopMatrix();
  }

  void hub()
  {
    if (hubTex == 0){
      hubTex = LoadTexture("C:\\Users\\Sourav\\Desktop\\Image Load\\images\\test.bmp");
    }
    glBindTexture(GL_TEXTURE_2D, hubTex);
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);

    glTexCoord2f(0.0, 1.0);
    glVertex2f(0.05, 0.05);

    glTexCoord2f(1.0, 1.0);
    glVertex2f(0.3, 0.05);

    glTexCoord2f(1.0, 0.0);
    glVertex2f(0.3, 0.15);

    glTexCoord2f(0.0, 0.0);
    glVertex2f(0.05, 0.15);

    glEnd();
  }
}
