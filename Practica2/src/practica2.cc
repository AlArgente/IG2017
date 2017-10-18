//**************************************************************************
// Práctica 1
//
// F.J. melero
//
// GPL
//**************************************************************************
#ifdef _WIN32
#include <windows.h>
#endif
#include "escena.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include <GL/glut.h>
#include <ctype.h>

Escena *escena;

void draw_scene(void) {
  if (escena != NULL)
    escena->dibujar();
  glutSwapBuffers();
}

//***************************************************************************
// Funcion llamada cuando se produce un cambio en el tamaño de la ventana
//
// el evento manda a la funcion:
// nuevo ancho
// nuevo alto
//***************************************************************************

void change_window_size(int newWidth, int newHeight) {
  if (escena != NULL)
    escena->redimensionar(newWidth, newHeight);
  glutPostRedisplay();
}

//***************************************************************************
// Funcion llamada cuando se produce aprieta una tecla normal
//
// el evento manda a la funcion:
// codigo de la tecla
// posicion x del raton
// posicion y del raton
//***************************************************************************

void normal_keys(unsigned char Tecla1, int x, int y) {

  int salir = 0;
  if (escena != NULL)
    salir = escena->teclaPulsada(Tecla1, x, y);
  if (salir) {
    delete escena;
    exit(0);
  } else
    glutPostRedisplay();
}

//***************************************************************************
// Funcion llamada cuando se produce aprieta una tecla especial
//
// el evento manda a la funcion:
// codigo de la tecla
// posicion x del raton
// posicion y del raton

//***************************************************************************

void special_keys(int Tecla1, int x, int y) {
  if (escena != NULL)
    escena->teclaEspecial(Tecla1, x, y);
  glutPostRedisplay();
}

//***************************************************************************
// Programa principal
//
// Se encarga de iniciar la ventana, asignar las funciones e comenzar el
// bucle de eventos
//***************************************************************************

int main(int argc, char **argv) {

  if (argc < 4) {
    cout << "Tiene que pasar al menos 2 argumentos, el fichero ply y si elige "
            "revolución (revo) o cargar (carg) el documento ply y un N para "
            "aplicar revolucion al ply o al perfil de puntos."
         << endl;
    exit(-1);
  }
  bool option = false;

  char comprobar[100];
  strcpy(comprobar, argv[2]);

  if (strcmp(comprobar, "revo") == 0) {
    if (argc < 6 && argc > 3) {
      cout << "Tiene que pasar a parte del nombre del fichero ply un número N, "
              "el eje (x,y,z) y si quiere dibujar las tapas en caso de poder "
              "(S/N)"
           << endl;
    } else if (argc == 6) {
      cout << "Se cargará un ply por revolución" << endl;
      option = true;
    }
  } else if (strcmp(comprobar, "cargar") == 0) {
    cout << "Se cargará un PLY ya generado " << endl;
    option = false;
  }

  escena = new Escena();

  // se llama a la inicialización de glut
  glutInit(&argc, argv);

  // se indica las caracteristicas que se desean para la visualización con
  // OpenGL
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

  // variables que determninan la posicion y tamaño de la ventana X
  int UI_window_pos_x = 50, UI_window_pos_y = 50, UI_window_width = 1024,
      UI_window_height = 800;

  // posicion de la esquina inferior izquierdad de la ventana
  glutInitWindowPosition(UI_window_pos_x, UI_window_pos_y);
  // tamaño de la ventana (ancho y alto)
  glutInitWindowSize(UI_window_width, UI_window_height);

  // llamada para crear la ventana, indicando el titulo
  glutCreateWindow("Práctica 2: Alberto Argente del Castillo Garrido");

  // asignación de la funcion llamada "dibujar" al evento de dibujo
  glutDisplayFunc(draw_scene);
  // asignación de la funcion llamada "cambiar_tamanio_ventana" al evento
  // correspondiente
  glutReshapeFunc(change_window_size);
  // asignación de la funcion llamada "tecla_normal" al evento correspondiente
  glutKeyboardFunc(normal_keys);
  // asignación de la funcion llamada "tecla_Especial" al evento correspondiente
  glutSpecialFunc(special_keys);

  // funcion de inicialización
  if (option) {
    escena->inicializar(UI_window_width, UI_window_height, string(argv[1]),
                        stoi(argv[3]), tolower(*argv[4]), *argv[5]);
  } else {
    escena->inicializar(UI_window_width, UI_window_height, string(argv[1]),
                        stoi(argv[3]));
  }
  // inicio del bucle de eventos
  glutMainLoop();
  return 0;
}
