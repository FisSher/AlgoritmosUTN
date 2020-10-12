template <typename Nodo, typename Valor>
Nodo* agregar(Nodo*&lista,Valor valor) {
	Nodo* nuevo = new Nodo();
	nuevo->info = valor;
	nuevo->sig = NULL;
	if (lista == NULL)
		lista = nuevo;
	else
	{
		Nodo* aux = lista;
		while (aux->sig != NULL)
		{
			aux = aux->sig;
		}
		aux->sig = nuevo;
	}
	return nuevo;
}

template <typename Nodo, typename V>
Nodo* buscar(Nodo* lista, V valorBuscado) {
	Nodo* aux = lista;
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

template <typename Nodo, typename Valor, typename B >
Nodo* buscaEInserta(Nodo*& lista, Valor valorBuscado, B& encontrado) {
	Nodo* nodoBuscado = buscar(lista, valorBuscado);
	if (nodoBuscado != NULL) { // el nodo está en la lista
		encontrado = true;
	}
	else { // el nodo no está
		nodoBuscado = agregar(lista, valorBuscado);
		encontrado = false;
	}

	return nodoBuscado;
};