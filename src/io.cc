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
        throw mystd::io_exception(EIO,"couldn't open dir");


    while ((ent = readdir(dir)) != NULL)
        if("." != std::string(ent->d_name) && ".."!= std::string(ent->d_name))
            dir_list.push_back(ent->d_name);
    closedir(dir);

    return dir_list;
}

std::string mystd::get_cwd() {
    char path [FILENAME_MAX] ;
    ::getcwd(path, sizeof path);
    return std::string(path);
}

long mystd::file_size(std::string filename) {
    struct stat stat_buf;
    int rc = stat(filename.c_str(), &stat_buf);
    if(rc!=0)
        throw io_exception(EIO,"mystd::file_size");
    return stat_buf.st_size;
}