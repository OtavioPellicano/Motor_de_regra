#include "logbox.h"


namespace opmm {


LogBox::LogBox(QObject *parent) : QObject(parent)
{

}
/**
 * @brief LogBox::operator <<
 * @param str
 * use to populate mLogList
 */
void LogBox::operator <<(const QString &str)
{
    mLogList << str;
}

void LogBox::clear()
{
    mLogList.clear();
}

QString LogBox::logStr()
{

    if (mLogList.size() != 0)
    {
        for(QStringList::iterator itStr = mLogList.begin(); itStr != mLogList.end(); ++itStr)
        {
            if (itStr != mLogList.end() - 1)
            {
                mLog += *itStr + "\n";
            }
            else
            {
                mLog += *itStr;
            }

        }
    }

    return mLog;
}

QStringList LogBox::logList() const
{
    return mLogList;
}

void LogBox::setLogList(const QStringList &logList)
{
    mLogList = logList;
}




}
