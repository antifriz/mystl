//
// Created by ivan on 5/25/15.
//

#include <mystl/io.h>
#include <stdio.h>
#include <dirent.h>
#include <errno.h>
#include <unistd.h>
#include <sys/stat.h>

std::vector<std::string> mystd::read_dir(std::string dir_path) {

    std::vector<std::string> dir_list;
    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir(dir_path.c_str())) == NULL)
        throw mystd::io_exception(EIO, "couldn't open dir");


    while ((ent = readdir(dir)) != NULL)
        if ("." != std::string(ent->d_name) && ".." != std::string(ent->d_name))
            dir_list.push_back(ent->d_name);
    closedir(dir);

    return dir_list;
}

std::string mystd::get_cwd() {
    char path[FILENAME_MAX];
    ::getcwd(path, sizeof path);
    return std::string(path);
}

long mystd::file_size(std::string filename) {
    struct stat stat_buf;
    int rc = stat(filename.c_str(), &stat_buf);
    if (rc != 0)
        throw io_exception(EIO, "mystd::file_size");
    return stat_buf.st_size;
}

#include <termios.h>

char ::mystd::getch(bool display_char) {
    char buf = 0;
    struct termios old = {0};
    fflush(stdout);
    if (tcgetattr(0, &old) < 0)
        perror("tcsetattr()");
    old.c_lflag &= ~ICANON;
    old.c_lflag &= ~ECHO;
    old.c_cc[VMIN] = 1;
    old.c_cc[VTIME] = 0;
    if (tcsetattr(0, TCSANOW, &old) < 0)
        perror("tcsetattr ICANON");
    if (read(0, &buf, 1) < 0)
        perror("read()");
    old.c_lflag |= ICANON;
    old.c_lflag |= ECHO;
    if (tcsetattr(0, TCSADRAIN, &old) < 0)
        perror("tcsetattr ~ICANON");
    if (display_char)printf("%c\n", buf);
    return buf;
}