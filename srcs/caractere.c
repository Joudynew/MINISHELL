/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   caractere.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joudafke <joudafke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 23:42:53 by joudafke          #+#    #+#             */
/*   Updated: 2025/07/11 23:42:55 by joudafke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	neutralize_special_char_in_single_quote(char *input)
{
	int		i;
	char	quote;

	i = 0;
	quote = 0;
	while (input[i])
	{
		if (!quote && (input[i] == '\''))
			quote = input[i];
		else if (quote && input[i] == quote)
			quote = 0;
		else if (quote && (is_special_char(input[i]) || input[i] == '$'))
			input[i] *= -1;
		i++;
	}
}

void	neutralize_special_char_in_double_quote(char *input)
{
	int		i;
	char	quote;

	i = 0;
	quote = 0;
	while (input[i])
	{
		if (!quote && input[i] == '\"')
			quote = input[i];
		else if (quote && input[i] == quote)
			quote = 0;
		else if (quote && is_special_char(input[i]))
			input[i] *= -1;
		i++;
	}
}
