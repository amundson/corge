#ifndef CORGE_H_

class Corge
{
private:
    static const int version_major;
    static const int version_minor;

public:
    Corge();
    int get_version() const;
    int corgegate() const;
};

#endif // CORGE_H_
