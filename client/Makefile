NAME	= client
CC		= gcc
CCFLAGS	= -Wall -Wextra -Werror
#LDFLAG =

############ DIRECTORIES ############
SOURCES_D	= sources/
INCLUDES_D	= includes/
OBJECTS_D	= objects/
DEP_D		= dep/

############### LIBRARIES ############
LIB_D = ../libft_printf
LIBS = -L$(LIB_D) -lftprintf

############### INCLUDES ############
INCLUDES	= -I$(INCLUDES_D) -I$(LIB_D)/inc

############## SOURCES ##############
SOURCES_F	= main.c

############## OBJECTS ##############
OBJECTS	= $(SOURCES_F:%.c=%.o)

DEPENDENCIES = $(OBJECTS:%.o=$(DEP_D)%.d)

all: createDir createLibs $(NAME)

createDir:
	@test -d $(OBJECTS_D) || mkdir $(OBJECTS_D)
	@test -d $(DEP_D) || mkdir $(DEP_D)

createLibs:
	make -C $(LIB_D)

-include $(DEPENDENCIES)

# build executable from .o files
$(NAME): $(OBJECTS)
	$(CC) $(addprefix $(OBJECTS_D), $^) $(LIBS) -o $@

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
