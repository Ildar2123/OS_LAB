#include <iostream>
#include <dlfcn.h>

int main(){
    char *error;

    void *library = dlopen("./lib.so", RTLD_LAZY);

    if(library == nullptr){
        std::cout << dlerror() << std::endl;
        exit(EXIT_FAILURE);
    }

    void (*func)() = (void (*)())dlsym(library, "about");

    if((error = dlerror()) != nullptr){
        std::cout << error << std::endl;
        exit(EXIT_FAILURE);
    }

    (*func)();

    dlclose(library);
    return 0;
}