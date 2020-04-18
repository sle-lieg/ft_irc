NAME	= libsocket_tools.a
CC		= gcc
CCFLAGS	= -Wall -Wextra -Werror

############ DIRECTORIES ############
SOURCES_D	= sources/
INCLUDES_D	= includes/
OBJECTS_D	= objects/
DEP_D		= dep/

############### LIBRARIES ############
LIB_D = ../libft
LIBS = -L$(LIB_D) -lftprintf

############### INCLUDES ############
# INCLUDES	= -I$(INCLUDES_D)
INCLUDES	= -I$(INCLUDES_D) -I$(LIB_D)/inc

############## SOURCES ##############
SOURCES_F	=	create_socket.c display_socket_addr.c \
				get_in_addr.c get_ntoa_addr.c get_port.c \
				init_addr_infos.c

############## OBJECTS ##############
OBJECTS	= $(SOURCES_F:%.c=%.o)

DEPENDENCIES = $(OBJECTS:%.o=$(DEP_D)%.d)

all: createDir $(NAME)

debug: CCFLAGS += -g
debug: all

createDir:
	@test -d $(OBJECTS_D) || mkdir $(OBJECTS_D)
	@test -d $(DEP_D) || mkdir $(DEP_D)

-include $(DEPENDENCIES)

$(NAME): $(OBJECTS)
	ar rc $(NAME) $(addprefix $(OBJECTS_D), $^)
	ranlib $(NAME)

%.o: $(SOURCES_D)%.c
	$(CC) $(CCFLAGS) -MMD -MF $(DEP_D)$(@F:%.o=%.d) -c $< -o $(OBJECTS_D)$@ $(INCLUDES)

clean:
	rm -f $(OBJECTS)
	rm -f $(DEPENDENCIES)

fclean: clean
	rm -f $(NAME)

re: fclean clean all
