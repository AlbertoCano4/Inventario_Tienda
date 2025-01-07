#include "Inventario.hpp"

Inventario::Inventario() {
    camisetasEnInventario.clear();
    bufandasEnInventario.clear();
    sudaderasEnInventario.clear();
    pantalonesEnInventario.clear();
    gafasDeSolEnInventario.clear();
    gorrasEnInventario.clear();
}

void Inventario::anadirProductoDesdeAlmacen(const Almacen& almacen) {
    string codigo;
    int cantidad;
    
    cout << "Ingrese el código del producto que desea añadir: ";
    cin >> codigo;
    // Manejo de entrada y validación de cantidad
    while (true) {
        try {
            cout << "Ingrese la cantidad que desea añadir: ";
            cin >> cantidad;
            
            // Detectar entradas no numéricas
            if (cin.fail()) {
                cin.clear(); // Limpiar estado de error de cin
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descartar entrada incorrecta
                throw invalid_argument("Error: Has introducido un valor no numérico.");
            }
            
            // Validar si la cantidad es mayor a 0
            if (cantidad <= 0) {
                throw invalid_argument("Error: La cantidad debe ser mayor a 0.");
            }
            
            break; // Salir del bucle si la entrada es válida
        } catch (const invalid_argument& e) {
            cout << e.what() << " Inténtelo de nuevo.\n";
        }
    }
    
    // Limpiar el buffer de entrada
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    
    bool productoEncontrado = false;
    
    try {
        // Buscar en las camisetas
        for (auto& camiseta : camisetasEnInventario) {
            if (camiseta.getCodProducto() == codigo) {
                camiseta.setCantidad(camiseta.getCantidad() + cantidad);
                cout << "Camiseta " << codigo << " actualizado. Nueva cantidad: " << camiseta.getCantidad() << "\n";
                productoEncontrado = true;
                break;
            }
        }
        // Buscar en las Sudaderas
        if (!productoEncontrado) {
            for (auto& sudadera : sudaderasEnInventario) {
                if (sudadera.getCodProducto() == codigo) {
                    sudadera.setCantidad(sudadera.getCantidad() + cantidad);
                    cout << "Sudadera " << codigo << " actualizada. Nueva cantidad: " << sudadera.getCantidad() << "\n";
                    productoEncontrado = true;
                    break;
                }
            }
        }
        // Buscar en los Pantalones
        if (!productoEncontrado) {
            for (auto& pantalon : pantalonesEnInventario) {
                if (pantalon.getCodProducto() == codigo) {
                    pantalon.setCantidad(pantalon.getCantidad() + cantidad);
                    cout << "Pantalon " << codigo << " actualizada. Nueva cantidad: " << pantalon.getCantidad() << "\n";
                    productoEncontrado = true;
                    break;
                }
            }
        }
        // Buscar en las bufandas
        if (!productoEncontrado) {
            for (auto& bufanda : bufandasEnInventario) {
                if (bufanda.getCodProducto() == codigo) {
                    bufanda.setCantidad(bufanda.getCantidad() + cantidad);
                    cout << "Bufanda " << codigo << " actualizada. Nueva cantidad: " << bufanda.getCantidad() << "\n";
                    productoEncontrado = true;
                    break;
                }
            }
        }
        // Buscar en las Gafas de Sol
        if (!productoEncontrado) {
            for (auto& gafasDeSol : gafasDeSolEnInventario) {
                if (gafasDeSol.getCodProducto() == codigo) {
                    gafasDeSol.setCantidad(gafasDeSol.getCantidad() + cantidad);
                    cout << "gafas De Sol " << codigo << " actualizada. Nueva cantidad: " << gafasDeSol.getCantidad() << "\n";
                    productoEncontrado = true;
                    break;
                }
            }
        }
        // Buscar en las Gorras
        if (!productoEncontrado) {
            for (auto& gorra : gorrasEnInventario) {
                if (gorra.getCodProducto() == codigo) {
                    gorra.setCantidad(gorra.getCantidad() + cantidad);
                    cout << "Gorra " << codigo << " actualizada. Nueva cantidad: " << gorra.getCantidad() << "\n";
                    productoEncontrado = true;
                    break;
                }
            }
        }
        
        // Si no está en el inventario, buscar en el almacén
        if (!productoEncontrado) {
            for (const auto& camiseta : almacen.getCamisetas()) {
                if (camiseta.getCodProducto() == codigo) {
                    Camiseta nuevaCamiseta = camiseta;
                    nuevaCamiseta.setCantidad(cantidad);
                    camisetasEnInventario.push_back(nuevaCamiseta);
                    cout << "Camiseta " << codigo << " añadido al inventario. Cantidad: " << cantidad << "\n";
                    productoEncontrado = true;
                    break;
                }
            }
        }
        
        if (!productoEncontrado) {
            for (const auto& sudadera : almacen.getSudaderas()) {
                if (sudadera.getCodProducto() == codigo) {
                    Sudadera nuevaSudadera = sudadera;
                    nuevaSudadera.setCantidad(cantidad);
                    sudaderasEnInventario.push_back(nuevaSudadera);
                    cout << "Sudadera " << codigo << " añadida al inventario. Cantidad: " << cantidad << "\n";
                    productoEncontrado = true;
                    break;
                }
            }
        }
        
        if (!productoEncontrado) {
            for (const auto& pantalon : almacen.getPantalones()) {
                if (pantalon.getCodProducto() == codigo) {
                    Pantalon nuevoPantalon = pantalon;
                    nuevoPantalon.setCantidad(cantidad);
                    pantalonesEnInventario.push_back(nuevoPantalon);
                    cout << "Pantalón " << codigo << " añadido al inventario. Cantidad: " << cantidad << "\n";
                    productoEncontrado = true;
                    break;
                }
            }
        }
        
        if (!productoEncontrado) {
            for (const auto& bufanda : almacen.getBufandas()) {
                if (bufanda.getCodProducto() == codigo) {
                    Bufanda nuevaBufanda = bufanda;
                    nuevaBufanda.setCantidad(cantidad);
                    bufandasEnInventario.push_back(nuevaBufanda);
                    cout << "Bufanda " << codigo << " añadida al inventario. Cantidad: " << cantidad << "\n";
                    productoEncontrado = true;
                    break;
                }
            }
        }
        
        if (!productoEncontrado) {
            for (const auto& gafas : almacen.getGafasDeSol()) {
                if (gafas.getCodProducto() == codigo) {
                    GafasDeSol nuevasGafas = gafas;
                    nuevasGafas.setCantidad(cantidad);
                    gafasDeSolEnInventario.push_back(nuevasGafas);
                    cout << "Gafas de Sol " << codigo << " añadidas al inventario. Cantidad: " << cantidad << "\n";
                    productoEncontrado = true;
                    break;
                }
            }
        }
        
        if (!productoEncontrado) {
            for (const auto& gorra : almacen.getGorras()) {
                if (gorra.getCodProducto() == codigo) {
                    Gorra nuevaGorra = gorra;
                    nuevaGorra.setCantidad(cantidad);
                    gorrasEnInventario.push_back(nuevaGorra);
                    cout << "Gorra " << codigo << " añadida al inventario. Cantidad: " << cantidad << "\n";
                    productoEncontrado = true;
                    break;
                }
            }
        }
        
        
        if (!productoEncontrado) {
            throw runtime_error("Error: Producto no encontrado en el inventario ni en el almacén.");
        }
    } catch (const runtime_error& e) {
        cout << e.what() << "\n";
    } catch (const exception& e) {
        cout << "Error inesperado: " << e.what() << "\n";
    }
}

