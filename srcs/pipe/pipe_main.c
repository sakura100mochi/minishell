/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 13:06:30 by csakamot          #+#    #+#             */
/*   Updated: 2023/09/28 18:09:01 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../includes/built_in.h"
#include "../../includes/pipe.h"

// static char	*format_command(t_parser *parser)
// {
// 	size_t	cmd_len;
// 	size_t	file_len;
// 	char	*tmp;
// 	char	*file;

// 	cmd_len = 0;
// 	while (parser->cmd[cmd_len] != ' ' && parser->cmd[cmd_len] != '\0')
// 		cmd_len++;
// 	file_len = ft_strlen(parser->cmd) - (cmd_len + 1);
// 	tmp = ft_substr(parser->cmd, 0, cmd_len);
// 	file = ft_substr(parser->cmd, cmd_len + 1, file_len);
// 	free(parser->cmd);
// 	parser->cmd = tmp;
// 	return (file);
// }

int	pipe_main(t_init *state, t_parser *parser, size_t len)
{
	size_t	index;

	index = 0;
	state->pipe = init_pipe(len);
	while (index < len)
	{
		parser = parser->next;
		index++;
	}
	return (0);
}

// int main() {
//     int pipe_fd[2];
//     pid_t child_pid;

//     // パイプを作成
//     if (pipe(pipe_fd) == -1) {
//         perror("pipe");
//         exit(EXIT_FAILURE);
//     }

//     // 子プロセスをフォーク
//     child_pid = fork();

//     if (child_pid == -1) {
//         perror("fork");
//         exit(EXIT_FAILURE);
//     }

//     if (child_pid == 0) { // 子プロセス
//         // パイプの出力側を標準出力にリダイレクト
//         dup2(pipe_fd[1], STDOUT_FILENO);
//         close(pipe_fd[0]);
//         close(pipe_fd[1]);

//         // /bin/ls コマンドを実行
//         execl("/bin/ls", "/bin/ls", NULL);
//         perror("execl");
//         exit(EXIT_FAILURE);
//     } else { // 親プロセス
//         // パイプの入力側を標準入力にリダイレクト
//         dup2(pipe_fd[0], STDIN_FILENO);
//         close(pipe_fd[0]);
//         close(pipe_fd[1]);

//         // /usr/bin/grep コマンドを実行
//         execl("/usr/bin/grep", "/usr/bin/grep", "Make", NULL);
//         perror("execl");
//         exit(EXIT_FAILURE);
//     }

//     return 0;
// }
