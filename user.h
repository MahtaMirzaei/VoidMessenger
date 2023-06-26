#ifndef USER_H
#define USER_H

#include <QObject>
#include <QDebug>
#include "api.h"
#include <QDataStream>
#include <QFile>
#include <QDir>
//#include "refresherchannel.h"
//#include "refresherDirect.h"
//#include "refreshergroup.h"
//#include "refresherabstract.h"
class User : public QObject
{
    Q_OBJECT
public:
    User();
    explicit User(QString userName,QString passWord,QString token = "",QString userPath="userLog.dat",QObject* parent = nullptr);
    void Register();
    void login();
    void logOut();
    int loadFromFile();
    int saveToFile();
    QString getUserName();
    QString getPassword();
    QString getToken();
    void SetUserName(const QString& new_user_name);
    void SetPassWord(const QString& new_pass_word);
    friend QDataStream& operator<<(QDataStream &stream,const User &u);
    friend QDataStream& operator>>(QDataStream &stream,User &u);
    int msgCountGetterDm();
    int msgCountGetterChannel();
    int msgCountGetterGroup();
    void allMsgCountsReInit(QString dst);
private:
    const QString m_UserLogFilePath;
    QString m_username;
    QString m_password;
    QString m_token;
    API* m_server;
    int msgCountDm;
    int msgCountChannel;
    int msgCountGroup;
    //void writeToFile(char* filePath);
    //void readFromFile(char* filePath);
private slots:
    void msgCountChannelSlot(QString argMsgCount);
    void msgCountDmSlot(QString argMsgCount);
    void msgCountGroupSlot(QString argMsgCount);
    void server_handler_on_Register();
    void server_handler_on_Login(QString token);
    void server_handler_on_Logout();
    void server_handler_on_failure(QString Error);
signals:
    void Success();
    void Failure(QString Error);
};

#endif // USER_H
