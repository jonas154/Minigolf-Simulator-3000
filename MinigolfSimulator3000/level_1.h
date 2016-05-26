#ifndef LEVEL_1_H
#define LEVEL_1_H

#include "court.h"


class Level_1 : public Court
{
public:

    //! \brief Constructor
    Level_1();

    //! \brief Destructor
    virtual ~Level_1(){};

    //! \brief Constructs the level
    void constructLevel();

private:


};

#endif // LEVEL_1_H
