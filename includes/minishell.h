/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joudafke <joudafke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 13:19:51 by ibarbouc          #+#    #+#             */
/*   Updated: 2025/07/21 21:39:41 by joudafke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include "parser.h"
# include "printf.h"
# include <errno.h>
# include <limits.h>
# include <linux/limits.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

typedef struct s_env
{
	char			*name;
	char			*value;
	char			*env;
	struct s_env	*next;

}					t_env;

typedef enum e_quote_state
{
	NO_QUOTE,
	SINGLE_QUOTE,
	DOUBLE_QUOTE,
}					t_quote_state;

typedef struct s_expand
{
	char			*result;
	char			*tmp;
	char			*expanded;
	char			temp[2];
	int				i;
	t_quote_state	quote;
}					t_expand;

// expand
t_env				*create_env_list(char **envp);
void				add_env_node(t_env **env_list, char *name, char *value);
char				*expand_variables(char *input, t_env *env_list,
						int exit_status);
char				*get_env_value(char *name, t_env *env_list);
int					extract_var_name(char *input, int start_index,
						char *var_name_buffer);
int					is_valid_var_char(char c);

// builtin
void				exec_builtin(t_ast_node *node, t_env *env_list, char *input,
						t_token *token, char *input_for_free);
// void				exec_builtin(char **args, t_env *env_list, char *input);
int					builtin_echo(char **args);
int					builtin_env(t_env *env_list);
int					builtin_pwd(char **args);
void				ft_cd(char *path);
void				builtin_exit(t_env *env_list, t_ast_node *node, char *input,
						t_token *token, char *input_for_free);
// void				builtin_exit(t_env *env_list, char **args, char *input);
t_env				*builtin_unset(t_env *env, char *cmd);
int					builtin_export(t_env *env_list, char **cmd);
t_env				*find_env_node(t_env *env, char *name);
void				add_or_replace(t_env **env, char *cmd);
int					ft_is_num(char *str);

// caracteres & quotes
int					is_quote_closed(char *input);
int					is_special_char(char c);
void				neutralize_special_char_in_double_quote(char *input);
void				neutralize_special_char_in_single_quote(char *input);

// syntax
void				syntax_pipe(char *input);
void				*no_cmd_process_redirections(t_ast_node *redir_list);

// utils
int					ft_strcmp(char *s1, char *s2);
t_env				*free_list(t_env *a);
// int					execute_ast(t_ast_node *node, char **envp, t_env *env_list,
// 						t_token *token, char *input);
int					execute_ast(t_ast_node *node, char **envp, t_env *env_list,
						t_token *token, char *input, t_ast_node *first_node, bool is_pipe);
char				*ft_strjoin2(char const *s1, char const *s2);
void process_heredoc(t_ast_node *heredoc_node, t_env *env_list, t_token **token, char *input, t_ast_node *node);
void	free_in_child(t_env *env_list, t_ast_node *node, char *path);
void preprocess_all_heredocs(t_ast_node *node, t_env *env_list, t_token **token, char *input);


#endif