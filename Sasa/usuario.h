#ifndef USUARIO_H_INCLUDED
#define USUARIO_H_INCLUDED
#include <string>

class Usuario
{
    private:
        int id = 1;
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
        int getId();
        string getNombre();
        string getPassword();
        int getPerfil();
        int getEstado();
        void cargar();
        void mostrar();
        bool escribirDisco();
        bool leerDisco(int pos=0);
};

#endif // USUARIO_H_INCLUDED
