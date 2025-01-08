#include "Inventario.hpp"

/*
 Importante para no comentar siempre lo mismo
 
 Se utiliza const auto& en los bucles porque los objetos del vector no necesitan ser modificados dentro del bucle.
 (const) asegura que el objeto iterado no pueda cambiarse sin querer.
 El (&) evita copiar el objeto completo, accediendo a él por referencia.
 
 Los atributos con Const tipo& tienen como objetivo no modificar el atributo al que llaman.
 
Los métodos con constson porque no modifican los datos miembros del objeto Inventario.
Esto garantiza que el estado interno del objeto permanezca inalterado durante la ejecución del método.
 */

Inventario::Inventario() {
    // Se inicializa vacío para que no haya datos residuales al crear un nuevo inventario.
    camisetasEnInventario.clear(); // Inicializa el vector de camisetas vacío.
    bufandasEnInventario.clear(); // Inicializa el vector de bufandas vacío.
    sudaderasEnInventario.clear(); // Inicializa el vector de sudaderas vacío.
    pantalonesEnInventario.clear(); // Inicializa el vector de pantalones vacío.
    gafasDeSolEnInventario.clear(); // Inicializa el vector de gafas de sol vacío.
    gorrasEnInventario.clear(); // Inicializa el vector de gorras vacío.
}

