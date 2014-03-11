#ifndef STRUCTURE_H
#define STRUCTURE_H
#include <QObject>



struct ModelParameters
{
    double Power;
    double dn;
    double dR; // range between reciver and transmit posts;
    unsigned int N; // N in row
    unsigned int M; // M in col
    double L; // row lenth
    double H; // col  height
    double hexDiff; // hexogonal range. val = 0 means no qudratic antenna;
    unsigned short ADCBit;
    unsigned long discret; // in Hz;
    unsigned short noiseLvl;
    bool isComplex;

};

struct TargetParams
{
quint64 startTime;
quint64 stopTime;
qint32 signalId;
double Rtr;
double Rrv;
double cosX;
double cosY;
double E;
bool isNoise;
};


struct Task
{

    quint64 taskId;
    quint64 startTime, stopTime;
    ModelParameters model;
    bool taskType;
    quint32 startIndex, stopIndex; // for part of Antenna;
};

struct TargetTask : public Task
{
        QList<TargetParams> target;

};

struct ChannelTask : public Task
{
    QList<quint64,QByteArray> array;

};

struct TargetArray : public Task
{
    QList<quint64,QByteArray> array;
};

 int CorrectType[] = {0xAA, 0xAB, 0xAC, 0xAD};

#endif // STRUCTURE_H