void Inventario::mostrarInventario() const {
    cout << "\n=== Estado del Inventario ===\n";
    
    cout << "\n=== Camisetas ===\n";
    for (const auto& camiseta : camisetasEnInventario) {
        camiseta.mostrarInformacion();
        cout << "-------------------\n";
    }
    
    cout << "\n=== Sudaderas ===\n";
    for (const auto& sudadera : sudaderasEnInventario) {
        sudadera.mostrarInformacion();
        cout << "-------------------\n";
    }
    
    cout << "\n=== Pantalones ===\n";
    for (const auto& pantalon : pantalonesEnInventario) {
        pantalon.mostrarInformacion();
        cout << "-------------------\n";
    }
    
    cout << "\n=== Bufandas ===\n";
    for (const auto& bufanda : bufandasEnInventario) {
        bufanda.mostrarInformacion();
        cout << "-------------------\n";
    }
    
    cout << "\n=== Gafas de Sol ===\n";
    for (const auto& gafas : gafasDeSolEnInventario) {
        gafas.mostrarInformacion();
        cout << "-------------------\n";
    }
    
    cout << "\n=== Gorras ===\n";
    for (const auto& gorra : gorrasEnInventario) {
        gorra.mostrarInformacion();
        cout << "-------------------\n";
    }
}

