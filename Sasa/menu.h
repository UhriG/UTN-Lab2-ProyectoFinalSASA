#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

// Declaraciones de Menu
void menuPrincipal(); // Menu Principal
void menuUsuario(); // Menu Usuario
void menuProducto(); // Menu Producto
void menuCategoria(); // Menu Categoria
void menuConfiguracion(); // Menu Configuracion
// SUB MENU USUARIO
void crearUsuario(); // Crear Usuario
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
// SUB MENU CONFIGURACION
void copiaSeguridad(); // Crear Copia de Seguridad
void recuperarCopia(); // Recupera Copia de Seguridad
void exportarDatos(); // Exporta datos a csv
// FUNCIONES GLOBALES O NECESARIAS


#endif // MENU_H_INCLUDED
