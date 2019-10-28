#include "ManejoUsuario.h"

stNodo * cargarUsuario(Usuario usuario,int id,stNodo * lista,int adm)
{
    int i=0;
    char c;
    int existente;
    char nombre[50];

    printf("\t\t\t\t<<<<<<INGRESE NOMBRE USUARIO>>>>>>\n\n\t\t\t\t\t");
    fflush(stdin);
    gets(nombre);
    existente=buscarUsuario(usuario,nombre,lista);

    if(existente == -1)
    {
        strcpy(usuario.nombreUsuario,nombre);
        printf("\n\t\t\t\t<<<<<<<<<<INGRESE PASSWORD>>>>>>>>\n\n\t\t\t\t\t");
        fflush(stdin);
        while((c=getch())!=13)
        {
            usuario.pass[i]=c;
            i++;

            printf("*");
        }
        usuario.pass[i]='\0';
        printf("\n");
        printf("\n\t\t\t\t<<<<INGRESE AÑO DE NACIMIENTO>>>>>>\n\n\t\t\t\t\t");
        fflush(stdin);
        scanf("%i",&usuario.anioNacimiento);

        printf("\n\t\t\t\t<<<<<<<<<<<<INGRESE GENERO>>>>>>>>>>\n\n\t\t\t\t\t");
        printf("\n\t\t\t\t  MASCULINO : m         FEMENINO : f \n\n\t\t\t\t\t");
        fflush(stdin);
        scanf("%c",&usuario.genero);

        usuario=seleccionarPais(usuario);

        id=id+1;
        usuario.idUsuario=id;
        usuario.eliminado=0;
        usuario.cantidad=0;
        if(adm == 1)
        {
            usuario.administrador=1;
        }
        else
        {
            usuario.administrador=0;
        }

        lista=agregarOrdenado(lista,crearNodoUsu(usuario));
        guardarUsuario(usuario);
    }
    else
    {
        printf("\t\t\t\tUsuario existente ingrese con otro nombre\n");
        getch();
    }
    return lista;
}

