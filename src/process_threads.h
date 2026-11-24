// What the process scheduler (process_threads.cpp) offers a game's own code.

#pragma once

#include <cstdint>
#include <vector>

// The keys of the processes that have started (have a thread), lowest first, for a snapshot of the game to know which
// processes' state is all in RDRAM: one that hasn't started is only its jmp_buf and stack there, while one that has
// keeps its locals on its thread's native stack. Read-only, and nothing in the engine calls it.
std::vector<uint32_t> mp_prc_started();

// Ends the thread of the process with this key, if it has one, without running any more of it, as the scheduler's reset
// ends them all: a game that takes up a snapshot in which that process hasn't started (or is another one) has it start
// afresh, from RDRAM, at its next resume. From the thread that runs the scheduler, between resumes.
void mp_prc_end(uint32_t key);
