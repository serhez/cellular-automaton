/*
 * @Author: serhez <contact.sergiohernandez@gmail.com>
 * @Date: 18-06-2021 14:55
 * @Last Modified by: serhez <contact.sergiohernandez@gmail.com>
 * @Last Modified time: 20-06-2021 16:05
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
        ConwayRules(const uint_fast8_t dimensions);

        bool applyToCell(const core::GridState& current_state, core::GridState& new_state, const core::GridCell& cell) const override;

    private:
        /**
         * @MIN_NEIGHBOURS_RATIO The dimension-agnostic minimum ratio of neighbours a cell needs to survive
         */
        static constexpr float MIN_NEIGHBOURS_RATIO = 1./4.;

        /**
         * @MAX_NEIGHBOURS_RATIO The dimension-agnostic maximum ratio of neighbours a cell needs to survive or to be revived
         */
        static constexpr float MAX_NEIGHBOURS_RATIO = 3./8.;

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
};

}  // namespace rules

#endif