void Inventario::anadirProductoDesdeAlmacen(const Almacen& almacen) {
    // El parámetro almacen es const porque no se modifica dentro de esta función.
    // Esto garantiza que los datos del almacén no puedan ser alterados accidentalmente.
    
    string codigo; // Código del producto que se quiere añadir.
    int cantidad; // Cantidad del producto que se quiere añadir.
    
    cout << "Ingrese el código del producto que desea añadir: ";
    cin >> codigo;
    
    // Manejo de entrada y validación de cantidad
    while (true) {
        try {
            cout << "Ingrese la cantidad que desea añadir: ";
            cin >> cantidad;
            
            // Detectar entradas no numéricas
            if (cin.fail()) {
                cin.clear(); // Restablece la entrada para que pueda aceptar nuevos datos.
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpia el texto no válido que el usuario ingresó.
                throw invalid_argument("Error: Has introducido un valor no numérico."); // Indica que el usuario no ingresó un número.
            }
            
            // Validar si la cantidad es mayor a 0
            if (cantidad <= 0) {
                throw invalid_argument("Error: La cantidad debe ser mayor a 0."); // Indica que el usuario no ingresó un número mayor a 0.
            }
            
            break; // Salir del bucle si la entrada es válida
        } catch (const invalid_argument& e) {
            cout << e.what() << " Inténtelo de nuevo.\n";
        }
    }
    
    // Limpiar el buffer de entrada para eliminar cualquier dato adicional
    // (como texto o un salto de línea) que el usuario haya ingresado.
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    bool productoEncontrado = false; // falso porque primero tiene que buscar en el inventario
    
    try {
        // Buscar en las camisetas
        for (auto& camiseta : camisetasEnInventario) { // Recorre un bucle para todas las camisetas que se hayan añadido
            if (camiseta.getCodProducto() == codigo) {  // Si el codigo del producto camiseta coincide con el introducido por el usuario pasa a actualizar su cantidad
                camiseta.setCantidad(camiseta.getCantidad() + cantidad); // actualiza la cantidad de producto a la que ya habia en inventario
                cout << "Camiseta " << codigo << " actualizado. Nueva cantidad: " << camiseta.getCantidad() << "\n"; // muestra la nueva cantidad
                productoEncontrado = true; // Significa que el codigo coincide con una camiseta
                break; // sale del nucle
            }
        }
        // Buscar en las Sudaderas
        if (!productoEncontrado) { // no se encontro el producto buscado
            for (auto& sudadera : sudaderasEnInventario) { // Recorre un bucle para todas las sudaderas que se hayan añadido
                if (sudadera.getCodProducto() == codigo) { // Si el código del producto sudadera coincide con el introducido por el usuario, pasa a actualizar su cantidad
                    sudadera.setCantidad(sudadera.getCantidad() + cantidad); // Actualiza la cantidad de producto a la que ya había en inventario
                    cout << "Sudadera " << codigo << " actualizada. Nueva cantidad: " << sudadera.getCantidad() << "\n"; // Muestra la nueva cantidad
                    productoEncontrado = true; // Marca que el código coincide con una sudadera
                    break; // Sale del bucle
                }
            }
        }
        
        // Buscar en los Pantalones
        if (!productoEncontrado) { // sigue sin encontrarse...
            for (auto& pantalon : pantalonesEnInventario) { // Recorre un bucle para todos los pantalones que se hayan añadido
                if (pantalon.getCodProducto() == codigo) { // Si el código del producto pantalón coincide con el introducido por el usuario, pasa a actualizar su cantidad
                    pantalon.setCantidad(pantalon.getCantidad() + cantidad); // Actualiza la cantidad de producto a la que ya había en inventario
                    cout << "Pantalón " << codigo << " actualizado. Nueva cantidad: " << pantalon.getCantidad() << "\n"; // Muestra la nueva cantidad
                    productoEncontrado = true; // Marca que el código coincide con un pantalón
                    break; // Sale del bucle
                }
            }
        }
        
        // Buscar en las bufandas
        if (!productoEncontrado) {
            for (auto& bufanda : bufandasEnInventario) { // Recorre un bucle para todas las bufandas que se hayan añadido
                if (bufanda.getCodProducto() == codigo) { // Si el código del producto bufanda coincide con el introducido por el usuario, pasa a actualizar su cantidad
                    bufanda.setCantidad(bufanda.getCantidad() + cantidad); // Actualiza la cantidad de producto a la que ya había en inventario
                    cout << "Bufanda " << codigo << " actualizada. Nueva cantidad: " << bufanda.getCantidad() << "\n"; // Muestra la nueva cantidad
                    productoEncontrado = true; // Marca que el código coincide con una bufanda
                    break; // Sale del bucle
                }
            }
        }
        
        // Buscar en las Gafas de Sol
        if (!productoEncontrado) {
            for (auto& gafasDeSol : gafasDeSolEnInventario) { // Recorre un bucle para todas las gafas de sol que se hayan añadido
                if (gafasDeSol.getCodProducto() == codigo) { // Si el código del producto gafas de sol coincide con el introducido por el usuario, pasa a actualizar su cantidad
                    gafasDeSol.setCantidad(gafasDeSol.getCantidad() + cantidad); // Actualiza la cantidad de producto a la que ya había en inventario
                    cout << "Gafas de Sol " << codigo << " actualizado. Nueva cantidad: " << gafasDeSol.getCantidad() << "\n"; // Muestra la nueva cantidad
                    productoEncontrado = true; // Marca que el código coincide con unas gafas de sol
                    break; // Sale del bucle
                }
            }
        }
        
        // Buscar en las Gorras
        if (!productoEncontrado) {
            for (auto& gorra : gorrasEnInventario) { // Recorre un bucle para todas las gorras que se hayan añadido
                if (gorra.getCodProducto() == codigo) { // Si el código del producto gorra coincide con el introducido por el usuario, pasa a actualizar su cantidad
                    gorra.setCantidad(gorra.getCantidad() + cantidad); // Actualiza la cantidad de producto a la que ya había en inventario
                    cout << "Gorra " << codigo << " actualizado. Nueva cantidad: " << gorra.getCantidad() << "\n"; // Muestra la nueva cantidad
                    productoEncontrado = true; // Marca que el código coincide con una gorra
                    break; // Sale del bucle
                }
            }
        }
        
        // Si no está en el inventario, buscar en el almacén
        if (!productoEncontrado) {
            // Recorre todos los productos de tipo camiseta en el almacén
            for (const auto& camiseta : almacen.getCamisetas()) {
                if (camiseta.getCodProducto() == codigo) { // Si el código del producto coincide con el introducido por el usuario
                    Camiseta nuevaCamiseta = camiseta; // Crea una copia del producto encontrado
                    nuevaCamiseta.setCantidad(cantidad); // Establece la cantidad del producto
                    camisetasEnInventario.push_back(nuevaCamiseta); // Añade la nueva camiseta al inventario
                    cout << "Camiseta " << codigo << " añadido al inventario. Cantidad: " << cantidad << "\n"; // Notifica que se añadió
                    productoEncontrado = true; // Marca que el producto fue encontrado y añadido
                    break; // Sale del bucle
                }
            }
        }
        
        if (!productoEncontrado) {
            // Recorre todos los productos de tipo sudadera en el almacén
            for (const auto& sudadera : almacen.getSudaderas()) {
                if (sudadera.getCodProducto() == codigo) { // Si el código del producto coincide
                    Sudadera nuevaSudadera = sudadera; // Crea una copia del producto encontrado
                    nuevaSudadera.setCantidad(cantidad); // Establece la cantidad del producto
                    sudaderasEnInventario.push_back(nuevaSudadera); // Añade la nueva sudadera al inventario
                    cout << "Sudadera " << codigo << " añadida al inventario. Cantidad: " << cantidad << "\n"; // Notifica que se añadió
                    productoEncontrado = true; // Marca que el producto fue encontrado y añadido
                    break; // Sale del bucle
                }
            }
        }
        
        if (!productoEncontrado) {
            // Recorre todos los productos de tipo pantalón en el almacén
            for (const auto& pantalon : almacen.getPantalones()) {
                if (pantalon.getCodProducto() == codigo) { // Si el código del producto coincide
                    Pantalon nuevoPantalon = pantalon; // Crea una copia del producto encontrado
                    nuevoPantalon.setCantidad(cantidad); // Establece la cantidad del producto
                    pantalonesEnInventario.push_back(nuevoPantalon); // Añade el nuevo pantalón al inventario
                    cout << "Pantalón " << codigo << " añadido al inventario. Cantidad: " << cantidad << "\n"; // Notifica que se añadió
                    productoEncontrado = true; // Marca que el producto fue encontrado y añadido
                    break; // Sale del bucle
                }
            }
        }
        
        if (!productoEncontrado) {
            // Recorre todos los productos de tipo bufanda en el almacén
            for (const auto& bufanda : almacen.getBufandas()) {
                if (bufanda.getCodProducto() == codigo) { // Si el código del producto coincide
                    Bufanda nuevaBufanda = bufanda; // Crea una copia del producto encontrado
                    nuevaBufanda.setCantidad(cantidad); // Establece la cantidad del producto
                    bufandasEnInventario.push_back(nuevaBufanda); // Añade la nueva bufanda al inventario
                    cout << "Bufanda " << codigo << " añadida al inventario. Cantidad: " << cantidad << "\n"; // Notifica que se añadió
                    productoEncontrado = true; // Marca que el producto fue encontrado y añadido
                    break; // Sale del bucle
                }
            }
        }
        
        if (!productoEncontrado) {
            // Recorre todos los productos de tipo gafas de sol en el almacén
            for (const auto& gafas : almacen.getGafasDeSol()) {
                if (gafas.getCodProducto() == codigo) { // Si el código del producto coincide
                    GafasDeSol nuevasGafas = gafas; // Crea una copia del producto encontrado
                    nuevasGafas.setCantidad(cantidad); // Establece la cantidad del producto
                    gafasDeSolEnInventario.push_back(nuevasGafas); // Añade las nuevas gafas al inventario
                    cout << "Gafas de Sol " << codigo << " añadidas al inventario. Cantidad: " << cantidad << "\n"; // Notifica que se añadió
                    productoEncontrado = true; // Marca que el producto fue encontrado y añadido
                    break; // Sale del bucle
                }
            }
        }
        
        if (!productoEncontrado) {
            // Recorre todos los productos de tipo gorra en el almacén
            for (const auto& gorra : almacen.getGorras()) {
                if (gorra.getCodProducto() == codigo) { // Si el código del producto coincide
                    Gorra nuevaGorra = gorra; // Crea una copia del producto encontrado
                    nuevaGorra.setCantidad(cantidad); // Establece la cantidad del producto
                    gorrasEnInventario.push_back(nuevaGorra); // Añade la nueva gorra al inventario
                    cout << "Gorra " << codigo << " añadida al inventario. Cantidad: " << cantidad << "\n"; // Notifica que se añadió
                    productoEncontrado = true; // Marca que el producto fue encontrado y añadido
                    break; // Sale del bucle
                }
            }
        }
        
        // Si no se encuentra el producto en el inventario ni en el almacén
        if (!productoEncontrado) {
            throw runtime_error("Error: Producto no encontrado en el inventario ni en el almacén."); // Lanza una excepción
        }
    } catch (const runtime_error& e) { // Captura una excepción específica de tipo runtime_error.
        cout << e.what() << "\n"; // Imprime el mensaje de error asociado a la excepción.
    } catch (const exception& e) { // Captura cualquier otra excepción genérica.
        cout << "Error inesperado: " << e.what() << "\n"; // Imprime el mensaje de error para excepciones genéricas.
    }
}

