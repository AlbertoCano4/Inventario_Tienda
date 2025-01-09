# Gestión de Inventarios de Tiendas

Este proyecto es una aplicación completa para la gestión del inventario de tiendas, que permite realizar operaciones como registrar ventas, devoluciones, ampliaciones de inventario y cambios. Además, incluye medidas de seguridad, funcionalidades avanzadas como la sobrecarga de operadores, y lectura y modificación de datos en archivos. Perfecto para optimizar la administración de productos en tiendas múltiples.

---

## Características Principales

### **Gestín de múltiples tiendas:**
- Cada tienda tiene su propio inventario y archivo txt.
- Cambio de tienda con códigos de verificación seguros.

### **Operaciones de inventario:**
- Consultar inventario completo o por categorías.
- Registrar ventas, devoluciones, ampliaciones y cambios de productos.
- Validación de entradas y control de cantidades para evitar errores.

### **Seguridad y acceso:**
- Códigos de verificación para garantizar acceso seguro a cada tienda.
- Límite de intentos fallidos, bloqueando el acceso tras superarlo.

### **Persistencia de datos:**
- Guardado automático del estado del inventario antes de salir o cambiar de tienda.
- Archivos de texto para registrar inventarios y transacciones.

### **Modularidad y escalabilidad:**
- Diseño basado en clases como `Producto`, `Inventario`, `Tienda` y `Almacen`.
- Sobrecarga de operadores para manejar cantidades de productos de forma intuitiva.

### **Registro de transacciones:**
- Códigos únicos generados para cada operación.
- Historial de cambios, devoluciones y ventas en un archivo centralizado.

---

## Estructura del Proyecto
```plaintext
Proyecto/
├── src/
│   ├── main.cpp            # Punto de entrada del programa.
│   ├── Menu.cpp            # Implementación de los menús de usuario.
│   ├── Inventario.cpp      # Métodos relacionados con el inventario.
│   ├── Producto.cpp        # Implementación de la clase abstracta Producto.
│   ├── Almacen.cpp         # Creación de productos y almacenamiento inicial.
│   └── Tienda.cpp          # Gestín de tiendas específicas.
├── include/
│   ├── Definiciones.hpp    # Enumeraciones y constantes generales.
│   ├── Producto.hpp        # Clase base Producto.
│   ├── Inventario.hpp      # Clase Inventario y su lógica.
│   ├── Tienda.hpp          # Clase Tienda para manejar múltiples tiendas.
│   ├── Almacen.hpp         # Clase Almacen para administrar productos base.
│   └── Menu.hpp            # Declaración de funciones para menús.
├── data/
│   ├── inventarioMadrid.txt    # Inventario persistente para Madrid.
│   ├── inventarioBarcelona.txt # Inventario persistente para Barcelona.
│   ├── transacciones.txt       # Registro de transacciones realizadas.
│   └── ...                     # Otros archivos para persistencia de datos.
├── README.md               # Documentación del proyecto.
└── Makefile                # Script para compilar el proyecto.
```

---

## Instalación y Configuración

### **Requisitos:**
- Un compilador compatible con C++ (como `g++` o el que viene Xcode).
- Configuración adecuada del directorio de trabajo si usas Xcode:

### **Problema de no lectura de txt:**
1. Abre tu proyecto en Xcode.
2. Haz clic en el esquema de tu proyecto (junto al botón de ejecutar) y selecciona **Edit Scheme...**.
3. Ve a la pestaña **Run** > **Options**.
4. Marca la casilla **Use custom working directory**.
5. Selecciona la carpeta del proyecto.

---

## Uso del Programa

### **Menú Principal:**
El programa ofrece un menú principal con las siguientes opciones:

1. **Consultar Inventario:** Visualiza el inventario completo o por categorías.
2. **Registrar Venta:** Reduce las cantidades tras una venta.
3. **Ampliar Inventario:** Incrementa las cantidades disponibles de un producto.
4. **Devoluciones:** Devuelve productos al inventario.
5. **Cambios:** Permite intercambiar productos con el cliente.
6. **Cambiar de Tienda:** Guarda el inventario actual y cambia de tienda.
7. **Salir:** Guarda el inventario y cierra el programa.

### **Flujo de Trabajo Ejemplo:**
1. Elige una tienda (Madrid o Barcelona) tras introducir el código correcto.
2. Consulta el inventario o realiza operaciones como ventas o devoluciones.
3. Cambia entre tiendas o sale del programa guardando el estado actual.

### **Manejo de Errores:**
- Entradas no válidas (letras en lugar de números) no cierran el programa.
- Los errores son manejados con mensajes claros y el menú se vuelve a mostrar.

---

## Clases Principales

### **`Producto` (Abstracta):**
Clase base para todas las categorías de productos(Ropa: "Camiseta, Pantalon y Sudadera", Accesorio: "Bufanda, Gafas de sol, Gorra"). Define propiedades comunes como:
- **Código:** Identificador único.
- **Precio:** Precio de venta del producto.
- **Cantidad:** Unidades disponibles.
- **Temporada y Género:** Metadatos del producto.

#### **Sobrecarga de Operadores:**
- `+=` y `-=` para aumentar o reducir cantidades de forma intuitiva.

---

### **`Inventario`:**
Gestor principal de productos en una tienda:
- **Registrar operaciones:** Ventas, devoluciones y ampliaciones.
- **Consultas:** Por categoría o inventario completo.
- **Validaciones:** Evita entradas no válidas y operaciones inconsistentes.

---

### **`Tienda`:**
- Vincula un inventario a una tienda específica.
- Administra el archivo de persistencia del inventario.

---

### **`Almacen`:**
- Base de datos de productos para ampliar el inventario de las tiendas.

---

## Registro de Transacciones
- Cada operación (venta, devolución, cambio) genera un **código único de transacción.**
- El archivo `transacciones.txt` guarda:
  - Tipo de operación.
  - Fecha y hora.
  - Productos involucrados.
  - Tienda correspondiente.

Ejemplo de entrada en el archivo:
```plaintext
Código de transacción: TX-MAD123A9
Tipo de operación: Venta
Fecha y hora: 2025-01-08 12:45:32
Tienda: Madrid
Código de producto: CAM001
Cantidad: 2
Precio total: 49.98 €
--------------------------------------
```

---

## Futuras Mejoras
- **Optimizar código repetitivo:** Consolidar funciones de ventas, devoluciones y cambios.
- **Clase `Transaccion`:** Gestionar transacciones en una clase dedicada, para que cambio y devolución lean un codigo y carguen la ingo concreta.
- **Consultas avanzadas:** Permitir búsquedas por código de producto o atributos específicos.
- **Productos entre tiendas:** Implementar transferencia de productos entre tiendas.
- **Soporte para más tiendas y productos:** Escalabilidad para incluir nuevas ubicaciones y categorías.
- **Ventas múltiples:** Registrar varias ventas en una sola operación.
- **Tests automatizados:** Mejorar la robustez del código.

---

## Contribuciones
Las contribuciones son bienvenidas. Sigue estos pasos:
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

---

## Autores
- **Sofía Azpiroz** - [GitHub](https://github.com/Sofiazpiroz)
- **Paloma Belenguer** - [GitHub](https://github.com/pomibelenguer)
- **Alberto Cano** - [GitHub](https://github.com/AlbertoCano4)
- **Ignacio Fernández** - [GitHub](https://github.com/ignaciofern)
- **Gonzalo Ruiz** - [GitHub](https://github.com/gon-ruiz)

