CC = gcc
FLAGS = -Wall -Werror -std=c99
APP = fp_analyzer

all: $(APP) $(APP)_d

$(APP): $(APP).c main.c
	$(CC) $(FLAGS) $^ -o $@

$(APP)_d: $(APP).c main.c
	$(CC) $(FLAGS) -D DOUBLE $^ -o $@

clean:
	rm -rf $(APP) $(APP)_d
