#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>
#include <vector>
#include <sys/stat.h>

using namespace std;

const char *HELP_FL = "-h";
const char *EXECUTE_FL = "-exe";

void showInfo();
int executeProgramm(char *argv[]);
void job(char *argv[], const string &arguments);
char **getArgumentForChildProgramm(char *progName, const string &agruments);

int main(int argc, char *argv[])
{
    if (argc < 2)
        cout << "Слишком мало аргументов; -h за помощью\n";
    else
    {
        if (strcmp(argv[1], HELP_FL) == 0)
            showInfo();
        else if (strcmp(argv[1], EXECUTE_FL) == 0)
        {
            if (argc < 3)
            {
                cout << "Слишком мало аргументов для " << EXECUTE_FL << "; -h за помощью\n";
                return -1;
            }
            executeProgramm(argv);
        }
        else
        {
            cout << "Неизвестный параметр " << argv[1] << "; -h за помощью\n";
        }
    }
    return 0;
}

void showInfo()
{
    cout << "Авторы (ИС-841): Хабибулин Ильдар\n";
    cout << "Параметры:\n";
    cout << "-exe <path> - программа, которая будет запускаться в дочернем процессе\n";
    cout << "Пример: ./LiteSH -exe ../bin/file_manager\n";
}

int executeProgramm(char *argv[])
{
    string arguments;
    int pid;

    while (1)
    {
        cout << "\n\nqwt - для выхода\nВведите аргументы для программы: ";
        getline(cin, arguments);

        if (strstr(arguments.c_str(), "qwt") != nullptr)
            return 0;

        switch ((pid = fork()))
        {
        case -1:
            perror("fork");
            break;
        case 0:
            job(argv, arguments);
            exit(EXIT_SUCCESS);
        }

        usleep(50000);
    }

    return 0;
}

void job(char *argv[], const string &arguments)
{
    umask(0);

    if (setsid() < 0)
    {
        perror("setsid");
        exit(EXIT_FAILURE);
    }

    if (execv(argv[2], getArgumentForChildProgramm(argv[2], arguments)) == -1)
    {
        perror("execvp");
        exit(EXIT_FAILURE);
    }
}

char **getArgumentForChildProgramm(char *progName, const string &agruments)
{
    vector<string> argvVector;
    size_t curPosition = 0;
    size_t spacePosition;
    string substr;

    argvVector.push_back(progName);
    do
    {
        spacePosition = agruments.find(' ', curPosition);
        substr = agruments.substr(curPosition, spacePosition - curPosition);
        if (!substr.empty())
            argvVector.push_back(substr);
        curPosition = spacePosition + 1;
    } while (spacePosition != string::npos);

    char **argv = new char *[argvVector.size() + 1];
    for (size_t i = 0; i < argvVector.size(); ++i)
    {
        argv[i] = new char[argvVector[i].size() + 1];
        strcpy(argv[i], argvVector[i].c_str());
    }
    argv[argvVector.size()] = 0;
    return argv;
}