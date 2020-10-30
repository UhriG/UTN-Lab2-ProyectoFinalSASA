#ifndef USUARIO_H_INCLUDED
#define USUARIO_H_INCLUDED
#include <string>

class Usuario
{
    private:
        int id = 0;
        char nombre[10];
        string password;
        int perfil;
        int estado;
    public:
        void setNombre(char *n);
        void setPassword(string p);
        void setPerfil(int p=3);
        void setEstado(int e=1);
        //Get
        int getId(){return id;};
        char * getNombre(){return nombre;};
        string getPassword(){return password;};
        int getPerfil(){return perfil;};
        int getEstado(){return estado;};
        void cargar();
        void mostrar();
        bool escribirDisco();
        int leerDisco(int pos);
        bool buscarUsuario(string nombre);
};

int buscarNombre(char *nombre);


#endif // USUARIO_H_INCLUDED
