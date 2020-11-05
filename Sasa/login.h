#ifndef LOGIN_H_INCLUDED
#define LOGIN_H_INCLUDED



class Login
{
    /*private:
        Usuario nombre;
        Usuario password;
        Usuario estado;
        Usuario perfil;*/
    public:
        void menuLogin();
        void login();
        int comprobarCredenciales(char *passB, char *nombreB);
};

#endif // LOGIN_H_INCLUDED