void Inventario::mostrarInventario() const {
    // El método "const" asegura que no se modifiquen los atributos de la clase durante la ejecución de este método.
    // Esto significa que "mostrarInventario" solo puede leer los datos, pero no alterarlos.
    
    // muestra todos los productos que haya en el txt de la tienda donde estemos
    cout << "\n=== Estado del Inventario ===\n";
    
    cout << "\n=== Camisetas ===\n";
    // muestra todas las camisetas que haya en el txt de la tienda donde estemos
    for (const auto& camiseta : camisetasEnInventario) {
        camiseta.mostrarInformacion();
        cout << "-------------------\n";
    }
    
    cout << "\n=== Sudaderas ===\n";
    // muestra todas las sudaderas que haya en el txt de la tienda donde estemos
    for (const auto& sudadera : sudaderasEnInventario) {
        sudadera.mostrarInformacion();
        cout << "-------------------\n";
    }
    
    cout << "\n=== Pantalones ===\n";
    // muestra tods los pantalones que haya en el txt de la tienda donde estemos
    for (const auto& pantalon : pantalonesEnInventario) {
        pantalon.mostrarInformacion();
        cout << "-------------------\n";
    }
    
    cout << "\n=== Bufandas ===\n";
    // muestra todas las bufandas que haya en el txt de la tienda donde estemos
    for (const auto& bufanda : bufandasEnInventario) {
        bufanda.mostrarInformacion();
        cout << "-------------------\n";
    }
    
    cout << "\n=== Gafas de Sol ===\n";
    // muestra todas las gafas de sol que haya en el txt de la tienda donde estemos
    for (const auto& gafas : gafasDeSolEnInventario) {
        gafas.mostrarInformacion();
        cout << "-------------------\n";
    }
    
    cout << "\n=== Gorras ===\n";
    // muestra todas las gorras que haya en el txt de la tienda donde estemos
    for (const auto& gorra : gorrasEnInventario) {
        gorra.mostrarInformacion();
        cout << "-------------------\n";
    }
}

void Inventario::guardarInventario(const string& archivoNombre) const {
    // Crear un archivo de salida con el nombre especificado
    ofstream archivo(archivoNombre);
    
    // Verificar si el archivo se pudo abrir correctamente
    if (!archivo) {
        cerr << "Error al abrir el archivo " << archivoNombre << "\n"; // Mensaje de error si no se puede abrir
        return; // Salir del método
    }
    
    // Guardar la cantidad de camisetas en el inventario
    archivo << "Camisetas\n" << camisetasEnInventario.size() << "\n"; // Escribir la etiqueta y el tamaño del vector
    for (const auto& producto : camisetasEnInventario) { // repetir sobre cada camiseta
        archivo << producto.getCodProducto() << "\n" // Guardar el código del producto
        << producto.getCantidad() << "\n" // Guardar la cantidad
        << producto.getPrecioVenta() << "\n" // Guardar el precio de venta
        << temporadaToString(producto.getTemporada()) << "\n" // Convertir y guardar la temporada como string
        << generoToString(producto.getGenero()) << "\n" // Convertir y guardar el género como string
        << tallaToString(producto.getTalla()) << "\n" // Convertir y guardar la talla como string
        << tipoCamisetaToString(producto.getTipo()) << "\n" // Convertir y guardar el tipo de camiseta como string
        << producto.getMaterial() << "\n" // Guardar el material
        << (producto.getEstampado() ? "Sí" : "No") << "\n"; // Guardar si tiene estampado como "Sí" o "No"
    }
    
    // Guardar la cantidad de bufandas en el inventario
    archivo << "Bufandas\n" << bufandasEnInventario.size() << "\n"; // Etiqueta y tamaño
    for (const auto& bufanda : bufandasEnInventario) { // repetir sobre bufandas
        archivo << bufanda.getCodProducto() << "\n"
        << bufanda.getCantidad() << "\n"
        << bufanda.getPrecioVenta() << "\n"
        << temporadaToString(bufanda.getTemporada()) << "\n"
        << generoToString(bufanda.getGenero()) << "\n"
        << estiloTostring(bufanda.getEstilo()) << "\n" // Convertir y guardar estilo como string
        << (bufanda.getEsDeLana() ? "Sí" : "No") << "\n"; // Guardar si es de lana
    }
    
    // Guardar la cantidad de sudaderas en el inventario
    archivo << "Sudaderas\n" << sudaderasEnInventario.size() << "\n"; // Etiqueta y tamaño
    for (const auto& sudadera : sudaderasEnInventario) { // repetir sobre sudaderas
        archivo << sudadera.getCodProducto() << "\n"
        << sudadera.getCantidad() << "\n"
        << sudadera.getPrecioVenta() << "\n"
        << temporadaToString(sudadera.getTemporada()) << "\n"
        << generoToString(sudadera.getGenero()) << "\n"
        << tallaToString(sudadera.getTalla()) << "\n"
        << tipoSudaderaToString(sudadera.getTipoSudadera()) << "\n" // Convertir tipo de sudadera a string
        << sudadera.getMaterial() << "\n"
        << (sudadera.getCremallera() ? "Sí" : "No") << "\n"; // Guardar si tiene cremallera
    }
    
    // Guardar la cantidad de pantalones en el inventario
    archivo << "Pantalones\n" << pantalonesEnInventario.size() << "\n"; // Etiqueta y tamaño
    for (const auto& pantalon : pantalonesEnInventario) { // repetir sobre pantalones
        archivo << pantalon.getCodProducto() << "\n"
        << pantalon.getCantidad() << "\n"
        << pantalon.getPrecioVenta() << "\n"
        << temporadaToString(pantalon.getTemporada()) << "\n"
        << generoToString(pantalon.getGenero()) << "\n"
        << tallaToString(pantalon.getTalla()) << "\n"
        << tipoPantalonToString(pantalon.getTipoPantalon()) << "\n" // Convertir tipo de pantalón a string
        << (pantalon.getCargo() ? "Sí" : "No") << "\n"; // Guardar si tiene bolsillos cargo
    }
    
    // Guardar la cantidad de gafas de sol en el inventario
    archivo << "GafasDeSol\n" << gafasDeSolEnInventario.size() << "\n"; // Etiqueta y tamaño
    for (const auto& gafas : gafasDeSolEnInventario) { // repetir sobre gafas de sol
        archivo << gafas.getCodProducto() << "\n"
        << gafas.getCantidad() << "\n"
        << gafas.getPrecioVenta() << "\n"
        << temporadaToString(gafas.getTemporada()) << "\n"
        << generoToString(gafas.getGenero()) << "\n"
        << estiloTostring(gafas.getEstilo()) << "\n" // Convertir estilo a string
        << gafas.getFormaLente() << "\n" // Guardar forma de lente
        << (gafas.getProteccionUV() ? "Sí" : "No") << "\n"; // Guardar si tienen protección UV
    }
    
    // Guardar la cantidad de gorras en el inventario
    archivo << "Gorras\n" << gorrasEnInventario.size() << "\n"; // Etiqueta y tamaño
    for (const auto& gorra : gorrasEnInventario) { // repetir sobre gorras
        archivo << gorra.getCodProducto() << "\n"
        << gorra.getCantidad() << "\n"
        << gorra.getPrecioVenta() << "\n"
        << temporadaToString(gorra.getTemporada()) << "\n"
        << generoToString(gorra.getGenero()) << "\n"
        << estiloTostring(gorra.getEstilo()) << "\n" // Convertir estilo a string
        << gorra.getTipo() << "\n" // Guardar tipo de gorra
        << gorra.getMaterial() << "\n"; // Guardar material de la gorra
    }
    
    // Cerrar el archivo después de escribir todo
    archivo.close();
    cout << "Inventario guardado en " << archivoNombre << "\n"; // Notificar al usuario
}

