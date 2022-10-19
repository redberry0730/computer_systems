FLAGS = -Wall -Werror -std=gnu99
APP = mem_alloc

$(APP): $(APP).c main.c
	gcc $(FLAGS) $^ -o $@

clean:
	rm -f $(APP)
