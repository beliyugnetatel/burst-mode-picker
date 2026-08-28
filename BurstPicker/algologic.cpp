#include "algologic.h"

AlgoLogic::AlgoLogic() {}


void AlgoLogic::makeBW(const QString &filePath)
{
    QImage Image(filePath);
    if (Image.format() != QImage::Format_RGB32 && Image.format() != QImage::Format_ARGB32)
    {
        Image = Image.convertToFormat(QImage::Format_RGB32);
    }

    for (int i = 0; i < Image.height(); ++i)
    {
        QRgb *line = reinterpret_cast<QRgb*>(Image.scanLine(i));

        for (int j = 0; j < Image.width(); ++j)
        {
            QRgb currentPixel = line[j];

            int r = qRed(currentPixel);
            int g = qGreen(currentPixel);
            int b = qBlue(currentPixel);

            int gray = (r * 0.299) + (g * 0.587) + (b * 0.114);

            line[j] = qRgb(gray, gray, gray);
        }
    }
}


void AlgoLogic::Laplace(QImage image)
{
    int kernel[3][3] = {
        {0, 1, 0},
        {1, -4, 1},
        {0, 1, 0}
    };


    for (int i = 1; i < image.height() - 1; ++i)
    {

    }

}
