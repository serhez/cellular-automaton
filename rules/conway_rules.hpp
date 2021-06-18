/*
 * @Author: Hezser <contact.sergiohernandez@gmail.com>
 * @Date: 18-06-2021 14:55
 * @Last Modified by: Hezser <contact.sergiohernandez@gmail.com>
 * @Last Modified time: 18-06-2021 16:56
 */

#ifndef CONWAY_RULES_HPP
#define CONWAY_RULES_HPP

#include <vector>
#include <xtensor/xarray.hpp>
#include "rules.hpp"

namespace rules
{

/**
 * @brief The rules defined by John Conway for his Game of Life, extrapolated to be dimension-agnostic
 */
class ConwayRules : public Rules
{
    public:
        /**
         * @brief Instantiates a ConwayRules object
         *
         * @param dimensions The number of dimensions of the grid the rules will be applied to
         */
        ConwayRules(const uint_fast8_t dimensions)

        bool applyToCell(const core::GridState& current_state, core::GridState& new_state, const std::vector<uint_fast64_t> cell) override;

    private:
        /**
         * @m_d The number of dimensions of the grid the rules will be applied to
         */
        const uint_fast8_t m_d;
        
        /**
         * @m_min_neighbours The minimum number of neighbours for a cell to survive
         */
        const uint_fast64_t m_min_neighbours;

        /**
         * @m_max_neighbours The maximum number of neighbours for a cell to survive or to be revived
         */
        const uint_fast64_t m_max_neighbours;
}

}  // namespace rules

#endif
