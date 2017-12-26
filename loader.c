#include<stdio.h>
#include<dlfcn.h>

int main(int argcount, char ** arguments){
	if(argcount < 3) return fprintf(stderr,"Using %s 'path to library' 'void function without arguments'\n",arguments[0]);
	void * Library = dlopen(arguments[1], RTLD_NOW);
	if(!Library) return fprintf(stderr,"Cannot found library %s\n",arguments[1]);
	void (*fcn)(void) = dlsym(Library, arguments[2]);
	if(fcn) fcn();
	else fprintf(stderr,"Error found function %s\n",arguments[2]);
	dlclose(Library);
}
