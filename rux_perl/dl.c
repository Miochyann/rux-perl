/* Copyright (c) [2023] [Syswonder Community]
 *   [Ruxos] is licensed under Mulan PSL v2.
 *   You can use this software according to the terms and conditions of the Mulan PSL v2.
 *   You may obtain a copy of Mulan PSL v2 at:
 *               http://license.coscl.org.cn/MulanPSL2
 *   THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY OR FIT FOR A
 * PARTICULAR PURPOSE. See the Mulan PSL v2 for more details.
 */

#include <stdio.h>
#include <unistd.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
    puts("Hello, Ruxos dl!");
    printf("argc %d, argv %p\n", argc, argv);

    // int i = 0;
    for (int i = 0; i <= argc; i++) {
        printf("arg %d: %s\n", i, *(argv + i));
    }
    // printf("arg %d: %s\n", i, *(argv + i));

    char *app_path = argv[0];
    // printf("go\n");
    // execl(app_path, app_path, "--help", 0);

    // 打开输出文件
    int fd = open("output.txt", O_WRONLY | O_CREAT | O_APPEND, 0644);
    char *data = argv[1];
    // 写入数据到文件描述符中
    write(fd, "\n", 1);
    write(fd, data, strlen(data));
    write(fd, "\n", 1);

    if (fd == -1) {
        perror("open failed");
        return 1;
    }

    // // 重定向标准输出到文件
    // if (dup2(fd, STDOUT_FILENO) == -1) {
    //     perror("dup2 failed");
    //     return 1;
    // }

    chdir("/perl-5.38.2");

    execv(app_path, argv);


    return 0;
}
