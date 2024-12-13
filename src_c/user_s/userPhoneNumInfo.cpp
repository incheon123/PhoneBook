#include "../../src_h/user_h/userPhoneNumInfo.h"

QString UserPhoneNumInfo::getOwner(){
    return this->owner;
}
QString UserPhoneNumInfo::getPhoneNumUserId(){
    return this->phoneNumUserId;
}
QString UserPhoneNumInfo::getPhoneNumber(){
    return this->phoneNumber;
}
QString UserPhoneNumInfo::getName(){
    return this->name;
}
QString UserPhoneNumInfo::getCreateTime(){
    return this->createTime;
}
void UserPhoneNumInfo::setOwner(QString owner){
    this->owner = owner;
}
void UserPhoneNumInfo::setPhoneNumUserId(QString phoneNumUserId){
    this->phoneNumUserId = phoneNumUserId;
}
void UserPhoneNumInfo::setPhoneNumber(QString phoneNumber){
    this->phoneNumber = phoneNumber;
}
void UserPhoneNumInfo::setName(QString name){
    this->name = name;
}
void UserPhoneNumInfo::setCreateTime(QString createTime){
    this->createTime = createTime;
}
