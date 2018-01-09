#ifndef LOGBOX_H
#define LOGBOX_H

#include <QObject>
#include <QStringList>
#include <QString>


namespace opmm {


class LogBox : public QObject
{
    Q_OBJECT
public:
    explicit LogBox(QObject *parent = nullptr);

    void operator <<(const QString &str);

    QString logStr();

signals:

public slots:

private:
    QStringList mLogList;
    QString mLog = "";
};

}






#endif // LOGBOX_H
