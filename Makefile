# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gyildiz <gyildiz@student.42istanbul.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/27 13:54:40 by gyildiz           #+#    #+#              #
#    Updated: 2025/04/08 18:48:05 by gyildiz          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT =			./Libft/libft.a
CC =			cc
CFLAGS =		-Wall -Werror -Wextra

SERVER =		server
CLIENT =		client
SERVER_BONUS =	server_bonus
CLIENT_BONUS =	client_bonus

SRCS_SERVER =	server.c
SRCS_CLIENT =	client.c client_utils.c

OBJS_SERVER =	$(SRCS_SERVER:.c=.o)
OBJS_CLIENT =	$(SRCS_CLIENT:.c=.o)

SRCS_SERVER_BONUS = server_bonus.c
OBJS_SERVER_BONUS = $(SRCS_SERVER_BONUS:.c=.o)

SRCS_CLIENT_BONUS = client_bonus.c client_utils_bonus.c
OBJS_CLIENT_BONUS = $(SRCS_CLIENT_BONUS:.c=.o)

all: $(SERVER) $(CLIENT)

$(SERVER): $(OBJS_SERVER) $(LIBFT)
	${CC} ${OBJS_SERVER} ${LIBFT} -o ${SERVER}

$(CLIENT): $(OBJS_CLIENT) $(LIBFT)
	${CC} ${OBJS_CLIENT} ${LIBFT} -o ${CLIENT}

$(LIBFT):
	${MAKE} -C ./Libft
	
bonus: $(SERVER_BONUS) $(CLIENT_BONUS)

$(SERVER_BONUS): $(OBJS_SERVER_BONUS) $(LIBFT)
	${CC} ${OBJS_SERVER_BONUS} ${LIBFT} -o ${SERVER_BONUS}

$(CLIENT_BONUS): $(OBJS_CLIENT_BONUS) $(LIBFT)
	${CC} ${OBJS_CLIENT_BONUS} ${LIBFT} -o ${CLIENT_BONUS}

clean:
	$(MAKE) clean -C ./Libft
	rm -rf ${OBJS_SERVER} ${OBJS_CLIENT} $(OBJS_SERVER_BONUS)\
		${OBJS_CLIENT_BONUS}

fclean:	clean
	$(MAKE) fclean -C ./Libft
	rm -rf $(NAME) $(CLIENT) $(SERVER) $(SERVER_BONUS) $(CLIENT_BONUS)

re:	fclean all

.PHONY: all clean fclean re