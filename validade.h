#ifndef VALIDADE_H
#define VALIDADE_H

namespace opmm {

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
