#include "file.h"
#include <qmessagebox.h>
#include <qjsondocument.h>
#include <qjsonobject.h>


QString File::fileDataStr(const QString &filename)
{
    QFile file(filename);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QMessageBox *msg = new QMessageBox(QMessageBox::Icon::Critical, "Ошибка чтения",
                                                            "Ошибка при открытии файла",
                           QMessageBox::Ok, nullptr, Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
            msg->setAttribute(Qt::WA_DeleteOnClose);
            msg->show();
        return "";
    }
    file.seek(0);
    QString val = file.readAll();
    file.close();
    return val;
}

ProxyFile::ProxyFile(IFile *realObj)
{
    realObj == nullptr ? m_file = new File : m_file = realObj;
}

QString ProxyFile::fileDataStr(const QString &filename)
{
    QString val = m_file->fileDataStr(filename);
    QByteArray temp = val.toUtf8();
    QJsonParseError jsonErr;
    QJsonDocument JDoc(QJsonDocument::fromJson(temp, &jsonErr));
    if(JDoc.isEmpty()) {
        QMessageBox *msg = new QMessageBox(QMessageBox::Icon::Critical, "Ошибка чтения",
                                                            "В считанном файле нет json данных",
                           QMessageBox::Ok, nullptr, Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
            msg->setAttribute(Qt::WA_DeleteOnClose);
            msg->show();
        return "";
    }
    QJsonObject jObj = JDoc.object();
    QString result = "";
    result += QString("Site.ru:\n\tЛогин: %1\n").arg(jObj.value("Site.ru").toObject().value("login").toString());
    result += QString("\tПароль: %1\n").arg(jObj.value("Site.ru").toObject().value("password").toString());
    result += QString("DNS:\n\tПервый: %1\n").arg(jObj.value("DNS").toObject().value("first").toString());
    result += QString("\tВторой: %1\n").arg(jObj.value("DNS").toObject().value("second").toString());
    return result;
}
