#ifndef LOGGER_H
#define LOGGER_H

#include <QObject>
#include <QFile>
#include <QTextStream>
#include <QDateTime>


class Logger : public QObject
{
    Q_OBJECT
public:
    explicit Logger(QObject *parent = 0);
    explicit Logger(QString str,QObject *parent = 0);
    ~Logger();
    void skipError();

    inline void setFileName(QString fn) {fileName = fn;}
    inline QString getFileName() {return fileName;}
    inline QString getErrorString() {return errorString;}
    inline bool hasError() {return error;}


protected:
    QString fileName;
    QFile* pFile;
    QTextStream* pStream;
    inline void init();
    bool error;
    QString errorString;

signals:
    void Error(QString);

public slots:
    void write (QString str);
    void open();

};

#endif // LOGGER_H
