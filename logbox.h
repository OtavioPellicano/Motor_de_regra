#ifndef LOGBOX_H
#define LOGBOX_H

#include <QObject>
#include <QStringList>
#include <QString>


namespace opmm {

/**
 * @brief The LogBox class
 * Classe destinada ao armazenamento de logs do sistema
 */
class LogBox : public QObject
{
    Q_OBJECT
public:
    explicit LogBox(QObject *parent = nullptr);

    void operator <<(const QString &str);

    void clear();

    QString logStr();

    QStringList logList() const;
    void setLogList(const QStringList &logList);

signals:

public slots:

private:
    QStringList mLogList;
    QString mLog = "";
};

}






#endif // LOGBOX_H
