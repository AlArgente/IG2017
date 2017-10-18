#ifdef _WIN32
#include <windows.h>
#endif

#include "escena.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include <GL/gl.h>
#include <GL/glut.h>
#include <cstdio>
#include <ctype.h>
#include <iostream>

using namespace std;

Escena::Escena() {
  item = 1;
  mode = 'F';
  Front_plane = 50;
  Back_plane = 2000;
  Observer_distance = 4 * Front_plane;
  Observer_angle_x = Observer_angle_y = 0;
  ejes.changeAxisSize(5000);
}

void Escena::inicializar(int UI_window_width, int UI_window_height,
                         const string _filename, const int _N, const char _ejeR,
                         const char _tapas) {
  // Width, Height, filename, N, ejeR, d_tapas
  glClearColor(1, 1, 1, 1); // se indica cual sera el color para limpiar la
                            // ventana	(r,v,a,al)

  glEnable(GL_DEPTH_TEST); // se habilita el z-bufer
  filename = _filename;
  N = _N;
  ejeR = _ejeR;
  d_tapas = _tapas;
  this->change_projection();
  Width = UI_window_width / 10;
  Height = UI_window_height / 10;
  glViewport(0, 0, UI_window_width, UI_window_height);
  tetraedro = Tetraedro(40.0);
  cubo = Cubo(40.0);
  piramide = Piramide(40.0);
  octaedro = Octaedro(40.0);
  prismahex = PrismaHex(40.0);
  ply = PlyObject(filename);
  revoply = ObjectPerfil(filename, N, ejeR, d_tapas);
  plybarri.initialice3(40.0, 80);
  first = true;
}

void Escena::inicializar(int UI_window_width, int UI_window_height,
                         const string _filename, int _N) {
  // Width, Height, filename, N
  glClearColor(1, 1, 1, 1); // se indica cual sera el color para limpiar la
                            // ventana	(r,v,a,al)

  glEnable(GL_DEPTH_TEST); // se habilita el z-bufer
  filename = _filename;
  N = _N;
  this->change_projection();
  Width = UI_window_width / 10;
  Height = UI_window_height / 10;
  glViewport(0, 0, UI_window_width, UI_window_height);
  tetraedro = Tetraedro(40.0);
  cubo = Cubo(40.0);
  piramide = Piramide(40.0);
  octaedro = Octaedro(40.0);
  prismahex = PrismaHex(40.0);
  ply = PlyObject(filename);
  revoply.initialice2(N, ejeR, d_tapas);
  plybarri.initialice3(40.0, 80);
  second = true;
}

//**************************************************************************
// Funcion que dibuja objetos en la escena
//**************************************************************************
void Escena::draw_objects() {

  // Tetraedro tetraedro(40.0);
  // Cubo cubo(40.0);
  // Piramide piramide(40.0);
  // Octaedro octaedro(40.0);
  // PrismaHex prismahex(40.0);
  // PlyObject ply(filename);
  // ObjectPerfil revoply(filename, N, ejeR, d_tapas);
  // ObjectPerfil revoply(N, ejeR, d_tapas);

  if (item == 1) {
    tetraedro.dibujar(mode);
  }
  if (item == 2) {
    cubo.dibujar(mode);
  }
  if (item == 3) {
    piramide.dibujar(mode);
  }
  if (item == 4) {
    octaedro.dibujar(mode);
  }
  if (item == 5) {
    prismahex.dibujar(mode);
  }
  if (item == 6) {
    ply.dibujar(mode);
  }
  if (item == 7) {
    revoply.dibujar(mode);
  }
  if (item == 8) {
    plybarri.dibujar(mode);
  }
}

void Escena::dibujar() {

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Limpiar la pantalla
  change_observer();
  draw_axis();
  draw_objects();
}

