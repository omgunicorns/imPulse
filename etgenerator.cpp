//#include <QAudioFormat>
#include <QtMultimedia>
#include <QtMath>

#define FREQ_CONST ((2.0 * M_PI) / SAMPLE_RATE)
#define SAMPLE_RATE 44100

void ETGen(double dur, double freq, double vol)
{
    QAudioFormat format;
    format.setSampleRate(SAMPLE_RATE);
    format.setChannelCount(1);
    format.setSampleSize(8);
    format.setCodec("audio/pcm");
    format.setByteOrder(QAudioFormat::LittleEndian);
    format.setSampleType(QAudioFormat::UnSignedInt);

    QAudioDeviceInfo info(QAudioDeviceInfo::defaultOutputDevice());

    QByteArray* buf = new QByteArray();

    int length = dur * SAMPLE_RATE;

    buf->resize(length);

    for( int i = 0; i < length; i++)
    {
        qreal t = qSin(freq * i * FREQ_CONST)-1;
        (*buf)[i] = (quint8)t;
    }

    QBuffer* input = new QBuffer(buf);
    input->open(QIODevice::ReadOnly);

    QAudioOutput* audio = new QAudioOutput(format, Q_NULLPTR);
    audio->setVolume(vol);
    audio->start(input);
}
