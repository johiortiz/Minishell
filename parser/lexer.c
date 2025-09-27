/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyorti <johyorti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 17:06:58 by johyorti          #+#    #+#             */
/*   Updated: 2025/09/28 00:51:21 by johyorti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minishell.h"

t_list	*lexer(char *line)
{
	t_list		*tokens;		// aqui se iran guardando cada token encontrado 
	t_state		state;			// memoria del estado del autómata. Guarda el "modo" actual para saber qué reglas aplicar.
	int			i;				// contador para recorrer el string
	int			token_start;	// marca de inicio, cuando empieza a leer una palabra guarda la posicion de i aqui para saber dónde empezó


	tokens = NULL;				// Empieza en NULL porque la lista está vacía al principio
	state = STATE_GENERAL;		// Empieza como STATE_GENERAL porque es nuestro punto de partida por defecto.
	i = 0;
	token_start = 0;			// i y token_start incializan en 0 porque comenzamos a leer el string desde el primer carácter.

	// Aqui deberia ir el bucle principal del autómata
	while (line[i])
	{
		if (!tokens)
			return (NULL);
		if (state == STATE_GENERAL)
		{
			if (ft_isspace(line[i]))		// Lógica para ignorar espacios
			{
				i++;
				continue ;
			}
			else if (line[i] == '|')		// Lógica para crear un token PIPE
				create_and_add_token(&tokens, "|", TOKEN_PIPE);
			else if (line[i] == '<')
			{
				if (line[i + 1] == '<')
				{
					create_and_add_token(&tokens, "<<", TOKEN_HEREDOC);
					i++; 							// Avanzamos i un carácter extra para saltar el segundo '<'
				}
				else
					create_and_add_token(&tokens, "<", TOKEN_REDIR_IN);
			}
			else if (line[i] == '>')
			{
				if (line[i + 1] == '<')
				{
					create_and_add_token(&tokens, "<<", TOKEN_HEREDOC);
					i++;
				}
				else
					create_and_add_token(&tokens, ">", TOKEN_REDIR_OUT);
			}
			else if (line[i + 1] == '>')
				create_and_add_token(&tokens, ">>", TOKEN_REDIR_APPEND);
			else if (line[i] == '"')
			{
				state = STATE_IN_DQUOTE;
				token_start = i + 1;
			}
			else if (line[i] == '\'')
			{
				state = STATE_IN_SQUOTE;
				token_start = i + 1;
			}
			else
			{
				state = STATE_IN_WORD;
				token_start = i;
			}
		}
		else if (state == STATE_IN_WORD)
		{
			// ... lógica para este estado
			if (ft_isspace(line[i] || line[i] == '|' || line[i] == '<' || \
				line[i] == '>' || line[i] == '"' || line[i] == '\''))
				{
					
				}
		}
		// ... etc. para los otros estados
		i++;
	}
	return (tokens);
}
