##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile for navy
##

SRC	    =	src/*.c

NAME	=	navy

S_LIB   =   lib/*.c

all:	$(NAME)

m_lib:
	gcc -c $(S_LIB)
	@ar rc libnavy.a *.o
	make clean
	mv libnavy.a lib/

$(NAME):
	make m_lib
	-mkdir -p data/
	gcc -o $(NAME) main.c $(SRC) -I include -Llib -lnavy -g

clean:
	-rm -f *.o

fclean:	clean
	-rm -rf $(NAME)
	-rm -rf lib/libnavy.a
	-rm unit*
	-rm data/pid.txt
	-rm *gcno
	-rm *gcda

re:
	make fclean
	make

.PHONY:
	all clean fclean m_lib re
