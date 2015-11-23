/*
*
* Autor: Daniel B. Brumazzi
* Compilando: gcc -lpthread main.c -o threads
*
*/

#include "thread_coms.h"

int main(){
	pthread_t trilhas[10];	// cria as trilhas de threads
	_argv *a;		// parametros
	int x;			// contador
	int t_id[10];		// armazenador dos endereços das trilhas

	srand(time(NULL));	// gera numeros aleatorios com o clock do processador
	for(x=0; x<10; x++){
		a = (_argv *) malloc(sizeof(_argv));	// aloca _argv em a
		a->delay = 1+(rand()%10);		// gera um numero aleatorio para delay
		a->id = x;				// id do parametro
		sprintf(a->message,"Delay de %i", a->delay); //define a mensagem para o parametro
		/* armazenador = pthread_create(<endereço da trilha[x]>, 0, <funcção>, <_argv>)
		 * essa função cria as trilhas executando a função
		 * function_thread com p parametro "a"
		 * */
		t_id[x] = pthread_create(&trilhas[x], NULL, function_thread, (void *) a);
	}
	
	puts("Executando...");

	pthread_exit(NULL); // finaliza espera o encerramento de todas as trilas

	return 0;
}
