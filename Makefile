all:
	gcc loader.c -ldl -o loader
	gcc -fPIC -shared library.c -o lib
	./loader ./lib function
clean:
	rm loader lib 
