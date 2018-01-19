#include "DePara.h"

namespace opmm {

DePara::DePara(const string &pathIn, const string &pathOut, const layout &tipoLayout)
{
    setDirPathIn(QDir(QString::fromStdString(pathIn)));
    setDirPathOut(QDir(QString::fromStdString(pathOut)));
    setTipoLayout(tipoLayout);

    setFiltro("*.csv");
    QStringList listaFiltros;
    listaFiltros.append(mFiltro);
    mDirPathIn.setNameFilters(listaFiltros);
    setListaArquivosIn(dirPathIn().entryList());

    processarDePara();

}


QDir DePara::dirPathIn() const
{
    return mDirPathIn;
}

void DePara::setDirPathIn(const QDir &dirPathIn)
{
    mDirPathIn = dirPathIn;
}

QDir DePara::dirPathOut() const
{
    return mDirPathOut;
}

void DePara::setDirPathOut(const QDir &dirPathOut)
{
    mDirPathOut = dirPathOut;
}

layout DePara::tipoLayout() const
{
    return mTipoLayout;
}

void DePara::setTipoLayout(const layout &tipoLayout)
{
    mTipoLayout = tipoLayout;
}

void DePara::processarDePara()
{
    switch (tipoLayout()) {
    case HDM:

        for(QStringList::iterator itQStr = listaArquivosIn().begin(); itQStr != listaArquivosIn().end(); ++itQStr)
        {
            setNomeArquivoIn(dirPathIn().absoluteFilePath(*itQStr).toStdString());

            mArquivoIn.open(nomeArquivoIn());

            if(mArquivoIn.is_open())
            {
                string linhaArq;
                for(size_t i = 1; getline(mArquivoIn, linhaArq);++i)
                {
                    //mMedicaoNormalizada = new NormalizacaoDeDados(linhaArq, tipoLayout(),  )
                }


                mArquivoIn.close();
            }
            else
            {
                qDebug() << "Impossivel abrir arquivo origem!";
            }

        }


        break;
    default:
        break;
    }
}

string DePara::nomeArquivoIn() const
{
    return mNomeArquivoIn;
}

void DePara::setNomeArquivoIn(const string &nomeArquivoIn)
{
    mNomeArquivoIn = nomeArquivoIn;
}


QStringList DePara::listaArquivosIn() const
{
    return mListaArquivosIn;
}

void DePara::setListaArquivosIn(const QStringList &listaArquivosIn)
{
    mListaArquivosIn = listaArquivosIn;
}

QString DePara::filtro() const
{
    return mFiltro;
}

void DePara::setFiltro(const QString &filtro)
{
    mFiltro = filtro;
}


}

