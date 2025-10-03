/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyorti <johyorti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 06:12:27 by johyorti          #+#    #+#             */
/*   Updated: 2025/10/03 06:51:52 by johyorti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minishell.h"

// Función para crear un nueco comando simple vacío, útil para no repetir código

static	t_simple_cmd	*create_new_simple_cmd(void)
{
	t_simple_cmd	*cmd;
	
	cmd = malloc(sizeof(t_simple_cmd));
	if (!cmd)
		return (NULL);
	cmd->args = NULL;
	cmd->redirs = NULL;
	return (cmd);
}

/// --- Parser Principal ---
t_list	*parser(t_list *tokens)
{
	t_list					*commands;
	t_simple_cmd	*current_cmd;
	t_list					*current_token_node;
	t_token			*token;

	commands = NULL;
	current_cmd = NULL;
	current_token_node = tokens;
	
	// Creamos el primer comando simple para empezar a rellenarlo.
	if (current_token_node)
	{
		current_cmd = create_new_simple_cmd();
		ft_lstadd_back(&commands, ft_lstnew(current_cmd));
	}
	// El bucle recorrerá la lista de tokens de principio a fin.
	while (current_token_node)
	{
		// Falta añadir toda la lógica del bucle
		token = (t_token *)current_token_node->content;
		if (token->type == TOKEN_WORD)
			add_arg_to_cmd(current_cmd, token->value);
		else if (token->type == TOKEN_REDIR_OUT)
		{
			// 1. Avanzamos al siguiente token, que debería ser el nombre del archivo.
			current_token_node = current_token_node->next;
			// 2. qué pasa si no hay siguiente token?
			if (!current_token_node)
			{
				ft_putstr_fd("minishell: syntax error near unexpected token 'newline'\n", 2);
				// Aqui se debería parar y limpiar todo (TODO)
				break ;
			}
			// 3. y si el siguiente token NO es una palabra?
			t_token	*filename_token = (t_token *)current_token_node->content;
			if (filename_token->type != TOKEN_WORD)
			{
				ft_putstr_fd("minishell: syntax error near unexpected token\n", 2);
				// parar y limpiar
				break ;
			}
			// 4. Si todo esta ok, creamos y añadimos la redirección.
			// (se deberia crear una función aux "add_redir_to_cmd")
			t_redir	*new_redir;
			new_redir = malloc(sizeof(t_redir));
			// acá tenemos que hacer la comprobación del malloc
			new_redir->type = TOKEN_REDIR_OUT;	// Guarda el tipo de redirección
			new_redir->filename = ft_strdup(filename_token->value); // guarda el nombre
			ft_lstadd_back(&current_cmd->redirs, ft_lstnew(new_redir));
			// aplicar misma lógia para <, >>, <<.
		}
		current_token_node = current_token_node->next;
	}
	return (commands);
}