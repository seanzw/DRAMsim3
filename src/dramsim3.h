#ifndef __MEMORY_SYSTEM__H
#define __MEMORY_SYSTEM__H

#include <functional>
#include <string>

namespace dramsim3 {

// This should be the interface class that deals with CPU
class MemorySystem {
   public:
    MemorySystem(const std::string &config_file,
                 const std::string &output_dir,
                 const std::string &output_prefix,
                 std::function<void(uint64_t)> read_callback,
                 std::function<void(uint64_t)> write_callback,
                 unsigned int interleave_bits_low,
                 unsigned int interleave_bits_high
                 );
    ~MemorySystem();
    void ClockTick();
    void RegisterCallbacks(std::function<void(uint64_t)> read_callback,
                           std::function<void(uint64_t)> write_callback);
    double GetTCK() const;
    int GetBusBits() const;
    int GetBurstLength() const;
    int GetQueueSize() const;
    void PrintStats() const;
    void ResetStats();

    bool WillAcceptTransaction(uint64_t hex_addr, bool is_write) const;
    bool AddTransaction(uint64_t hex_addr, bool is_write);
};

}  // namespace dramsim3

#endif
