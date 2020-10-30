#ifndef USUARIO_H_INCLUDED
#define USUARIO_H_INCLUDED
#include <string>

class Usuario
{
    private:
        int id = 0;
        string nombre;
        string password;
        int perfil;
        int estado;
    public:
        void setNombre(string n);
        void setPassword(string p);
        void setPerfil(int p=3);
        void setEstado(int e=1);
        //Get
        int getId(){return id;};
        string getNombre(){return nombre;};
        string getPassword(){return password;};
        int getPerfil(){return perfil;};
        int getEstado(){return estado;};
        void cargar();
        void mostrar();
        bool escribirDisco();
        bool leerDisco(int pos=0);
        bool buscarUsuario(string nombre);
};

#endif // USUARIO_H_INCLUDED
