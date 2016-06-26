#ifndef GROUNDMATERIAL_H
#define GROUNDMATERIAL_H


#include "courtelement.h"
#include <QGraphicsPolygonItem>
#include <QPolygonF>


//! \brief This class provides the functionality for using different ground materials in the Court
class GroundMaterial : public CourtElement, public QGraphicsPolygonItem
{

public:

//--------------------------

    //! \brief enum for different materials
    enum eMaterial{concrete_material = 0, grass_material, wood_material, sand_material,
                   water_material, nonNewtonian_material, speedUp_material, hole_material};

//--------------------------

    /*! \brief Constructor
     *
     * Constructs a GroundMaterial object.
     * @param[in] _material The ground's material as defined in enum eMaterial
     * @param[in] _polygon The ground's polygon, can be set later via setPolygon()
     */
    GroundMaterial(const int _material, const QPolygonF _polygon = QPolygonF(), QGraphicsItem* parent = 0)
        :
        CourtElement(CourtElement::groundmaterial_type), material(_material), minSpeed(0.0001), maxSpeed(10.0)
    {
        switch(material)
        {
            case concrete_material:
                frictionCoefficient = 0.01;
            break;

            case grass_material:
                frictionCoefficient = 0.01;
                minSpeed = 0.0001;
            break;

            case wood_material:
                frictionCoefficient = 0.01;
            break;

            case sand_material:
                frictionCoefficient = 0.08;
                minSpeed = 0.1;
            break;

            case water_material:
                frictionCoefficient = 0.3;
            break;

            case nonNewtonian_material:
                frictionCoefficient = 0.03;
                minSpeed = 0.5;
            break;

            case speedUp_material:
                frictionCoefficient = -0.01;
            break;

            case hole_material:
                frictionCoefficient = 0.01;
                maxSpeed = 4.0;
            break;

            default:
                frictionCoefficient = 0.01;
            break;
        }

        this->setPolygon(_polygon);

    };

//--------------------------

    //! \brief Destructor
    virtual ~GroundMaterial(){};

//--------------------------

    //! \brief reimplementation from QGraphicsItem::type()
    int type() const
    {
        return elementType;
    };

//--------------------------

    //! \brief Returns the current material's friction coefficient
    double getFrictionCoefficient() const
    {
        return frictionCoefficient;
    };

//--------------------------

    //! \brief Returns the current material's minimum speed
    double getMinSpeed()
    {
        return minSpeed;
    }

//--------------------------

    //! \brief Returns the current material's maximum speed
    double getMaxSpeed()
    {
        return maxSpeed;
    }

//--------------------------

    //! \brief Returns the ground's material, as defined in enum eMaterial
    int getMaterial() const
    {
        return material;
    };

//--------------------------------------

private:

    const int material;
    double frictionCoefficient;
    double minSpeed;
    double maxSpeed;

};

#endif // GROUNDMATERIAL_H
