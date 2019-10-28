#include "tdaUsuario.h"

stNodo * inicLista()
{
    return NULL;
}
stNodo * crearUsuario(Usuario dato)
{
    stNodo * aux=(stNodo*)malloc(sizeof(stNodo));
    aux->dato=dato;
    aux->siguiente=NULL;
    return aux;
}
stNodo * agregarPpio(stNodo * lista,stNodo * nuevo)
{
    if(lista==NULL)
    {
        lista=nuevo;
    }
    else
    {
        nuevo->siguiente=lista;
        lista=nuevo;
    }
    return lista;
}
stNodo * agregarOrdenado(stNodo * lista,stNodo * nuevo)
{
    if(lista==NULL)
    {
        lista=nuevo;
    }
    else
    {


        if(strcmp(lista->dato.nombreUsuario,nuevo->dato.nombreUsuario)>0)
        {
            lista=agregarPpio(lista,nuevo);
        }
        else
        {
            stNodo * ante=lista;
            stNodo * seg=lista->siguiente;

            while(lista!=NULL && strcmp(seg->dato.nombreUsuario,nuevo->dato.nombreUsuario)<0)
            {
                ante=seg;
                seg=seg->siguiente;
            }

            nuevo->siguiente=seg;
            ante->siguiente=nuevo;

        }
    }

    return lista;
}

stNodo * buscarNodo(int id,stNodo * lista)
{


    stNodo * seg;
    seg = lista;

    while ((seg != NULL) &&  id != seg->dato.idUsuario)
    {
        seg=seg->siguiente;
    }

    return seg;
}

stNodo * remplazar(stNodo * lista, stNodo * remplazo){
    if((lista!= NULL)&& lista == remplazar){
        lista->dato=remplazo->dato;
    }else{
        lista=remplazar(lista->siguiente,remplazo);
    }
return lista;
}

stNodo * borrarNodo(stNodo * lista,int id)
{
    stNodo * seg;
    stNodo * ante;
    if((lista != NULL) && id == lista->dato.idUsuario)
    {

        stNodo * aux = lista;

        lista = lista->siguiente;
        free(aux);
    }
    else
    {
        seg = lista;
        while((seg != NULL) && seg->dato.idUsuario != id )
        {
            ante = seg;
            seg = seg->siguiente;
        }

        if(seg!=NULL)
        {
            ante->siguiente = seg->siguiente;

            free(seg);

        }
    }
    return lista;
}
