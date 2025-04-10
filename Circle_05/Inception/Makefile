NAME		= inception
HOST_URL	= tkwak.42.fr

all: $(NAME)

$(NAME): up

up:
	@mkdir -p ~/data/database
	@mkdir -p ~/data/wordpress_files
	@echo "Attempting to add host..."
	@echo "127.0.0.1 $(HOST_URL)" | sudo tee -a /etc/hosts && echo " $(HOST_ADD)" || echo "Failed to add host."
	@echo "Building and starting containers..."
	@docker-compose -p $(NAME) -f ./srcs/docker-compose.yml up --build || echo "Docker compose failed."

show:
	@docker image ls -a && echo "\n" && docker ps

backend:
	@docker exec -it nginx /bin/sh

db:
	@docker exec -it mariadb /bin/sh

frontend:
	@docker exec -it wordpress /bin/sh

clean:
	@docker stop $$(docker ps -qa) || echo "No containers to stop"; \
	docker rm $$(docker ps -qa) || echo "No containers to remove"; \
	docker rmi -f $$(docker images -qa) || echo "No images to remove"; \
	if [ $$(docker volume ls -q | wc -l) -gt 0 ]; then \
		docker volume rm $$(docker volume ls -q); \
	fi; \
	if [ $$(docker network ls -q | grep -v "bridge\|host\|none" | wc -l) -gt 0 ]; then \
		docker network rm $$(docker network ls -q | grep -v "bridge\|host\|none"); \
	fi 2>/dev/null; \

fclean: clean
	@sudo rm -rf ~/data
	@echo "Attempting to remove host..."
	@sudo sed -i "/127.0.0.1 $(HOST_URL)/d" /etc/hosts && echo " $(HOST_RM)" || echo "Failed to remove host."

HIDE		= /dev/null 2>&1
HOST_ADD 	= Host $(HOST_URL) added
HOST_RM		= Host $(HOST_URL) removed

.PHONY: all up clean fclean re
