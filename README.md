COSAS QUE AÑADIR:
 
 2. Hacer la BBDD,
       2.1 Guardar en ventas.txt todas las transacciones de las 5 tiendas y que si se hace una devolución o cambio se actualicen los datos xq si devuelvo 3 de 5 y luego cambio con el mismo codigo me saldra que puedo cambiar 5 cuando solo puedo cambiar 2 ya que hay 3 que estan devueltos
       2.2 Guardar el inventario de cada tienda en su archivo txt y que cada vez que haya una ampliación, venta, cambio o devolución, se actualice al instante en el archivo inventario(Tienda).txt
       2.3 En ventas.txt hacer que si se hace un cambio para la transaccion 1, se actualice la cantidad real de esa transacción y generar un codigo transacción 2 que muestre el producto cambiado y su cantidad
           Ej: Compro 5 de C001 y genero TX1, luego cambio 2 de C001 por 2 de C001 esto hace que TX1 pase de tener Q=5 a Q=3, por si el futuro quiero cambiar o devolver de nuevo ese producto
               Despues de cambio genero un TX2 para el producto C002 que hemos cambiado con Q=2 
           De esta forma no se duplicaran los productos cambiados si ejecutamos ese metodo varias veces
       2.4 En inventario(Tienda).txt se deben cargar todos los atributos específicos de cada producto, no solo los generales de producto
       2.5 LLamar a la función cargarInventario y que lo cargue correctamente
       2.6 Los metodos: devolución, cambio y consultar inventario deben trabajar sobre el txt de inventario (y que se vaya actualizando)
       2.7 Cada vez que iniciamos el programa desde 0 no se borre lo que ya había en el inventario.txt anterior

 3. Cuando se hacen cambios, si quiero cambiar un producto por otro que valga diferente, se abona la diferencia o te dan un cheque con el importe correspondiente

 4. Añadir más productos (directamente en la clase warehouse) o (más complejo: crear un archivo productos.txt o un txt para cada tipo de producto para poder añadir manuealmente los productos que queramos) 

 5. OTRAS MODFICACIONES PARA HACERLO MEJOR

 6. Poner comentarios

 7. Hacer algunos metodos mas simples


Si no se te actualiza el archivo.txt
Configura el directorio de trabajo de tu proyecto para que sea una ubicación conocida (por ejemplo, la carpeta de tu repositorio):

1. Abre tu proyecto en Xcode.
2. En la parte superior izquierda, haz clic en el esquema de tu proyecto (junto al botón de ejecutar) y selecciona Edit Scheme....
3. Ve a la pestaña Run en la barra lateral.
4. Haz clic en la pestaña Options.
5. Marca la casilla Use custom working directory.
6. Selecciona la carpeta de tu proyecto como el directorio de trabajo.

Cuando vuelvas a compilar, tendrás que dar permisos para que Xcode acceda a ese archivo para sobreescribir en el.
