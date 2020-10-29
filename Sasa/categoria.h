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
        void setNombre();
//        void setFechaCrea(Fecha);
//        void setFechaMod(Fecha);
        int getId(){return id;};
        string getNombre(){return nombre;};
//        Fecha getFechaCrea(){return Fecha;};
//        Fecha getFechaMod(){return Fecha;};
        void cargar();
        void mostrar();
        bool escribirDisco();
        bool leerDisco();
};

#endif // CATEGORIA_H_INCLUDED
