# Definição de variável para o comando do Git
GIT = git

# Target para fazer push das mudanças
push:
	$(GIT) add .
	@if ! $(GIT) diff-index --quiet HEAD --; then \
		$(GIT) commit -m "Commit automático"; \
		$(GIT) push; \
	else \
		echo "Nada a commitar, repositório limpo."; \
	fi

# Target para fazer pull das mudanças
pull:
	$(GIT) pull

# Target padrão que executa push e pull
all: pull push

.PHONY: push pull all

