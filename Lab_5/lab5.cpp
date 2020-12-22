#include <time.h>
#include <iostream>

extern "C"  void CurTime()
{   
    using std::cout;
    using std::endl;
    setlocale(LC_ALL, "Russian");
 
    time_t t;
    time(&t);
 
    tm* local = localtime(&t);
 
    char Hours[10] = {0};
    char Minutes[10] = {0};
    char Date [20] = {0};
    strftime(Hours, sizeof(Hours)/sizeof(Hours[0]), "%H", local);
    strftime(Minutes, sizeof(Minutes)/sizeof(Minutes[0]), "%M", local);
    strftime(Date, sizeof(Date)/sizeof(Date[0]), "%d %B %Y", local);
 
    cout << "Текущее время и дата: " << Hours << ":" << Minutes << " " << Date << endl;
}

extern "C" void about(){
    using std::cout;
    using std::endl;

    cout<<"Авторы:"<<endl;
    cout<<"Группа: ИС-841"<<endl;
    cout<<"Хабибулин Ильдар- github.com/ildar2123"<<endl;
    cout<<"Лабораторные работы по дисциплине \"Операционные системы\""<<endl;
    cout<<"CибГУТИ 2020"<<endl;
}
