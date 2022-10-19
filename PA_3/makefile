C = gcc
FLAGS = -Wall -Werror -std=c99
APP = div

$(APP): div.s main.c
	$(CC) $(FLAGS) $^ -o $@

clean:
	rm -f $(APP)
