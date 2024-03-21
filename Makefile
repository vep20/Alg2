# Definição de variáveis para os comandos do Git
GIT = git
COMMIT_MESSAGE = "algum comentario"

# Target para adicionar todas as mudanças
add:
	$(GIT) add .

# Target para fazer commit das mudanças
commit: add
	$(GIT) commit -m $(COMMIT_MESSAGE)

# Target para fazer push das mudanças
push: commit
	$(GIT) push

# Target para fazer pull das mudanças
pull:
	$(GIT) pull

# Target padrão que executa add, commit, push e pull
all: pull push

.PHONY: add commit push pull all