void Inventario::guardarInventario(const string& archivoNombre) const {
    ofstream archivo(archivoNombre);
    if (!archivo) {
        cerr << "Error al abrir el archivo " << archivoNombre << "\n";
        return;
    }
    
    // Guardar cantidad de camisetas
    archivo << "Camisetas\n" << camisetasEnInventario.size() << "\n";
    for (const auto& producto : camisetasEnInventario) {
        archivo << producto.getCodProducto() << "\n"
        << producto.getCantidad() << "\n"
        << producto.getPrecioVenta() << "\n"
        << temporadaToString(producto.getTemporada()) << "\n"
        << generoToString(producto.getGenero()) << "\n"
        << tallaToString(producto.getTalla()) << "\n"
        << tipoCamisetaToString(producto.getTipo()) << "\n"
        << producto.getMaterial() << "\n"
        << (producto.getEstampado() ? "Sí" : "No") << "\n";
    }
    
    // Guardar cantidad de bufandas
    archivo << "Bufandas\n" << bufandasEnInventario.size() << "\n";
    for (const auto& bufanda : bufandasEnInventario) {
        archivo << bufanda.getCodProducto() << "\n"
        << bufanda.getCantidad() << "\n"
        << bufanda.getPrecioVenta() << "\n"
        << temporadaToString(bufanda.getTemporada()) << "\n"
        << generoToString(bufanda.getGenero()) << "\n"
        << estiloTostring(bufanda.getEstilo()) << "\n"
        << (bufanda.getEsDeLana() ? "Sí" : "No") << "\n";
    }
    
    // Guardar cantidad de Sudaderas
    archivo << "Sudaderas\n" << sudaderasEnInventario.size() << "\n";
    for (const auto& sudadera : sudaderasEnInventario) {
        archivo << sudadera.getCodProducto() << "\n"
        << sudadera.getCantidad() << "\n"
        << sudadera.getPrecioVenta() << "\n"
        << temporadaToString(sudadera.getTemporada()) << "\n"
        << generoToString(sudadera.getGenero()) << "\n"
        << tallaToString(sudadera.getTalla()) << "\n"
        << tipoSudaderaToString(sudadera.getTipoSudadera()) << "\n" // Enum convertido a string
        << sudadera.getMaterial() << "\n"
        << (sudadera.getCremallera() ? "Sí" : "No") << "\n";
    }
    
    // Guardar cantidad de Pantalones
    archivo << "Pantalones\n" << pantalonesEnInventario.size() << "\n";
    for (const auto& pantalon : pantalonesEnInventario) {
        archivo << pantalon.getCodProducto() << "\n"
        << pantalon.getCantidad() << "\n"
        << pantalon.getPrecioVenta() << "\n"
        << temporadaToString(pantalon.getTemporada()) << "\n"
        << generoToString(pantalon.getGenero()) << "\n"
        << tallaToString(pantalon.getTalla()) << "\n"
        << tipoPantalonToString(pantalon.getTipoPantalon()) << "\n" // Enum convertido a string
        << (pantalon.getCargo() ? "Sí" : "No") << "\n";
    }
    
    // Guardar cantidad de Gafas de Sol
    archivo << "GafasDeSol\n" << gafasDeSolEnInventario.size() << "\n";
    for (const auto& gafas : gafasDeSolEnInventario) {
        archivo << gafas.getCodProducto() << "\n"
        << gafas.getCantidad() << "\n"
        << gafas.getPrecioVenta() << "\n"
        << temporadaToString(gafas.getTemporada()) << "\n"
        << generoToString(gafas.getGenero()) << "\n"
        << estiloTostring(gafas.getEstilo()) << "\n"
        << gafas.getFormaLente() << "\n"
        << (gafas.getProteccionUV() ? "Sí" : "No") << "\n";
    }
    
    // Guardar cantidad de Gorras
    archivo << "Gorras\n" << gorrasEnInventario.size() << "\n";
    for (const auto& gorra : gorrasEnInventario) {
        archivo << gorra.getCodProducto() << "\n"
        << gorra.getCantidad() << "\n"
        << gorra.getPrecioVenta() << "\n"
        << temporadaToString(gorra.getTemporada()) << "\n"
        << generoToString(gorra.getGenero()) << "\n"
        << estiloTostring(gorra.getEstilo()) << "\n"
        << gorra.getTipo() << "\n"
        << gorra.getMaterial() << "\n";
    }
    archivo.close();
    cout << "Inventario guardado en " << archivoNombre << "\n";
}


