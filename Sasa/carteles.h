#ifndef CARTELES_H
#define CARTELES_H

void cTitulo(); // Cartel TITULO
void gotoXYPred(int x=1, int y=3); // GOTO X E Y PREDETERMINADOS
void cMenuPrincipal(); // Cartel MENU PRINCIPAL
void cMenuConfiguracion(); // Cartel MENU CATEGORIA
void cMenu(int selec); // Cartel MENU CON VECTORES
void cMenuLogin(); // Cartel MENU LOGIN
void cMenuProdListar(); // Cartel PRODUCTO LISTAR
void cMenuMovimientos(); // Cartel MENU MOVIMIENTOS
void cMenuBitacora(); // Cartel listar bitacora
void cMenuCsv(); // Cartel exportar CSV
void cTabla(int modo); // Cartel LISTAR FORMATO TABLA
void cLinea(int cantidad); // Cartel DIBUJA UNA LINEA DETERMINADA
void cMsjPerfil(); // Cartel de Perfil sin acceso
void cListar(int cant, int modo, int submodo=0); // Cartel Listado
void cListarMovFecha(); // Cartel mostrar los filtros para mov fecha
#endif // CARTELES_H
