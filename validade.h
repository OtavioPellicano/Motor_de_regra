#ifndef VALIDADE_H
#define VALIDADE_H

namespace opmm {

enum layout {ABR, TGR, NETMETRICS, SEMIGLOBE, HDM};

class Validade
{
public:
    Validade();

    virtual bool medicaoValida() const;

protected:
    virtual void setMedicaoValida(const bool &medicaoValida);

private:
    bool mMedicaoValida;
};


}


#endif // VALIDADE_H
