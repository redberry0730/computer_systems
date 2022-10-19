FLAGS = -Wall -Werror -std=c99
APP = lab5
CC = gcc

$(APP): $(APP).c
	$(CC) $(FLAGS) $^ -o $@
	./$@

clean:
	rm -f $(APP)
