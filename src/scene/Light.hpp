#pragma once

#include <string>

namespace scene{

/**
 * An abstract class to represent the light
*/
class Light{

    public:
        /**
         * Cast a light into a printable string
         * @return The light as a string
        */
        virtual std::string toString() const {
            return "";
        };

        /**
         * An empty destructor
        */
        ~Light(){};

};

};