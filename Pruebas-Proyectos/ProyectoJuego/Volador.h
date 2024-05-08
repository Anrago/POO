class Volador
{
protected:
    bool Volando = false;

public:
    Volador() = default;
    bool IsFlaying() const { return Volando; };
    virtual void Volar() { Volando = true;};
    virtual void Aterrizar() { Volando = false;};
};
