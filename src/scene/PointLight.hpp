#pragma once

#include "Light.hpp"

namespace scene{

/**
 * A class to represent a light on a point
*/
class PointLight : Light{

    public:
        /**
         * Cast a light into a printable string
         * @return The light as a string
        */
        std::string toString() const override {
            return "";
        };

};

};