stNodo * cargarMasUsuario(stNodo *lista)
{
    Usuario usuario;
    char control;
    int pos;
    do
    {
        pos=traerUltimoid();
        lista=cargarUsuario(usuario,pos,lista,0);
        printf("\n\t\t\t\tDesea seguir cargando\n");
        fflush(stdin);
        scanf("%c",&control);
    }
    while(control != 27);
    return lista;
}
void guardarUsuario(Usuario usuario)
{
    FILE *archi=fopen("archivo","ab");
    if(archi!=NULL)
    {
        fwrite(&usuario,sizeof(Usuario),1,archi);
        fclose(archi);
    }

}
void mostrarTodosArchivo()
{
    Usuario usuario;
    FILE *archi=fopen("archivo","rb");
    if(archi!=NULL)
    {
        while(fread(&usuario,sizeof(Usuario),1,archi)>0)
        {
            mostrarAlumno(usuario);
        }

    }
    fclose(archi);
}
void mostrarTodosLista(stNodo * lista)
{
    Usuario usuario;
    if(lista!=NULL)
    {
        mostrarAlumno(lista->dato);
        mostrarTodosLista(lista->siguiente);
    }
}
void mostrarActivosArchivo()
{
    Usuario usuario;
    FILE *archi=fopen("archivo","rb");
    if(archi!=NULL)
    {
        while(fread(&usuario,sizeof(Usuario),1,archi)>0)
        {
            if(usuario.eliminado==0)
            {
                mostrarAlumno(usuario);
            }

        }

    }
    fclose(archi);
}
void mostrarActivosLista(stNodo * lista)
{
    Usuario usuario;
    if(lista!=NULL)
    {
        if(lista->dato.eliminado == 0)
        {
            mostrarAlumno(lista->dato);
        }
        mostrarActivosLista(lista->siguiente);

    }
}
void mostrarAlumno(Usuario usuario)
{
    printf("\t\t\t\t");
    linea(40);
    if(usuario.administrador==1)
    {
        printf("\t\t\t\tAdministrador\n\n");
    }
    printf("\t\t\t\tID del usuario:     \t%i\n",usuario.idUsuario);
    printf("\t\t\t\tNombre:             \t%s\n",usuario.nombreUsuario);
    printf("\t\t\t\tContracenia:        \t%s\n",usuario.pass);
    printf("\t\t\t\tGenero:             \t%c\n",usuario.genero);
    printf("\t\t\t\tAnio de nacimiento: \t%i\n",usuario.anioNacimiento);
    printf("\t\t\t\tPais de origen:     \t%s\n",usuario.pais);

    printf("\t\t\t\tEliminado:          \t%i\n",usuario.eliminado);
    printf("\t\t\t\tCantidad de canciones: \t%i\n",usuario.cantidad);
    printf("\t\t\t\t");
    linea(40);
    color(10);

}
int traerUltimoid()
{
    Usuario usuario;
    int id=-1;
    FILE*archi=fopen("archivo","rb");
    if(archi!=NULL)
    {
        fseek(archi,sizeof(Usuario)*(-1),SEEK_END);
        if(fread(&usuario,sizeof(Usuario),1,archi)>0)
        {
            id=usuario.idUsuario;
        }
        fclose(archi);
    }
    return id;
}
int contarRegistrosUSU(char archivo[],int pesoDato)
{
    int total=0;
    FILE *archi=fopen("archivo","rb");
    if(archi!=NULL)
    {
        fseek(archi,0,SEEK_END);
        total=ftell(archi)/pesoDato;
    }
    return total;
}
Usuario seleccionarPais(Usuario usuario)
{
    int selec;

    printf("\t\t\t\t<<<<<<<<<<INGRESE PAIS DE ORIGEN>>>>>>>>\n\n\t\t\t\t\t");
    printf("1:Argentina\t2:Bolivia\t3:Chile\n\t\t\t\t\t4:Uruguay\t5:Paraguay\t6:Peru\n\t\t\t\t\t7:Brasil\n\t\t\t\t\t");
    fflush(stdin);
    scanf("%i",&selec);
    switch(selec)
    {
    case 1:

        strcpy(usuario.pais,"Argentina");
        break;
    case 2:
        strcpy(usuario.pais,"Bolivia");
        break;
    case 3:
        strcpy(usuario.pais,"Chile");
        break;
    case 4:
        strcpy(usuario.pais,"Uruguay");
        break;
    case 5:
        strcpy(usuario.pais,"Paraguay");
        break;
    case 6:
        strcpy(usuario.pais,"Peru");
        break;
    case 7:
        strcpy(usuario.pais,"Brasil");
        break;

    }
    return usuario;
}
void linea(int largo)
{
    int i;
    for(i=0; i<largo; i++)
    {
        printf("%c",205);
    }
    printf("\n");
}
Usuario buscar(Usuario usuario,char buscador[],stNodo * lista)
{
    Usuario aux;
    stNodo * seg=iniclista();
    int id=-1;
    int flag=0;
    int val;
    if(lista!=NULL)
    {
        if(strcmp(lista->dato.nombreUsuario,buscador)== 0)
        {
            aux=lista->dato;
        }
        else
        {
            aux=buscar(usuario,buscador,lista->siguiente);
        }



    }
    return aux;
}
int buscarUsuario(Usuario usuario,char buscador[],stNodo * lista)
{
    int flag=0;
    int id=-1;

    if(lista!=NULL)
    {
        if(strcmp(lista->dato.nombreUsuario,buscador)==0)
        {
            id=usuario.idUsuario;
            flag=1;
        }
        else
        {
            id=buscarUsuario(usuario,buscador,lista);
        }
    }
    return id;
}
int confirmarAcceso(Usuario usuario,int id,char password[],stNodo * lista)
{
    int flag=0;
    int acceso=0;
    if(lista!=NULL)
    {
        if(lista->dato.idUsuario == id)
        {
            if(strcmp(lista->dato.pass,password)==0)
            {
                acceso=1;
            }
        }
        else
        {
            acceso=confirmarAcceso(usuario,id,password,lista);
        }
    }
    return acceso;
}
int confirmarADM(Usuario usuario,char nombre[],stNodo * lista)
{
    int adm=0;
    usuario=buscar(usuario,nombre,lista);
    adm=usuario.administrador;
    return adm;
}
stNodo * baja(char nombre[],Usuario usuario,stNodo * lista)
{
    int pos;
    Usuario aux;
    int confirmacion=buscarUsuario(usuario,nombre,lista);
    if(confirmacion!=-1)
    {
        aux=buscar(usuario,nombre,lista);
        pos=aux.idUsuario;
        aux.eliminado=1;
        FILE *archi=fopen("archivo","r+b");
        if(archi!=NULL && confirmacion!=-1)
        {
            fseek(archi,sizeof(Usuario)*pos,SEEK_SET);
            fwrite(&aux,sizeof(Usuario),1,archi);
            fclose(archi);
            confirmacion=1;
            lista=borrarNodo(lista,pos);
        }

    }
    else
    {
        printf("\t\t\t\tEl usuario ingresado no existe\n");
        getch();
    }
    return confirmacion;
}
stNodo * altaUsuario(char nombre[],Usuario usuario,stNodo * lista){
    int pos;
    Usuario aux;
    int confirmacion=buscarUsuario(usuario,nombre,lista);
    if(confirmacion!=-1)
    {
        aux=buscar(usuario,nombre,lista);
        pos=aux.idUsuario;
        aux.eliminado=0;
        FILE *archi=fopen("archivo","r+b");
        if(archi!=NULL && confirmacion!=-1)
        {
            fseek(archi,sizeof(Usuario)*pos,SEEK_SET);
            fwrite(&aux,sizeof(Usuario),1,archi);
            fclose(archi);
            lista=agregarOrdenado(lista,crearUsuario(aux));

        }

    }
    else
    {
        printf("\t\t\t\tEl usuario ingresado no existe\n");
        getch();
    }
    return lista;
}
void Logo()
{
    color(5);
    char barra=92;
    printf("\n\n\n");
    printf("\t\t\t\t\t\t|~~~~~~~~|\n");
    printf("\t\t\t\t\t\t|~~~~~~~~|\n");
    printf("\t\t\t\t\t\t|        |\n");
    printf("\t\t\t\t\t    /~~%c|    /~~%c|\n",barra,barra);
    printf("\t\t\t\t\t    %c__/     %c__/)\n",barra,barra);


    color(11);
    printf("\t\t\t\t");
    linea(40);
    printf("\t\t\t\t                 PRISNA                 \n");
    printf("\t\t\t\t");
    linea(40);
    color(10);
}
stNodo * modificar(Usuario usuario,int opcion,stNodo * lista)
{
//caso 1: cambia nombre//caso 2:cambia contraseña//case 3:cambia edad//caso 4: cambia pais;
    char nomPass[50];
    int edad;
    switch(opcion)
    {
    case 1:
        printf("\t\t\t\tIngrese nombre para remplazar\n");
        printf("\t\t\t\tNombre anterior : %s\n",usuario.nombreUsuario);
        printf("\t\t\t\tNuevo nombre : ");
        fflush(stdin);
        gets(nomPass);
        strcpy(usuario.nombreUsuario,nomPass);
        getch();
        break;
    case 2:
        printf("\t\t\t\tIngrese contrasenia nueva\n");
        printf("\t\t\t\tContrasenia anterior : %s\n",usuario.pass);
        printf("\t\t\t\tNueva contrasenia : ");
        fflush(stdin);
        gets(nomPass);
        strcpy(usuario.pass,nomPass);
        getch();
        break;
    case 3:
        printf("\t\t\t\tIngrese edad nueva\n");
        printf("\t\t\t\tEdad anterior : %i\n",usuario.anioNacimiento);
        printf("\t\t\t\tEdad nueva : ");
        fflush(stdin);
        scanf("%i",&edad);
        usuario.anioNacimiento=edad;
        break;
    case 4:
        usuario=seleccionarPais(usuario);
        break;
    }
    mostrarAlumno(usuario);
    lista=remplazar(lista,crearUsuario(usuario));
    FILE *archi=fopen("archivo","r+b");
    if(archi!=NULL)
    {
        fseek(archi,sizeof(Usuario)*usuario.idUsuario,SEEK_SET);
        fwrite(&usuario,sizeof(Usuario),1,archi);
        fclose(archi);
        getch();
    }
return lista;
}
/*void misCanciones(Usuario usuario,Cancion cancione,int pos)
{
    int minutos;
    int segundos;
    FILE *cancionArchi=fopen(arCancion,"rb");
    FILE *usuarioArchi=fopen("archivo","rb");
    int i=0;
    if(cancionArchi!=NULL && usuarioArchi!=NULL)
    {
        fseek(usuarioArchi,sizeof(Usuario)*pos,SEEK_SET);
        fread(&usuario,sizeof(Usuario),1,usuarioArchi);
        mostrarAlumno(usuario);
        if(usuario.cantidad==0)
        {
            printf("\n\t\t\t\tNo tiene cargada ninguna cancion\n");
        }
        else
        {
            while(i<usuario.cantidad)
            {
                fseek(cancionArchi,0,SEEK_SET);
                while(fread(&cancione,sizeof(Cancion),1,cancionArchi)>0)
                {
                    if(cancione.idCancion==usuario.playlist[i])
                    {
                        minutos=cancione.duracion/100;
                        segundos=cancione.duracion-(minutos*100);
                        printf("\t\t\t\t%i _ %s\t\t %i : %i\n",i,cancione.titulo,minutos,segundos);
                    }
                }
                i++;
            }
        }
        fclose(cancionArchi);
        fclose(usuarioArchi);
    }

    getch();
}
void buscarMiCancion(nodoArbolCancion * cancion, nodoPlaylist * playlist)
{

}*/
void cursor()
{
    HANDLE consoleHadle=GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize=100;
    info.bVisible=FALSE;
    SetConsoleCursorInfo(consoleHadle,&info);
}
