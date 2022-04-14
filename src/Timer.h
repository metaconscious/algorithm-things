#ifndef ALGORITHM_THINGS_TIMER_H
#define ALGORITHM_THINGS_TIMER_H

#include <chrono>
#include <functional>
#include <tuple>
#include <utility>
#include <variant>

namespace algo
{
    template<typename Function, typename... Args>
    class Timer
    {
    public:
        using clock_type = std::chrono::steady_clock;
        using duration_type = std::chrono::duration<double, std::ratio<1>>;
        using time_point = std::chrono::time_point<clock_type>;

    private:
        Function m_executor;
        std::tuple<Args...> m_args;
        double m_second;

        auto timeWithReturn() -> decltype(std::apply(m_executor, m_args))
        {
            time_point begin{ clock_type::now() };
            auto result{ std::apply(m_executor, m_args) };
            m_second = std::chrono::duration_cast<duration_type>(clock_type::now() - begin)
                .count();
            return result;
        }

        void timeWithoutReturn()
        {
            time_point begin{ clock_type::now() };
            std::apply(m_executor, m_args);
            m_second = std::chrono::duration_cast<duration_type>(clock_type::now() - begin)
                .count();
        }

    public:
        explicit Timer(Function executor, Args... args)
        : m_executor{ executor }, m_args{ args... }, m_second{}
        {
        }

        auto time() -> decltype(auto)
        {
            if constexpr(std::is_void_v<decltype(std::apply(m_executor, m_args))>)
            {
                timeWithoutReturn();
            }
            else
            {
                return timeWithReturn();
            }
        }

        [[nodiscard]] double getLastTime() const
        {
            return m_second;
        }

        void reset()
        {
            m_second = 0.0;
        }

    };
}

#endif // ALGORITHM_THINGS_TIMER_H
