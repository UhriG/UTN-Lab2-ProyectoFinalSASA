#ifndef LOGIN_H_INCLUDED
#define LOGIN_H_INCLUDED



class Login
{
    public:
        void menuLogin();
        void login();
        int comprobarCredenciales(char *passB, char *nombreB);
};

#endif // LOGIN_H_INCLUDED
