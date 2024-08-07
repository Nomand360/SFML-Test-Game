#ifndef AIRCRAFT_H
#define AIRCRAFT_H
#include "Entity.h"

class Aircraft : public Entity {
public:
    enum class Type : uint8_t {
        Eagle,
        Raptor
    };

public:
    explicit Aircraft(Type type);

private:
    Type mType;
};

#endif // AIRCRAFT_H
