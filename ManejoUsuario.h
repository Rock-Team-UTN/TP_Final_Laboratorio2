#ifndef MANEJOUSUARIO_H_INCLUDED
#define MANEJOUSUARIO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "tdaUsuario.h"

stNodo * cargarUsuario(Usuario usuario,int id,stNodo * lista,int adm);

stNodo * crearNodoUsu(Usuario dato);

stNodo * cargarMasUsuario(stNodo *lista);

void guardarUsuario(Usuario usuario);

void mostrarTodosArchivo();

void mostrarTodosLista(stNodo * lista);

void mostrarActivosArchivo();

void mostrarActivosLista(stNodo * lista);

void mostrarAlumno(Usuario usuario);

int traerUltimoid();

int contarRegistrosUSU(char archivo[],int pesoDato);

Usuario seleccionarPais(Usuario usuario);

Usuario buscar(Usuario usuario,char buscador[],stNodo * lista);

int buscarUsuario(Usuario usuario,char buscador[],stNodo * lista);

int confirmarAcceso(Usuario usuario,int id,char password[],stNodo * lista);

int confirmarADM(Usuario usuario,char nombre[],stNodo * lista);

stNodo * baja(char nombre[],Usuario usuario,stNodo * lista);

stNodo * altaUsuario(char nombre[],Usuario usuario,stNodo * lista);

stNodo * modificar(Usuario usuario,int opcion,stNodo * lista);

///void misCanciones(Usuario usuario,Cancion cancione,int pos);

///void buscarMiCancion(Usuario usuario,Cancion cancione,int posCancion);

void cursor();



#endif // MANEJOUSUARIO_H_INCLUDED
