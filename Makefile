all: server client

server:
	make -C server/

client:
	make -C client/

cleanall:
	make fclean -C server/
	make fclean -C client/
	make fclean -C libserver_tools/
	make fclean -C libft/