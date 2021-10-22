NAME	=	philo

SRCS	=	./srcs/death.c\
			./srcs/eat.c\
			./srcs/init_destroy.c\
			./srcs/launch.c\
			./srcs/philo.c\
			./srcs/routine.c\
			./srcs/threading.c\
			./srcs/timing.c\
			./srcs/utils.c

CC		=	gcc

CFLAGS		=	-Werror -Wextra -Wall 

SANFLAGS	=	-Werror -Wextra -Wall -fsanitize=thread -g

DEL			=	rm -f

OBJ 		=	$(addsuffix .o, $(basename $(SRCS)))

%.o: %.c
				$(CC) -c -o $@ $< $(CFLAGS)

all:			$(NAME)

$(NAME):$(OBJ)
				${CC} ${CFLAGS} -o ${NAME} ${OBJ} -lpthread

clean:
				${DEL} ${OBJ}

fclean:			clean
				${DEL} ${NAME}

re:				clean all

san:			re
				${CC} ${SANFLAGS} -o ${NAME} ${OBJ} -lpthread

.PHONY: 		clean re fclean all