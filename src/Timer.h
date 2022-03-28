#ifndef ALGORITHM_THINGS_TIMER_H
#define ALGORITHM_THINGS_TIMER_H

#include <chrono>
#include <functional>
#include <utility>

namespace algo
{
    template<typename R, typename... Args>
    class Timer
    {
    public:
        using clock_type = std::chrono::steady_clock;
        using duration_type = std::chrono::duration<double, std::ratio<1>>;
        using time_point = std::chrono::time_point<clock_type>;

    private:
        std::function<R(Args...)> m_executor;
        double m_second;

    public:
        explicit Timer(std::function<R(Args...)> executor) : m_executor{ executor }, m_second{}
        {
        }

        Timer(const Timer&) = delete;
        Timer(Timer&&) = delete;
        Timer& operator=(const Timer&) = delete;
        Timer& operator=(Timer&&) = delete;

        R operator()(Args... args)
        {
            time_point begin{ clock_type::now() };
            auto result{ m_executor(std::forward<Args>(args)...) };
            m_second = std::chrono::duration_cast<duration_type>(clock_type::now() - begin).count();
            return result;
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

    template<typename... Args>
    class Timer<void, Args...>
    {
    public:
        using clock_type = std::chrono::steady_clock;
        using duration_type = std::chrono::duration<double, std::ratio<1>>;
        using time_point = std::chrono::time_point<clock_type>;

    private:
        std::function<void(Args...)> m_executor;
        double m_second;

    public:
        explicit Timer(std::function<void(Args...)> executor) : m_executor{ executor }, m_second{}
        {
        }

        Timer(const Timer&) = delete;
        Timer(Timer&&) = delete;
        Timer& operator=(const Timer&) = delete;
        Timer& operator=(Timer&&) = delete;

        void operator()(Args... args)
        {
            time_point begin{ clock_type::now() };
            m_executor(std::forward<Args>(args)...);
            m_second = std::chrono::duration_cast<duration_type>(clock_type::now() - begin).count();
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
