#ifndef USUARIO_H_INCLUDED
#define USUARIO_H_INCLUDED
#include <string>

class Usuario
{
    private:
        int id;
        char nombre[20];
        char password[10];
        int perfil;
        int estado;
    public:
        void setNombre(char *n);
        void setPassword(char *p);
        void setPerfil(int p=3);
        void setEstado(int e=1);
        //Get
        int getId(){return id;};
        char *getNombre(){return nombre;};
        char *getPassword(){return password;};
        int getPerfil(){return perfil;};
        int getEstado(){return estado;};
        void cargar();
        void mostrar();
        bool escribirDisco();
        int leerDisco(int pos);
        void admin(); // crea usuario admin
};

int buscarNombre(char *nombre);
int cantUsuario(); // Devuelve la cantidad de registros
void compAdmin(); // Comprueba si existe admin

#endif // USUARIO_H_INCLUDED
