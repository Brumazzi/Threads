#ifndef __THREADS_COMS__
	#define __THREADS_COMS__

	#include <stdio.h>
	#include <unistd.h>
	#include <pthread.h>
	#include <malloc.h>

	typedef struct{			// estrutura passada por parametro
		unsigned int delay;	// tempo de espera
		int id;			// id da estrutura
		char message[32];	// mensagem de texto
	}_argv;

	void *function_thread(void *_struct){
		_argv *a = (_argv *) _struct; // recebe o endereço de memoria da estrutura e insere em "a"
		sleep(a->delay);
		printf("[\t\033[32;01m%i\t\033[00m] - %s\n", a->id, a->message); //escreve o id e a mensagem dentro da estrutura

		free(_struct); //limpa a memoria da trilha
		return 0;
	}
#endif
