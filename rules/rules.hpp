/*
 * @Author: Hezser <contact.sergiohernandez@gmail.com>
 * @Date: 18-06-2021 16:05
 * @Last Modified by: Hezser <contact.sergiohernandez@gmail.com>
 * @Last Modified time: 18-06-2021 16:59
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
        virtual bool applyToCell(const core::GridState& current_state, core::GridState& new_state, const std::vector<uint_fast64_t> cell) = 0;

        /**
         * @inactive_radius The maximum radius from which a cell can change its state from any other cell, given all rules (max. 8 bits)
         */
        const uint_fast8_t inactive_radius;

    protected:
        /**
         * @brief Hidden default constructor
         *
         */
        Rules();
}

}  // namespace rules

#endif