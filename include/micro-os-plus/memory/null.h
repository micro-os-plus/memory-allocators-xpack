/*
 * This file is part of the µOS++ distribution.
 *   (https://github.com/micro-os-plus/)
 * Copyright (c) 2016 Liviu Ionescu.
 *
 * Permission to use, copy, modify, and/or distribute this software
 * for any purpose is hereby granted, under the terms of the MIT license.
 *
 * If a copy of the license was not distributed with this file, it can
 * be obtained from https://opensource.org/licenses/MIT/.
 */

#ifndef MICRO_OS_PLUS_MEMORY_NULL_H_
#define MICRO_OS_PLUS_MEMORY_NULL_H_

// ----------------------------------------------------------------------------

#if defined(__cplusplus)

// ----------------------------------------------------------------------------

#include <micro-os-plus/rtos.h>

// ----------------------------------------------------------------------------

#pragma GCC diagnostic push

#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
#endif

namespace micro_os_plus
{
  namespace memory
  {

#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wweak-vtables"
#endif

    // ========================================================================

    /**
     * @headerfile os.h <micro-os-plus/rtos.h>
     * @ingroup micro-os-plus-rtos-memres
     * @brief
     * An internal memory manager that throws a `bad_alloc()`
     * exception when trying to allocate.
     *
     * It is the default memory manager when running on bare metal
     * platforms, to prevent unwanted dynamic allocations,
     * unless another setting is done during startup.
     */
    class null_memory_resource : public rtos::memory::memory_resource
    {
    public:
      /**
       * @name Constructors & Destructor
       * @{
       */

      /**
       * @brief Default constructor. Construct a memory manager object
       * instance.
       */
      null_memory_resource () = default;

      /**
       * @cond ignore
       */

      // The rule of five.
      null_memory_resource (const null_memory_resource&) = delete;
      null_memory_resource (null_memory_resource&&) = delete;
      null_memory_resource&
      operator= (const null_memory_resource&)
          = delete;
      null_memory_resource&
      operator= (null_memory_resource&&)
          = delete;

      /**
       * @endcond
       */

      /**
       * @brief Destruct the memory manager object instance.
       */
      ~null_memory_resource () override = default;

      /**
       * @}
       */

    protected:
      /**
       * @name Private Member Functions
       * @{
       */

      /**
       * @brief Implementation of the memory allocator.
       * @param bytes Number of bytes to allocate.
       * @param alignment Alignment constraint (power of 2).
       * @return Pointer to newly allocated block, or `nullptr`.
       */
      virtual void*
      do_allocate (std::size_t bytes, std::size_t alignment) override;

      /**
       * @brief Implementation of the memory deallocator.
       * @param addr Address of a previously allocated block to free.
       * @param bytes Number of bytes to deallocate (may be 0 if unknown).
       * @param alignment Alignment constraint (power of 2).
       * @par Returns
       *  Nothing.
       */
      virtual void
      do_deallocate (void* addr, std::size_t bytes,
                     std::size_t alignment) noexcept override;

      /**
       * @}
       */
    };

#pragma GCC diagnostic pop

    // -------------------------------------------------------------------------
  } // namespace memory
} // namespace micro_os_plus

// ===== Inline & template implementations ====================================

namespace micro_os_plus
{
  namespace memory
  {

    // ========================================================================

#pragma GCC diagnostic push
// Needed because 'alignment' is used only in trace calls.
#pragma GCC diagnostic ignored "-Wunused-parameter"

    inline void*
    null_memory_resource::do_allocate (std::size_t bytes,
                                       std::size_t alignment)
    {
      estd::__throw_bad_alloc ();
    }

    inline void
    null_memory_resource::do_deallocate (void* addr, std::size_t bytes,
                                         std::size_t alignment) noexcept
    {
    }

#pragma GCC diagnostic pop

    // ==========================================================================
  } // namespace memory
} // namespace micro_os_plus

#pragma GCC diagnostic pop

// ----------------------------------------------------------------------------

#endif // __cplusplus

// ----------------------------------------------------------------------------

#endif // MICRO_OS_PLUS_MEMORY_NULL_H_

// ----------------------------------------------------------------------------
