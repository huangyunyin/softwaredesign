#ifndef _READ_MESSAGE_H
#define _READ_MESSAGE_H
#include <iostream>
#include <list>
#include <fstream>
#include "Message.h"
using namespace std;

class ReadMessage {
public:
    ReadMessage(const char *fpath) { file_path = fpath; }
    ~ReadMessage() {}

    list<Message> ReadFromFile();

private:
    const char* file_path;
};
#endif