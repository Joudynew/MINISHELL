/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: joudafke <joudafke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 23:16:42 by joudafke          #+#    #+#             */
/*   Updated: 2025/07/21 21:46:02 by joudafke         ###   ########.fr       */
=======
/*   By: ifadhli <ifadhli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 23:16:42 by joudafke          #+#    #+#             */
/*   Updated: 2025/07/17 02:59:58 by ifadhli          ###   ########.fr       */
>>>>>>> b1e7a0598a3d92c610b7ed95730b1919c8a37583
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

#include "parser.h"

int	is_operator(char c)
{
	if (c == '|' || c == '<' || c == '>' || c == '(' || c == ')' || c == '&')
		return (1);
	return (0);
}

int	ending_quotes(char *input, int start)
{
	char	quote;
	int		i;

	quote = input[start];
	i = start + 1;
	while (input[i] && input[i] != quote)
		i++;
	return (i);
}

t_token	*create_token(t_token_type token_type, char *value)
{
	t_token	*new_token;

	new_token = malloc(sizeof(t_token));
	if (!new_token)
		return (NULL);
	new_token->type = token_type;
	if (!value)
		new_token->value = NULL;
	else
		new_token->value = ft_strdup(value);
	new_token->next = NULL;
	return (new_token);
}

void	add_token(t_token **token_list, t_token *new_token)
{
	t_token	*tmp;

	if (!*token_list)
	{
		*token_list = new_token;
		return ;
	}
	tmp = *token_list;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_token;
}

<<<<<<< HEAD
void	free_tokens(t_token **token_list)
{
	t_token	*tmp;
	t_token *ok = *token_list;
	while (ok)
	{
		tmp = ok;
		ok = ok->next;
		if (tmp->value)
		{
			free(tmp->value);
		}
=======
void	free_tokens(t_token *token_list)
{
	t_token	*tmp;

	while (token_list)
	{
		tmp = token_list;
		token_list = token_list->next;
		if (tmp->value)
			free(tmp->value);
>>>>>>> b1e7a0598a3d92c610b7ed95730b1919c8a37583
		free(tmp);
	}
}


// void	free_tokens(t_token *token_list)
// {
// 	t_token	*tmp;

// 	int i = 0;
// 	while (token_list)
// 	{
		
// 		tmp = token_list;
// 		token_list = token_list->next;
// 		if (tmp->value)
// 			free(tmp->value);
// 		free(tmp);
// 		i++;
// 		}
// }
// int	is_operator(char c)
// {
// 	if (c == '|' || c == '<' || c == '>' || c == '(' || c == ')' || c == '&')
// 		return (1);
// 	return (0);
// }

// int	ending_quotes(char *input, int start)
// {
// 	char	quote;
// 	int		i;

// 	quote = input[start];
// 	i = start + 1;
// 	while (input[i] && input[i] != quote)
// 		i++;
// 	return (i);
// }

// t_token	*create_token(t_token_type token_type, char *value)
// {
// 	t_token	*new_token;

// 	new_token = malloc(sizeof(t_token));
// 	if (!new_token)
// 		return (NULL);
// 	new_token->type = token_type;
// 	if (!value)
// 		new_token->value = NULL;
// 	else
// 		new_token->value = ft_strdup(value);
// 	new_token->next = NULL;
// 	return (new_token);
// }

// void	add_token(t_token **token_list, t_token *new_token)
// {
// 	t_token	*tmp;

// 	if (!*token_list)
// 	{
// 		*token_list = new_token;
// 		return ;
// 	}
// 	tmp = *token_list;
// 	while (tmp->next)
// 		tmp = tmp->next;
// 	tmp->next = new_token;
// }

// void	free_tokens(t_token *token_list)
// {
// 	t_token	*tmp;

// 	while (token_list)
// 	{
// 		tmp = token_list;
// 		token_list = token_list->next;
// 		if (tmp->value)
// 			free(tmp->value);
// 		free(tmp);
// 	}
// }
