#include <iostream>
using namespace std;

// definicao de tipo
struct NO {
	int valor;
	NO* prox;
};

NO* topo = NULL;

// headers
void menu();
void inicializar();
void exibir();
void pop();
void push();
//--------------------------


int main()
{
	menu();
}

void menu()
{
	int op = 0;
	while (op != 5) {
		system("cls"); // somente no windows
		cout << "Menu Pilha";
		cout << endl << endl;
		cout << "1 - Inicializar Pilha \n";
		cout << "2 - exibir elementos \n";
		cout << "3 - Inserir elemento (Push) \n";
		cout << "4 - Remover elementos (Pop) \n";
		cout << "5 - Sair \n";


		cout << "Opcao: ";
		cin >> op;

		switch (op)
		{
		case 1: inicializar();
			break;
		case 2:exibir();
			break;
		case 3:push();
			break;
		case 4: pop();
			break;
		case 5:
			return;
		default:
			break;
		}

		system("pause"); // somente no windows
	}
}

void inicializar()
{

	// se a lista já possuir elementos
	// libera a memoria ocupada
	NO* aux = topo;
	while (aux != NULL) {
		NO* paraExcluir = aux;
		aux = aux->prox;
		free(paraExcluir);
	}

	topo = NULL;
	cout << "Pilha inicializada \n";

}

void exibir() 
{
	NO* aux = topo;
		if (topo == NULL) {
			cout << "Lista vazia \n";
			return;
		}
		else {
			cout << "Conteudo da pilha: \n";
			while (aux != NULL) {
				cout << aux->valor;
				if (aux->prox != NULL) {
					cout << " -> ";
				}
				aux = aux->prox;
			}
			cout << endl;
		}
}


void push()
{
	// aloca memoria dinamicamente para o novo elemento
	NO* novo = (NO*)malloc(sizeof(NO));
	NO* aux = topo;
	if (novo == NULL)
	{
		return;
	}

	cout << "Digite o elemento: ";
	cin >> novo->valor;
	novo->prox = topo;
	topo = novo;
	topo->prox = aux;

	/*int valor = novo->valor;*/

	cout << "valor "  <<  novo->valor  << " inserido na pilha \n";
}

void pop()
{
	NO* aux = topo;

	if (topo == NULL) {
		cout << "pilha vazia! \n";
		return;
	}
	
	else {
		cout << "O valor " << aux->valor << " foi removido \n";

		topo = topo->prox;

		free(aux);
	}
}

