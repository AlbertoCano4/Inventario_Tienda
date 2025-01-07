# Gestión de Inventarios para Tiendas

Este proyecto es una aplicación diseñada para gestionar el inventario de tiendas. Permite realizar operaciones como registrar ventas, ampliaciones de inventario, devoluciones, cambios, y consultar el estado de los productos en las tiendas. Además, incluye medidas de seguridad para el acceso, funcionalidades avanzadas como la sobrecarga de operadores para manejar cantidades de productos y lectura de archivos txt para cargar la base de datos de los productos de una compilacion a otra.

---

## Características

- **Gestión de múltiples tiendas:**
  - Cada tienda tiene su propio inventario y archivo de persistencia.
  - Cambiar entre tiendas con códigos de verificación.
- **Operaciones de inventario:**
  - Consultar inventario completo o por categorías.
  - Registrar ventas, devoluciones, ampliaciones, y cambios de productos.
  - Control de cantidades y validación de entradas.
- **Seguridad:**
  - Código de verificación con un límite de intentos.
  - Bloqueo del sistema tras intentos fallidos repetidos.
- **Estructura modular:**
  - Clases bien definidas como `Producto`, `Inventario`, `Tienda`, y `Almacen`.
  - Sobrecarga de operadores en la clase `Producto` para manipular cantidades.
- **Persistencia de datos:**
  - Guardado automático del estado del inventario antes de salir o cambiar de tienda.

---

## Estructura del Proyecto

Proyecto/ ├── src/ │ ├── main.cpp # Punto de entrada del programa. │ ├── Menu.cpp # Implementación de los menús de usuario. │ ├── Inventario.cpp # Métodos relacionados con el inventario. │ ├── Producto.cpp # Métodos y lógica de la clase abstracta Producto. │ ├── Almacen.cpp # Creación de productos y añadir a un vector específico para cada tipo de producto. │ └── Tienda.cpp # Gestión de tiendas específicas. ├── include/ │ ├── Definiciones.hpp # Definiciones generales como enumeraciones. │ ├── Producto.hpp # Clase base abstracta Producto. │ ├── Inventario.hpp # Clase Inventario y su lógica. │ ├── Tienda.hpp # Clase Tienda para manejar múltiples tiendas. │ ├── Almacen.hpp # Clase Almacen para crear productos. │ └── Menu.hpp # Declaración de funciones para menús. ├── data/ │ ├── inventarioMadrid.txt # Archivo de datos persistentes para la tienda de Madrid. │ ├── inventarioBarcelona.txt # Archivo de datos persistentes para la tienda de Barcelona. │ ├── Transacciones.txt # Registro de todas las transacciones realizadas. │ └── ... # Otros archivos para almacenar datos persistentes. ├── README.md # Documentación del proyecto. └── Makefile # Script para compilar el proyecto.

---

## Instalación y Ejecución

Xcode o VisualStudio compilador g++

Si no se te actualiza el archivo.txt
Configura el directorio de trabajo de tu proyecto para que sea una ubicación conocida (por ejemplo, la carpeta de tu repositorio):

1. Abre tu proyecto en Xcode.
2. En la parte superior izquierda, haz clic en el esquema de tu proyecto (junto al botón de ejecutar) y selecciona Edit Scheme....
3. Ve a la pestaña Run en la barra lateral.
4. Haz clic en la pestaña Options.
5. Marca la casilla Use custom working directory.
6. Selecciona la carpeta de tu proyecto como el directorio de trabajo.

Cuando vuelvas a compilar, tendrás que dar permisos para que Xcode acceda a ese archivo para sobreescribir en el.

---

## Uso del Programa

### Menú Principal
El programa ofrece un menú principal con las siguientes opciones:

1. **Consultar Inventario:** Visualizar todos los productos o por categoría.
2. **Registrar Venta:** Reducir cantidades tras vender un producto.
3. **Ampliar Inventario:** Incrementar cantidades de productos.
4. **Devoluciones:** Sumar productos devueltos al inventario.
5. **Cambios:** Intercambiar productos entre el cliente y la tienda, ajustando cantidades.
6. **Cambiar de Tienda:** Guardar el inventario actual y cambiar a otra tienda.
7. **Salir:** Guardar el estado actual del inventario y salir del programa.

### Seguridad
- **Códigos de verificación:** Se requiere un código para acceder a cada tienda.
- **Bloqueo tras intentos fallidos:** Si se falla tres veces, el programa se cierra automáticamente.

---

## Clases Principales

### `Producto` (Abstracta)
Clase base para todas las categorías de productos. Define propiedades comunes como tipo, código, precio, cantidad, temporada y género. Implementa sobrecarga de operadores para manejar cantidades:

- `+=` Incrementar cantidad.
- `-=` Decrementar cantidad.

### `Inventario`
Gestión de productos en una tienda:
- Métodos para registrar ventas, devoluciones, ampliaciones y cambios.
- Validaciones como límites de cantidades y entradas no numéricas.
- Interacción con un almacén para añadir nuevos productos.

### `Tienda`
Asocia un inventario con una ubicación específica y su archivo de persistencia.

### `Almacen`
Base de datos de productos disponibles para ampliar el inventario.

---

## Contribuciones
¡Las contribuciones son bienvenidas! Si deseas colaborar, sigue estos pasos:
1. Haz un fork del proyecto.
2. Crea una rama con tus cambios:
   ```bash
   git checkout -b nueva-funcionalidad
   ```
3. Realiza tus cambios y súbelos:
   ```bash
   git add .
   git commit -m "Descripción de tus cambios"
   git push origin nueva-funcionalidad
   ```
4. Crea un Pull Request.

## Futuras Mejoras:
- Tests
- Hacer una sola función en venta, cambio y devolución que reconozcá si existe el producto en el inventario y llamar a la función que hace la venta, cambio o devolución (if, else if, else)
- En cambio y devolución leer el codigo de transacción y hacer la operación aunque sea en otra tienda (Crear clase Transaccion)
- Agregar más tiendas y productos
- añadir más funciones al menu principal, como pasar productos de una tienda a otra
- Poder consultar el inventario de forma mas personalizada (Cod producto)
- No tener que añadir primero al txt un producto para poder ampliar producto de ese tipo
- En una venta poder vender mas de un tipo de producto y registrarlo en transacciones

---

## Autores
**Sofía Azpiroz** - https://github.com/Sofiazpiroz

**Paloma Belenguer** - https://github.com/pomibelenguer

**Alberto Cano** - https://github.com/AlbertoCano4

**Ignacio Fernández** - 

**Gonzalo Ruiz** - https://github.com/gon-ruiz

