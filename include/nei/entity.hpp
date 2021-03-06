#ifndef NEI_ENTITY_HPP
#define NEI_ENTITY_HPP
constexpr int WORLD_DOMINATION_SUCCESS = 0;

#include <nei/analyser.hpp>
#include <nei/concept.hpp>
#include <nei/ndarray.hpp>
#include <nei/sense.hpp>
#include <nei/type.hpp>
#include <nei/universe.hpp>
#include <vector>

namespace nei
{
    template<int Dimension>
    class entity
    {
    public:
        entity(const nei::universe<Dimension>&);

        void live();

        const nei::universe<Dimension>& universe() const;

        void notify_sense_update();
        void process_memory_analyse();

        auto concepts()
        {
            return concepts_;
        }

    private:
        const nei::universe<Dimension>& universe_;
        // physical
        nei::ndarray<10> position_;
        nei::sense<Dimension> senses_;

        // logical
        nei::analyser<Dimension> analyser_;
        // memory
        std::vector<nei::unit_type> memory_;
        std::vector<nei::concept> concepts_;

        void experiment() {}
        void evolve() {}
    };
} // nei

#include "entity.tpp"

#endif // NEI_ENTITY_HPP
