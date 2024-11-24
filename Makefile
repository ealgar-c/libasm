NAME = libasm.a

SRCS_PATH = src/
SRCS = ft_strlen.s ft_strcpy.s ft_strcmp.s ft_write.s ft_read.s ft_strdup.s

OBJ_PATH = objs/
OBJS = $(addprefix $(OBJ_PATH), $(SRCS:.s=.o))

ASM_CMP = nasm -f elf64

C_CMP = gcc
C_CMP += -Wall -Wextra -Werror

ifeq ($(shell uname -s), Linux)
    ASM_CMP += -D__linux__
endif

all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "$(NAME) Created"

$(OBJ_PATH)%.o: $(SRCS_PATH)%.s
	@mkdir -p $(OBJ_PATH)
	@$(ASM_CMP) $< -o $@

clean:
	@rm -rf $(OBJ_PATH)

fclean: clean
	@rm -f $(NAME)
	@echo "$(NAME) Deleted"

re: fclean all

test: all
	@$(C_CMP) $(NAME) tester/libasm_tester.c -o libasm_tester
	@./libasm_tester
	@rm -f libasm_tester
	@make fclean

.PHONY: all clean fclean re test
