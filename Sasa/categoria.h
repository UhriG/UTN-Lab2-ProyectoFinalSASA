#ifndef CATEGORIA_H_INCLUDED
#define CATEGORIA_H_INCLUDED

class categoria
{
    private:
        int id;
        string nombre;
//        Fecha fecha_creacion;
//        Fecha fecha_modificacion;
    public:
        void setNombre(string);
//        void setFechaCrea(Fecha);
//        void setFechaMod(Fecha);
        int getId();
        string getNombre();
//        Fecha getFechaCrea(){return Fecha;};
//        Fecha getFechaMod(){return Fecha;};
        void cargar(int);
        void mostrar();
        bool escribirDisco();
        bool leerDisco(int);
};

#endif // CATEGORIA_H_INCLUDED
