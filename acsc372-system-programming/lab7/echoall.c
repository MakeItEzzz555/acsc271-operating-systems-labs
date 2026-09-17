#include <stdio.h>

int main(int argc, char *argv[], char *envp[])
{
    (void)argc;
    (void)argv;

    for (char **env = envp; *env != NULL; env++) {
        printf("%s\n", *env);
    }

    return 0;
}