void Inventario::cargarInventario(const string& archivoNombre) {
    ifstream archivo(archivoNombre);
    if (!archivo) {
        cerr << "Error al abrir el archivo " << archivoNombre << "\n";
        return;
    }
    
    camisetasEnInventario.clear();
    bufandasEnInventario.clear();
    sudaderasEnInventario.clear();
    pantalonesEnInventario.clear();
    gafasDeSolEnInventario.clear();
    gorrasEnInventario.clear();
    
    string linea, codigo, temporadaStr, generoStr, tallaStr, tipoCamisetaStr, material, estampadoStr, estiloStr, lanaStr, tipoSudaderaStr, cremStr, tipoPantalonStr, cargoStr, formaLente, uv, tipoGorra, materialGorra;;
    int cantidad;
    float precio;
    
    // Cargar camisetas
    getline(archivo, linea); // "Camisetas"
    size_t numCamisetas;
    archivo >> numCamisetas;
    archivo.ignore(numeric_limits<streamsize>::max(), '\n');
    
    for (size_t i = 0; i < numCamisetas; i++) {
        getline(archivo, codigo);
        archivo >> cantidad >> precio;
        archivo.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(archivo, temporadaStr);
        getline(archivo, generoStr);
        getline(archivo, tallaStr);
        getline(archivo, tipoCamisetaStr);
        getline(archivo, material);
        getline(archivo, estampadoStr);
        
        Temporada temporada = stringToTemporada(temporadaStr);
        Genero genero = stringToGenero(generoStr);
        Talla talla = stringToTalla(tallaStr);
        TipoCamiseta tipoCamiseta = stringToTipoCamiseta(tipoCamisetaStr);
        bool estampado = (estampadoStr == "Sí");
        
        camisetasEnInventario.emplace_back(codigo, precio, cantidad, temporada, genero, talla, tipoCamiseta, material, estampado);
    }
    
    // Cargar bufandas
    getline(archivo, linea); // "Bufandas"
    size_t numBufandas;
    archivo >> numBufandas;
    archivo.ignore(numeric_limits<streamsize>::max(), '\n');
    
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
    getline(archivo, linea); // "Sudaderas"
    size_t numSudaderas;
    archivo >> numSudaderas;
    archivo.ignore(numeric_limits<streamsize>::max(), '\n');
    
    for (size_t i = 0; i < numSudaderas; i++) {
        getline(archivo, codigo);
        archivo >> cantidad >> precio;
        archivo.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(archivo, temporadaStr);
        getline(archivo, generoStr);
        getline(archivo, tallaStr);
        getline(archivo, tipoSudaderaStr); // Leer tipo sudadera
        getline(archivo, material);
        getline(archivo, cremStr);
        
        Temporada temporada = stringToTemporada(temporadaStr);
        Genero genero = stringToGenero(generoStr);
        Talla talla = stringToTalla(tallaStr);
        TipoSudadera tipoSudadera = stringToTipoSudadera(tipoSudaderaStr); // Conversión
        bool cremallera = (cremStr == "Sí");
        
        sudaderasEnInventario.emplace_back(codigo, precio, cantidad, temporada, genero, talla, tipoSudadera, material, cremallera);
    }
    
    // Cargar pantalones
    getline(archivo, linea); // "Pantalones"
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
        getline(archivo, tipoPantalonStr); // Leer tipo pantalón
        getline(archivo, cargoStr);
        
        Temporada temporada = stringToTemporada(temporadaStr);
        Genero genero = stringToGenero(generoStr);
        Talla talla = stringToTalla(tallaStr);
        TipoPantalon tipoPantalon = stringToTipoPantalon(tipoPantalonStr); // Conversión
        bool cargo = (cargoStr == "Sí");
        
        pantalonesEnInventario.emplace_back(codigo, precio, cantidad, temporada, genero, talla, tipoPantalon, cargo);
    }
    
    // Cargar gafas de sol
    getline(archivo, linea); // "GafasDeSol"
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
    getline(archivo, linea); // "Gorras"
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
    
    if (categoria == "Camiseta") {
        for (const auto& camiseta : camisetasEnInventario) {
            camiseta.mostrarInformacion();
            cout << "-------------------\n";
        }
    } else if (categoria == "Sudadera") {
        for (const auto& sudadera : sudaderasEnInventario) {
            sudadera.mostrarInformacion();
            cout << "-------------------\n";
        }
    } else if (categoria == "Pantalon") {
        for (const auto& pantalon : pantalonesEnInventario) {
            pantalon.mostrarInformacion();
            cout << "-------------------\n";
        }
    } else if (categoria == "Bufanda") {
        for (const auto& bufanda : bufandasEnInventario) {
            bufanda.mostrarInformacion();
            cout << "-------------------\n";
        }
    } else if (categoria == "Gafas de sol") {
        for (const auto& gafas : gafasDeSolEnInventario) {
            gafas.mostrarInformacion();
            cout << "-------------------\n";
        }
    } else if (categoria == "Gorra") {
        for (const auto& gorra : gorrasEnInventario) {
            gorra.mostrarInformacion();
            cout << "-------------------\n";
        }
    } else {
        cout << "Categoría no válida.\n";
    }
}

