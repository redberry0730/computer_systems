FLAGS = -Wall -Werror -std=c99
APP = lab6
CC = gcc

$(APP): $(APP).c main.c
	$(CC) $(FLAGS) $^ -o $@
	./$@

clean:
	rm -f $(APP)
