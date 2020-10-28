SRCS = $(wildcard src/*.c)
OBJS = $(SRCS:.c=.o)
HEADERS = headers/*.h

NAME = bsq

CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f

all: $(NAME)

.c.o: 
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${HEADERS}

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)