string Inventario::generarCodigoTransaccion(const string& codigoProducto) {
    // Inicializar la semilla de números aleatorios solo una vez
    static bool semillaInicializada = false;
    if (!semillaInicializada) {
        srand(static_cast<unsigned int>(time(nullptr))); // Conversión explícita
        semillaInicializada = true;
    }
    
    string codigo = "TX-" + codigoProducto;
    const char letras[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const int numeroAleatorio = rand() % 10; // Número entre 0 y 9
    
    // Generar dos letras aleatorias
    char letra1 = letras[rand() % (sizeof(letras) - 1)];
    char letra2 = letras[rand() % (sizeof(letras) - 1)];
    
    // Construir el código
    codigo += letra1;
    codigo += to_string(numeroAleatorio);
    codigo += letra2;
    
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

    Producto* productoSaliente = nullptr;
    Producto* productoEntrante = nullptr;

    // Buscar ambos productos en el inventario
    for (auto& camiseta : camisetasEnInventario) {
        if (camiseta.getCodProducto() == codigoProductoCambiado) {
            productoSaliente = &camiseta;
        }
        if (camiseta.getCodProducto() == codigoProductoCambio) {
            productoEntrante = &camiseta;
        }
    }

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
        productoSaliente->setCantidad(productoSaliente->getCantidad() + 1);
        productoEntrante->setCantidad(productoEntrante->getCantidad() - 1);

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

void Inventario::registrarCambioEnArchivo(const string& tienda, const string& codigoProductoSaliente,
                              const string& codigoProductoEntrante, const string& codigoTransaccion) {
    ofstream archivo("transacciones.txt", ios::app);
    if (!archivo) {
        cerr << "Error al abrir el archivo transacciones.txt." << endl;
        return;
    }

    time_t ahora = time(nullptr);
    tm* tiempoLocal = localtime(&ahora);

    archivo << "Código de transacción: " << codigoTransaccion << endl;
    archivo << "Tipo de operación: Cambio" << endl;
    archivo << "Fecha y hora: "
            << tiempoLocal->tm_year + 1900 << "-"
            << setw(2) << setfill('0') << tiempoLocal->tm_mon + 1 << "-"
            << setw(2) << setfill('0') << tiempoLocal->tm_mday << " "
            << setw(2) << setfill('0') << tiempoLocal->tm_hour << ":"
            << setw(2) << setfill('0') << tiempoLocal->tm_min << ":"
            << setw(2) << setfill('0') << tiempoLocal->tm_sec << endl;
    archivo << "Tienda: " << tienda << endl;
    archivo << "Código del producto cambiado: " << codigoProductoSaliente << endl;
    archivo << "Código del producto llevado: " << codigoProductoEntrante << endl;
    archivo << "--------------------------------------" << endl;

    archivo.close();
}

void Inventario::registrarDevolucion(const string& tiendaNombre) {
    string codigoProducto;
    cout << "Ingrese el código del producto que desea devolver: ";
    cin >> codigoProducto;
    
    // Buscar el producto en cada contenedor
    for (auto& camiseta : camisetasEnInventario) {
        if (camiseta.getCodProducto() == codigoProducto) {
            procesarDevolucion(camiseta, tiendaNombre);
            return;
        }
    }
    
    for (auto& sudadera : sudaderasEnInventario) {
        if (sudadera.getCodProducto() == codigoProducto) {
            procesarDevolucion(sudadera, tiendaNombre);
            return;
        }
    }
    
    for (auto& pantalon : pantalonesEnInventario) {
        if (pantalon.getCodProducto() == codigoProducto) {
            procesarDevolucion(pantalon, tiendaNombre);
            return;
        }
    }
    
    for (auto& bufanda : bufandasEnInventario) {
        if (bufanda.getCodProducto() == codigoProducto) {
            procesarDevolucion(bufanda, tiendaNombre);
            return;
        }
    }
    
    for (auto& gafas : gafasDeSolEnInventario) {
        if (gafas.getCodProducto() == codigoProducto) {
            procesarDevolucion(gafas, tiendaNombre);
            return;
        }
    }
    
    for (auto& gorra : gorrasEnInventario) {
        if (gorra.getCodProducto() == codigoProducto) {
            procesarDevolucion(gorra, tiendaNombre);
            return;
        }
    }
    
    // Si no se encontró el producto
    cout << "El producto con código \"" << codigoProducto << "\" no se encuentra en el inventario." << endl;
}


void Inventario::procesarDevolucion(Producto& producto, const string& tiendaNombre) {
    producto.mostrarInformacion();

    int cantidad;
    while (true) {
        try {
            cout << "Ingrese la cantidad que desea devolver: ";
            cin >> cantidad;

            // Validar si la entrada es un número válido
            if (cin.fail()) {
                cin.clear(); // Limpiar el estado de error de cin
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descartar la entrada incorrecta
                throw invalid_argument("Error: La cantidad debe ser un número entero válido.");
            }

            // Validar rango de cantidad
            if (cantidad <= 0 || cantidad > producto.getCantidad()) {
                throw out_of_range("Cantidad no válida. Debe estar entre 1 y " + to_string(producto.getCantidad()) + ".");
            }

            // Si la cantidad es válida, salir del bucle
            break;
        } catch (const exception& e) {
            cout << e.what() << " Inténtelo de nuevo.\n";
        }
    }

    // Calcular el precio total
    float precioTotal = cantidad * producto.getPrecioVenta();

    // Confirmar la devolución
    cout << "El precio total es: " << fixed << setprecision(2) << precioTotal << " €" << endl;
    cout << "¿Desea confirmar la devolución? (s/n): ";
    char confirmacion;
    cin >> confirmacion;

    if (tolower(confirmacion) == 's') {
        // Actualizar inventario
        producto.setCantidad(producto.getCantidad() + cantidad);

        // Generar un código de transacción
        string codigoTransaccion = generarCodigoTransaccion(producto.getCodProducto());

        // Registrar la devolución en el archivo
        registrarDevolucionEnArchivo("Devolución", tiendaNombre, producto.getCodProducto(), cantidad, precioTotal, codigoTransaccion);

        // Confirmar al usuario
        cout << "Devolución registrada exitosamente." << endl;
        cout << "Detalles de la transacción:" << endl;
        cout << " - Código de transacción: " << codigoTransaccion << endl;
        cout << " - Cantidad devuelta: " << cantidad << endl;
        cout << " - Precio total: " << fixed << setprecision(2) << precioTotal << " €" << endl;
    } else {
        cout << "Devolución cancelada." << endl;
    }
}


void Inventario::registrarDevolucionEnArchivo(const string& tipoOperacion, const string& tienda, const string& codigoProducto,
                             int cantidad, float precioTotal, const string& codigoTransaccion) {
    ofstream archivo("transacciones.txt", ios::app);
    if (!archivo) {
        cerr << "Error al abrir el archivo transacciones.txt." << endl;
        return;
    }
    
    time_t ahora = time(nullptr);
    tm* tiempoLocal = localtime(&ahora);
    
    archivo << "Código de transacción: " << codigoTransaccion << endl;
    archivo << "Tipo de operación: " << tipoOperacion << endl;
    archivo << "Fecha y hora: "
    << tiempoLocal->tm_year + 1900 << "-"
    << setw(2) << setfill('0') << tiempoLocal->tm_mon + 1 << "-"
    << setw(2) << setfill('0') << tiempoLocal->tm_mday << " "
    << setw(2) << setfill('0') << tiempoLocal->tm_hour << ":"
    << setw(2) << setfill('0') << tiempoLocal->tm_min << ":"
    << setw(2) << setfill('0') << tiempoLocal->tm_sec << endl;
    archivo << "Tienda: " << tienda << endl;
    archivo << "Código de producto: " << codigoProducto << endl;
    archivo << "Cantidad: " << cantidad << endl;
    archivo << "Precio unitario: " << fixed << setprecision(2) << precioTotal / cantidad << " €" << endl;
    archivo << "Precio total: " << fixed << setprecision(2) << precioTotal << " €" << endl;
    archivo << "--------------------------------------" << endl;
    
    archivo.close();
}

void Inventario::registrarVenta(const string& tiendaNombre) {
    string codigoProducto;
    cout << "Ingrese el código del producto que desea vender: ";
    cin >> codigoProducto;
    
    // Buscar el producto en cada contenedor
    for (auto& camiseta : camisetasEnInventario) {
        if (camiseta.getCodProducto() == codigoProducto) {
            procesarVenta(camiseta, tiendaNombre);
            return;
        }
    }
    
    for (auto& sudadera : sudaderasEnInventario) {
        if (sudadera.getCodProducto() == codigoProducto) {
            procesarVenta(sudadera, tiendaNombre);
            return;
        }
    }
    
    for (auto& pantalon : pantalonesEnInventario) {
        if (pantalon.getCodProducto() == codigoProducto) {
            procesarVenta(pantalon, tiendaNombre);
            return;
        }
    }
    
    for (auto& bufanda : bufandasEnInventario) {
        if (bufanda.getCodProducto() == codigoProducto) {
            procesarVenta(bufanda, tiendaNombre);
            return;
        }
    }
    
    for (auto& gafas : gafasDeSolEnInventario) {
        if (gafas.getCodProducto() == codigoProducto) {
            procesarVenta(gafas, tiendaNombre);
            return;
        }
    }
    
    for (auto& gorra : gorrasEnInventario) {
        if (gorra.getCodProducto() == codigoProducto) {
            procesarVenta(gorra, tiendaNombre);
            return;
        }
    }
    
    // Si no se encontró el producto
    cout << "El producto con código \"" << codigoProducto << "\" no se encuentra en el inventario." << endl;
}


void Inventario::procesarVenta(Producto& producto, const string& tiendaNombre) {
    producto.mostrarInformacion();
    
    // Verificar si el inventario está vacío para el producto
    if (producto.getCantidad() == 0) {
        cout << "El producto \"" << producto.getCodProducto() << "\" no tiene unidades disponibles en el inventario." << endl;
        return;
    }
    
    int cantidad;
    cout << "Ingrese la cantidad que desea vender: ";
    cin >> cantidad;
    
    // Validar cantidad
    if (cantidad <= 0 || cantidad > producto.getCantidad()) {
        cout << "Cantidad no válida. Debe estar entre 1 y " << producto.getCantidad() << "." << endl;
        return;
    }
    
    // Calcular el precio total
    float precioTotal = cantidad * producto.getPrecioVenta();
    
    // Confirmar la venta
    cout << "El precio total es: " << fixed << setprecision(2) << precioTotal << " €" << endl;
    cout << "¿Desea confirmar la venta? (s/n): ";
    char confirmacion;
    cin >> confirmacion;
    
    if (tolower(confirmacion) == 's') {
        // Actualizar inventario
        producto.setCantidad(producto.getCantidad() - cantidad);
        
        // Generar un código de transacción
        string codigoTransaccion = generarCodigoTransaccion(producto.getCodProducto());
        
        // Registrar la venta en el archivo
        registrarVentaEnArchivo("Venta", tiendaNombre, producto.getCodProducto(), cantidad, precioTotal, codigoTransaccion);
        
        // Confirmar al usuario
        cout << "Venta registrada exitosamente." << endl;
        cout << "Detalles de la transacción:" << endl;
        cout << " - Código de transacción: " << codigoTransaccion << endl;
        cout << " - Cantidad vendida: " << cantidad << endl;
        cout << " - Precio total: " << fixed << setprecision(2) << precioTotal << " €" << endl;
    } else {
        cout << "Venta cancelada." << endl;
    }
}

void Inventario::registrarVentaEnArchivo(const string& tipoOperacion, const string& tienda, const string& codigoProducto,
                             int cantidad, float precioTotal, const string& codigoTransaccion) {
    ofstream archivo("transacciones.txt", ios::app);
    if (!archivo) {
        cerr << "Error al abrir el archivo transacciones.txt." << endl;
        return;
    }
    
    time_t ahora = time(nullptr);
    tm* tiempoLocal = localtime(&ahora);
    
    archivo << "Código de transacción: " << codigoTransaccion << endl;
    archivo << "Tipo de operación: " << tipoOperacion << endl;
    archivo << "Fecha y hora: "
    << tiempoLocal->tm_year + 1900 << "-"
    << setw(2) << setfill('0') << tiempoLocal->tm_mon + 1 << "-"
    << setw(2) << setfill('0') << tiempoLocal->tm_mday << " "
    << setw(2) << setfill('0') << tiempoLocal->tm_hour << ":"
    << setw(2) << setfill('0') << tiempoLocal->tm_min << ":"
    << setw(2) << setfill('0') << tiempoLocal->tm_sec << endl;
    archivo << "Tienda: " << tienda << endl;
    archivo << "Código de producto: " << codigoProducto << endl;
    archivo << "Cantidad: " << cantidad << endl;
    archivo << "Precio unitario: " << fixed << setprecision(2) << precioTotal / cantidad << " €" << endl;
    archivo << "Precio total: " << fixed << setprecision(2) << precioTotal << " €" << endl;
    archivo << "--------------------------------------" << endl;
    
    archivo.close();
}
