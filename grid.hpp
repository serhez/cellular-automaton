/*
 * @Author: Hezser <contact.sergiohernandez@gmail.com>
 * @Date: 13-06-2021 04:24
 * @Last Modified by: Hezser <contact.sergiohernandez@gmail.com>
 * @Last Modified time: 13-06-2021 05:47
 */

#ifndef GRID_HPP
#define GRID_HPP

namespace core
{

// Forward declaration
class Grid;

typedef std::vector<std::vector<int_fast64_t>> GridState;
typedef std::function<bool(Grid&, std::vector<int_fast64_t>)> CellUpdateFunction;

class Grid
{
    public:
        /**
         * @brief Instantiates a grid
         *
         * @param dimensions The dimensions of the grid
         * @param initial_state The initial state of the grid, describing the initial active cells
         * @param rules The evolutionary rules of the grid
         * @param max_rule_radius The maximum radius from which a cell can become active from any other active cell, given all rules
         */
        Grid(uint_fast8_t dimensions, GridState initial_state, CellUpdateFunction rules, uint_fast8_t max_rule_radius) noexcept;

        /**
         * @brief Destructs the grid
         *
         */
        ~Grid() noexcept;

        /**
         * @brief Updates the grid one time step
         *
         * @return True on sucess, false otherwise
         */
        bool update();

        /**
         * @brief State getter
         *
         * @return The current state
         */
        GridState state() const { return m_state; }

    private:
        /**
         * @m_d The dimensions of the grid
         */
        uint_fast8_t m_d;

        /**
         * @m_state The current state of the grid, which holds which cells are currently active
         */
        GridState m_state;

        /**
         * @m_rules The evolutionary rules of the grid
         */
        CellUpdateFunction m_rules;

        /**
         * @m_max_rule_radius The maximum radius from which a cell can become active from any other active cell, given all rules
         */
        uint_fast8_t m_max_rule_radius;

};

}  // namespace core

#endif
