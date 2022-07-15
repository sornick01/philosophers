NAME = philo

CC = gcc
CFLAGS = -Wall -Wextra -Werror -pthread

RM = rm -rf

SRC_DIR = ./sources/
INC_DIR = ./includes/
OBJ_DIR = ./objects/

INC = $(wildcard $(addsuffix *.h, $(INC_DIR)))
SRC = $(wildcard $(addsuffix *.c, $(SRC_DIR)))
OBJ	= $(addprefix $(OBJ_DIR), $(notdir $(patsubst %.c, %.o, $(SRC))))

VPATH = $(SRC_DIR)

all:				$(NAME)

$(NAME):			$(INC)  $(OBJ)
					$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)%.o: %.c $(INC)
					mkdir -p $(OBJ_DIR)
					$(CC) $(CFLAGS) -c $< -o $@

clean:
					$(RM) $(OBJ_DIR)

fclean:				clean
					$(RM) $(NAME)

bonus:				all

re:					fclean all
