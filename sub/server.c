#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <signal.h>

static int lfd = -1, cfd = -1;

int main(int argc, char const *argv[])
{
        struct sockaddr_in servaddr, cliaddr;
        socklen_t clilen;
        pid_t childpid;
        
        if (argc != 2) {
                printf("Usage: %s port\n", argv[0]);
                exit(0);
        }

        lfd = socket(AF_INET, SOCK_STREAM, 0);
        if (lfd < 0) {
                perror("socket error");
                exit(-1);
        }

        servaddr.sin_family = AF_INET;
        servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
        servaddr.sin_port = htons(atoi(argv[1]));

        if (bind(lfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0) {
                perror("bind error");
                goto end;
        }

        if (listen(lfd, 1000) < 0) {
                perror("listen error");
                goto end;
        }

        while(1) {
                clilen = sizeof(cliaddr);
                cfd = accept(lfd, (struct sockaddr *)&cliaddr, &clilen);
                if (cfd < 0) {
                        perror("accept error");
                        goto end;
                }

                childpid = fork();
                if (childpid == 0) {
                        close(lfd);
                        ssize_t n;
                        char buff[1024];
                        while((n = read(cfd, buff, 1000)) > 0) {
                                buff[n] = 0;
                                printf("%s: %s\n", inet_ntoa(cliaddr.sin_addr), buff);
                        }
                        exit(0);
                }
                close(cfd);
                cfd = -1;
        }

end:
        close(lfd);
        return 0;
}

