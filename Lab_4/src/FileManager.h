
#ifndef LAB2_FILE_H
#define LAB2_FILE_H
#include <string>
#include <iostream>
#include <filesystem>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <fstream>
#include <pwd.h>
#include <sys/types.h>
#include <iomanip>
#include <cstdlib>
#include "stdio.h"
#include <string>

namespace fs = std::filesystem;
void move (const char *from,const char *to);
void copy (std::filesystem::path what, std::filesystem::path to);
void delete_f(const char *file);
unsigned long size(std::string dest);
void show_all(char *dest);
void procfs();
int executeRequest(int argc, char *argv[]);
#endif //LAB2_FILE_H
