#include <iostream>
#include <vector>
#include <cstring>
#include "File.h"


using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(int argc, char *argv[]) {
    if (argc > 1) {
        std::vector<string> allArgs(argv, argv + argc);//все argv в string
        if (allArgs[1] == "help" || allArgs[1] == "-help" || allArgs[1] == "-h") {
            cout << "Группа: ИС-841" << endl;
            cout << "Авторы:" << endl;
            cout << "Хабибулин Ильдар" << endl;
            cout
                    << "Краткое описание:\n Проект работает с файловой системы. Умеет перемещать, копировать, удалять файлы\n";
            cout << "Так же проект умеет подсчитывать общий размер указанной дериктории или файла и др.";
            cout<<endl<<"Аргументы:"<<endl;
            cout<<"1) -move <oldPlace> <NewPlace> \t\t\tперемещает файл"<<endl;
            cout<<"./lab2_20 -move File.sh /folder/File.sh"<<endl;
            cout<<"2)- copy <File> <Destination> \t\t\tкопирует файл в пункт назначения"<<endl;
            cout<<"./lab2_20 -copy File.sh ./src"<<endl;
            cout<<"3) -delete <File>\t\t\t\tудаляет файл"<<endl;
            cout<<"./lab2_20 -delete File.sh"<<endl;
            cout<<"4) -size <Destination> or <File>\t\tпоказывает размер папки\\файла"<<endl;
            cout<<"./lab2_20 -size home/os || ./lab2_20 File.sh"<<endl;
            cout<<"5) -ls <Destination>\t\t\t\tотображает размер выбранной папки"<<endl;
            cout<<"./lab2_20 /home/os"<<endl;
            cout<<"6) -procfs \t\t\t\t\tотображает все процессы procfs"<<endl;
            cout<<"./lab2_20 -procfs"<<endl;
        }// } else if (argc > 1) {
        if (allArgs[1] == "-move" && argc > 3) {
            move(argv[2], argv[3]);
        }

        if (allArgs[1] == "-copy" && argc > 3) {
            copy(argv[2], argv[3]);
        }

        if (allArgs[1] == "-delete" && argc > 2) {
            delete_f(argv[2]);
        }

        if (allArgs[1] == "-size") {
            std::cout << "Byte:" << size(allArgs[2]) << std::endl;
        }

        if (allArgs[1] == "-ls") {
            show_all(argv[2]);
        }

        if (allArgs[1] == "-procfs") {
            procfs();
        }
        //} else


    } else
        cout << "Недостаточно аргументов или команда не верна. Используйте -help";
}



