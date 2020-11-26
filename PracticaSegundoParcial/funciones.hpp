template <typename T, typename V>
T* agregar(T*& lista, V valor) {
	T* nuevo = new T();
	nuevo->info = valor;
	nuevo->sig = NULL;
	if (lista == NULL) { // la lista esta vacía
		lista = nuevo;
	}
	else {
		T* aux = lista;
		while (aux->sig != NULL) {
			aux = aux->sig;
		}
		aux->sig = nuevo;
	}

	return nuevo;
}

template <typename T, typename V>
T* buscar(T* lista, V valorBuscado) {
	T* aux = lista;
	try
	{
		while (aux != NULL && aux->info.id != valorBuscado.id)
		{
			aux = aux->sig;
		}
	}
	catch (std::exception& e)
	{
		std::cout << "Error en la busqueda: " << e.what() << std::endl;
	}

	return aux;
}

template <typename T, typename V, typename B >
T* buscaEInserta(T*& lista, V valorBuscado, B& encontrado) {
	T* nodoBuscado = buscar(lista, valorBuscado);
	if (nodoBuscado != NULL) { // el nodo está en la lista
		encontrado = true;
	}
	else { // el nodo no está
		nodoBuscado = agregar(lista, valorBuscado);
		encontrado = false;
	}

	return nodoBuscado;
};