/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 13:06:30 by csakamot          #+#    #+#             */
/*   Updated: 2023/09/28 11:10:07 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../includes/built_in.h"
#include "../../includes/pipe.h"

int	pipe_main(t_init *state, t_parser *parser)
{
	while (parser != NULL)
	{
		execution_main(state);
		parser = parser->next;
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
