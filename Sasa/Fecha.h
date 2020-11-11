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
        void setDia(int);
        void setMes(int);
        void setAnio(int);
        int getDia(){return dia;};
        int getMes(){return mes;};
        int getAnio(){return anio;};
        void cargarFecha();
        void mostrarFecha();
        void fechaActual();
};


#endif // FECHA_H_INCLUDED
