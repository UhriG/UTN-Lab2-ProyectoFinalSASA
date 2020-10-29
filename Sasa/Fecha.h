#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

class Fecha
{
    private:
        int dia;
        int mes;
        int anio;
    public:
        Fecha();
        void setDia();
        void setMes();
        void setAnio();
        void getDia();
        void getMes();
        void getAnio();
        void cargarFecha();
        void mostrarFecha();
        void fechaActual();
};


#endif // FECHA_H_INCLUDED
