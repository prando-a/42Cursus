all:
	mkdir -p ~/data/nginx
	mkdir -p ~/data/wordpress
	mkdir -p ~/data/mariadb
	sudo docker-compose -f ./srcs/docker-compose.yml up --build

down:
	docker-compose -f ./srcs/docker-compose.yml down

nuke:
	docker-compose -f ./srcs/docker-compose.yml down
	docker system prune --all --volumes
	rm -rf ~/data/

re: nuke all

.PHONY: all down nuke re
