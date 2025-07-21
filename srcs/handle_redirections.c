/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_redirections.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joudafke <joudafke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 20:59:41 by joudafke          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/07/21 21:48:33 by joudafke         ###   ########.fr       */
=======
/*   Updated: 2025/07/21 01:03:37 by joudafke         ###   ########.fr       */
>>>>>>> b1e7a0598a3d92c610b7ed95730b1919c8a37583
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "minishell.h"

pid_t g_heredoc_interrupted = 0;

void	sigint_heredoc_handler(int sig)
{
<<<<<<< HEAD
	(void)sig;
	g_heredoc_interrupted = 1;
	write(STDOUT_FILENO, "\n", 1);
	rl_replace_line("", 0);
	rl_done = 1;
=======
	write(2, "ici", 3);
	(void)sig;
	g_heredoc_interrupted = 1;
	rl_replace_line("", 0);
	rl_done = 1;
	rl_cleanup_after_signal();
    rl_free_line_state();
	write(STDOUT_FILENO, "\n", 1);
>>>>>>> b1e7a0598a3d92c610b7ed95730b1919c8a37583
}

void	read_heredoc_lines(int fd_input, char *delimiter)
{
	char	*line;
	int		line_number;

	line_number = 1;
	while (!g_heredoc_interrupted)
	{
		line = readline("heredoc> ");
<<<<<<< HEAD
		// line = readline_stderr("heredoc> ");
=======
>>>>>>> b1e7a0598a3d92c610b7ed95730b1919c8a37583
		if (!line)
        {
            // if (line)
            //     free(line);
            // if (!line && !g_heredoc_interrupted)
                fprintf(stderr, "minishell: warning: here-document at line %d delimited by end-of-file (wanted `%s')\n", line_number, delimiter);
            break;
        }
		if (ft_strcmp(line, delimiter) == 0)
		{
<<<<<<< HEAD
			printf("HERE\n");
=======
>>>>>>> b1e7a0598a3d92c610b7ed95730b1919c8a37583
			free(line);
			break ;
		}
		if (write(fd_input, line, strlen(line)) == -1
			|| write(fd_input, "\n", 1) == -1)
		{
			perror("write");
			free(line);
			close(fd_input);
			exit(EXIT_FAILURE);
		}
		free(line);
		line_number++;
	}
}

