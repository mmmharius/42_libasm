NAME = libasm.a

SRCS = ft_strlen.s ft_strcpy.s ft_strcmp.s ft_write.s ft_read.s ft_strdup.s
OBJS = $(SRCS:.s=.o)

NASM_FORMAT = elf64

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.s
	nasm -f $(NASM_FORMAT) $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	rm -f libasm
	rm -f main

re: fclean all

main: $(NAME) main.c
	gcc -fPIC main.c libasm.a -o libasm

.PHONY: all clean fclean re