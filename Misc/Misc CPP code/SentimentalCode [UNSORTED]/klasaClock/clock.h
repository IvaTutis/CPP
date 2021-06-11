#include <chrono>

class Clock{
    public:
        enum Interval{sec, millisec, microsec};
        Clock(){start();}
        void start(){ begin = mClock.now();}
        double stop(Interval unit){ 
            end = mClock.now();
            switch(unit){
                case sec:      return std::chrono::duration_cast<std::chrono::seconds>(end-begin).count();
                case millisec: return std::chrono::duration_cast<std::chrono::milliseconds>(end-begin).count();
                default:       return std::chrono::duration_cast<std::chrono::microseconds>(end-begin).count();
            };
        }
    private:
        std::chrono::high_resolution_clock mClock;
        std::chrono::time_point<std::chrono::high_resolution_clock> begin;
        std::chrono::time_point<std::chrono::high_resolution_clock> end;
};
