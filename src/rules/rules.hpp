/*
 * @Author: serhez <contact.sergiohernandez@gmail.com>
 * @Date: 18-06-2021 16:05
 * @Last Modified by: serhez <contact.sergiohernandez@gmail.com>
 * @Last Modified time: 20-06-2021 16:06
 */

#ifndef RULES_HPP
#define RULES_HPP

#include <vector>
#include "../core/grid.hpp"

namespace rules
{

/**
 * @brief An interface which encapsulates a set of rules to define the next state of a grid, given its current state
 */
class Rules {
    public:
        /**
         * @brief Applies the rules to a cell in the grid
         *
         * @param current_state The current state of the grid (read-only)
         * @param new_state The new state of the grid that must be changed to enforce the rules
         * @param cell The coordinates of the cell to update in the grid
         * @return True on success, false otherwise
         */
        virtual bool applyToCell(const core::GridState& current_state, core::GridState& new_state, const core::GridCell& cell) const = 0;

        /**
         * @brief Inactive radius getter
         *
         * @return The maximum radius from which a cell can change its state from any other cell, given all rules (max. 8 bits)
         */
        uint_fast8_t getInactiveRadius() const { return m_inactive_radius; }

    protected:
        /**
         * @brief Instantiates the base class Rules
         *
         * @param inactive_radius The maximum radius from which a cell can change its state from any other cell, given all rules (max. 8 bits) 
         */
        Rules(uint_fast8_t inactive_radius) : m_inactive_radius{inactive_radius} {}

        /**
         * @m_inactive_radius The maximum radius from which a cell can change its state from any other cell, given all rules (max. 8 bits)
         */
        const uint_fast8_t m_inactive_radius;

    private:
        /**
         * @brief Hidden default constructor
         *
         */
        Rules();
};

}  // namespace rules

#endif
