CC = gcc //Den fortæller, at vi bruger GCC (GNU Compiler Collection) som C-kompilator.
CFLAGS = -Wall -Iinclude 

// - wall is alle advarsler 
//-include fortæller kompilatoren, at den skal kigge efter headerfiler i mappen include/

all: crypto //

crypto: src/main.c src/crypto.c
	$(CC) $(CFLAGS) -o crypto src/main.c src/crypto.c  //kompiler main.c og crypto.c sammen til en exe fil kaldet crypto

clean: 
	rm -f crypto 
.PHONY: all clean 