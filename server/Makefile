NAME	= server
CC		= gcc
CCFLAGS	= -Wall -Wextra -Werror
#LDFLAG =

############ DIRECTORIES ############
SOURCES_D	= sources/
INCLUDES_D	= includes/
OBJECTS_D	= objects/
DEP_D		= dep/

############### LIBRARIES ############
LIBFT_D = ../libft
LIBSERVER_TOOLS_D = ../libsocket_tools
LIBS += -L$(LIBFT_D) -lftprintf
LIBS += -L$(LIBSERVER_TOOLS_D) -lsocket_tools

############### INCLUDES ############
INCLUDES	+= -I$(INCLUDES_D)
INCLUDES	+= -I$(LIBFT_D)/inc
INCLUDES	+= -I$(LIBSERVER_TOOLS_D)/includes

############## SOURCES ##############
SOURCES_F	=	main.c \
				create_server.c \
				handle_request.c \
				handle_readset.c \
				new_connection.c

############## OBJECTS ##############
OBJECTS	= $(SOURCES_F:%.c=%.o)

DEPENDENCIES = $(OBJECTS:%.o=$(DEP_D)%.d)

all: createDir createLibs $(NAME)

debug: CCFLAGS += -g
debug: createDir createLibsDebug $(NAME)

createDir:
	@test -d $(OBJECTS_D) || mkdir $(OBJECTS_D)
	@test -d $(DEP_D) || mkdir $(DEP_D)

createLibs:
	make -C $(LIBFT_D)
	make -C $(LIBSERVER_TOOLS_D)

createLibsDebug:
	make debug -C $(LIBFT_D)
	make debug -C $(LIBSERVER_TOOLS_D)

-include $(DEPENDENCIES)

# build executable from .o files
$(NAME): $(OBJECTS)
	$(CC) $(addprefix $(OBJECTS_D), $^) $(LIBS) -o $@

# create FILE.o files referenced in $(OBJECTS) variable, from corresponding
# FILE.cpp files present in the $(SOURCE_D) directory
%.o: $(SOURCES_D)%.c
	$(CC) $(CCFLAGS) -MMD -MF $(DEP_D)$(@F:%.o=%.d) -c $< -o $(OBJECTS_D)$@ $(INCLUDES)

clean:
	rm -f $(OBJECTS)
	rm -f $(DEPENDENCIES)

fclean: clean
	rm -f $(NAME)

re: fclean clean all
