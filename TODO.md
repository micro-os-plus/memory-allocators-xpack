# To Do

Currently the definitions depend on the RTOS, since they 
are derived from `rtos::memory::memory_resource`.

Study the C++17/20 standards and redefine them standalone,
with the option to also be able to use them
inside the RTOS.

Define templates for the functions in `rtos/src/libc/stdlib/malloc.cpp`,
and instantiate them there.
