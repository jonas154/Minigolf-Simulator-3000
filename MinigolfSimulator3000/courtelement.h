#ifndef COURTELEMENT_H
#define COURTELEMENT_H


//! \brief Baseclass for elements in the Court (borderlines and groundmaterials)
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

    //! \brief The type of the CourtElement, borderline or groundmaterial
    const int elementType;

};

#endif // COURTELEMENT_H
