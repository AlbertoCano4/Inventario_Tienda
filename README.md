COSAS QUE AÑADIR:
 1. Permitir que una tienda pueda pasar ropa a otra
      (Ej: Tienda de madrid sold out de producto x y a la tienda de Barcelona le sobra ese producto x,
      hacer una función que permita mandar ropa de una tienda a otra (restar a Barcelona y Sumar a madrid))
  
 2. Hacer la BBDD,
       2.1 Guardar en ventas.txt todas las transacciones de las 5 tiendas y que si se hace una devolución o cambio se actualicen los datos xq si devuelvo 3 de 5 y luego cambio con el mismo codigo me saldra que puedo cambiar 5 cuando solo puedo cambiar 2 ya que hay 3 que estan devueltos
       2.2 Guardar el inventario de cada tienda en su archivo txt y que cada vez que haya una ampliación, venta, cambio o devolución, se actualice al instante en el archivo inventario(Tienda).txt
       2.3

 3. Añadir más productos (directamente en la clase) o (más complejo: crear un archivo productos.txt o un txt para cada tipo de producto para poder añadir manuealmente los productos que queramos) 

 4. OTRAS MODFICACIONES PARA HACERLO MEJOR

 5. Poner comentarios

 6. Hacer algunos metodos mas simples


Si no se te actualiza el archivo.txt
Configura el directorio de trabajo de tu proyecto para que sea una ubicación conocida (por ejemplo, la carpeta de tu repositorio):

1. Abre tu proyecto en Xcode.
2. En la parte superior izquierda, haz clic en el esquema de tu proyecto (junto al botón de ejecutar) y selecciona Edit Scheme....
3. Ve a la pestaña Run en la barra lateral.
4. Haz clic en la pestaña Options.
5. Marca la casilla Use custom working directory.
6. Selecciona la carpeta de tu proyecto como el directorio de trabajo.

Cuando vuelvas a compilar, tendrás que dar permisos para que Xcode acceda a ese archivo para sobreescribir en el.
