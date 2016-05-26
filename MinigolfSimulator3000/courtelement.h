#ifndef COURTELEMENT_H
#define COURTELEMENT_H

class CourtElement
{

public:

    //! \brief enum for different element types
    enum eType{borderline_type = 65537, groundmaterial_type};

    //! \brief Constructor
    CourtElement(const int _elementType)
        :
        elementType(_elementType)
    {
    };

    //! \brief Destructor
    virtual ~CourtElement(){};


protected:

    const int elementType;

};

#endif // COURTELEMENT_H
