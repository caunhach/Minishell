NAME = minishell
MKDIR = mkdir

CC = gcc

LIBFTP = src/libft
PATHB = build/
PATHO = build/objs/
PATHS = src/
PATHSP = src/parser/
PATHUTIL = src/util/
PATHSIG = src/signal/
PATHERRO = src/error/
PATHSBUIL = src/builtin/
PATHSEX = src/execute/
PATHSEXEC = src/executor/
PATHSEXPAN = src/expander/

BUILD_PATHS = $(PATHB) $(PATHO)

src	=	main.c \
		src/parser/parser_1.c \
		src/util/envp.c \
		src/util/merge.c \
		src/util/merge_2.c \
		src/util/merge_3.c \
		src/util/merge_readline.c \
		src/util/merge_readline2.c \
		src/util/merge_checktoken.c \
		src/util/merge_checktoken2.c \
		src/signal/signal_1.c \
		src/signal/signal_2.c \
		src/error/ft_error.c \
		src/execute/exec_1.c \
		src/builtin/builtin_utils.c \
		src/builtin/builtin.c \
		src/builtin/ft_cd.c \
		src/builtin/ft_echo.c \
		src/builtin/ft_env.c \
		src/builtin/ft_export.c \
		src/builtin/ft_pwd.c \
		src/builtin/ft_unset.c \
		src/executor/error.c \
		src/executor/exec_cmd.c \
		src/executor/exec_expand.c \
		src/executor/exec_main.c \
		src/executor/exec_single_main.c \
		src/executor/free.c \
		src/executor/heredoc.c \
		src/executor/parse_env.c \
		src/executor/redirect.c \
		src/executor/utils_env.c \
		src/executor/utils.c \
		src/expander/expander_utils.c \
		src/expander/expander.c \
		src/expander/expander2.c \
		src/expander/expander3.c

OBJS	=	$(addprefix $(PATHO), $(notdir $(patsubst %.c, %.o, $(src))))

FLAGS	=	-Wall -Werror -Wextra -g#-fsanitize=address #-g

LIBFT	=	./src/libft/libft.a

HEADER	=	../includes/minishell.h \
			../includes/parser.h \
			../include/execution.h

READLINE_DIR = $(shell brew --prefix readline)

READLINE_LIB = -lreadline -lhistory -L $(READLINE_DIR)/lib
	
INCLUDES =-Iincludes -I$(PATHP) -I$(LIBFTP) -I$(READLINE_DIR)/include 

all: $(BUILD_PATHS) $(NAME)

$(PATHO)%.o:: $(PATHS)%.c
	@echo "Compiling ${notdir $<}			in	$(PATHS)"
	@$(CC) -c $(FLAGS) $(INCLUDES) $< -o $@

$(PATHO)%.o:: $(PATHSP)%.c $(HEADERS)
	@echo "Compiling ${notdir $<}			in	$(PATHSP)"
	@$(CC) -c $(FLAGS) $(INCLUDES) $< -o $@

$(PATHO)%.o:: $(PATHUTIL)%.c $(HEADERS)
	@echo "Compiling ${notdir $<}			in	$(PATHUTIL)"
	@$(CC) -c $(FLAGS) $(INCLUDES) $< -o $@

$(PATHO)%.o:: $(PATHSIG)%.c $(HEADERS)
	@echo "Compiling ${notdir $<}			in	$(PATHSIG)"
	@$(CC) -c $(FLAGS) $(INCLUDES) $< -o $@

$(PATHO)%.o:: $(PATHERRO)%.c $(HEADERS)
	@echo "Compiling ${notdir $<}			in	$(PATHERRO)"
	@$(CC) -c $(FLAGS) $(INCLUDES) $< -o $@

$(PATHO)%.o:: $(PATHSEX)%.c $(HEADERS)
	@echo "Compiling ${notdir $<}			in	$(PATHSEX)"
	@$(CC) -c $(FLAGS) $(INCLUDES) $< -o $@

$(PATHO)%.o:: $(PATHSBUIL)%.c $(HEADERS)
	@echo "Compiling ${notdir $<}			in	$(PATHSBUIL)"
	@$(CC) -c $(FLAGS) $(INCLUDES) $< -o $@

$(PATHO)%.o:: $(PATHSEXEC)%.c $(HEADERS)
	@echo "Compiling ${notdir $<}			in	$(PATHSEXEC)"
	@$(CC) -c $(FLAGS) $(INCLUDES) $< -o $@	

$(PATHO)%.o:: $(PATHSEXPAN)%.c $(HEADERS)
	@echo "Compiling ${notdir $<}			in	$(PATHSEXPAN)"
	@$(CC) -c $(FLAGS) $(INCLUDES) $< -o $@

$(NAME): $(LIBFT) $(OBJS) $(HEADERS)
	@$(CC) $(FLAGS) $(LIBFT) $(OBJS) $(READLINE_LIB) -o $(NAME)

	@echo "Success"

$(LIBFT):
	@$(MAKE) -C ./src/libft

$(PATHB):
	@$(MKDIR) $(PATHB)

$(PATHO):
	@$(MKDIR) $(PATHO)

clean:
	@echo "Cleaning"
	@rm -rf $(OBJS)
	@rm -rf $(PATHB).tmp*
	@rmdir $(PATHO) $(PATHB)
	@make fclean -C src/libft

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(LIBFT)

re: fclean all

.PRECIOUS: $(PATHO)%.o