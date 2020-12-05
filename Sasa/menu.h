#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

// Declaraciones de Menu
void menuPrincipal(); // Menu Principal
void menuUsuario(); // Menu Usuario
void menuProducto(); // Menu Producto
void menuCategoria(); // Menu Categoria
void menuMovimientos(); // Menu Movimientos
void menuConfiguracion(); // Menu Configuracion
// SUB MENU USUARIO
void crearUsuario(); // Crear Usuario
void modificarUsuario(); // Modifica Usuario
void eliminarUsuario(); // Elimina Usuario
void listarUsuarios(); // Lista Todos los Usuarios
// SUB MENU PRODUCTO
void crearProducto(); // Crear Producto
void modificarProducto(); // Modifica un Producto
void eliminarProducto(); // Elimina un Producto
void listarProducto(); // Lista los Producto
// SUB MENU CATEGORIA
void crearCategoria(); // Crear Categoria
void modificarCategoria(); // Modifica Categoria
void eliminarCategoria(); // Elimina una Categoria
void listarCategoria(); // Lista Todas las Categorias
// SUB MENU MOVIMIENTOS
void cargarIngresos(); // Carga productos al stock
void cargarEgresos(); // Quita productos al stock
void listarBitacora(); // Lista el total de movimientos de egreso y egreso
// SUB MENU BITACORA
void listarMovimientosTodos(); //Lista todos los movimientos de la bitacora
void listarMovimientosPorUsuario(); // Lista todos los movimientos por usuario
void listarMovimientosPorProducto(); // Lista todos los movimientos por Producto
void listarMovimientosPorFecha(); // Lista todo los movimientos por Mes indicado
// SUB MENU CONFIGURACION
void copiaSeguridad(); // Crear Copia de Seguridad
void recuperarCopia(); // Recupera Copia de Seguridad
void exportarDatos(); // Exporta datos a csv
// SUB MENU PRODUCTO LISTAR PRODUCTOS
void listarProductoPorCodAs(); // Lista los productos por codigo ascendente
void listarProductoPorCodDes(); // Lista los productos por codigo descendente
void listarProductoInd(); // Lista producto individual
void listarProductoTodos(); // Listar todos los productos
// FUNCIONES GLOBALES O NECESARIAS
int validarMenu(int opc, int min, int max);

#endif // MENU_H_INCLUDED