<<<<<<< HEAD
void process_heredoc(t_ast_node *heredoc_node, t_env *env_list, t_token **token, char *input, t_ast_node *node)
=======
void process_heredoc(t_ast_node *heredoc_node, t_env *env_list, t_token *token, char *input)
>>>>>>> b1e7a0598a3d92c610b7ed95730b1919c8a37583
{
	char rand_name[33];
	int fd_input;
	pid_t	pid_heredoc;
	int	status;
<<<<<<< HEAD
	
=======

>>>>>>> b1e7a0598a3d92c610b7ed95730b1919c8a37583
	if (!heredoc_node)
	{
		fprintf(stderr, "Erreur: heredoc_node est NULL\n");
		return;
	}
	create_rand(rand_name);
	heredoc_node->heredoc_tmpfile = ft_strdup(rand_name); // allocation dynamique
	if (!heredoc_node->heredoc_tmpfile)
	{
		perror("ft_strdup");
		exit(EXIT_FAILURE);
	}
<<<<<<< HEAD
	g_heredoc_interrupted = 0;
=======
>>>>>>> b1e7a0598a3d92c610b7ed95730b1919c8a37583
	pid_heredoc = fork();
	if (pid_heredoc == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (pid_heredoc == 0)
	{
<<<<<<< HEAD
		signal(SIGINT, sigint_heredoc_handler);
		signal(SIGQUIT, SIG_IGN);
=======
		
>>>>>>> b1e7a0598a3d92c610b7ed95730b1919c8a37583
		fd_input = open(rand_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd_input == -1)
		{
			perror(rand_name);
			free_in_child(env_list, heredoc_node, NULL);
			free_tokens(token);
			free(input);
			exit(EXIT_FAILURE);
		}
<<<<<<< HEAD
		read_heredoc_lines(fd_input, heredoc_node->filename); // filename contient le délimiteur
		close(fd_input);
		free_in_child(env_list, node, NULL);
=======
		if (!signal(SIGINT, sigint_heredoc_handler))
		{
			exit(0);
		}
		signal(SIGINT, SIG_DFL);
		read_heredoc_lines(fd_input, heredoc_node->filename); // filename contient le délimiteur
		close(fd_input);
		write(2, "ici\n", 4);
		free_in_child(env_list, heredoc_node, NULL);
>>>>>>> b1e7a0598a3d92c610b7ed95730b1919c8a37583
		free_tokens(token);
		free(input);
		exit(0);
	}
	else
	{
<<<<<<< HEAD
		signal(SIGINT, SIG_IGN); // Ignore SIGINT pendant attente
		waitpid(pid_heredoc, &status, 0);
		signal(SIGINT, check_signal);
=======
		waitpid(pid_heredoc, &status, 0);

>>>>>>> b1e7a0598a3d92c610b7ed95730b1919c8a37583
        if (WIFSIGNALED(status) && WTERMSIG(status) == SIGINT)
        {
            unlink(rand_name);
            free(heredoc_node->heredoc_tmpfile);
            heredoc_node->heredoc_tmpfile = NULL;
        }
	}
}

// void	process_heredoc(t_ast_node *heredoc_node, const char *outfile)
// {
// 	int	fd_input;

// 	if (!heredoc_node || !heredoc_node->filename)
// 	{
// 		fprintf(stderr, "Erreur: heredoc_node ou son filename est NULL\n");
// 		return ;
// 	}
// 	fd_input = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
// 	if (fd_input == -1)
// 	{
// 		perror(outfile);
// 		exit(EXIT_FAILURE);
// 	}
// 	g_heredoc_interrupted = 0;
// 	read_heredoc_lines(fd_input, heredoc_node->filename);
// 	close(fd_input);
// 	if (g_heredoc_interrupted)
// 		unlink(outfile);
// }

// void	process_redirect_in(t_ast_node *redirect_in_node)
// {
// 	int	fd_input;

// 	fd_input = open(redirect_in_node->filename, O_RDONLY);
// 	if (fd_input == -1)
// 	{
// 		perror("open");
// 		exit(EXIT_FAILURE);
// 	}
// 	if (dup2(fd_input, 0) == -1)
// 	{
// 		perror("dup2");
// 		close(fd_input);
// 		exit(EXIT_FAILURE);
// 	}
// 	close(fd_input);
// }

<<<<<<< HEAD
void preprocess_all_heredocs(t_ast_node *node, t_env *env_list, t_token **token, char *input)
=======
void preprocess_all_heredocs(t_ast_node *node)
>>>>>>> b1e7a0598a3d92c610b7ed95730b1919c8a37583
{
	if (!node)
		return;
	if (node->type == NODE_COMMAND && node->redirections)
	{
		t_ast_node *tmp = node->redirections;
		while (tmp)
		{
			if (tmp->redir_type == HEREDOC)
<<<<<<< HEAD
				process_heredoc(tmp, env_list, token, input, node);
			tmp = tmp->right;
		}
	}
	preprocess_all_heredocs(node->left, env_list, token, input);
	preprocess_all_heredocs(node->right, env_list, token, input);
=======
				process_heredoc(tmp, NULL, NULL, NULL);
			tmp = tmp->right;
		}
	}
	preprocess_all_heredocs(node->left);
	preprocess_all_heredocs(node->right);
>>>>>>> b1e7a0598a3d92c610b7ed95730b1919c8a37583
}


int no_cmd_process_redirect_in(t_ast_node *redirect_in_node)
{
	int	fd_input;

	fd_input = open(redirect_in_node->filename, O_RDONLY);
	if (fd_input == -1)
	{
		perror("open");
		return (-1);
	}
	close(fd_input);
	return (0);
}

