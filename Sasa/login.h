#ifndef LOGIN_H_INCLUDED
#define LOGIN_H_INCLUDED



class Login
{
    public:
        void menuLogin();
        void login();
        int comprobarCredenciales(char *passB, char *nombreB);
        bool guardarUsuario();
        int leerUsuario(int pos=0);
        void eliminarTemp();
        void setNombreUsuario(char *n);
        char *getNombre(){return nombreUsuario;};
    private:
        char nombreUsuario[20];
};

#endif // LOGIN_H_INCLUDED
