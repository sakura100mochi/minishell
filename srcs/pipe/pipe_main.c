/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 13:06:30 by csakamot          #+#    #+#             */
/*   Updated: 2023/09/28 23:50:05 by csakamot         ###   ########.fr       */
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

int	pipe_main(t_init *state, t_parser *parser, t_pipe *pipelist, size_t len)
{
	size_t	index;

	index = 0;
	while (index < len)
	{
		pipe(pipelist->pipe_fd);
		pipelist->pid = fork();
		if (pipelist->pid == -1)
			exit(EXIT_FAILURE);
		if (pipelist->pid == 0)
		{
			
		}
		parser = parser->next;
		index++;
	}
	return (0);
}

// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>
// #include <string.h>

// int main() {
//     int pipe_ls_to_grep[2];
//     int pipe_grep_to_wc[2];
//     pid_t ls_pid, grep_pid, wc_pid;

//     // パイプを作成
//     if (pipe(pipe_ls_to_grep) == -1 || pipe(pipe_grep_to_wc) == -1) {
//         perror("pipe");
//         exit(EXIT_FAILURE);
//     }

//     // ls -l を実行する子プロセスをフォーク
//     if ((ls_pid = fork()) == -1) {
//         perror("ls fork");
//         exit(EXIT_FAILURE);
//     }

//     if (ls_pid == 0) {
//         // 子プロセス内で ls -l を実行し、結果をパイプに書き込む
//         close(pipe_ls_to_grep[0]);  // パイプの読み込み側を閉じる
//         dup2(pipe_ls_to_grep[1], STDOUT_FILENO);
//         execlp("ls", "ls", "-l", NULL);
//         perror("ls execlp");
//         exit(EXIT_FAILURE);
//     } else {
//         // 親プロセス
//         close(pipe_ls_to_grep[1]);  // パイプの書き込み側を閉じる

//         // grep srcs を実行する子プロセスをフォーク
//         if ((grep_pid = fork()) == -1) {
//             perror("grep fork");
//             exit(EXIT_FAILURE);
//         }

//         if (grep_pid == 0) {
//             // 子プロセス内で grep srcs を実行し、結果を別のパイプに書き込む
//             close(pipe_grep_to_wc[0]);  // パイプの読み込み側を閉じる
//             dup2(pipe_ls_to_grep[0], STDIN_FILENO);
//             dup2(pipe_grep_to_wc[1], STDOUT_FILENO);
//             execlp("grep", "grep", "srcs", NULL);
//             perror("grep execlp");
//             exit(EXIT_FAILURE);
//         } else {
//             // 親プロセス
//             close(pipe_grep_to_wc[1]);  // パイプの書き込み側を閉じる

//             // wc -l を実行する子プロセスをフォーク
//             if ((wc_pid = fork()) == -1) {
//                 perror("wc fork");
//                 exit(EXIT_FAILURE);
//             }

//             if (wc_pid == 0) {
//                 // 子プロセス内で wc -l を実行し、結果を表示
//                 dup2(pipe_grep_to_wc[0], STDIN_FILENO);  // grep の出力をパイプから読み取る
//                 execlp("wc", "wc", "-l", NULL);
//                 perror("wc execlp");
//                 exit(EXIT_FAILURE);
//             } else {
//                 // 親プロセスはすべての子プロセスの終了を待つ
//                 close(pipe_ls_to_grep[0]);
//                 close(pipe_grep_to_wc[0]);
//                 waitpid(ls_pid, NULL, 0);
//                 waitpid(grep_pid, NULL, 0);
//                 waitpid(wc_pid, NULL, 0);
//             }
//         }
//     }

//     return 0;
// }
