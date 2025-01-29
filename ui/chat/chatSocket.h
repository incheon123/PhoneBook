#ifndef CHATSOCKET_H
#define CHATSOCKET_H

#include "../../../../ui/chat/chatbox.h"

#include <QObject>
#include <QTcpSocket>
#include <QWidget>

class ChatSocket : public QObject{

    Q_OBJECT

private:
    QTcpSocket *tcp;
    ChatBox* chatBox;

signals:
    void enterUser(QString userName);

public:
    ChatSocket();
    ChatSocket(ChatBox* chatBox);
    ~ChatSocket(){ };
    void startChat();
    void endChat();
    bool sendMessage();
    bool recvMessage();

private:
    void connetToHost();
};

#endif // CHATSOCKET_H
