#ifndef _ESCENA_H
#define _ESCENA_H

#include "cubo.h"
#include "ejes.h"
#include "objectperfil.h"
#include "octaedro.h"
#include "piramide.h"
#include "plyobject.h"
#include "prismahex.h"
#include "tetraedro.h"
#include <GL/gl.h>
#include <GL/glut.h>

class Escena {
private:
// tamaño de los ejes
#define AXIS_SIZE 5000
  string filename;
  int N = 12;
  char ejeR = 'y', d_tapas = 'S';
  Ejes ejes;
  int item;
  float size = 40.0;
  char mode;
  bool first = false, second = false;
  Tetraedro tetraedro; //(40.0);
  Cubo cubo;           // (40.0);
  Piramide piramide;   //(40.0);
  Octaedro octaedro;   // (40.0);
  PrismaHex prismahex; // (40.0);
  PlyObject ply;       // (filename);
  ObjectPerfil revoply;
  ObjectPerfil plybarri;
  /*
  ObjectPerfil revoply; //(filename);*/
  // variables que definen la posicion de la camara en coordenadas polares
  GLfloat Observer_distance;
  GLfloat Observer_angle_x;
  GLfloat Observer_angle_y;

  // variables que controlan la ventana y la transformacion de perspectiva
  GLfloat Width, Height, Front_plane, Back_plane;

private:
  void clear_window();
  void draw_axis();
  void draw_objects();

  // Transformaci�n de c�mara
  void change_projection();
  void change_observer();

public:
  Escena();
  void inicializar(int UI_window_width, int UI_window_height,
                   const string _filename, const int _N, const char _ejeR,
                   const char _tapas);
  void inicializar(int UI_window_width, int UI_window_height,
                   const string _filename, int _N);
  void redimensionar(int newWidth, int newHeight);

  // Dibujar
  void dibujar();

  // Interacci�n con la escena
  int teclaPulsada(unsigned char Tecla1, int x, int y);
  void teclaEspecial(int Tecla1, int x, int y);
};
#endif
