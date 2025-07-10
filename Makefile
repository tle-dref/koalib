NAME 		= libft.a

CC 			= cc
CFLAGS 		= -Wall -Wextra -Werror -g -I includes

# Sous-dossiers contenant les fichiers sources
SRC_DIRS 	= is lst mem str put to printf printf_e

# Fonctions regroupées par dossier
IS 			= ft_isalnum ft_isalpha ft_isascii ft_isdigit ft_isprint

LST 		= ft_lstnew ft_lstadd_front ft_lstsize ft_lstlast ft_lstadd_back \
	  		  ft_lstdelone ft_lstclear ft_lstiter ft_lstmap

MEM 		= ft_bzero ft_calloc ft_memchr ft_memcmp ft_memcpy ft_memmove ft_memset

STR 		= ft_strdup ft_strchr ft_strlcat ft_strlcpy ft_strlen ft_strcmp ft_strncmp \
	 		  ft_strnstr ft_strrchr ft_split ft_strjoin ft_strmapi ft_strtrim ft_substr \
	  		  ft_striteri get_next_line clean_join

PUT 		= ft_putchar_fd ft_putendl_fd ft_putnbr_fd ft_putstr_fd

TO 			= ft_atoi ft_itoa ft_tolower ft_toupper 

PRINTF 		= ft_printf hexa nbrs utils

PRINTF_E	= ft_printf_e hexa_e nbrs_e utils_e

# Construction des chemins des fichiers .c et .o
SRCS 		= $(addsuffix .c, $(addprefix src/is/, $(IS)) \
					$(addprefix src/lst/, $(LST)) \
					$(addprefix src/mem/, $(MEM)) \
					$(addprefix src/str/, $(STR)) \
					$(addprefix src/put/, $(PUT)) \
					$(addprefix src/to/, $(TO)) \
					$(addprefix src/printf/, $(PRINTF)) \
					$(addprefix src/printf_e/, $(PRINTF_E)))

OBJS 		= $(SRCS:.c=.o)

# Cible principale
all: $(NAME)

# Compilation de la bibliothèque
$(NAME): $(OBJS)
	@echo "\033[0;36m→ Compilation des fichiers sources\033[0m"
	@ar -rcs $(NAME) $(OBJS)
	@echo "\033[0;36m→ Bibliothèque créée\033[0m"

# Règle générique pour compiler les fichiers .o à partir des .c
.c.o:
	@$(CC) $(CFLAGS) -c $< -o $@

# Suppression des fichiers objets
clean:
	@rm -rf $(OBJS)
	@echo "\033[0;36m→ Suppression des fichiers objets\033[0m"

# Suppression des fichiers objets et de la bibliothèque
fclean: clean
	@rm -rf $(NAME)
	@echo "\033[0;36m→ Suppression de la bibliothèque\033[0m"

# Recompilation complète
re: fclean all

# Déclaration des règles phony pour éviter des conflits avec des fichiers du même nom
.PHONY: all clean fclean re
