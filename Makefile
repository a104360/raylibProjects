CC = gcc
SRC = $(wildcard src/*.c)
DEPS = $(wildcard include/*.h)
OBJ = $(SRC:src/.c=obj/.o)

LDFLAGS = -lraylib -lglfw -lGL -lGLU -lglut -lm -lX11 -lpthread -lXrandr -lXi -ldl -Iinclude

all: run

run: app
	./app

obj/%.o: src/%.c $(DEPS)
	$(CC) -c $^ -o $@

app: $(OBJ) 
	$(CC) $^ -o $@ $(LDFLAGS)

clean: 
	rm -f obj/* app