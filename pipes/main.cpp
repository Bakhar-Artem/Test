#include <iostream>
#include <string>
const std::string proc[] = { "./m","./a","./p","./s"};
const int stopWord = -1;
int main() {
    int p[3];
    int child = 0;
    for (int i = 0; i < 3; i++) {
        pipe(p);
        child = fork();
        if (child==0) {
            execlp(proc[i].c_str(),proc[i].c_str(), NULL);
            exit(0);
        }
        close(p[1]);
    }
    execlp(proc[3].c_str(),proc[3].c_str(), NULL);
    exit(0);
    return 0;
}