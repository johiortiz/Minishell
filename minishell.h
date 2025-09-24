#ifndef MINISHELL_H
# define MINISHELL_H

// Librerías estándar necesarias para el proyecto
# include <stdio.h>      // Para printf, perror
# include <stdlib.h>     // Para malloc, free, exit, getenv
# include <unistd.h>     // Para access, unlink, close, read, write, fork, etc.
# include <string.h>     // Para strerror
# include <sys/wait.h>   // Para waitpid, wait
# include <sys/stat.h>   // Para stat, lstat, fstat
# include <signal.h>     // Para sigaction, kill
# include <dirent.h>     // Para opendir, readdir, closedir

// Librerías de readline
# include <readline/readline.h>
# include <readline/history.h>

// Librería personal
# include "libft/libft.h"

// Enum para los diferentes tipos de tokens que el Lexer reconocerá
typedef enum e-tokentype
{
	TOKEN_WORD,				// Palabra (comando, arg, etc)
	TOKEN_PIPE,				// |
	TOKEN_REDIR_IN,			// <
	TOKEN_REDIR_OUT,		// >
	TOKEN_REDIR_APPEND,		// >>
	TOKEN_HEREDOC			// <<
	t_tokentype;
}

// Estructura para un solo token generado por el lexer
typedef struct s_token
{
	char			*value;		// String del token
	t_tokentype		type;		// El tipo de token según el enum
}	t_token;

// Estructura para una redirección, extraida por el Parser
typedef struct s_redir
{
	char			*filename;		// Nombre del archivo de la redirección
	t_tokentype		type;			// Tipo de redirección (<, >, <<, >>)
}	t_redir;

// Estructura para un comando simple
typedef struct s_simple_cmd
{
	char	**args;		// Array de strings (comando y args)
	t_list	*redirs;
}	t_simple_cmd;

/* ========================================================================== */
/* FUNCTION PROTOTYPES                             							  */
/* ========================================================================== */

/* --- PARSER ---*/


/* --- EXPANDER ---*/



/* --- EXECUTOR ---*/



/* --- BUILTINS ---*/


/*--- SIGNALS ---*/


/* --- UTILS ---*/

#endif