void Inventario::cargarInventario(const string& archivoNombre) {
    // Abre un archivo de entrada usando el nombre proporcionado.
    ifstream archivo(archivoNombre);
    if (!archivo) { // Comprueba si hubo un error al abrir el archivo.
        cerr << "Error al abrir el archivo " << archivoNombre << "\n";
        return; // Sale del método si ocurre un error.
    }
    
    // Limpia los vectores del inventario para evitar duplicados antes de cargar nuevos datos.
    camisetasEnInventario.clear();
    bufandasEnInventario.clear();
    sudaderasEnInventario.clear();
    pantalonesEnInventario.clear();
    gafasDeSolEnInventario.clear();
    gorrasEnInventario.clear();
    
    // Variables auxiliares para leer los datos del archivo.
    string linea, codigo, temporadaStr, generoStr, tallaStr, tipoCamisetaStr, material, estampadoStr,
           estiloStr, lanaStr, tipoSudaderaStr, cremStr, tipoPantalonStr, cargoStr, formaLente, uv, tipoGorra, materialGorra;
    int cantidad;
    float precio;

    // Cargar camisetas
    getline(archivo, linea); // Leer la etiqueta "Camisetas".
    size_t numCamisetas;
    archivo >> numCamisetas; // Leer la cantidad de camisetas.
    archivo.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignorar el salto de línea restante.

    // Iterar sobre el número de camisetas y cargarlas en el vector.
    for (size_t i = 0; i < numCamisetas; i++) {
        getline(archivo, codigo); // Leer el código del producto.
        archivo >> cantidad >> precio; // Leer cantidad y precio.
        archivo.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignorar el salto de línea restante.
        getline(archivo, temporadaStr); // Leer la temporada.
        getline(archivo, generoStr); // Leer el género.
        getline(archivo, tallaStr); // Leer la talla.
        getline(archivo, tipoCamisetaStr); // Leer el tipo de camiseta.
        getline(archivo, material); // Leer el material.
        getline(archivo, estampadoStr); // Leer si tiene estampado.

        // Convertir las cadenas leídas a los valores correspondientes de los enumeradores.
        Temporada temporada = stringToTemporada(temporadaStr);
        Genero genero = stringToGenero(generoStr);
        Talla talla = stringToTalla(tallaStr);
        TipoCamiseta tipoCamiseta = stringToTipoCamiseta(tipoCamisetaStr);
        bool estampado = (estampadoStr == "Sí");

        // Agregar una nueva camiseta al vector del inventario.
        camisetasEnInventario.emplace_back(codigo, precio, cantidad, temporada, genero, talla, tipoCamiseta, material, estampado);
    }

    // Cargar bufandas
    getline(archivo, linea); // Leer la etiqueta "Bufandas".
    size_t numBufandas;
    archivo >> numBufandas; // Leer la cantidad de bufandas.
    archivo.ignore(numeric_limits<streamsize>::max(), '\n');

    // Iterar sobre el número de bufandas y cargarlas en el vector.
    for (size_t i = 0; i < numBufandas; i++) {
        getline(archivo, codigo);
        archivo >> cantidad >> precio;
        archivo.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(archivo, temporadaStr);
        getline(archivo, generoStr);
        getline(archivo, estiloStr);
        getline(archivo, lanaStr);

        Temporada temporada = stringToTemporada(temporadaStr);
        Genero genero = stringToGenero(generoStr);
        Estilo estilo = stringToEstilo(estiloStr);
        bool esDeLana = (lanaStr == "Sí");

        bufandasEnInventario.emplace_back(codigo, precio, cantidad, temporada, genero, estilo, esDeLana);
    }

    // Cargar sudaderas
    getline(archivo, linea); // Leer la etiqueta "Sudaderas".
    size_t numSudaderas;
    archivo >> numSudaderas; // Leer la cantidad de sudaderas.
    archivo.ignore(numeric_limits<streamsize>::max(), '\n');

    // Iterar sobre el número de sudaderas y cargarlas en el vector.
    for (size_t i = 0; i < numSudaderas; i++) {
        getline(archivo, codigo);
        archivo >> cantidad >> precio;
        archivo.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(archivo, temporadaStr);
        getline(archivo, generoStr);
        getline(archivo, tallaStr);
        getline(archivo, tipoSudaderaStr);
        getline(archivo, material);
        getline(archivo, cremStr);

        Temporada temporada = stringToTemporada(temporadaStr);
        Genero genero = stringToGenero(generoStr);
        Talla talla = stringToTalla(tallaStr);
        TipoSudadera tipoSudadera = stringToTipoSudadera(tipoSudaderaStr);
        bool cremallera = (cremStr == "Sí");

        sudaderasEnInventario.emplace_back(codigo, precio, cantidad, temporada, genero, talla, tipoSudadera, material, cremallera);
    }

    //Cargar pantalones
    getline(archivo, linea); // Leer la etiqueta "Pantalones".
    size_t numPantalones;
    archivo >> numPantalones;
    archivo.ignore(numeric_limits<streamsize>::max(), '\n');

    for (size_t i = 0; i < numPantalones; i++) {
        getline(archivo, codigo);
        archivo >> cantidad >> precio;
        archivo.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(archivo, temporadaStr);
        getline(archivo, generoStr);
        getline(archivo, tallaStr);
        getline(archivo, tipoPantalonStr);
        getline(archivo, cargoStr);

        Temporada temporada = stringToTemporada(temporadaStr);
        Genero genero = stringToGenero(generoStr);
        Talla talla = stringToTalla(tallaStr);
        TipoPantalon tipoPantalon = stringToTipoPantalon(tipoPantalonStr);
        bool cargo = (cargoStr == "Sí");

        pantalonesEnInventario.emplace_back(codigo, precio, cantidad, temporada, genero, talla, tipoPantalon, cargo);
    }

    // Cargar gafas de sol
    getline(archivo, linea); // Leer la etiqueta "GafasDeSol".
    size_t numGafasDeSol;
    archivo >> numGafasDeSol;
    archivo.ignore(numeric_limits<streamsize>::max(), '\n');

    for (size_t i = 0; i < numGafasDeSol; i++) {
        getline(archivo, codigo);
        archivo >> cantidad >> precio;
        archivo.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(archivo, temporadaStr);
        getline(archivo, generoStr);
        getline(archivo, estiloStr);
        getline(archivo, formaLente);
        getline(archivo, uv);

        Temporada temporada = stringToTemporada(temporadaStr);
        Genero genero = stringToGenero(generoStr);
        Estilo estilo = stringToEstilo(estiloStr);
        bool proteccionUV = (uv == "Sí");

        gafasDeSolEnInventario.emplace_back(codigo, precio, cantidad, temporada, genero, estilo, formaLente, proteccionUV);
    }

    // Cargar gorras
    getline(archivo, linea); // Leer la etiqueta "Gorras".
    size_t numGorras;
    archivo >> numGorras;
    archivo.ignore(numeric_limits<streamsize>::max(), '\n');

    for (size_t i = 0; i < numGorras; i++) {
        getline(archivo, codigo);
        archivo >> cantidad >> precio;
        archivo.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(archivo, temporadaStr);
        getline(archivo, generoStr);
        getline(archivo, estiloStr);
        getline(archivo, tipoGorra);
        getline(archivo, materialGorra);

        Temporada temporada = stringToTemporada(temporadaStr);
        Genero genero = stringToGenero(generoStr);
        Estilo estilo = stringToEstilo(estiloStr);

        gorrasEnInventario.emplace_back(codigo, precio, cantidad, temporada, genero, estilo, tipoGorra, materialGorra);
    }
}


