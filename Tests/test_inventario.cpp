/*
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../Inventario.hpp"

// Prueba para generar código de transacción
 TEST_CASE("Generar código de transacción") {
     Inventario inventario;

     // Verificamos con un producto tipo "Camiseta" (C001)
     std::string codigoCamiseta = inventario.generarCodigoTransaccion("C001");

     // Verificar que el código empieza con "TX-"
     REQUIRE(codigoCamiseta.find("TX-") == 0);

     // Verificar que el código contiene "C001" (código de la camiseta)
     REQUIRE(codigoCamiseta.find("C001") != std::string::npos);

     // Verificar que el código tiene exactamente 10 caracteres
     REQUIRE(codigoCamiseta.size() == 10);

     // Verificar el formato Letra/Número/Letra al final
     REQUIRE(isalpha(codigoCamiseta[8])); // Séptimo carácter debe ser una letra
     REQUIRE(isdigit(codigoCamiseta[9])); // Octavo carácter debe ser un dígito
     REQUIRE(isalpha(codigoCamiseta[10])); // Noveno carácter debe ser una letra
}
 
// Prueba para registrar una venta
 TEST_CASE("Registrar una venta de producto") {
     Inventario inventario;

     // Agregar un producto con un precio de 15.5 por unidad
     Producto producto("C001", "Camiseta", 10, 19.99);
     inventario.agregarProducto(producto);

     // Cantidad vendida
     int cantidadVendida = 2;

     // Restar cantidad como si se hubiera vendido
     inventario.restarCantidad("C001", cantidadVendida);

     // Calcular el precio final
     float precioFinal = cantidadVendida * producto.getPrecioVenta();

     // Verificar que el stock se actualizó correctamente
     Producto* productoEnInventario = inventario.consultarProducto("C001");
     REQUIRE(productoEnInventario != nullptr);          // El producto debe existir
     REQUIRE(productoEnInventario->getCantidad() == 8); // El stock debe ser 10 - 2 = 8

     // Verificar que el precio final es correcto
     REQUIRE(precioFinal == (cantidadVendida * 15.5));  // Precio final debe ser 2 * 19.99 = 39.98
 }
*/
