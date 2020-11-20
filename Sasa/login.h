#ifndef LOGIN_H_INCLUDED
#define LOGIN_H_INCLUDED
#include "usuario.h"


class Login
{
    private:
        char nombreUsuario[20];
        int perfilUsuario;
    public:
        void menuLogin();
        void login();
        int comprobarCredenciales(char *passB, char *nombreB);
        bool guardarUsuario();
        int leerUsuario(int pos=0);
        void eliminarTemp();
        void setNombreUsuario(char *n);
        char *getNombre(){return nombreUsuario;};
        void setPerfilUsuario(int p);
        int getPerfilUsuario(){return perfilUsuario;};
};

void crearTemp(Usuario);
int perfilTemp();

#endif // LOGIN_H_INCLUDED
