#ifndef DEPARA_H
#define DEPARA_H

#include "NormalizacaoDeDados.h"

#include <QDir>
#include <QString>
#include <QStringList>
#include <fstream>
#include <QDebug>


using namespace std;

namespace opmm {

/**
 * @brief The DePara class
 * PRECISO FAZER O DePara de acordo com a Tecnologia!!!!!!
 *
 */
class DePara
{
public:
    DePara(const string &pathIn, const string &pathOut, const layout &tipoLayout);


    QDir dirPathIn() const;
    void setDirPathIn(const QDir &dirPathIn);

    QDir dirPathOut() const;
    void setDirPathOut(const QDir &dirPathOut);

    layout tipoLayout() const;
    void setTipoLayout(const layout &tipoLayout);

    QString filtro() const;
    void setFiltro(const QString &filtro);

    QStringList listaArquivosIn() const;
    void setListaArquivosIn(const QStringList &listaArquivosIn);


    string nomeArquivoIn() const;
    void setNomeArquivoIn(const string &nomeArquivoIn);

private:

    void processarDePara();


private:

    QDir mDirPathIn;
    string mNomeArquivoIn;
    ifstream mArquivoIn;

    QDir mDirPathOut;
    layout mTipoLayout;

    QString mFiltro;
    QStringList mListaArquivosIn;

    NormalizacaoDeDados *mMedicaoNormalizada;

};

}


#endif // DEPARA_H
