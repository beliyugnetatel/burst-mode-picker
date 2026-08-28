#ifndef ALGOLOGIC_H
#define ALGOLOGIC_H

#include <QString>
#include <QImage>


class AlgoLogic
{
public:
    AlgoLogic();

private:

    void makeBW(const QString &filePath);

    void Laplace(QImage image);
};

#endif // ALGOLOGIC_H
