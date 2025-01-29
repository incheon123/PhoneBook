#include "chatSocket.h"
#include "../../../../header/user/userAccount.h"

ChatSocket::ChatSocket(){

}
ChatSocket::ChatSocket(ChatBox* chatBox) {
    this->chatBox = chatBox;
}

void ChatSocket::startChat(){
    // 1. chatbox에 채팅시작하겠습니다 메세지 보내기
    // 2.

    tcp = new QTcpSocket(this);
    tcp->connectToHost("129.154.51.67", 80);

    ChatBox *ch = new ChatBox();

    QObject::connect(this, &ChatSocket::enterUser, chatBox, &ChatBox::sendMessage);

    // [1] 자신의 채팅방에 자기가 입장했다는 메시지 보내기
    // [2] 서버에 자신의 닉네임 보내기

    emit enterUser(UserAccount::getInstance()->getUserId() + "님이 입장하셨습니다"); //[1]
    tcp->write(UserAccount::getInstance()->getUserId().toStdString().c_str());

}

void ChatSocket::endChat(){

}
bool ChatSocket::sendMessage(){

}
bool ChatSocket::recvMessage(){

}
