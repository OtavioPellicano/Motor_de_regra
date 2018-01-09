#include "logbox.h"


namespace opmm {


LogBox::LogBox(QObject *parent) : QObject(parent)
{

}

void LogBox::operator <<(const QString &str)
{
    mLogList << str;
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




}
