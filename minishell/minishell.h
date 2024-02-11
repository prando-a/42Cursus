/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:40:24 by jose-mgo          #+#    #+#             */
/*   Updated: 2024/02/09 23:59:47 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <dirent.h>
# include <sys/wait.h>
# include <sys/ioctl.h>
# include <sys/stat.h>

# define RED     	"\x1b[31m"
# define GREEN   	"\x1b[32m"
# define YELLOW  	"\x1b[33m"
# define BLUE    	"\x1b[34m"
# define MAGENTA	"\x1b[35m"
# define CYAN    	"\x1b[36m"
# define WHITE		"\033[37m"
# define BOLD		"\033[1m"
# define RESET   	"\x1b[0m"
# define CLEAR		"\033[2J"

# define READ 	0
# define WRITE 	1

# define IN		0
# define OUT	1

# define EXPORT	0
# define UNSET	1

# define INFILE		0
# define HEREDOC	1
# define OUTFILE	0
# define APPEND		1

extern int	g_signal;

typedef struct s_exec
{
	pid_t	pid;
	int		cmdc;
	char	***cmdv;
	int		**input;
	char	***inpath;
	int		**output;
	char	***outpath;
	int		file[2];
	int		pipe_fd[2];
	int		dup_std[2];
	int		status;
}	t_exec;

typedef struct s_cmd
{
	char			**cmd;
	int				*pipe;
	int				*heredoc;
	int				*infile;
	int				*outfile;
	int				*append;
}	t_cmd;

typedef struct s_env
{
	char			*env_content;
	char			*env_name;
	struct s_env	*next;
}	t_env;

typedef struct s_ms
{
	char	*buffer;
	char	*prompt;
	char	**path;
	char	**new_env;
	int		exit_flag;
	int		status;
	t_env	*e_lst;
}	t_ms;

typedef struct s_parser
{
	char			*cmd;
	int				pipe;
	int				heredoc;
	int				infile;
	int				outfile;
	int				append;
}	t_parser;

typedef struct s_aux
{
	int		i;
	int		dquotes;
	char	*line;
	int		j;
	int		x;
	int		envindex;
	char	*env;
	char	*freeme;
	int		quotes;
}	t_aux;

typedef struct s_command_len
{
	int		x;
	char	*env;
	int		quotes;
	int		dquotes;
	int		i;
}	t_cl;

typedef struct s_numwords
{
	int	numwords;
	int	i;
	int	quotes;
	int	dquotes;
}	t_nw;

typedef struct s_parserk
{
	int	len;
	int	i;
	int	quotes;
	int	dquotes;
}	t_parserk;

typedef struct s_ms_parser_aux
{
	int			numargs;
	int			i;
	t_parser	info;
	int			len;
	t_cmd		*cmd;
}	t_mix;

//INIT
int			ms_init(t_ms *ms, char **env);
void		intro(void);
char		**get_path(t_ms *ms);
char		**path_join(char **arr, char *str);

//ENV UTILS
t_env		*set_env_list(char **env);
char		**set_env_matrix(t_env *env);
void		clear_env_lst(t_env *lst);
char		*ft_getenv(t_env *env, char *haystack, int status);

//MAIN
int			shell(t_ms *ms);

int			ft_add_env(char *env, t_env **head);
void		ft_free_cmd(t_cmd *cmd);
int			ft_quotes(char *command);
int			ft_chrqts(char *str);

//PARSER
t_cmd		*ms_parser(char *command, t_env *envlst, int status);
int			ms_quotes(t_ms *ms);
int			get_num_cmd(char *command);
char		*findenv(char *str);
int			get_command_len(char *command, t_env *envlst, int status);
t_parser	parse_command(char *command, t_env *envlst, int status);
t_cmd		*init_cmd_lst(char *command);
void		update_parse_info(t_parser *parse_info, int quotes, int dquotes);
int			is_metachar(char *c);
int			iter_str(char *command);
int			check_cnt(char *s);
int			syntax_check(t_cmd *p);
int			check_illegal_char(char *s);
t_aux		update_for_metachar(t_aux aux, char *command);
t_aux		update_struct_parse(t_aux aux, t_env *envlst, int status,
				char *command);
t_cl		update_cl(t_cl cl, t_env *envlst, int status, char *command);
t_aux		init_aux_struct(void);
size_t		ft_strlen_free(const char *str);
t_nw		update_nw(t_nw nw, char *s, int c);

//EJECUTOR Y BUILTINS
int			ms_exec(t_ms *ms, t_cmd *cmd);
int			exec_init(t_exec *exc, t_cmd *cmd);
char		***set_cmdv(t_cmd *cmd, int *cmdc);
void		set_output_vector(t_cmd *cmd, t_exec *exc, int i, int j);
void		set_input_vector(t_cmd *cmd, t_exec *exc, int i, int j);
int			exec_set_final_io(t_exec *exc, int i, int j, t_ms *ms);
int			get_heredoc(char *limiter, t_exec *exc, t_ms *ms);
int			exec_built_ins(char **cmd, t_ms *ms, t_exec *exc);
int			env_manager(int mode, char **cmd, t_ms *ms);
int			ft_env(t_env *lst);
int			ft_export(char *var, t_env **head);
int			ft_unset(char *var, t_env *lst);
int			ft_cd(char **new_pwd, t_env **env);

//SEÑALES
void		ms_sigcatch(int sig);

#endif