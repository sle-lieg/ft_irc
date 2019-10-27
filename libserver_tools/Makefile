NAME	= libserver_tools.a
CC		= gcc
FLAGS	= -Wall -Wextra -Werror

############ DIRECTORIES ############
SOURCES_D	= sources/
INCLUDES_D	= includes/
OBJECTS_D	= objects/
DEP_D		= dep/

############### LIBRARIES ############
LIB_D = ../libft_printf
LIBS = -L$(LIB_D) -lftprintf

############### INCLUDES ############
# INCLUDES	= -I$(INCLUDES_D)
INCLUDES	= -I$(INCLUDES_D) -I$(LIB_D)/inc

############## SOURCES ##############
SOURCES_F	= create_server.c

############## OBJECTS ##############
OBJECTS	= $(SOURCES_F:%.c=%.o)

DEPENDENCIES = $(OBJECTS:%.o=$(DEP_D)%.d)

all: createDir $(NAME)

createDir:
	@test -d $(OBJECTS_D) || mkdir $(OBJECTS_D)
	@test -d $(DEP_D) || mkdir $(DEP_D)

# createLibs:
# 	make -C $(LIB_D)

-include $(DEPENDENCIES)

# build executable from .o files
$(NAME): $(OBJECTS)
	ar rc $(NAME) $(addprefix $(OBJECTS_D), $^)
	ranlib $(NAME)

# create FILE.o files referenced in $(OBJECTS) variable, from corresponding
# FILE.cpp files present in the $(SOURCE_D) directory
%.o: $(SOURCES_D)%.c
	$(CC) $(FLAGS) -MMD -MF $(DEP_D)$(@F:%.o=%.d) -c $< -o $(OBJECTS_D)$@ $(INCLUDES)

clean:
	rm -f $(OBJECTS)
	rm -f $(DEPENDENCIES)

fclean: clean
	rm -f $(NAME)

re: fclean clean all





# SOURCES = init_addrinfo.c

# SRC_DIR_PRINTF = ./src/
# SRC_DIR_LIBFT	=	./libft/

# OBJ_DIR = ./obj/

# SRC_PRINTF	= $(addprefix $(SRC_DIR_PRINTF), $(SOURCES))
# SRC_LIBFT	= $(addprefix $(SRC_DIR_LIBFT), $(SRC_FILES_LIBFT))
# OBJ			= $(SRC_PRINTF:$(SRC_DIR_PRINTF)%.c=$(OBJ_DIR)%.o) $(SRC_LIBFT:$(SRC_DIR_LIBFT)%.c=$(OBJ_DIR)%.o)

# INC	= -I ./inc/

# all : createDir $(NAME)

# createDir:
# 	@test -d $(OBJ_DIR) || mkdir $(OBJ_DIR)

# $(NAME) : $(OBJ)
# 	@echo "\033[1;32m◊ +++++ CREATING $(NAME)	: √\033[0m"
# 	@echo "ar rc $(NAME)"	
# 	@ar rc $(NAME) $(OBJ)
# 	ranlib $(NAME)

# $(OBJ_DIR)%.o: $(SRC_DIR_PRINTF)%.c
# 	$(CC) $(FLAGS) -c $^ -o $@ $(INC)

# $(OBJ_DIR)%.o: $(SRC_DIR_LIBFT)%.c
# 	$(CC) $(FLAGS) -c $^ -o $@ $(INC)

# clean :
# 	@echo "\033[1;31m◊ ----- DELETING $(NAME) OBJECTS	: √\033[0m"
# 	@rm -f $(OBJ)

# fclean : clean
# 	@echo "\033[1;31m◊ ----- DELETING $(NAME)		: √\033[0m"
# 	@rm -f $(NAME)

# re : fclean all
