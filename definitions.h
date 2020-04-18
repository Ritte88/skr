#include <linux/input.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
# define BLANK -1

# define TRUE 1
# define FALSE 0

# define EV_SIZE 24

# define TECLA_MANTENIDA 2
# define TECLA_PRESIONADA 1
# define TECLA_SOLTADA 0

// Define la estructura de un remapeo de una tecla
struct keyRemap {
    // Patron de keycodes
    int from;
    int to; // to TIENE que ser diferente de 0
};

// Defina la estructura de mapeo de una combinación de teclas
// a un comando o script
struct scripLaunch {
    int from[8];

    // Tipo de acción en la que se ejecuta el
    // script o comando:
    //      TECLA_PRESIONADA, TECLA_SOLTADA o TECLA_MANTENIDA
    int onAction;

    // Script o comando
    char *to;
};

struct input_event rap1; // Inicio de evento
struct input_event rap2; // Finalización de evento
struct input_event event; // Plantilla para enviar un evento KEY
struct input_event ev; // Evento leido de la entrada cruda del teclado

// Lista con todos los remaps definidos por el usuario
struct keyRemap remaps[256];

// Lista con todos los remaps definidos por el usuario
struct scripLaunch scripts[256];

// De input se leen los eventos de teclado
FILE *input;

// Al archivo teclado se escriben los eventos
FILE *teclado;

// Indice del keyRemap recien eviado 
int remapEnviado;

// Indice del script recien eviado 
int scriptEnviado;

// teclas guarda la o las teclas presionadas en el momento
int teclas[8]={BLANK,BLANK,BLANK,BLANK,BLANK,BLANK,BLANK,BLANK};