void Inventario::consultarPorCategoria(const string& categoria) const {
    cout << "\n=== Consultando productos de la categoría: " << categoria << " ===\n";
    
    // Verifica si la categoría es "Camiseta".
    if (categoria == "Camiseta") {
        for (const auto& camiseta : camisetasEnInventario) {
            camiseta.mostrarInformacion();
            cout << "-------------------\n";
        }
    
    // Verifica si la categoría es "Camiseta".
    } else if (categoria == "Sudadera") {
        for (const auto& sudadera : sudaderasEnInventario) {
            sudadera.mostrarInformacion();
            cout << "-------------------\n";
        }
        
        // Verifica si la categoría es "Camiseta".
    } else if (categoria == "Pantalon") {
        for (const auto& pantalon : pantalonesEnInventario) {
            pantalon.mostrarInformacion();
            cout << "-------------------\n";
        }
        
    // Verifica si la categoría es "Camiseta".
    } else if (categoria == "Bufanda") {
        for (const auto& bufanda : bufandasEnInventario) {
            bufanda.mostrarInformacion();
            cout << "-------------------\n";
        }
    
    // Verifica si la categoría es "Camiseta".
    } else if (categoria == "Gafas de sol") {
        for (const auto& gafas : gafasDeSolEnInventario) {
            gafas.mostrarInformacion();
            cout << "-------------------\n";
        }
        
    // Verifica si la categoría es "Camiseta".
    } else if (categoria == "Gorra") {
        for (const auto& gorra : gorrasEnInventario) {
            gorra.mostrarInformacion();
            cout << "-------------------\n";
        }
    }
    
    // Si la categoría no coincide con ninguna de las conocidas.
    else {
        cout << "Categoría no válida.\n";
    }
}

