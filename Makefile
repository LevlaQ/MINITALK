# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gyildiz <gyildiz@student.42istanbul.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/27 13:54:40 by gyildiz           #+#    #+#              #
#    Updated: 2025/04/08 14:46:27 by gyildiz          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT =			./Libft/libft.a
CC =			cc
CFLAGS =		-Wall -Werror -Wextra

SERVER =		server
CLIENT =		client
SRCS_SERVER =	server.c
SRCS_CLIENT =	client.c client_utils.c

OBJS_SERVER =	$(SRCS_SERVER:.c=.o)
OBJS_CLIENT =	$(SRCS_CLIENT:.c=.o)

all: $(SERVER) $(CLIENT)

$(SERVER): $(OBJS_SERVER) $(LIBFT)
	${CC} ${OBJS_SERVER} ${LIBFT} -o ${SERVER}

$(CLIENT): $(OBJS_CLIENT) $(LIBFT)
	${CC} ${OBJS_CLIENT} ${LIBFT} -o ${CLIENT}

$(LIBFT):
	${MAKE} -C ./libft

clean:
	$(MAKE) clean -C ./libft
	rm -rf ${OBJS_SERVER} ${OBJS_CLIENT}

fclean:	clean
	$(MAKE) fclean -C ./libft
	rm -rf $(NAME) $(CLIENT)

re:	fclean all

.PHONY: all clean fclean re