int Escena::teclaPulsada(unsigned char Tecla1, int x, int y) {

  std::cout << "Tecla" << Tecla1 << std::endl;
  if (toupper(Tecla1) == 'Q')
    return 0;
  if (toupper(Tecla1) == '1') {
    item = 1;
    cout << "Dibujando el tetraedro." << endl;
    return 0;
  } else if (toupper(Tecla1) == '2') {
    item = 2;
    cout << "Dibujando el cubo." << endl;
    return 0;
  } else if (toupper(Tecla1) == '3') {
    item = 3;
    cout << "Dibujando la pirámide." << endl;
    return 0;
  } else if (toupper(Tecla1) == '4') {
    item = 4;
    cout << "Dibujando el octaedro." << endl;
    return 0;
  } else if (toupper(Tecla1) == '5') {
    item = 5;
    cout << "Dibujando el prisma hexagonal." << endl;
    return 0;
  } else if (toupper(Tecla1) == '6') {
    item = 6;
    cout << "Dibujando el modelo ply cargado." << endl;
    return 0;
  } else if (toupper(Tecla1) == '7') {
    item = 7;
    cout << "Dibujando el modelo ply por revolución." << endl;
    return 0;
  } else if (toupper(Tecla1) == '8') {
    item = 8;
    cout << "Dibujando un objeto predeterminado por barrido." << endl;
    return 0;
  }
  if (toupper(Tecla1) == 'P') {
    mode = 'P';
    cout << "Dibujando el modo puntos." << endl;
    return 0;
  } else if (toupper(Tecla1) == 'L') {
    mode = 'L';
    cout << "Dibujando el modo líneas." << endl;
    return 0;
  } else if (toupper(Tecla1) == 'F') {
    mode = 'F';
    cout << "Dibujando el modo sólido." << endl;
    return 0;
  } else if (toupper(Tecla1) == 'C') {
    mode = 'C';
    cout << "Dibujando el modo ajedrez." << endl;
    return 0;
  } else if (toupper(Tecla1) == 'A') {
    mode = 'A';
    cout << "Dibujando todo a la vez." << endl;
    return 0;
  } else if (toupper(Tecla1) == 'N') {
    int _N;
    cout << "Introduzca el N nuevo para aplicar revolución: " << endl;
    cin >> _N;
    if (first) {
      revoply.clear();
      plybarri.clear();
      this->inicializar(Width * 10, Height * 10, filename, _N, ejeR, d_tapas);
    } else if (second) {
      ply.clear();
      revoply.clear();
      plybarri.clear();
      this->inicializar(Width * 10, Height * 10, filename, _N);
    }
    return 0;
  } else if (toupper(Tecla1) == 'T') {
    if (first) {
      if (d_tapas == 'S') {
        d_tapas = 'N';
      } else {
        d_tapas = 'S';
      }
      revoply.clear();
      plybarri.clear();
      this->inicializar(Width * 10, Height * 10, filename, N, ejeR, d_tapas);
    }
    return 0;
  }
}

void Escena::teclaEspecial(int Tecla1, int x, int y) {
  switch (Tecla1) {
  case GLUT_KEY_LEFT:
    Observer_angle_y--;
    break;
  case GLUT_KEY_RIGHT:
    Observer_angle_y++;
    break;
  case GLUT_KEY_UP:
    Observer_angle_x--;
    break;
  case GLUT_KEY_DOWN:
    Observer_angle_x++;
    break;
  case GLUT_KEY_PAGE_UP:
    Observer_distance *= 1.2;
    break;
  case GLUT_KEY_PAGE_DOWN:
    Observer_distance /= 1.2;
    break;
  }

  std::cout << Observer_distance << std::endl;
}

//**************************************************************************
// Funcion para definir la transformaci�n de proyeccion
//***************************************************************************

void Escena::change_projection() {
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glFrustum(-Width, Width, -Height, Height, Front_plane, Back_plane);
}

void Escena::redimensionar(int newWidth, int newHeight) {
  change_projection();
  Width = newWidth / 10;
  Height = newHeight / 10;
  glViewport(0, 0, newWidth, newHeight);
}

//**************************************************************************
// Funcion para definir la transformaci�n de vista (posicionar la camara)
//***************************************************************************

void Escena::change_observer() {

  // posicion del observador
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glTranslatef(0, 0, -Observer_distance);
  glRotatef(Observer_angle_x, 1, 0, 0);
  glRotatef(Observer_angle_y, 0, 1, 0);
}

//**************************************************************************
// Funcion que dibuja los ejes utilizando la primitiva grafica de lineas
//***************************************************************************

void Escena::draw_axis() { ejes.draw(); }
