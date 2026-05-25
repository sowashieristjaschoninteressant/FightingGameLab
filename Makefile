
NAME := crashers


all: build


build:
	[ -d "bin" ] || mkdir "bin" 
	gcc -std=c17 -I /opt/homebrew/include -I ./inc -L /opt/homebrew/lib -o ./bin/$(NAME) ./src/*.c -lraylib -framework OpenGL -framework Cocoa -framework IOKit -framework CoreAudio -Wall -g -fsanitize=address

clean: 
	rm ./bin/$(NAME)