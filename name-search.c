#include "libs.h"
#include "tads.h"

int check_name (char **argv, userinfo *user) {

    return (strcmp (argv[2], user->name) == 0) ? (1) : 0;

}

int parse_file (char **argv, int fd, userinfo *user) {

    char buff[1024], aux[1024];

    int occ = 0, count = 0, name_len = 0, n = read (fd, buff, 1024);

    sprintf (aux, "%d bytes read\n", n);
    write (1, aux, strlen (aux));

    for (int i = 0; i < n; i++) {

        name_len++;

        if (buff[i] == '\n') {

            count++;

            user->name = malloc (name_len * sizeof (char));

            for (int j = 0; j < name_len; j++) {

                user->name[j] = buff[i - name_len + 1 + j];

            }

            user->name[name_len - 1] = '\0';

            occ = (check_name (argv, &(*user))) ? occ + 1 : occ;

            name_len = 0;

        }

    }

    close (fd);

    sprintf (aux, "%d occurences in file\n", count);
    write (1, aux, strlen (aux));

    sprintf (aux, "%d occurences found\n", occ);
    write (1, aux, strlen (aux));

    return (0);

}

int read_file (char **argv, int *fd, userinfo *user) {

    if ((*fd = open (argv[1], O_RDONLY)) < 0) {

        write (
            1,
            "Error: Cannot open the file\n",
            strlen ("Error: Cannot open the file\n")
            );

        return (-1);

    } else {

        parse_file (argv, *fd, &(*user));

        return (0);

    }

}

int main (int argc, char **argv) {

    if (argc < 3) {

        write (
            1,
            "Error: Missing parameters.\n",
            strlen("Error: Missing parameters.\n")
            );

        write (
            1,
            "Usage: ./main <file> <Name>\n",
            strlen("Usage: ./main <file> <Name>\n")
            );

        write (
            1,
            "Example: ./main users.txt Norah\n",
            strlen("Example: ./main users.txt Norah\n")
            );

        return (-1);

    } else {

        int fd;

        userinfo user;

        return (read_file (argv, &fd, &user) < 0) ? (-1) : (0);

    }

}
