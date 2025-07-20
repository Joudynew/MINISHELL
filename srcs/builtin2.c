/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joudafke <joudafke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 23:42:46 by joudafke          #+#    #+#             */
/*   Updated: 2025/07/18 19:38:21 by joudafke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_builtin(t_ast_node *node, t_env *env_list, char *input,
		t_token *token, char *input_for_free)
{
	if (!node->args || !node->args[0])
		return ;
	if (ft_strncmp(node->args[0], "pwd", 4) == 0)
		builtin_pwd(node->args);
	else if (ft_strncmp(node->args[0], "env", 4) == 0)
		builtin_env(env_list);
	else if (ft_strncmp(node->args[0], "echo", 5) == 0)
		builtin_echo(node->args);
	else if (ft_strncmp(node->args[0], "cd", 3) == 0)
		ft_cd(node->args[1]);
	else if (ft_strncmp(node->args[0], "export", 7) == 0)
		builtin_export(env_list, node->args);
	else if (ft_strncmp(node->args[0], "unset", 6) == 0)
		builtin_unset(env_list, node->args[1]);
	else if (ft_strncmp(node->args[0], "exit", 5) == 0)
		builtin_exit(env_list, node, input, token, input_for_free);
	else
		return ;
}

// void	exec_builtin(char **args, t_env *env_list, char *input)
// {
// 	if (!args || !args[0])
// 		return ;
// 	if (ft_strncmp(args[0], "pwd", 4) == 0)
// 		builtin_pwd();
// 	else if (ft_strncmp(args[0], "env", 4) == 0)
// 		builtin_env(env_list);
// 	else if (ft_strncmp(args[0], "echo", 5) == 0)
// 		builtin_echo(args);
// 	else if (ft_strncmp(args[0], "cd", 3) == 0)
// 		ft_cd(args[1]);
// 	else if (ft_strncmp(args[0], "export", 7) == 0)
// 		builtin_export(env_list, args);
// 	else if (ft_strncmp(args[0], "unset", 6) == 0)
// 		builtin_unset(env_list, args[1]);
// 	else if (ft_strncmp(args[0], "exit", 5) == 0)
// 		builtin_exit(env_list, args, input);
// 	else
// 		return ;
// }