int process_redirect_in(t_ast_node *redirect_in_node)
{
	int	fd_input;
	const char *infile;

	if (redirect_in_node->redir_type == HEREDOC && redirect_in_node->heredoc_tmpfile)
		infile = redirect_in_node->heredoc_tmpfile;
	else
		infile = redirect_in_node->filename;
	fd_input = open(infile, O_RDONLY);
	if (fd_input == -1)
	{
		perror(infile);
		return (-1);
	}
	if (dup2(fd_input, 0) == -1)
	{
		perror("dup2");
		close(fd_input);
		return (-1);
	}
	close(fd_input);
	return (0);
}


// void	process_redirect_out(t_ast_node *redirect_out_node)
// {
// 	int	fd_output;

// 	fd_output = open(redirect_out_node->filename, O_WRONLY
// 			| O_CREAT | O_TRUNC,
// 			0644);
// 	if (fd_output == -1)
// 	{
// 		perror(redirect_out_node->filename);
// 		exit(EXIT_FAILURE);
// 	}
// 	if (dup2(fd_output, STDOUT_FILENO) == -1)
// 	{
// 		perror("dup2");
// 		close(fd_output);
// 		exit(EXIT_FAILURE);
// 	}
// 	close(fd_output);
// }


int	no_cmd_process_redirect_out(t_ast_node *redirect_out_node)
{
	int	fd_output;

	fd_output = open(redirect_out_node->filename, O_WRONLY
			| O_CREAT | O_TRUNC, 0644);
	if (fd_output == -1)
	{
		perror(redirect_out_node->filename);
		return (-1);
	}
	close(fd_output);
	return (0);
}

void	no_cmd_process_append(t_ast_node *append_node)
{
	int	fd_output;
	fd_output = open(append_node->filename, O_WRONLY | O_CREAT | O_APPEND,
			0644);
	if (fd_output == -1)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}
	close(fd_output);
}

int	process_redirect_out(t_ast_node *redirect_out_node)
{
	int	fd_output;

	fd_output = open(redirect_out_node->filename, O_WRONLY
			| O_CREAT | O_TRUNC, 0644);
	if (fd_output == -1)
	{
		perror(redirect_out_node->filename);
		return (-1);
	}
	if (dup2(fd_output, STDOUT_FILENO) == -1)
	{
		perror("dup2");
		close(fd_output);
		return (-1);
	}
	close(fd_output);
	return (0);
}

void	process_append(t_ast_node *append_node)
{
	int	fd_output;
	fd_output = open(append_node->filename, O_WRONLY | O_CREAT | O_APPEND,
			0644);
	if (fd_output == -1)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}
	dup2(fd_output, 1);
	close(fd_output);
}

void	*no_cmd_process_redirections(t_ast_node *redir_list)
{
	t_ast_node	*current_node;

	current_node = redir_list;
	while (current_node)
	{
		if (current_node->redir_type == HEREDOC)
		{
			//process_heredoc(current_node);
			cleanup_heredocs(current_node);
		}
		else if (current_node->redir_type == REDIRECT_IN)
			no_cmd_process_redirect_in(current_node);
		else if (current_node->redir_type == REDIRECT_OUT)
			no_cmd_process_redirect_out(current_node);
		else if (current_node->redir_type == APPEND)
			no_cmd_process_append(current_node);
		current_node = current_node->right;
	}
	return (NULL);
}


void	*process_redirections(t_ast_node *redir_list)
{
	t_ast_node	*current_node;

	current_node = redir_list;
	while (current_node)
	{
		if (current_node->redir_type == HEREDOC)
		{
			//process_heredoc(current_node);
			process_redirect_in(current_node);
		}
		else if (current_node->redir_type == REDIRECT_IN)
			process_redirect_in(current_node);
		else if (current_node->redir_type == REDIRECT_OUT)
			process_redirect_out(current_node);
		else if (current_node->redir_type == APPEND)
			process_append(current_node);
		current_node = current_node->right;
	}
	return (NULL);
}
