SERVER=server/server
CLIENT=client/client

all: $(SERVER) $(CLIENT)

$(SERVER):
	make -C ./server/

$(CLIENT):
	make -C ./client/

cleanall:
	make fclean -C server/
	make fclean -C client/
	make fclean -C libserver_tools/
	make fclean -C libft/