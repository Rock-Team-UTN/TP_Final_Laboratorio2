#ifndef TDAUSUARIO_H_INCLUDED
#define TDAUSUARIO_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>

typedef struct
{
    int idUsuario;
    char nombreUsuario[30];
    char pass[50];
    int anioNacimiento;
    char genero;
    char pais[20];
    int playlist[50]; //Guarda los id de las canciones.
    int cantidad; // Es el válidos de la playlist.
    int eliminado;
    int administrador;   // indica 1 o 0 si el cliente fue eliminado
} Usuario;

typedef struct
{
    Usuario dato;
    struct stNodo * siguiente;
} stNodo;


stNodo * inicLista();

stNodo * crearUsuario(Usuario dato);

stNodo * agregarPpio(stNodo * lista,stNodo * nuevo);

stNodo * agregarOrdenado(stNodo * lista,stNodo * nuevo);

stNodo * buscarNodo(int id, stNodo * lista);

stNodo * borrarNodo(stNodo * lista,int id);

stNodo * remplazar(stNodo * lista, stNodo * remplazo);

#endif // TDAUSUARIO_H_INCLUDED
