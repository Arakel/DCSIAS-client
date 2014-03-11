#include "logger.h"

Logger::Logger(QObject *parent) :
    QObject(parent)
{
    filename = QString("TaskLog.txt");
    init();
}

Logger::Logger(QString str, QObject *parent) : QObject(parent)
{
    filename = str;
    init();
}


Logger::~Logger()
{
    delete pStream;
    pFile->flush();
    pFile->close();
    delete pFile;
}

void Logger::init()
{
    pFile = new QFile;
    pFile->setFileName(filename);
    pStream = new QTextStream(pFile);
    if(pFile->open(QIODevice::Append))
    {
        *pStream << QString("Start Application at %1").arg(QDateTime::currentDateTime().toString("dd/MM/yy HH:mm"));
        error = false;


    }
    else
    {
        error = true;
        errorString = QString("Cann't open logfile");
    }
}

void Logger::open()
{
    if(pFile->isOpen())
    {
        pFile->flush();
        pFile->close();
        error = false;
        errorString.clear();
    }
    pFile->setFileName(filename);
    if(pFile->open(QIODevice::Append))
    {
        *pStream << QString("Change lof file to %1 at %2").arg(filename).arg(QDateTime::currentDateTime().toString("dd/MM/yy HH:mm"));

    }
    else
    {
        error = true;
        errorString = QString("Cann't open logfile");
        emit Error(QString("Cann't open logfile"));
    }

}

void Logger::write(QString str)
{
    if(pFile->isOpen())
    {
        *pStream << str << endl;
        pFile->flush();
    }
    else
    {
        error = true;
        errorString = QString("Cann't open logfile");
        emit Error(QString("Cann't open logfile"));
    }
}

void Logger::hasError() {return error;}


void Logger::getErrorString() {return errorString;}


void Logger::skipError()
{
    error = false;
    errorString.clear();
}
