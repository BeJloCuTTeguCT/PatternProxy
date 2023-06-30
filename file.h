#ifndef IFILE_H
#define IFILE_H

#include <qfile.h>

class IFile
{
public:
    virtual QString fileDataStr(const QString &filename) = 0;
};
#endif // IFILE_H



#ifndef FILE_H
#define FILE_H
class File : public IFile
{
public:
    QString fileDataStr(const QString &filename) override;
};
#endif // FILE_H



#ifndef PROXYFILE_H
#define PROXYFILE_H
class ProxyFile : public IFile
{
    IFile *m_file;

public:
    ProxyFile(IFile *realObj = nullptr);
    QString fileDataStr(const QString &filename) override;
};
#endif // PROXYFILE_H
