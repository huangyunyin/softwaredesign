#ifndef _WRITE_MESSAGE_H
#define _WRITE_MESSAGE_H
#include <iostream>
#include <list>
#include "Message.h"
using namespace std;

class WriteMessage {
public :
    WriteMessage(const char *fpath) { file_path = fpath; }
    ~WriteMessage() {}

    void WriteMessageAfter(Message message);
    void WriteMessageAll(list<Message> message_list);

private:
    const char *file_path;
};
#endif