string Inventario::generarCodigoTransaccion(const string& codigoProducto) {
    
    // Inicializar la semilla de números aleatorios solo una vez para evitar reiniciar la secuencia.
    static bool semillaInicializada = false;                // Variable estática para rastrear si la semilla ya se inicializó.
    if (!semillaInicializada) {
        srand(static_cast<unsigned int>(time(nullptr)));    // Inicializa la semilla con el tiempo actual.
        semillaInicializada = true;                         // Marca que la semilla ya fue inicializada.
    }
    
    // Inicia el código de transacción con un prefijo "TX-" seguido del código del producto.
    string codigo = "TX-" + codigoProducto;

    // Arreglo de letras posibles para las partes aleatorias del código.
    const char letras[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    // Genera un número aleatorio entre 0 y 9.
    const int numeroAleatorio = rand() % 10;

    // Selecciona dos letras aleatorias del arreglo `letras`.
    char letra1 = letras[rand() % (sizeof(letras) - 1)]; // Primera letra aleatoria.
    char letra2 = letras[rand() % (sizeof(letras) - 1)]; // Segunda letra aleatoria.

    // Construir el código combinando el prefijo, el código del producto, las letras y el número aleatorio.
    codigo += letra1;                       // Añade la primera letra aleatoria.
    codigo += to_string(numeroAleatorio);   // Añade el número aleatorio convertido a string.
    codigo += letra2;                       // Añade la segunda letra aleatoria.

    // Devuelve el código de transacción generado.
    return codigo;
}

void Inventario::registrarCambio(const string& tiendaNombre) {
    string codigoProductoCambiado, codigoProductoCambio;
    
    // Solicitar código del producto que se cambia
    cout << "Ingrese el código del producto que se cambia: ";
    cin >> codigoProductoCambiado;
    
    // Solicitar código del producto por el que se cambia
    cout << "Ingrese el código del producto por el que se cambia: ";
    cin >> codigoProductoCambio;
    
    Producto* productoSaliente = nullptr; // Puntero para almacenar el producto que será devuelto.
    Producto* productoEntrante = nullptr; // Puntero para almacenar el producto que será llevado.
    
    // Buscar ambos productos en el inventario
    for (auto& camiseta : camisetasEnInventario) {
        if (camiseta.getCodProducto() == codigoProductoCambiado) {
            productoSaliente = &camiseta; // Enlaza el puntero al producto saliente.
        }
        if (camiseta.getCodProducto() == codigoProductoCambio) {
            productoEntrante = &camiseta; // Enlaza el puntero al producto entrante.
        }
    }
    
    // Repetir la búsqueda para cada categoría de productos.
    for (auto& sudadera : sudaderasEnInventario) {
        if (sudadera.getCodProducto() == codigoProductoCambiado) {
            productoSaliente = &sudadera;
        }
        if (sudadera.getCodProducto() == codigoProductoCambio) {
            productoEntrante = &sudadera;
        }
    }
    
    for (auto& pantalon : pantalonesEnInventario) {
        if (pantalon.getCodProducto() == codigoProductoCambiado) {
            productoSaliente = &pantalon;
        }
        if (pantalon.getCodProducto() == codigoProductoCambio) {
            productoEntrante = &pantalon;
        }
    }
    
    for (auto& bufanda : bufandasEnInventario) {
        if (bufanda.getCodProducto() == codigoProductoCambiado) {
            productoSaliente = &bufanda;
        }
        if (bufanda.getCodProducto() == codigoProductoCambio) {
            productoEntrante = &bufanda;
        }
    }
    
    for (auto& gafas : gafasDeSolEnInventario) {
        if (gafas.getCodProducto() == codigoProductoCambiado) {
            productoSaliente = &gafas;
        }
        if (gafas.getCodProducto() == codigoProductoCambio) {
            productoEntrante = &gafas;
        }
    }
    
    for (auto& gorra : gorrasEnInventario) {
        if (gorra.getCodProducto() == codigoProductoCambiado) {
            productoSaliente = &gorra;
        }
        if (gorra.getCodProducto() == codigoProductoCambio) {
            productoEntrante = &gorra;
        }
    }
    
    // Validar si ambos productos existen
    if (!productoSaliente) {
        cout << "El producto con código \"" << codigoProductoCambiado << "\" no se encuentra en el inventario." << endl;
        return;
    }
    
    if (!productoEntrante) {
        cout << "El producto con código \"" << codigoProductoCambio << "\" no se encuentra en el inventario." << endl;
        return;
    }
    
    // Verificar disponibilidad del producto que la tienda quiere dar
    if (productoEntrante->getCantidad() == 0) {
        cout << "El producto \"" << productoEntrante->getCodProducto() << "\" no tiene existencias en el inventario. No se puede realizar el cambio." << endl;
        return;
    }
    
    // Comparar precios
    float precioSaliente = productoSaliente->getPrecioVenta();
    float precioEntrante = productoEntrante->getPrecioVenta();
    
    cout << "--------------------------------------" << endl;
    cout << "Producto que se devuelve:" << endl;
    productoSaliente->mostrarInformacion();
    cout << "--------------------------------------" << endl;
    cout << "Producto que se lleva:" << endl;
    productoEntrante->mostrarInformacion();
    
    // Mostrar el resultado de la comparación de precios
    if (precioSaliente > precioEntrante) {
        float diferencia = precioSaliente - precioEntrante;
        cout << "El producto que devuelve el cliente cuesta más. La tienda generará un cupón de "
        << diferencia << " euros como crédito para el cliente.\n";
    } else if (precioSaliente < precioEntrante) {
        float diferencia = precioEntrante - precioSaliente;
        cout << "El producto que lleva el cliente cuesta más. El cliente deberá pagar una diferencia de "
        << diferencia << " euros.\n";
    } else {
        cout << "Ambos productos tienen el mismo precio. No hay diferencia de valor.\n";
    }
    
    // Confirmar el cambio
    cout << "¿Desea confirmar el cambio? (s/n): ";
    char confirmacion;
    cin >> confirmacion;
    
    if (tolower(confirmacion) == 's') {
        // Ajustar cantidades
        productoSaliente->setCantidad(productoSaliente->getCantidad() + 1); // Incrementa la cantidad del producto devuelto.
        productoEntrante->setCantidad(productoEntrante->getCantidad() - 1); // Decrementa la cantidad del producto llevado.
        
        // Generar un código de transacción
        string codigoTransaccion = generarCodigoTransaccion(productoSaliente->getCodProducto() + "-" + productoEntrante->getCodProducto());
        
        // Registrar el cambio en el archivo
        registrarCambioEnArchivo(tiendaNombre, productoSaliente->getCodProducto(), productoEntrante->getCodProducto(), codigoTransaccion);
        
        // Confirmar al usuario
        cout << "Cambio registrado exitosamente." << endl;
        cout << "Detalles del cambio:" << endl;
        cout << " - Código de transacción: " << codigoTransaccion << endl;
        cout << " - Código del producto cambiado: " << productoSaliente->getCodProducto() << endl;
        cout << " - Código del producto llevado: " << productoEntrante->getCodProducto() << endl;
    } else {
        cout << "Cambio cancelado." << endl;
    }
}

void Inventario::registrarCambioEnArchivo(const string& tienda, const string& codigoProductoSaliente, const string& codigoProductoEntrante, const string& codigoTransaccion) {
    // Abre el archivo "transacciones.txt" en modo de agregar (append).
    ofstream archivo("transacciones.txt", ios::app);
    
    // Verifica si el archivo se abrió correctamente.
    if (!archivo) {
        cerr << "Error al abrir el archivo transacciones.txt." << endl; // Mensaje de error si no se puede abrir.
        return; // Finaliza el método si ocurre un error.
    }

    // Obtiene la hora y fecha actual del sistema.
    time_t ahora = time(nullptr); // Obtiene la hora actual en segundos desde el epoch.
    tm* tiempoLocal = localtime(&ahora); // Convierte la hora a una estructura de tiempo local.

    // Escribe la transacción en el archivo con formato detallado.
    archivo << "Código de transacción: " << codigoTransaccion << endl; // Escribe el código de transacción.
    archivo << "Tipo de operación: Cambio" << endl; // Especifica que la operación es un cambio.
    archivo << "Fecha y hora: "
            << tiempoLocal->tm_year + 1900 << "-" // Año actual (se suma 1900 porque tm_year es desde 1900).
            << setw(2) << setfill('0') << tiempoLocal->tm_mon + 1 << "-" // Mes actual (se suma 1 porque tm_mon empieza desde 0).
            << setw(2) << setfill('0') << tiempoLocal->tm_mday << " " // Día del mes.
            << setw(2) << setfill('0') << tiempoLocal->tm_hour << ":" // Hora del día.
            << setw(2) << setfill('0') << tiempoLocal->tm_min << ":" // Minutos.
            << setw(2) << setfill('0') << tiempoLocal->tm_sec << endl; // Segundos.
    archivo << "Tienda: " << tienda << endl; // Escribe el nombre de la tienda donde ocurrió el cambio.
    archivo << "Código del producto cambiado: " << codigoProductoSaliente << endl; // Escribe el código del producto que se devolvió.
    archivo << "Código del producto llevado: " << codigoProductoEntrante << endl; // Escribe el código del producto que se entregó.
    archivo << "--------------------------------------" << endl; // Agrega una línea separadora para mejor legibilidad.

    archivo.close(); // Cierra el archivo después de escribir los datos.
}

void Inventario::registrarDevolucion(const string& tiendaNombre) {
    string codigoProducto; // Código del producto que se quiere devolver.
    cout << "Ingrese el código del producto que desea devolver: ";
    cin >> codigoProducto; // Leer el código del producto ingresado por el usuario.
    
    // Buscar el producto en cada contenedor del inventario.
    for (auto& camiseta : camisetasEnInventario) { // Buscar en las camisetas.
        if (camiseta.getCodProducto() == codigoProducto) { // Si se encuentra el producto.
            procesarDevolucion(camiseta, tiendaNombre); // Procesa la devolución de la camiseta.
            return; // Salir del método.
        }
    }
    
    for (auto& sudadera : sudaderasEnInventario) { // Buscar en las sudaderas.
        if (sudadera.getCodProducto() == codigoProducto) { // Si se encuentra el producto.
            procesarDevolucion(sudadera, tiendaNombre); // Procesa la devolución de la sudadera.
            return; // Salir del método.
        }
    }
    
    for (auto& pantalon : pantalonesEnInventario) { // Buscar en los pantalones.
        if (pantalon.getCodProducto() == codigoProducto) { // Si se encuentra el producto.
            procesarDevolucion(pantalon, tiendaNombre); // Procesa la devolución del pantalón.
            return; // Salir del método.
        }
    }
    
    for (auto& bufanda : bufandasEnInventario) { // Buscar en las bufandas.
        if (bufanda.getCodProducto() == codigoProducto) { // Si se encuentra el producto.
            procesarDevolucion(bufanda, tiendaNombre); // Procesa la devolución de la bufanda.
            return; // Salir del método.
        }
    }
    
    for (auto& gafas : gafasDeSolEnInventario) { // Buscar en las gafas de sol.
        if (gafas.getCodProducto() == codigoProducto) { // Si se encuentra el producto.
            procesarDevolucion(gafas, tiendaNombre); // Procesa la devolución de las gafas de sol.
            return; // Salir del método.
        }
    }
    
    for (auto& gorra : gorrasEnInventario) { // Buscar en las gorras.
        if (gorra.getCodProducto() == codigoProducto) { // Si se encuentra el producto.
            procesarDevolucion(gorra, tiendaNombre); // Procesa la devolución de la gorra.
            return; // Salir del método.
        }
    }
    
    // Si no se encontró el producto en el inventario.
    cout << "El producto con código \"" << codigoProducto << "\" no se encuentra en el inventario." << endl;
}

void Inventario::procesarDevolucion(Producto& producto, const string& tiendaNombre) {
    producto.mostrarInformacion(); // Muestra la información del producto a devolver.

    int cantidad; // Cantidad que el cliente desea devolver.
    while (true) {
        try {
            cout << "Ingrese la cantidad que desea devolver: ";
            cin >> cantidad; // Leer la cantidad.

            // Validar si la entrada es un número válido.
            if (cin.fail()) {
                cin.clear(); // Limpia el estado de error de cin.
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descarta la entrada incorrecta.
                throw invalid_argument("Error: La cantidad debe ser un número entero válido."); // Lanza un error si la entrada es inválida.
            }

            // Validar si la cantidad está en el rango permitido.
            if (cantidad <= 0 || cantidad > producto.getCantidad()) {
                throw out_of_range("Cantidad no válida. Debe estar entre 1 y " + to_string(producto.getCantidad()) + "."); // Lanza un error si la cantidad no es válida.
            }

            // Si la cantidad es válida, salir del bucle.
            break;
        } catch (const exception& e) {
            cout << e.what() << " Inténtelo de nuevo.\n"; // Muestra el error y permite al usuario intentarlo nuevamente.
        }
    }

    // Calcular el precio total de la devolución.
    float precioTotal = cantidad * producto.getPrecioVenta();

    // Confirmar la devolución con el usuario.
    cout << "El precio total es: " << fixed << setprecision(2) << precioTotal << " €" << endl;
    cout << "¿Desea confirmar la devolución? (s/n): ";
    char confirmacion;
    cin >> confirmacion;

    if (tolower(confirmacion) == 's') { // Si el usuario confirma la devolución.
        // Actualizar la cantidad del producto en el inventario.
        producto.setCantidad(producto.getCantidad() + cantidad);

        // Generar un código de transacción único para la devolución.
        string codigoTransaccion = generarCodigoTransaccion(producto.getCodProducto());

        // Registrar la devolución en un archivo de transacciones.
        registrarDevolucionEnArchivo("Devolución", tiendaNombre, producto.getCodProducto(), cantidad, precioTotal, codigoTransaccion);

        // Confirmar al usuario que la devolución se registró.
        cout << "Devolución registrada exitosamente." << endl;
        cout << "Detalles de la transacción:" << endl;
        cout << " - Código de transacción: " << codigoTransaccion << endl;
        cout << " - Cantidad devuelta: " << cantidad << endl;
        cout << " - Precio total: " << fixed << setprecision(2) << precioTotal << " €" << endl;
    } else {
        cout << "Devolución cancelada." << endl; // Mensaje si el usuario cancela la devolución.
    }
}

void Inventario::registrarDevolucionEnArchivo(const string& tipoOperacion, const string& tienda, const string& codigoProducto, int cantidad, float precioTotal, const string& codigoTransaccion) {
    // Abre el archivo "transacciones.txt" en modo de agregar (append).
    ofstream archivo("transacciones.txt", ios::app);
    if (!archivo) { // Si no se puede abrir el archivo, muestra un mensaje de error.
        cerr << "Error al abrir el archivo transacciones.txt." << endl;
        return;
    }
    
    // Obtiene la fecha y hora actual.
    time_t ahora = time(nullptr); // Obtiene el tiempo actual en segundos desde el epoch.
    tm* tiempoLocal = localtime(&ahora); // Convierte el tiempo a formato local.
    
    // Escribe la información de la transacción en el archivo.
    archivo << "Código de transacción: " << codigoTransaccion << endl; // Código único de la transacción.
    archivo << "Tipo de operación: " << tipoOperacion << endl; // Especifica que es una devolución.
    archivo << "Fecha y hora: "
    << tiempoLocal->tm_year + 1900 << "-" // Año actual.
    << setw(2) << setfill('0') << tiempoLocal->tm_mon + 1 << "-" // Mes actual.
    << setw(2) << setfill('0') << tiempoLocal->tm_mday << " " // Día del mes.
    << setw(2) << setfill('0') << tiempoLocal->tm_hour << ":" // Hora del día.
    << setw(2) << setfill('0') << tiempoLocal->tm_min << ":" // Minutos.
    << setw(2) << setfill('0') << tiempoLocal->tm_sec << endl; // Segundos.
    archivo << "Tienda: " << tienda << endl; // Nombre de la tienda.
    archivo << "Código de producto: " << codigoProducto << endl; // Código del producto devuelto.
    archivo << "Cantidad: " << cantidad << endl; // Cantidad devuelta.
    archivo << "Precio unitario: " << fixed << setprecision(2) << precioTotal / cantidad << " €" << endl; // Precio por unidad.
    archivo << "Precio total: " << fixed << setprecision(2) << precioTotal << " €" << endl; // Precio total.
    archivo << "--------------------------------------" << endl; // Separador para la transacción.

    archivo.close(); // Cierra el archivo después de escribir los datos.
}

void Inventario::registrarVenta(const string& tiendaNombre) {
    string codigoProducto; // Código del producto que se desea vender.
    cout << "Ingrese el código del producto que desea vender: ";
    cin >> codigoProducto; // Leer el código del producto.

    // Buscar el producto en cada contenedor del inventario.
    for (auto& camiseta : camisetasEnInventario) { // Buscar en las camisetas.
        if (camiseta.getCodProducto() == codigoProducto) { // Si se encuentra el producto.
            procesarVenta(camiseta, tiendaNombre); // Procesa la venta de la camiseta.
            return; // Salir del método.
        }
    }
    
    for (auto& sudadera : sudaderasEnInventario) { // Buscar en las sudaderas.
        if (sudadera.getCodProducto() == codigoProducto) { // Si se encuentra el producto.
            procesarVenta(sudadera, tiendaNombre); // Procesa la venta de la sudadera.
            return; // Salir del método.
        }
    }
    
    for (auto& pantalon : pantalonesEnInventario) { // Buscar en los pantalones.
        if (pantalon.getCodProducto() == codigoProducto) { // Si se encuentra el producto.
            procesarVenta(pantalon, tiendaNombre); // Procesa la venta del pantalón.
            return; // Salir del método.
        }
    }
    
    for (auto& bufanda : bufandasEnInventario) { // Buscar en las bufandas.
        if (bufanda.getCodProducto() == codigoProducto) { // Si se encuentra el producto.
            procesarVenta(bufanda, tiendaNombre); // Procesa la venta de la bufanda.
            return; // Salir del método.
        }
    }
    
    for (auto& gafas : gafasDeSolEnInventario) { // Buscar en las gafas de sol.
        if (gafas.getCodProducto() == codigoProducto) { // Si se encuentra el producto.
            procesarVenta(gafas, tiendaNombre); // Procesa la venta de las gafas de sol.
            return; // Salir del método.
        }
    }
    
    for (auto& gorra : gorrasEnInventario) { // Buscar en las gorras.
        if (gorra.getCodProducto() == codigoProducto) { // Si se encuentra el producto.
            procesarVenta(gorra, tiendaNombre); // Procesa la venta de la gorra.
            return; // Salir del método.
        }
    }
    
    // Si no se encontró el producto en el inventario.
    cout << "El producto con código \"" << codigoProducto << "\" no se encuentra en el inventario." << endl;
}

void Inventario::procesarVenta(Producto& producto, const string& tiendaNombre) {
    producto.mostrarInformacion(); // Muestra la información del producto.

    // Verificar si el inventario tiene unidades disponibles del producto.
    if (producto.getCantidad() == 0) {
        cout << "El producto \"" << producto.getCodProducto() << "\" no tiene unidades disponibles en el inventario." << endl;
        return; // Salir del método si no hay stock.
    }

    int cantidad; // Cantidad que se desea vender.
    cout << "Ingrese la cantidad que desea vender: ";
    cin >> cantidad; // Leer la cantidad deseada.

    // Validar si la cantidad ingresada es válida.
    if (cantidad <= 0 || cantidad > producto.getCantidad()) {
        cout << "Cantidad no válida. Debe estar entre 1 y " << producto.getCantidad() << "." << endl;
        return; // Salir del método si la cantidad no es válida.
    }

    // Calcular el precio total de la venta.
    float precioTotal = cantidad * producto.getPrecioVenta();

    // Confirmar la venta con el usuario.
    cout << "El precio total es: " << fixed << setprecision(2) << precioTotal << " €" << endl;
    cout << "¿Desea confirmar la venta? (s/n): ";
    char confirmacion;
    cin >> confirmacion;

    if (tolower(confirmacion) == 's') { // Si el usuario confirma la venta.
        // Actualizar el inventario restando las unidades vendidas.
        producto.setCantidad(producto.getCantidad() - cantidad);

        // Generar un código único de transacción para la venta.
        string codigoTransaccion = generarCodigoTransaccion(producto.getCodProducto());

        // Registrar la venta en el archivo de transacciones.
        registrarVentaEnArchivo("Venta", tiendaNombre, producto.getCodProducto(), cantidad, precioTotal, codigoTransaccion);

        // Confirmar al usuario que la venta fue registrada.
        cout << "Venta registrada exitosamente." << endl;
        cout << "Detalles de la transacción:" << endl;
        cout << " - Código de transacción: " << codigoTransaccion << endl;
        cout << " - Cantidad vendida: " << cantidad << endl;
        cout << " - Precio total: " << fixed << setprecision(2) << precioTotal << " €" << endl;
    } else {
        cout << "Venta cancelada." << endl; // Mensaje si el usuario cancela la venta.
    }
}

void Inventario::registrarVentaEnArchivo(const string& tipoOperacion, const string& tienda, const string& codigoProducto,
                             int cantidad, float precioTotal, const string& codigoTransaccion) {
    // Abre el archivo "transacciones.txt" en modo de agregar (append).
    ofstream archivo("transacciones.txt", ios::app);
    if (!archivo) { // Si no se puede abrir el archivo, muestra un mensaje de error.
        cerr << "Error al abrir el archivo transacciones.txt." << endl;
        return;
    }
    
    // Obtiene la fecha y hora actual.
    time_t ahora = time(nullptr); // Obtiene el tiempo actual en segundos desde el epoch.
    tm* tiempoLocal = localtime(&ahora); // Convierte el tiempo a formato local.

    // Escribe los detalles de la transacción en el archivo.
    archivo << "Código de transacción: " << codigoTransaccion << endl; // Código único de la transacción.
    archivo << "Tipo de operación: " << tipoOperacion << endl; // Especifica que es una venta.
    archivo << "Fecha y hora: "
    << tiempoLocal->tm_year + 1900 << "-" // Año actual.
    << setw(2) << setfill('0') << tiempoLocal->tm_mon + 1 << "-" // Mes actual.
    << setw(2) << setfill('0') << tiempoLocal->tm_mday << " " // Día del mes.
    << setw(2) << setfill('0') << tiempoLocal->tm_hour << ":" // Hora del día.
    << setw(2) << setfill('0') << tiempoLocal->tm_min << ":" // Minutos.
    << setw(2) << setfill('0') << tiempoLocal->tm_sec << endl; // Segundos.
    archivo << "Tienda: " << tienda << endl; // Nombre de la tienda.
    archivo << "Código de producto: " << codigoProducto << endl; // Código del producto vendido.
    archivo << "Cantidad: " << cantidad << endl; // Cantidad vendida.
    archivo << "Precio unitario: " << fixed << setprecision(2) << precioTotal / cantidad << " €" << endl; // Precio por unidad.
    archivo << "Precio total: " << fixed << setprecision(2) << precioTotal << " €" << endl; // Precio total.
    archivo << "--------------------------------------" << endl; // Separador para la transacción.

    archivo.close(); // Cierra el archivo después de escribir los datos.
}
